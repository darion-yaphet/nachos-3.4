// post.cc 
// 	Routines to deliver incoming network messages to the correct
//	"address" -- a mailbox, or a holding area for incoming messages.
//	This module operates just like the US postal service (in other
//	words, it works, but it's slow, and you can't really be sure if
//	your mail really got through!).
//
//	Note that once we prepend the MailHdr to the outgoing message data,
//	the combination (MailHdr plus data) looks like "data" to the Network 
//	device.
//
// 	The implementation synchronizes incoming messages with threads
//	waiting for those messages.
//
// Copyright (c) 1992-1993 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation 
// of liability and disclaimer of warranty provisions.

#include "copyright.h"
#include "post.h"
#include "synch.h"
#include "system.h"

//----------------------------------------------------------------------
// Mail::Mail
//      Initialize a single mail message, by concatenating the headers to
//	the data.
//
//	"pktH" -- source, destination machine ID's
//	"mailH" -- source, destination mailbox ID's
//	"msgData" -- payload data
//----------------------------------------------------------------------

Mail::Mail(PacketHeader pktH, MailHeader mailH, const char *msgData)
    : pktHdr(pktH), mailHdr(mailH)
{
    ASSERT(mailH.length <= MaxMailSize);
    memmove(data, msgData, mailHdr.length);
}

//----------------------------------------------------------------------
// MailBox::MailBox
//      Initialize a single mail box within the post office, so that it
//	can receive incoming messages.
//
//	Just initialize a list of messages, representing the mailbox.
//----------------------------------------------------------------------

MailBox::MailBox()
{ 
    messages = std::make_unique<SynchList>(); 
}

//----------------------------------------------------------------------
// MailBox::~MailBox
//      De-allocate a single mail box within the post office.
//
//	Just delete the mailbox, and throw away all the queued messages 
//	in the mailbox.
//----------------------------------------------------------------------

MailBox::~MailBox()
{
    // List nodes do not own their payloads.  The enclosing PostOffice must
    // first stop producers and guarantee that no receiver is waiting.
    while (Mail *mail = messages->TryRemoveAs<Mail>())
        delete mail;
}

//----------------------------------------------------------------------
// PrintHeader
// 	Print the message header -- the destination machine ID and mailbox
//	#, source machine ID and mailbox #, and message length.
//
//	"pktHdr" -- source, destination machine ID's
//	"mailHdr" -- source, destination mailbox ID's
//----------------------------------------------------------------------

static void 
PrintHeader(PacketHeader pktHdr, MailHeader mailHdr)
{
    printf("From (%d, %d) to (%d, %d) bytes %d\n",
    	    pktHdr.from, mailHdr.from, pktHdr.to, mailHdr.to, mailHdr.length);
}

//----------------------------------------------------------------------
// MailBox::Put
// 	Add a message to the mailbox.  If anyone is waiting for message
//	arrival, wake them up!
//
//	We need to reconstruct the Mail message (by concatenating the headers
//	to the data), to simplify queueing the message on the SynchList.
//
//	"pktHdr" -- source, destination machine ID's
//	"mailHdr" -- source, destination mailbox ID's
//	"data" -- payload message data
//----------------------------------------------------------------------

void 
MailBox::Put(PacketHeader pktHdr, MailHeader mailHdr, const char *data)
{ 
    Mail *mail = new Mail(pktHdr, mailHdr, data); 

    messages->Append(reinterpret_cast<void *>(mail));	// put on the end of the list of 
					// arrived messages, and wake up 
					// any waiters
}

//----------------------------------------------------------------------
// MailBox::Get
// 	Get a message from a mailbox, parsing it into the packet header,
//	mailbox header, and data. 
//
//	The calling thread waits if there are no messages in the mailbox.
//
//	"pktHdr" -- address to put: source, destination machine ID's
//	"mailHdr" -- address to put: source, destination mailbox ID's
//	"data" -- address to put: payload message data
//----------------------------------------------------------------------

void 
MailBox::Get(PacketHeader *pktHdr, MailHeader *mailHdr, char *data) 
{ 
    DEBUG('n', "Waiting for mail in mailbox\n");
    Mail *mail = reinterpret_cast<Mail *>(messages->Remove());	// remove message from list;
						// will wait if list is empty

    *pktHdr = mail->pktHdr;
    *mailHdr = mail->mailHdr;
    if (DebugIsEnabled('n')) {
	printf("Got mail from mailbox: ");
	PrintHeader(*pktHdr, *mailHdr);
    }
    memmove(data, mail->data, mail->mailHdr.length);
					// copy the message data into
					// the caller's buffer
    delete mail;			// we've copied out the stuff we
					// need, we can now discard the message
}

