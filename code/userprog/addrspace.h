// addrspace.h 
//	Data structures to keep track of executing user programs 
//	(address spaces).
//
//	For now, we don't keep any information about address spaces.
//	The user level CPU state is saved and restored in the thread
//	executing the user program (see thread.h).
//
// Copyright (c) 1992-1993 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation 
// of liability and disclaimer of warranty provisions.

#ifndef ADDRSPACE_H
#define ADDRSPACE_H

#include "copyright.h"
#include "filesys.h"
#include "translate.h"

constexpr int UserStackSize = 1024; 	// increase this as necessary!

#include <memory>

class AddrSpace {
  public:
    explicit AddrSpace(OpenFile *executable);	// Create an address space,
					// initializing it with the program
					// stored in the file "executable"
    ~AddrSpace();			// De-allocate an address space

    [[nodiscard]] bool IsValid() const noexcept { return loadError == nullptr; }
    [[nodiscard]] const char* GetLoadError() const noexcept { return loadError; }
    // Fill a resident mapping; this baseline does not page data in from swap.
    bool ResolveTlbMiss(int virtualAddr);
    [[nodiscard]] const TranslationEntry* GetPageEntry(unsigned int page) const noexcept {
        return page < numPages ? &pageTable[page] : nullptr;
    }

    AddrSpace(const AddrSpace&) = delete;
    AddrSpace& operator=(const AddrSpace&) = delete;

    void InitRegisters();		// Initialize user-level CPU registers,
					// before jumping to user code

    void SaveState();			// Save/restore address space-specific
    void RestoreState();		// info on a context switch 

  private:
    std::unique_ptr<TranslationEntry[]> pageTable; // Assume linear page table translation
					// for now!
    unsigned int numPages{0};		// Number of pages in the virtual
					// address space
    const char* loadError{"executable not loaded"};
    unsigned int nextTlbSlot{0};
    void MergeTlbEntry(const TranslationEntry& entry);
};

#endif // ADDRSPACE_H
