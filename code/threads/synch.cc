// synch.cc 
//	Routines for synchronizing threads.  Three kinds of
//	synchronization routines are defined here: semaphores, locks 
//   	and condition variables (the implementation of the last two
//	are left to the reader).
//
// Any implementation of a synchronization routine needs some
// primitive atomic operation.  We assume Nachos is running on
// a uniprocessor, and thus atomicity can be provided by
// turning off interrupts.  While interrupts are disabled, no
// context switch can occur, and thus the current thread is guaranteed
// to hold the CPU throughout, until interrupts are reenabled.
//
// Because some of these routines might be called with interrupts
// already disabled (Semaphore::V for one), instead of turning
// on interrupts at the end of the atomic operation, we always simply
// re-set the interrupt state back to its original value (whether
// that be disabled or enabled).
//
// Copyright (c) 1992-1993 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation 
// of liability and disclaimer of warranty provisions.

#include "copyright.h"
#include "synch.h"
#include "system.h"

//----------------------------------------------------------------------
// Semaphore::Semaphore
// 	Initialize a semaphore, so that it can be used for synchronization.
//
//	"debugName" is an arbitrary name, useful for debugging.
//	"initialValue" is the initial value of the semaphore.
//----------------------------------------------------------------------

Semaphore::Semaphore(const char* debugName, int initialValue)
    : name(debugName), value(initialValue), queue(std::make_unique<List>())
{
}

//----------------------------------------------------------------------
// Semaphore::~Semaphore
// 	De-allocate semaphore, when no longer needed.  Assume no one
//	is still waiting on the semaphore!
//----------------------------------------------------------------------

Semaphore::~Semaphore() = default;

//----------------------------------------------------------------------
// Semaphore::P
// 	Wait until semaphore value > 0, then decrement.  Checking the
//	value and decrementing must be done atomically, so we
//	need to disable interrupts before checking the value.
//
//	Note that Thread::Sleep assumes that interrupts are disabled
//	when it is called.
//----------------------------------------------------------------------

void
Semaphore::P()
{
    IntStatus oldLevel = interrupt->SetLevel(IntOff);	// disable interrupts
    
    while (value == 0) { 			// semaphore not available
	queue->Append(static_cast<void *>(currentThread));	// so go to sleep
	currentThread->Sleep();
    } 
    value--; 					// semaphore available, 
						// consume its value
    
    (void) interrupt->SetLevel(oldLevel);	// re-enable interrupts
}

//----------------------------------------------------------------------
// Semaphore::V
// 	Increment semaphore value, waking up a waiter if necessary.
//	As with P(), this operation must be atomic, so we need to disable
//	interrupts.  Scheduler::ReadyToRun() assumes that threads
//	are disabled when it is called.
//----------------------------------------------------------------------

void
Semaphore::V()
{
    Thread *thread;
    IntStatus oldLevel = interrupt->SetLevel(IntOff);

    thread = static_cast<Thread *>(queue->Remove());
    if (thread != nullptr)	   // make thread ready, consuming the V immediately
	scheduler->ReadyToRun(thread);
    value++;
    (void) interrupt->SetLevel(oldLevel);
}

//----------------------------------------------------------------------
// Lock::Lock
// 	Initialize a lock to be FREE.
//----------------------------------------------------------------------

Lock::Lock(const char* debugName) 
    : name(debugName), holder(nullptr), waitQueue(std::make_unique<List>()) 
{
}

//----------------------------------------------------------------------
// Lock::~Lock
// 	Deallocate a lock. Assert that no thread is holding it.
//----------------------------------------------------------------------

Lock::~Lock()
{
    if (holder != nullptr) {
        LOG_ERROR('s', "Lock destruction error: Lock \"%s\" destroyed while held by thread \"%s\"!\n",
                  name ? name : "unnamed", holder->getName() ? holder->getName() : "unnamed");
        ASSERT(false);
    }
}

//----------------------------------------------------------------------
// Lock::Acquire
// 	Wait until the lock is FREE, then set it to BUSY and set holder.
// 	Detects self-deadlock immediately.
//----------------------------------------------------------------------

void Lock::Acquire()
{
    IntStatus oldLevel = interrupt->SetLevel(IntOff);	// disable interrupts

    // Self-deadlock detection
    if (isHeldByCurrentThread()) {
        LOG_ERROR('s', "Self-deadlock detected! Thread \"%s\" is re-acquiring lock \"%s\"!\n",
                  currentThread->getName() ? currentThread->getName() : "unnamed",
                  name ? name : "unnamed");
        ASSERT(false);
    }

    while (holder != nullptr) {
        LOG_DEBUG('s', "Thread \"%s\" waiting on busy lock \"%s\"\n",
                  currentThread->getName() ? currentThread->getName() : "unnamed",
                  name ? name : "unnamed");
        waitQueue->Append(currentThread);
        currentThread->Sleep();
    }

    holder = currentThread;
    LOG_DEBUG('s', "Thread \"%s\" acquired lock \"%s\"\n",
              currentThread->getName() ? currentThread->getName() : "unnamed",
              name ? name : "unnamed");

    (void) interrupt->SetLevel(oldLevel);		// re-enable interrupts
}

