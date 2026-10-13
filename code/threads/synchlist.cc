// synchlist.cc
//	Routines for synchronized access to a list.
//
//	Implemented by surrounding the List abstraction
//	with synchronization routines.
//
// 	Implemented in "monitor"-style -- surround each procedure with a
// 	lock acquire and release pair, using condition signal and wait for
// 	synchronization.
//
// Copyright (c) 1992-1993 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation 
// of liability and disclaimer of warranty provisions.

#include "copyright.h"
#include "synchlist.h"

//----------------------------------------------------------------------
// SynchList::SynchList
//	Allocate and initialize the data structures needed for a 
//	synchronized list, empty to start with.
//	Elements can now be added to the list.
//----------------------------------------------------------------------

SynchList::SynchList()
{
    list = std::make_unique<List>();
    lock = std::make_unique<Lock>("list lock"); 
    listEmpty = std::make_unique<Condition>("list empty cond");
}

//----------------------------------------------------------------------
// SynchList::~SynchList
// 	De-allocate the data structures created for synchronizing a list. 
//----------------------------------------------------------------------

SynchList::~SynchList()
{
    // Destroying a monitor cannot safely wake callers whose operation still
    // refers to it. Owners must stop and join such callers before teardown.
    ASSERT(activeOperations == 0);
    ASSERT(waitingRemovers == 0);
}

//----------------------------------------------------------------------
// SynchList::Append
//      Append an "item" to the end of the list.  Wake up anyone
//	waiting for an element to be appended.
//
//	"item" is the thing to put on the list, it can be a pointer to 
//		anything.
//----------------------------------------------------------------------

void
SynchList::Append(void *item)
{
    ++activeOperations;
    lock->Acquire();		// enforce mutual exclusive access to the list 
    list->Append(item);
    listEmpty->Signal(lock.get());	// wake up a waiter, if any
    lock->Release();
    --activeOperations;
}

//----------------------------------------------------------------------
// SynchList::Remove
//      Remove an "item" from the beginning of the list.  Wait if
//	the list is empty.
// Returns:
//	The removed item. 
//----------------------------------------------------------------------

void *
SynchList::Remove()
{
    void *item;

    ++activeOperations;
    lock->Acquire();			// enforce mutual exclusion
    while (list->IsEmpty()) {
	++waitingRemovers;
	listEmpty->Wait(lock.get());		// wait until list isn't empty
	--waitingRemovers;
    }
    item = list->Remove();
    ASSERT(item != nullptr);
    lock->Release();
    --activeOperations;
    return item;
}

//----------------------------------------------------------------------
// SynchList::TryRemove
//      Remove an item without waiting.  This is suitable for draining an
//      owner-managed queue during shutdown after all producers/consumers
//      have stopped.
//----------------------------------------------------------------------

void *
SynchList::TryRemove()
{
    ++activeOperations;
    lock->Acquire();
    void *item = list->Remove();
    lock->Release();
    --activeOperations;
    return item;
}

//----------------------------------------------------------------------
// SynchList::Mapcar
//      Apply function to every item on the list.  Obey mutual exclusion
//	constraints.
//
//	"func" is the procedure to be applied.
//----------------------------------------------------------------------

void
SynchList::Mapcar(VoidFunctionPtr func)
{ 
    ++activeOperations;
    lock->Acquire(); 
    list->Mapcar(func);
    lock->Release(); 
    --activeOperations;
}
