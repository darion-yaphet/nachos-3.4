// Synthetic NOFF images exercise the real loader without a cross compiler.
#include "system.h"
#include "addrspace.h"
#include "noff.h"
#include <climits>
#include <vector>

static unsigned SwapWord(unsigned value)
{
    return ((value & 0xffU) << 24) | ((value & 0xff00U) << 8) |
           ((value & 0xff0000U) >> 8) | ((value & 0xff000000U) >> 24);
}

static std::unique_ptr<OpenFile> ImageFile(NoffHeader header, int payloadBytes,
                                           bool swapped = false)
{
    constexpr const char* name = "loadtest";
    (void) fileSystem->Remove(name);
    const int bytes = sizeof(header) + payloadBytes;
    ASSERT(fileSystem->Create(name, bytes));
    std::unique_ptr<OpenFile> file(fileSystem->Open(name));
    ASSERT(file != nullptr);
    std::vector<char> data(bytes, 'X');
    if (swapped) {
        unsigned words[sizeof(header) / sizeof(unsigned)];
        memcpy(words, &header, sizeof(header));
        for (unsigned& word : words)
            word = SwapWord(word);
        memcpy(data.data(), words, sizeof(header));
    } else {
        memcpy(data.data(), &header, sizeof(header));
    }
    ASSERT(file->WriteAt(data.data(), bytes, 0) == bytes);
    return file;
}

void LoaderRegressionTest()
{
    NoffHeader good{};
    good.noffMagic = NOFFMAGIC;
    good.code = {0, sizeof(NoffHeader), 8};
    good.initData = {512, sizeof(NoffHeader) + 8, 4};
    good.uninitData = {768, -1, 4}; // BSS has no stored file bytes
    char before[MemorySize];
    memcpy(before, machine->mainMemory, sizeof(before));
    const auto reject = [&](NoffHeader invalid, int bytes) {
        auto file = ImageFile(invalid, bytes);
        AddrSpace space(file.get());
        ASSERT(!space.IsValid());
        ASSERT(space.GetLoadError() != nullptr);
        ASSERT(memcmp(before, machine->mainMemory, sizeof(before)) == 0);
    };
    NoffHeader bad = good;
    bad.noffMagic = 0;
    reject(bad, 12);
    bad = good;
    bad.code.size = -1;
    reject(bad, 12);
    bad = good;
    bad.code.virtualAddr = 4; // fixed entry point is virtual address zero
    reject(bad, 12);
    bad = good;
    bad.initData.virtualAddr = INT_MAX;
    reject(bad, 12);
    bad = good;
    bad.initData.inFileAddr = INT_MAX;
    reject(bad, 12);
    bad = good;
    bad.uninitData.size = INT_MAX;
    reject(bad, 12);
    bad = good;
    bad.initData.virtualAddr = 4; // overlaps executable code
    reject(bad, 12);
    bad = good;
    bad.initData.inFileAddr = sizeof(NoffHeader); // overlapping file payload
    reject(bad, 12);
    reject(good, 4); // truncated executable segment

    for (bool swapped : {false, true}) {
        auto file = ImageFile(good, 12, swapped);
        AddrSpace space(file.get());
        ASSERT(space.IsValid());
        ASSERT(machine->mainMemory[0] == 'X');
        ASSERT(machine->mainMemory[512] == 'X');
        ASSERT(machine->mainMemory[768] == 0);
        ASSERT(machine->mainMemory[256] == 0); // sparse segment hole
        space.InitRegisters();
        ASSERT(machine->ReadRegister(StackReg) >= 768 + 4 + UserStackSize - 16);
    }

    // Older converters leave unused segment metadata uninitialized.
    NoffHeader historical = good;
    historical.initData = {-1, -1, 0};
    historical.uninitData = {-1, -1, 0};
    auto file = ImageFile(historical, 8);
    AddrSpace space(file.get());
    ASSERT(space.IsValid());
    file.reset();
    ASSERT(fileSystem->Remove("loadtest"));
    printf("NOFF loader boundary tests PASSED\n");
}

void TlbRegressionTest()
{
    ASSERT(machine->tlb != nullptr);
    NoffHeader header{};
    header.noffMagic = NOFFMAGIC;
    header.code = {0, sizeof(header), 4};
    auto file = ImageFile(header, 4);
    auto space = std::make_shared<AddrSpace>(file.get());
    ASSERT(space->IsValid());
    currentThread->SetAddressSpace(space);
    space->RestoreState();
    ASSERT(machine->pageTable == nullptr);
    ASSERT(!space->ResolveTlbMiss(-1));
    ASSERT(!space->ResolveTlbMiss(MemorySize));
    ASSERT(space->ResolveTlbMiss(0));
    ASSERT(machine->WriteMem(0, 1, 0x5a));
    for (int page = 1; page <= TLBSize; ++page) {
        ASSERT(space->ResolveTlbMiss(page * PageSize));
        int value = 0;
        ASSERT(machine->ReadMem(page * PageSize, 1, &value));
    }
    ASSERT(space->GetPageEntry(0)->dirty && space->GetPageEntry(0)->use);
    space->SaveState();
    ASSERT(space->GetPageEntry(TLBSize)->use);
    space->RestoreState();
    for (int i = 0; i < TLBSize; ++i)
        ASSERT(!machine->tlb[i].valid);
    ASSERT(space->ResolveTlbMiss(0));
    int value = 0;
    ASSERT(machine->ReadMem(0, 1, &value) && value == 0x5a);
    currentThread->SetAddressSpace(nullptr);
    file.reset();
    ASSERT(fileSystem->Remove("loadtest"));
    printf("Resident TLB tests PASSED\n");
}

void ExitedAddressSpaceRegressionTest()
{
    NoffHeader header{};
    header.noffMagic = NOFFMAGIC;
    header.code = {0, sizeof(header), 4};
    auto file = ImageFile(header, 4);
    auto space = std::make_shared<AddrSpace>(file.get());
    ASSERT(space->IsValid());
    Thread* user = new Thread("last address-space owner", true);
    ThreadJoinHandle completion = user->GetJoinHandle();
    user->SetAddressSpace(std::move(space));
    user->Fork([](intptr_t) {
        currentThread->space->InitRegisters();
        currentThread->space->RestoreState();
        if (machine->tlb != nullptr)
            ASSERT(currentThread->space->ResolveTlbMiss(0));
        ASSERT(machine->WriteMem(0, 1, 0x5a));
    }, 0);
    ASSERT(completion.Join() == 0);
    ASSERT(machine->pageTable == nullptr);
    if (machine->tlb != nullptr)
        for (int i = 0; i < TLBSize; ++i)
            ASSERT(!machine->tlb[i].valid);
    file.reset();
    ASSERT(fileSystem->Remove("loadtest"));
    printf("Exited address-space lifetime tests PASSED\n");
}
