// Device and queued-payload lifetime regression tests.
#include "system.h"

#ifdef USER_PROGRAM
#include "console.h"
#endif

#ifdef NETWORK
#include "network.h"
#include "post.h"
#endif

namespace {

int eventOrder[4] = {};
unsigned eventCount = 0;

void RecordEvent(intptr_t arg)
{
    ASSERT(eventCount < 4);
    eventOrder[eventCount++] = static_cast<int>(arg);
}

void RecordAlternateEvent(intptr_t arg)
{
    ASSERT(eventCount < 4);
    eventOrder[eventCount++] = 100 + static_cast<int>(arg);
}

#if defined(USER_PROGRAM) || defined(NETWORK)
void AdvancePastDeviceDelay()
{
    for (int elapsed = 0; elapsed <= ConsoleTime; elapsed += SystemTick)
        interrupt->OneTick();
}

void CountCallback(intptr_t arg)
{
    auto *count = reinterpret_cast<unsigned *>(arg);
    ++*count;
}
#endif

} // namespace

void DeviceRegressionTest()
{
    eventCount = 0;
    int ticksBeforeCancel = stats->totalTicks;
    IntStatus levelBeforeCancel = interrupt->getLevel();

    // All events have the same due time. Cancelling one exact owner pair
    // must retain other handlers/arguments in insertion order.
    interrupt->Schedule(RecordEvent, 1, SystemTick, ConsoleReadInt);
    interrupt->Schedule(RecordEvent, 2, SystemTick, ConsoleReadInt);
    interrupt->Schedule(RecordAlternateEvent, 2, SystemTick, ConsoleReadInt);
    interrupt->Schedule(RecordEvent, 2, SystemTick, ConsoleReadInt);
    interrupt->Schedule(RecordEvent, 3, SystemTick, ConsoleReadInt);
    ASSERT(interrupt->Cancel(RecordEvent, 2) == 2);
    ASSERT(interrupt->getLevel() == levelBeforeCancel);
    ASSERT(stats->totalTicks == ticksBeforeCancel);

    interrupt->OneTick();
    ASSERT(eventCount == 3);
    ASSERT(eventOrder[0] == 1);
    ASSERT(eventOrder[1] == 102);
    ASSERT(eventOrder[2] == 3);

#ifdef USER_PROGRAM
    unsigned consoleCallbacks = 0;
    {
        Console console("/dev/null", "/dev/null", CountCallback,
                        CountCallback,
                        reinterpret_cast<intptr_t>(&consoleCallbacks));
        console.PutChar('x');
    }
    AdvancePastDeviceDelay();
    ASSERT(consoleCallbacks == 0);
#endif

#ifdef NETWORK
    unsigned networkCallbacks = 0;
    {
        // Reliability zero avoids external delivery while retaining the
        // asynchronous send-completion and receive-poll callbacks.
        Network network(31415, 0.0, CountCallback, CountCallback,
                        reinterpret_cast<intptr_t>(&networkCallbacks));
        PacketHeader packet{};
        packet.to = 31415;
        packet.from = 31415;
        packet.length = 1;
        network.Send(packet, "x");
    }
    AdvancePastDeviceDelay();
    ASSERT(networkCallbacks == 0);

    {
        MailBox mailbox;
        PacketHeader packet{};
        MailHeader mail{};
        mail.length = 1;
        mailbox.Put(packet, mail, "a");
        mailbox.Put(packet, mail, "b");
        // Destructor must drain both heap-allocated Mail payloads without
        // calling the blocking Remove path.
    }

    // The destroying thread is deliberately not the thread that constructed
    // this PostOffice (and therefore not the postal worker's parent).
    auto *secondaryPostOffice = new PostOffice(31416, 1.0, 2);
    PacketHeader secondaryPacket{};
    secondaryPacket.to = 31416;
    MailHeader secondaryMail{};
    secondaryMail.to = 1;
    secondaryMail.from = 0;
    const char secondaryMessage[] = "secondary post office";
    secondaryMail.length = sizeof(secondaryMessage);
    secondaryPostOffice->Send(secondaryPacket, secondaryMail,
                              secondaryMessage);
    char secondaryResult[MaxMailSize] = {};
    secondaryPostOffice->Receive(1, &secondaryPacket, &secondaryMail,
                                 secondaryResult);
    ASSERT(memcmp(secondaryMessage, secondaryResult,
                  sizeof(secondaryMessage)) == 0);

    Thread *deleter = new Thread("post office deleter", true);
    ThreadJoinHandle deleterHandle = deleter->GetJoinHandle();
    deleter->Fork([](intptr_t arg) {
        delete reinterpret_cast<PostOffice *>(arg);
    }, reinterpret_cast<intptr_t>(secondaryPostOffice));
    ASSERT(deleterHandle.Join() == 0);
    AdvancePastDeviceDelay();

    // Cancelling the secondary instance's callbacks must not disturb another
    // PostOffice using the same callback thunks with a different argument.
    PacketHeader survivorPacket{};
    survivorPacket.to = 0;
    MailHeader survivorMail{};
    survivorMail.to = 9;
    survivorMail.from = 8;
    const char survivorMessage[] = "surviving post office";
    survivorMail.length = sizeof(survivorMessage);
    postOffice->Send(survivorPacket, survivorMail, survivorMessage);
    char survivorResult[MaxMailSize] = {};
    postOffice->Receive(9, &survivorPacket, &survivorMail, survivorResult);
    ASSERT(memcmp(survivorMessage, survivorResult,
                  sizeof(survivorMessage)) == 0);
#endif

    printf("Device lifetime tests PASSED\n");
#ifdef NETWORK
    // The global PostOffice intentionally keeps a receive poll pending. Halt
    // exercises its live-worker shutdown instead of leaving main to finish
    // while the postal worker continues polling forever.
    interrupt->Halt();
#endif
}

#ifdef NETWORK
void PostOfficeShutdownEntryRegressionTest()
{
    static Semaphore deletionStarted("post office deletion started", 0);
    PostOffice* retiring = new PostOffice(31417, 1.0, 2);
    Thread* client = new Thread("entry during shutdown");
    client->Fork([](intptr_t arg) {
        deletionStarted.P();
        PacketHeader packet{};
        packet.to = 31417;
        MailHeader mail{};
        mail.length = 1;
        reinterpret_cast<PostOffice*>(arg)->Send(packet, mail, "x");
    }, reinterpret_cast<intptr_t>(retiring));
    Thread* deleter = new Thread("shutdown with gated client");
    deleter->Fork([](intptr_t arg) {
        // Without a timer, the client is queued before the postal worker and
        // reaches Send while the destructor is waiting for the worker to stop.
        (void) interrupt->SetLevel(IntOff);
        deletionStarted.V();
        delete reinterpret_cast<PostOffice*>(arg);
    }, reinterpret_cast<intptr_t>(retiring));
    currentThread->Yield();
}
#endif
