// thread.h 
//	Data structures for managing threads.  A thread represents
//	sequential execution of code within a program.
//	So the state of a thread includes the program counter,
//	the processor registers, and the execution stack.
//	
// 	Note that because we allocate a fixed size stack for each
//	thread, it is possible to overflow the stack -- for instance,
//	by recursing to too deep a level.  The most common reason
//	for this occuring is allocating large data structures
//	on the stack.  For instance, this will cause problems:
//
//		void foo() { int buf[1000]; ...}
//
//	Instead, you should allocate all data structures dynamically:
//
//		void foo() { int *buf = new int[1000]; ...}
//
//
// 	Bad things happen if you overflow the stack, and in the worst 
//	case, the problem may not be caught explicitly.  Instead,
//	the only symptom may be bizarre segmentation faults.  (Of course,
//	other problems can cause seg faults, so that isn't a sure sign
//	that your thread stacks are too small.)
//	
//	One thing to try if you find yourself with seg faults is to
//	increase the size of thread stack -- ThreadStackSize.
//
//  	In this interface, forking a thread takes two steps.
//	We must first allocate a data structure for it: "t = new Thread".
//	Only then can we do the fork: "t->fork(f, arg)".
//
// Copyright (c) 1992-1993 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation 
// of liability and disclaimer of warranty provisions.

#ifndef THREAD_H
#define THREAD_H

#include "copyright.h"
#include "utility.h"
#include <memory>

#ifdef HOST_DARWIN_ARM64
#include <ucontext.h>
#endif

#ifdef USER_PROGRAM
#include "machine.h"
#include "addrspace.h"
#endif

// CPU register state to be saved on context switch.  
// The SPARC and MIPS only need 10 registers, but the Snake needs 18.
// For simplicity, this is just the max over all architectures.
constexpr int MachineStateSize = 18;


// Size of the thread's private execution stack.
// WATCH OUT IF THIS ISN'T BIG ENOUGH!!!!!
constexpr int StackSize = (4 * 1024);	// in words


// Thread state
enum ThreadStatus { JUST_CREATED, RUNNING, READY, BLOCKED };

// external function, dummy routine whose sole job is to call Thread::Print
extern void ThreadPrint(intptr_t arg);

// The following class defines a "thread control block" -- which
// represents a single thread of execution.
//
//  Every thread has:
//     an execution stack for activation records ("stackTop" and "stack")
//     space to save CPU registers while not running ("machineState")
//     a "status" (running/ready/blocked)
//    
//  Some threads also belong to a user address space; threads
//  that only run in the kernel have a NULL address space.

class Semaphore;

class Thread {
  private:
    // NOTE: DO NOT CHANGE the order of these first two members.
    int* stackTop = nullptr;			 // the current stack pointer
    __attribute__((unused)) int machineState[MachineStateSize] = {};  // all registers except for stackTop

#ifdef HOST_DARWIN_ARM64
    ucontext_t context = {};
    VoidFunctionPtr rootFunction = nullptr;
    intptr_t rootArgument = 0;
#endif

  public:
    explicit Thread(const char* debugName, bool joinable = false); // initialize a Thread 
    ~Thread(); 					// deallocate a Thread
						// NOTE -- thread being deleted
						// must not be running when delete 
						// is called

    // Non-copyable
    Thread(const Thread &) = delete;
    Thread &operator=(const Thread &) = delete;

    // basic thread operations

    void Fork(VoidFunctionPtr func, intptr_t arg); // Make thread run (*func)(arg)
    void Yield();  				// Relinquish the CPU if any 
						// other thread is runnable
    void Sleep();  				// Put the thread to sleep and 
						// relinquish the processor
    void Finish();  				// The thread is done executing
    
    // Thread synchronization & joining
    int Join();                                 // Wait for thread to finish and retrieve status
    void SetExitStatus(int st) noexcept { exitStatus = st; }
    [[nodiscard]] int GetExitStatus() const noexcept { return exitStatus; }
    [[nodiscard]] bool IsJoinable() const noexcept { return isJoinable; }

    void CheckOverflow() const;   		// Check if thread has 
						// overflowed its stack
    void setStatus(ThreadStatus st) noexcept { status = st; }
    [[nodiscard]] ThreadStatus getStatus() const noexcept { return status; }
    [[nodiscard]] const char* getName() const noexcept { return name; }
    void Print() const { printf("%s, ", name ? name : "unnamed"); }

#ifdef HOST_DARWIN_ARM64
    ucontext_t *GetContext() noexcept { return &context; }
    void RunThreadRoot();
#endif

  private:
    // some of the private data for this class is listed above
    
    int* stack = nullptr; 	 		// Bottom of the stack 
						// nullptr if this is the main thread
						// (If nullptr, don't deallocate stack)
    ThreadStatus status = JUST_CREATED;		// ready, running or blocked
    const char* name = nullptr;

    bool isJoinable{false};
    bool hasExited{false};
    int exitStatus{0};
    std::unique_ptr<Semaphore> joinSem;

    void StackAllocate(VoidFunctionPtr func, intptr_t arg);
    						// Allocate a stack for thread.
						// Used internally by Fork()

#ifdef USER_PROGRAM
// A thread running a user program actually has *two* sets of CPU registers -- 
// one for its state while executing user code, one for its state 
// while executing kernel code.

    int userRegisters[NumTotalRegs];	// user-level CPU register state

  public:
    void SaveUserState();		// save user-level register state
    void RestoreUserState();		// restore user-level register state

    AddrSpace *space;			// User code this thread is running.
#endif
};

// Magical machine-dependent routines, defined in switch.s

extern "C" {
// First frame on thread execution stack; 
//   	enable interrupts
//	call "func"
//	(when func returns, if ever) call ThreadFinish()
void ThreadRoot();

// Stop running oldThread and start running newThread
void SWITCH(Thread *oldThread, Thread *newThread);
}

#endif // THREAD_H