//----------------------------------------------------------------------
// Lock::Release
// 	Release lock, waking up a waiting thread if any.
// 	Enforces that only the lock holder can release the lock.
//----------------------------------------------------------------------

void Lock::Release()
{
    IntStatus oldLevel = interrupt->SetLevel(IntOff);	// disable interrupts

    // Lock misuse detection
    if (!isHeldByCurrentThread()) {
        LOG_ERROR('s', "Lock misuse detected! Thread \"%s\" tried to release lock \"%s\" held by \"%s\"!\n",
                  currentThread->getName() ? currentThread->getName() : "unnamed",
                  name ? name : "unnamed",
                  holder && holder->getName() ? holder->getName() : "<none>");
        ASSERT(false);
    }

    LOG_DEBUG('s', "Thread \"%s\" released lock \"%s\"\n",
              currentThread->getName() ? currentThread->getName() : "unnamed",
              name ? name : "unnamed");
    holder = nullptr;

    Thread *nextThread = waitQueue->RemoveAs<Thread>();
    if (nextThread != nullptr) {
        scheduler->ReadyToRun(nextThread);
    }

    (void) interrupt->SetLevel(oldLevel);		// re-enable interrupts
}

//----------------------------------------------------------------------
// Lock::isHeldByCurrentThread
// 	Return true if currentThread holds the lock.
//----------------------------------------------------------------------

bool Lock::isHeldByCurrentThread() const
{
    return (holder != nullptr && holder == currentThread);
}

//----------------------------------------------------------------------
// Condition::Condition
// 	Initialize condition variable.
//----------------------------------------------------------------------

Condition::Condition(const char* debugName) 
    : name(debugName), waitQueue(std::make_unique<List>()) 
{
}

Condition::~Condition() = default;

//----------------------------------------------------------------------
// Condition::Wait
// 	Release lock atomically and sleep until signaled, then re-acquire.
//----------------------------------------------------------------------

void Condition::Wait(Lock* conditionLock)
{
    ASSERT(conditionLock != nullptr);
    if (!conditionLock->isHeldByCurrentThread()) {
        LOG_ERROR('s', "Condition::Wait misuse! Thread \"%s\" does not hold lock \"%s\"!\n",
                  currentThread->getName() ? currentThread->getName() : "unnamed",
                  conditionLock->getName() ? conditionLock->getName() : "unnamed");
        ASSERT(false);
    }

    IntStatus oldLevel = interrupt->SetLevel(IntOff);

    conditionLock->Release();
    waitQueue->Append(currentThread);
    currentThread->Sleep();
    conditionLock->Acquire();

    (void) interrupt->SetLevel(oldLevel);
}

//----------------------------------------------------------------------
// Condition::Signal
// 	Wake up one waiting thread if any.
//----------------------------------------------------------------------

void Condition::Signal(Lock* conditionLock)
{
    ASSERT(conditionLock != nullptr);
    if (!conditionLock->isHeldByCurrentThread()) {
        LOG_ERROR('s', "Condition::Signal misuse! Thread \"%s\" does not hold lock \"%s\"!\n",
                  currentThread->getName() ? currentThread->getName() : "unnamed",
                  conditionLock->getName() ? conditionLock->getName() : "unnamed");
        ASSERT(false);
    }

    IntStatus oldLevel = interrupt->SetLevel(IntOff);

    Thread *nextThread = waitQueue->RemoveAs<Thread>();
    if (nextThread != nullptr) {
        scheduler->ReadyToRun(nextThread);
    }

    (void) interrupt->SetLevel(oldLevel);
}

//----------------------------------------------------------------------
// Condition::Broadcast
// 	Wake up all waiting threads.
//----------------------------------------------------------------------

void Condition::Broadcast(Lock* conditionLock)
{
    ASSERT(conditionLock != nullptr);
    if (!conditionLock->isHeldByCurrentThread()) {
        LOG_ERROR('s', "Condition::Broadcast misuse! Thread \"%s\" does not hold lock \"%s\"!\n",
                  currentThread->getName() ? currentThread->getName() : "unnamed",
                  conditionLock->getName() ? conditionLock->getName() : "unnamed");
        ASSERT(false);
    }

    IntStatus oldLevel = interrupt->SetLevel(IntOff);

    while (!waitQueue->IsEmpty()) {
        Thread *nextThread = waitQueue->RemoveAs<Thread>();
        if (nextThread != nullptr) {
            scheduler->ReadyToRun(nextThread);
        }
    }

    (void) interrupt->SetLevel(oldLevel);
}