//----------------------------------------------------------------------
// PostalHelper, ReadAvail, WriteDone
// 	Dummy functions because C++ can't indirectly invoke member functions
//	The first is forked as part of the "postal worker thread; the
//	later two are called by the network interrupt handler.
//
//	"arg" -- pointer to the Post Office managing the Network
//----------------------------------------------------------------------

static void PostalHelper(intptr_t arg)
{ PostOffice* po = reinterpret_cast<PostOffice *>(arg); po->PostalDelivery(); }
static void ReadAvail(intptr_t arg)
{ PostOffice* po = reinterpret_cast<PostOffice *>(arg); po->IncomingPacket(); }
static void WriteDone(intptr_t arg)
{ PostOffice* po = reinterpret_cast<PostOffice *>(arg); po->PacketSent(); }

//----------------------------------------------------------------------
// PostOffice::PostOffice
// 	Initialize a post office as a collection of mailboxes.
//	Also initialize the network device, to allow post offices
//	on different machines to deliver messages to one another.
//
//      We use a separate thread "the postal worker" to wait for messages 
//	to arrive, and deliver them to the correct mailbox.  Note that
//	delivering messages to the mailboxes can't be done directly
//	by the interrupt handlers, because it requires a Lock.
//
//	"addr" is this machine's network ID 
//	"reliability" is the probability that a network packet will
//	  be delivered (e.g., reliability = 1 means the network never
//	  drops any packets; reliability = 0 means the network never
//	  delivers any packets)
//	"nBoxes" is the number of mail boxes in this Post Office
//----------------------------------------------------------------------

PostOffice::PostOffice(NetworkAddress addr, double reliability, int nBoxes)
    : netAddr(addr), numBoxes(nBoxes)
{
// First, initialize the synchronization with the interrupt handlers
    messageAvailable = std::make_unique<Semaphore>("message available", 0);
    messageSent = std::make_unique<Semaphore>("message sent", 0);
    workerStopped = std::make_unique<Semaphore>("postal worker stopped", 0);
    sendLock = std::make_unique<Lock>("message send lock");

// Second, initialize the mailboxes
    boxes = std::make_unique<MailBox[]>(nBoxes);

// Third, initialize the network; tell it which interrupt handlers to call
    network = std::make_unique<Network>(addr, reliability, ReadAvail, WriteDone, reinterpret_cast<intptr_t>(this));

// Finally, create a thread whose sole job is to wait for incoming messages,
//   and put them in the right mailbox. 
    Thread *t = new Thread("postal worker", true);
    // Request handle-managed lifetime before Fork. The PostOffice may be
    // destroyed by a thread other than this parent, so shutdown uses the
    // workerStopped handshake instead of the parent-only Join operation.
    (void)t->GetJoinHandle();
    t->Fork(PostalHelper, reinterpret_cast<intptr_t>(this));
}

//----------------------------------------------------------------------
// PostOffice::~PostOffice
// 	De-allocate the post office data structures.
//----------------------------------------------------------------------

PostOffice::~PostOffice()
{
    // Callers blocked in Send or Receive still borrow synchronization and
    // mailbox state; the owner must stop them before destroying PostOffice.
    IntStatus oldLevel = interrupt->SetLevel(IntOff);
    stopping = true;
    ASSERT(activeClients == 0);

    messageAvailable->V();
    workerStopped->P();

    // Network callbacks borrow this PostOffice. Cancel them while all
    // callback targets and synchronization objects still exist.
    network.reset();
    boxes.reset();
    sendLock.reset();
    workerStopped.reset();
    messageSent.reset();
    messageAvailable.reset();

    // All state reachable by a device callback or client is gone before
    // restoring the caller's interrupt level. Enabling may advance time.
    (void)interrupt->SetLevel(oldLevel);
}

//----------------------------------------------------------------------
// PostOffice::PostalDelivery
// 	Wait for incoming messages, and put them in the right mailbox.
//
//      Incoming messages have had the PacketHeader stripped off,
//	but the MailHeader is still tacked on the front of the data.
//----------------------------------------------------------------------

