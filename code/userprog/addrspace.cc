// addrspace.cc 
//	Routines to manage address spaces (executing user programs).
//
//	In order to run a user program, you must:
//
//	1. link with the -N -T 0 option 
//	2. run coff2noff to convert the object file to Nachos format
//		(Nachos object code format is essentially just a simpler
//		version of the UNIX executable object code format)
//	3. load the NOFF file into the Nachos file system
//		(if you haven't implemented the file system yet, you
//		don't need to do this last step)
//
// Copyright (c) 1992-1993 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation 
// of liability and disclaimer of warranty provisions.

#include "copyright.h"
#include "system.h"
#include "addrspace.h"
#include "noff.h"
#include <algorithm>
#include <cstring>

//----------------------------------------------------------------------
// SwapHeader
// 	Do little endian to big endian conversion on the bytes in the 
//	object file header, in case the file was generated on a little
//	endian machine, and we're now running on a big endian machine.
//----------------------------------------------------------------------

static unsigned int SwapWord(unsigned int value)
{
    return ((value & 0xffU) << 24) | ((value & 0xff00U) << 8) |
           ((value & 0xff0000U) >> 8) | ((value & 0xff000000U) >> 24);
}

static void
SwapHeader (NoffHeader *noffH)
{
	noffH->noffMagic = SwapWord(noffH->noffMagic);
	noffH->code.size = SwapWord(noffH->code.size);
	noffH->code.virtualAddr = SwapWord(noffH->code.virtualAddr);
	noffH->code.inFileAddr = SwapWord(noffH->code.inFileAddr);
	noffH->initData.size = SwapWord(noffH->initData.size);
	noffH->initData.virtualAddr = SwapWord(noffH->initData.virtualAddr);
	noffH->initData.inFileAddr = SwapWord(noffH->initData.inFileAddr);
	noffH->uninitData.size = SwapWord(noffH->uninitData.size);
	noffH->uninitData.virtualAddr = SwapWord(noffH->uninitData.virtualAddr);
	noffH->uninitData.inFileAddr = SwapWord(noffH->uninitData.inFileAddr);
}

//----------------------------------------------------------------------
// AddrSpace::AddrSpace
// 	Create an address space to run a user program.
//	Load the program from a file "executable", and set everything
//	up so that we can start executing user instructions.
//
//	Assumes that the object code file is in NOFF format.
//
//	First, set up the translation from program memory to physical 
//	memory.  For now, this is really simple (1:1), since we are
//	only uniprogramming, and we have a single unsegmented page table
//
//	"executable" is the file containing the object code to load into memory
//----------------------------------------------------------------------

AddrSpace::AddrSpace(OpenFile *executable)
{
    if (executable == nullptr) {
        loadError = "missing executable";
        return;
    }
    NoffHeader header{};
    const int fileLength = executable->Length();
    if (fileLength < static_cast<int>(sizeof(header)) ||
        executable->ReadAt(reinterpret_cast<char*>(&header), sizeof(header), 0) != sizeof(header)) {
        loadError = "truncated NOFF header";
        return;
    }
    if (header.noffMagic != NOFFMAGIC && SwapWord(header.noffMagic) == NOFFMAGIC)
        SwapHeader(&header);
    if (header.noffMagic != NOFFMAGIC) {
        loadError = "invalid NOFF magic";
        return;
    }
    if (header.code.virtualAddr != 0 || header.code.size < 4 || header.code.size % 4 != 0) {
        loadError = "code must contain aligned instructions at entry point zero";
        return;
    }

    const Segment segments[] = {header.code, header.initData, header.uninitData};
    unsigned int imageEnd = 0;
    for (int i = 0; i < 3; ++i) {
        const Segment& segment = segments[i];
        if (segment.size < 0) {
            loadError = "negative segment size";
            return;
        }
        // Historical converters leave unused metadata of empty segments unset.
        if (segment.size == 0)
            continue;
        if (segment.virtualAddr < 0 || segment.virtualAddr > MemorySize - UserStackSize ||
            segment.size > MemorySize - UserStackSize - segment.virtualAddr) {
            loadError = "segment exceeds resident address space";
            return;
        }
        const unsigned int end = segment.virtualAddr + segment.size;
        imageEnd = std::max(imageEnd, end);
        if (i < 2 && (segment.inFileAddr < static_cast<int>(sizeof(header)) ||
                      segment.inFileAddr > fileLength ||
                      segment.size > fileLength - segment.inFileAddr)) {
            loadError = "truncated or invalid stored segment";
            return;
        }
        for (int j = 0; j < i; ++j) {
            const Segment& earlier = segments[j];
            if (earlier.size != 0 && segment.virtualAddr < earlier.virtualAddr + earlier.size &&
                earlier.virtualAddr < segment.virtualAddr + segment.size) {
                loadError = "overlapping virtual segments";
                return;
            }
            if (i < 2 && earlier.size != 0 &&
                segment.inFileAddr < earlier.inFileAddr + earlier.size &&
                earlier.inFileAddr < segment.inFileAddr + segment.size) {
                loadError = "overlapping stored segments";
                return;
            }
        }
    }
    const unsigned int pages = divRoundUp(imageEnd + UserStackSize, PageSize);
    const unsigned int bytes = pages * PageSize;
    auto image = std::make_unique<char[]>(bytes);
    for (int i = 0; i < 2; ++i) {
        const Segment& segment = segments[i];
        if (segment.size != 0 && executable->ReadAt(image.get() + segment.virtualAddr,
                segment.size, segment.inFileAddr) != segment.size) {
            loadError = "short segment read";
            return;
        }
    }
    auto table = std::make_unique<TranslationEntry[]>(pages);
    for (unsigned int i = 0; i < pages; ++i) {
        table[i].virtualPage = i;
        table[i].physicalPage = i; // one resident image, as in the original lab
        table[i].valid = true;
        table[i].readOnly = false;
    }
    // Commit only after validating and reading the complete image.
    memcpy(machine->mainMemory, image.get(), bytes);
    pageTable = std::move(table);
    numPages = pages;
    loadError = nullptr;
}

