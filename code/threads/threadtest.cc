// threadtest.cc 
//	Simple test case for the threads assignment.
//
//	Create two threads, and have them context switch
//	back and forth between themselves by calling Thread::Yield, 
//	to illustrate the inner workings of the thread system.
//	Also tests Lock, LockGuard, and Mesa Condition Variables.
//
// Copyright (c) 1992-1993 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation 
// of liability and disclaimer of warranty provisions.

#include "copyright.h"
#include "system.h"
#include "synch.h"

//----------------------------------------------------------------------
// SimpleThread
// 	Loop 5 times, yielding the CPU to another ready thread 
//	each iteration.
//
//	"which" is simply a number identifying the thread, for debugging
//	purposes.
//----------------------------------------------------------------------

void
SimpleThread(intptr_t which)
{
    int num;
    
    for (num = 0; num < 5; num++) {
	printf("*** thread %ld looped %d times\n", static_cast<long>(which), num);
        currentThread->Yield();
    }
}

// Concurrency test shared state
static Lock testLock("TestLock");
static int sharedCounter = 0;
static constexpr int INCREMENTS_PER_THREAD = 10;
static Semaphore synchDone("SynchDone", 0);

static void MutexWorker(intptr_t id) {
    for (int i = 0; i < INCREMENTS_PER_THREAD; i++) {
        LockGuard guard(testLock);
        int current = sharedCounter;
        currentThread->Yield(); // Intentionally provoke context switches
        sharedCounter = current + 1;
    }
    LOG_INFO('t', "MutexWorker %ld finished\n", static_cast<long>(id));
    synchDone.V();
}

// Mesa Condition Variable Producer-Consumer test
static Lock bufferLock("BufferLock");
static Condition bufferNotFull("NotFull");
static Condition bufferNotEmpty("NotEmpty");
static int bufferCount = 0;
static constexpr int BUFFER_CAPACITY = 3;
static constexpr int TOTAL_ITEMS = 6;

static void Consumer(intptr_t arg) {
    (void)arg;
    for (int i = 0; i < TOTAL_ITEMS; i++) {
        LockGuard guard(bufferLock);
        while (bufferCount == 0) {
            bufferNotEmpty.Wait(&bufferLock);
        }
        bufferCount--;
        LOG_DEBUG('s', "Consumer retrieved item (buffer count: %d)\n", bufferCount);
        bufferNotFull.Signal(&bufferLock);
    }
    synchDone.V();
}

static void Producer(intptr_t arg) {
    (void)arg;
    for (int i = 0; i < TOTAL_ITEMS; i++) {
        LockGuard guard(bufferLock);
        while (bufferCount == BUFFER_CAPACITY) {
            bufferNotFull.Wait(&bufferLock);
        }
        bufferCount++;
        LOG_DEBUG('s', "Producer inserted item (buffer count: %d)\n", bufferCount);
        bufferNotEmpty.Signal(&bufferLock);
        currentThread->Yield();
    }
    synchDone.V();
}

//----------------------------------------------------------------------
// ThreadTest
// 	Runs the complete concurrency test suite:
//      1. Basic context switch ping-pong
//      2. Mutual exclusion with Lock and LockGuard
//      3. Mesa condition variable synchronization (Producer-Consumer)
//----------------------------------------------------------------------

void
ThreadTest()
{
    LOG_INFO('t', "=== Starting Nachos Concurrency Test Suite ===\n");

    // Test 1: Context switch Ping-Pong
    Thread *t1 = new Thread("forked thread");
    t1->Fork(SimpleThread, 1);
    SimpleThread(0);

    // Test 2: Mutex & LockGuard test
    sharedCounter = 0;
    Thread *t2 = new Thread("mutex worker 1");
    Thread *t3 = new Thread("mutex worker 2");
    t2->Fork(MutexWorker, 1);
    t3->Fork(MutexWorker, 2);
    synchDone.P();
    synchDone.P();
    ASSERT(sharedCounter == 2 * INCREMENTS_PER_THREAD);
    printf("--> Mutex & LockGuard test PASSED (counter = %d)\n", sharedCounter);

    // Test 3: Condition Variable test (Producer-Consumer)
    bufferCount = 0;
    Thread *cons = new Thread("consumer");
    Thread *prod = new Thread("producer");
    cons->Fork(Consumer, 0);
    prod->Fork(Producer, 0);
    synchDone.P();
    synchDone.P();
    ASSERT(bufferCount == 0);
    printf("--> Condition Variable (Mesa) test PASSED\n");

    // Test 4: Thread::Join and Exit status test
    Thread *joinChild = new Thread("joinable worker", true);
    joinChild->Fork([](intptr_t arg) {
        LOG_INFO('t', "JoinWorker %ld running and yielding\n", static_cast<long>(arg));
        for (int i = 0; i < 3; i++) {
            currentThread->Yield();
        }
        currentThread->SetExitStatus(static_cast<int>(arg * 10));
        LOG_INFO('t', "JoinWorker %ld finishing with status %d\n",
                 static_cast<long>(arg), currentThread->GetExitStatus());
    }, 7);
    int status = joinChild->Join();
    ASSERT(status == 70);
    printf("--> Thread::Join test PASSED (status = %d)\n", status);

    LOG_INFO('t', "=== All Nachos Concurrency Tests PASSED ===\n");
}