void
PostOffice::PostalDelivery()
{
    PacketHeader pktHdr;
    MailHeader mailHdr;
    char buffer[MaxPacketSize];

    for (;;) {
        // first, wait for a message
        messageAvailable->P();
        if (stopping) {
            // Keep interrupts off between making the destructor runnable and
            // finishing, so it cannot resume and free state still in use here.
            (void)interrupt->SetLevel(IntOff);
            workerStopped->V();
            currentThread->Finish();
            ASSERT(false);
        }
        pktHdr = network->Receive(buffer);

        memcpy(&mailHdr, buffer, sizeof(mailHdr));
        if (DebugIsEnabled('n')) {
	    printf("Putting mail into mailbox: ");
	    PrintHeader(pktHdr, mailHdr);
        }

	// check that arriving message is legal!
	ASSERT(0 <= mailHdr.to && mailHdr.to < numBoxes);
	ASSERT(mailHdr.length <= MaxMailSize);

	// put into mailbox
        boxes[mailHdr.to].Put(pktHdr, mailHdr, buffer + sizeof(MailHeader));
    }
}

//----------------------------------------------------------------------
// PostOffice::Send
// 	Concatenate the MailHeader to the front of the data, and pass 
//	the result to the Network for delivery to the destination machine.
//
//	Note that the MailHeader + data looks just like normal payload
//	data to the Network.
//
//	"pktHdr" -- source, destination machine ID's
//	"mailHdr" -- source, destination mailbox ID's
//	"data" -- payload message data
//----------------------------------------------------------------------

void
PostOffice::Send(PacketHeader pktHdr, MailHeader mailHdr, const char* data)
{
    IntStatus entryLevel = interrupt->SetLevel(IntOff);
    ASSERT(!stopping);
    ++activeClients;
    (void)interrupt->SetLevel(entryLevel);

    char buffer[MaxPacketSize];	// space to hold concatenated
				// mailHdr + data

    if (DebugIsEnabled('n')) {
	printf("Post send: ");
	PrintHeader(pktHdr, mailHdr);
    }
    ASSERT(mailHdr.length <= MaxMailSize);
    ASSERT(0 <= mailHdr.to && mailHdr.to < numBoxes);
    
    // fill in pktHdr, for the Network layer
    pktHdr.from = netAddr;
    pktHdr.length = mailHdr.length + sizeof(MailHeader);

    // concatenate MailHeader and data
    memmove(buffer, &mailHdr, sizeof(MailHeader));
    memmove(buffer + sizeof(MailHeader), data, mailHdr.length);

    {
        LockGuard guard(sendLock.get());   	// only one message can be sent
					// to the network at any one time
        network->Send(pktHdr, buffer);
        messageSent->P();		// wait for interrupt to tell us
					// ok to send the next message
    }

    IntStatus exitLevel = interrupt->SetLevel(IntOff);
    ASSERT(activeClients > 0);
    --activeClients;
    (void)interrupt->SetLevel(exitLevel);
}

//----------------------------------------------------------------------
// PostOffice::Receive
// 	Retrieve a message from a specific box if one is available, 
//	otherwise wait for a message to arrive in the box.
//
//	Note that the MailHeader + data looks just like normal payload
//	data to the Network.
//
//
//	"box" -- mailbox ID in which to look for message
//	"pktHdr" -- address to put: source, destination machine ID's
//	"mailHdr" -- address to put: source, destination mailbox ID's
//	"data" -- address to put: payload message data
//----------------------------------------------------------------------

void
PostOffice::Receive(int box, PacketHeader *pktHdr, 
				MailHeader *mailHdr, char* data)
{
    IntStatus entryLevel = interrupt->SetLevel(IntOff);
    ASSERT(!stopping);
    ++activeClients;
    (void)interrupt->SetLevel(entryLevel);

    ASSERT((box >= 0) && (box < numBoxes));

    boxes[box].Get(pktHdr, mailHdr, data);
    ASSERT(mailHdr->length <= MaxMailSize);

    IntStatus exitLevel = interrupt->SetLevel(IntOff);
    ASSERT(activeClients > 0);
    --activeClients;
    (void)interrupt->SetLevel(exitLevel);
}

//----------------------------------------------------------------------
// PostOffice::IncomingPacket
// 	Interrupt handler, called when a packet arrives from the network.
//
//	Signal the PostalDelivery routine that it is time to get to work!
//----------------------------------------------------------------------

void
PostOffice::IncomingPacket()
{ 
    messageAvailable->V(); 
}

//----------------------------------------------------------------------
// PostOffice::PacketSent
// 	Interrupt handler, called when the next packet can be put onto the 
//	network.
//
//	The name of this routine is a misnomer; if "reliability < 1",
//	the packet could have been dropped by the network, so it won't get
//	through.
//----------------------------------------------------------------------

void 
PostOffice::PacketSent()
{ 
    messageSent->V();
}