//----------------------------------------------------------------------
// AddrSpace::~AddrSpace
// 	Deallocate an address space.
//----------------------------------------------------------------------

AddrSpace::~AddrSpace()
{
    if (machine != nullptr && machine->tlb != nullptr && currentThread != nullptr &&
        currentThread->space == this) {
        for (int i = 0; i < TLBSize; ++i)
            machine->tlb[i].valid = false;
    }
    if (machine != nullptr && machine->pageTable == pageTable.get() && pageTable != nullptr) {
        machine->pageTable = nullptr;
        machine->pageTableSize = 0;
    }
}

//----------------------------------------------------------------------
// AddrSpace::InitRegisters
// 	Set the initial values for the user-level register set.
//
// 	We write these directly into the "machine" registers, so
//	that we can immediately jump to user code.  Note that these
//	will be saved/restored into the currentThread->userRegisters
//	when this thread is context switched out.
//----------------------------------------------------------------------

void
AddrSpace::InitRegisters()
{
    ASSERT(IsValid());
    int i;

    for (i = 0; i < NumTotalRegs; i++)
	machine->WriteRegister(i, 0);

    // Initial program counter -- must be location of "Start"
    machine->WriteRegister(PCReg, 0);	

    // Need to also tell MIPS where next instruction is, because
    // of branch delay possibility
    machine->WriteRegister(NextPCReg, 4);

   // Set the stack register to the end of the address space, where we
   // allocated the stack; but subtract off a bit, to make sure we don't
   // accidentally reference off the end!
    machine->WriteRegister(StackReg, numPages * PageSize - 16);
    DEBUG('a', "Initializing stack register to %d\n", numPages * PageSize - 16);
}

//----------------------------------------------------------------------
// AddrSpace::SaveState
// 	On a context switch, save any machine state, specific
//	to this address space, that needs saving.
//
//	For now, nothing!
//----------------------------------------------------------------------

void AddrSpace::MergeTlbEntry(const TranslationEntry& entry)
{
    if (entry.valid && entry.virtualPage >= 0 &&
        static_cast<unsigned int>(entry.virtualPage) < numPages &&
        pageTable[entry.virtualPage].physicalPage == entry.physicalPage) {
        pageTable[entry.virtualPage].use |= entry.use;
        pageTable[entry.virtualPage].dirty |= entry.dirty;
    }
}

void AddrSpace::SaveState()
{
    if (machine->tlb != nullptr)
        for (int i = 0; i < TLBSize; ++i) {
            MergeTlbEntry(machine->tlb[i]);
            machine->tlb[i].valid = false;
        }
}

bool AddrSpace::ResolveTlbMiss(int virtualAddr)
{
    if (!IsValid() || machine->tlb == nullptr || virtualAddr < 0)
        return false;
    unsigned int vpn = static_cast<unsigned int>(virtualAddr) / PageSize;
    if (vpn >= numPages || !pageTable[vpn].valid)
        return false;
    for (int i = 0; i < TLBSize; ++i)
        if (machine->tlb[i].valid && machine->tlb[i].virtualPage == static_cast<int>(vpn))
            return true;
    const unsigned int slot = nextTlbSlot++ % TLBSize;
    MergeTlbEntry(machine->tlb[slot]);
    machine->tlb[slot] = pageTable[vpn];
    DEBUG('a', "Resident TLB mapping for page %u\n", vpn);
    return true;
}

//----------------------------------------------------------------------
// AddrSpace::RestoreState
// 	On a context switch, restore the machine state so that
//	this address space can run.
//
//      For now, tell the machine where to find the page table.
//----------------------------------------------------------------------

void AddrSpace::RestoreState() 
{
    ASSERT(IsValid());
    if (machine->tlb != nullptr) {
        machine->pageTable = nullptr;
        machine->pageTableSize = 0;
        for (int i = 0; i < TLBSize; ++i)
            machine->tlb[i].valid = false;
    } else {
        machine->pageTable = pageTable.get();
        machine->pageTableSize = numPages;
    }
}
