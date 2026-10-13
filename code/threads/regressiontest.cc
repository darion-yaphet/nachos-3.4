// Boundary regression tests, run explicitly with nachos -T <suite>.
#include "system.h"
#include "synch.h"
#include <climits>
#include <utility>

#ifdef USER_PROGRAM
#include "usermem.h"
#endif
#ifdef FILESYS
#include "filehdr.h"
#endif
#ifdef NETWORK
#include "post.h"
#endif

static void ListRegressionTest()
{
    int a = 1, b = 2, c = 3;
    List source;
    source.Append(&a);
    source.Append(&b);
    List moved(std::move(source));
    ASSERT(source.IsEmpty());
    source.Append(&c);
    ASSERT(source.RemoveAs<int>() == &c);
    List target;
    target.Append(nullptr); // null payloads must not stop node cleanup
    target.Append(&c);
    target = std::move(moved);
    ASSERT(moved.IsEmpty());
    List& alias = target;
    target = std::move(alias);
    ASSERT(target.RemoveAs<int>() == &a);
    ASSERT(target.RemoveAs<int>() == &b);
    ASSERT(target.IsEmpty());
    target.Append(nullptr);
    target.Append(&c);
    printf("List ownership tests PASSED\n");
}

static void ThreadLifecycleRegressionTest()
{
    for (int i = 0; i < 2; ++i) {
        Thread* child = new Thread("short detached child");
        child->Fork([](intptr_t) { ASSERT(threadToBeDestroyed == nullptr); }, 0);
    }
    currentThread->Yield();
    ASSERT(threadToBeDestroyed == nullptr);
    printf("Detached thread lifecycle tests PASSED\n");
}

static void MultipleJoinRegressionTest()
{
    static Semaphore gate("never finishes", 0);
    Thread* child = new Thread("multiple join target", true);
    child->Fork([](intptr_t) { gate.P(); }, 0);
    for (int i = 0; i < 2; ++i) {
        Thread* waiter = new Thread("join claimant");
        waiter->Fork([](intptr_t arg) {
            reinterpret_cast<Thread*>(arg)->Join();
        }, reinterpret_cast<intptr_t>(child));
    }
    currentThread->Yield();
}

static void JoinRegressionTest()
{
    Thread* child = new Thread("already finished child", true);
    child->Fork([](intptr_t) { currentThread->SetExitStatus(42); }, 0);
    currentThread->Yield();
    ASSERT(child->Join() == 42);
    ASSERT(interrupt->getLevel() == IntOn);
    printf("Join boundary tests PASSED\n");
}

#ifdef USER_PROGRAM
static void UserMemoryRegressionTest()
{
    // Exercise both linear-page-table and TLB builds with the same mapping.
    TranslationEntry mapping{};
    mapping.virtualPage = 0;
    mapping.physicalPage = 0;
    mapping.valid = true;
    TranslationEntry* savedTable = machine->pageTable;
    unsigned int savedSize = machine->pageTableSize;
    if (machine->tlb != nullptr) {
        machine->tlb[0] = mapping;
    } else {
        machine->pageTable = &mapping;
        machine->pageTableSize = 1;
    }

    char buf[4] = {};
    machine->mainMemory[0] = '\0';
    ASSERT(UserMem::ReadString(0, buf, 1));
    const char text[] = "abc";
    ASSERT(UserMem::CopyToUser(text, 0, sizeof(text)));
    ASSERT(UserMem::ReadString(0, buf, sizeof(buf)));
    ASSERT(strcmp(buf, text) == 0);
    ASSERT(!UserMem::ReadString(0, buf, 3));
    ASSERT(strcmp(buf, "ab") == 0);
    const unsigned char bytes[] = {0, 0x80, 0xff};
    unsigned char result[sizeof(bytes)] = {};
    ASSERT(UserMem::CopyToUser(bytes, PageSize - 3, sizeof(bytes)));
    ASSERT(UserMem::CopyFromUser(PageSize - 3, result, sizeof(result)));
    ASSERT(memcmp(bytes, result, sizeof(bytes)) == 0);
    ASSERT(!UserMem::CopyFromUser(-1, buf, 1));
    ASSERT(!UserMem::CopyToUser(buf, -1, 1));
    ASSERT(!UserMem::CopyFromUser(INT_MAX, buf, 2));
    ASSERT(!UserMem::CopyToUser(buf, INT_MAX, 2));
    ASSERT(!UserMem::CopyFromUser(0, buf, -1));
    ASSERT(!UserMem::CopyToUser(buf, 0, -1));
    ASSERT(!UserMem::CopyFromUser(0, nullptr, 1));
    ASSERT(!UserMem::CopyToUser(nullptr, 0, 1));
    ASSERT(UserMem::CopyFromUser(0, buf, 0));
    ASSERT(UserMem::CopyToUser(buf, 0, 0));
    ASSERT(!UserMem::CopyFromUser(PageSize - 1, buf, 2));
    ASSERT(!UserMem::CopyToUser(buf, PageSize - 1, 2));
    buf[0] = 'x';
    ASSERT(!UserMem::ReadString(PageSize, buf, sizeof(buf)));
    ASSERT(buf[0] == '\0');

    TranslationEntry& active = machine->tlb != nullptr ? machine->tlb[0] : mapping;
    ASSERT(active.use && active.dirty);
    active.readOnly = true;
    ASSERT(!UserMem::CopyToUser(buf, 0, 1));
    active.valid = false;
    ASSERT(!UserMem::CopyFromUser(0, buf, 1));
    active.valid = true;
    active.physicalPage = NumPhysPages;
    ASSERT(!UserMem::CopyFromUser(0, buf, 1));

    if (machine->tlb != nullptr) {
        machine->tlb[0].valid = false;
    }
    machine->pageTable = savedTable;
    machine->pageTableSize = savedSize;
    printf("User memory boundary tests PASSED\n");
}
#endif

#ifdef FILESYS
static void FileSystemRegressionTest()
{
    BitMap bits(33);
    bits.Mark(31);
    ASSERT(bits.Test(31) && !bits.Test(30) && !bits.Test(32));
    bits.Clear(31);
    ASSERT(!bits.Test(31) && bits.NumClear() == 33);
    BitMap freeMap(NumSectors);
    FileHeader header;
    ASSERT(!header.Allocate(&freeMap, -1));
    ASSERT(!header.Allocate(&freeMap, MaxFileSize + 1));
    ASSERT(!header.Allocate(&freeMap, INT_MAX));
    ASSERT(freeMap.NumClear() == NumSectors);
    ASSERT(header.FileLength() == 0);
    ASSERT(header.Allocate(&freeMap, MaxFileSize));
    ASSERT(freeMap.NumClear() == NumSectors - NumDirect);
    header.Deallocate(&freeMap);
    ASSERT(freeMap.NumClear() == NumSectors);
    BitMap fullMap(1);
    fullMap.Mark(0);
    FileHeader emptyHeader;
    ASSERT(!emptyHeader.Allocate(&fullMap, 1));
    ASSERT(emptyHeader.FileLength() == 0);
    ASSERT(emptyHeader.Allocate(&fullMap, 0));

    ASSERT(!fileSystem->Create("badsize", -1));
    ASSERT(!fileSystem->Create("too-big", MaxFileSize + 1));
    ASSERT(fileSystem->Open("too-big") == nullptr);
    ASSERT(fileSystem->Create("boundary", 2 * SectorSize + 7));
    {
        std::unique_ptr<OpenFile> file(fileSystem->Open("boundary"));
        ASSERT(file != nullptr);
        char data[2 * SectorSize + 7];
        memset(data, 'A', sizeof(data));
        ASSERT(file->WriteAt(data, sizeof(data), 0) == sizeof(data));
        ASSERT(file->WriteAt("xyz", 3, SectorSize - 1) == 3);
        char result[sizeof(data)] = {};
        ASSERT(file->ReadAt(result, sizeof(result), 0) == sizeof(result));
        memcpy(data + SectorSize - 1, "xyz", 3);
        ASSERT(memcmp(data, result, sizeof(data)) == 0);
        ASSERT(file->ReadAt(result, 1, -1) == 0);
        ASSERT(file->WriteAt(data, 1, -1) == 0);
        ASSERT(file->ReadAt(nullptr, 1, 0) == 0);
        ASSERT(file->WriteAt(nullptr, 1, 0) == 0);
        ASSERT(file->ReadAt(result, -1, 0) == 0);
        ASSERT(file->WriteAt(data, -1, 0) == 0);
        ASSERT(file->ReadAt(result, INT_MAX, 1) == sizeof(result) - 1);
        ASSERT(file->WriteAt(data, INT_MAX, 1) == sizeof(data) - 1);
        ASSERT(file->ReadAt(result, 1, file->Length()) == 0);
        ASSERT(file->ReadAt(result, 1, INT_MAX) == 0);
        ASSERT(file->WriteAt(data, 1, INT_MAX) == 0);
    }
    ASSERT(fileSystem->Remove("boundary"));
    printf("File system boundary tests PASSED\n");
}
#endif

#ifdef NETWORK
static void NetworkRegressionTest()
{
    PacketHeader packet{};
    packet.to = 0; // runner uses the default machine id and reliable delivery
    MailHeader mail{};
    mail.to = 0;
    mail.from = 1;
    const char message[] = "network boundary payload";
    mail.length = sizeof(message);
    postOffice->Send(packet, mail, message);
    char result[MaxMailSize] = {};
    postOffice->Receive(0, &packet, &mail, result);
    ASSERT(packet.to == 0 && packet.from == 0);
    ASSERT(mail.to == 0 && mail.from == 1 && mail.length == sizeof(message));
    ASSERT(memcmp(message, result, sizeof(message)) == 0);
    printf("Network self-delivery tests PASSED\n");
    // Network polling keeps scheduling interrupts even after all work finishes.
    interrupt->Halt();
}
#endif

extern void JoinHandleRegressionTest();
extern void NonParentJoinRegressionTest(bool completed);
extern void DeviceRegressionTest();
#ifdef NETWORK
extern void PostOfficeShutdownEntryRegressionTest();
#endif
#ifdef USER_PROGRAM
extern void ProcessRegressionTest();
extern void LoaderRegressionTest();
extern void TlbRegressionTest();
extern void ExitedAddressSpaceRegressionTest();
#endif

void RegressionTest(const char* suite)
{
    if (strcmp(suite, "list") == 0) {
        ListRegressionTest();
    } else if (strcmp(suite, "handles") == 0) {
        JoinHandleRegressionTest();
    } else if (strcmp(suite, "join-nonparent") == 0) {
        NonParentJoinRegressionTest(false);
    } else if (strcmp(suite, "join-cached-nonparent") == 0) {
        NonParentJoinRegressionTest(true);
    } else if (strcmp(suite, "device") == 0) {
        DeviceRegressionTest();
#ifdef NETWORK
    } else if (strcmp(suite, "post-shutdown-entry") == 0) {
        PostOfficeShutdownEntryRegressionTest();
#endif
#ifdef USER_PROGRAM
    } else if (strcmp(suite, "process") == 0) {
        ProcessRegressionTest();
    } else if (strcmp(suite, "loader") == 0) {
        LoaderRegressionTest();
    } else if (strcmp(suite, "tlb") == 0) {
        TlbRegressionTest();
    } else if (strcmp(suite, "exited-space") == 0) {
        ExitedAddressSpaceRegressionTest();
#endif
    } else if (strcmp(suite, "lifecycle") == 0) {
        ThreadLifecycleRegressionTest();
    } else if (strcmp(suite, "join-unstarted") == 0) {
        (new Thread("unstarted join target", true))->Join();
    } else if (strcmp(suite, "join-multiple") == 0) {
        MultipleJoinRegressionTest();
    } else if (strcmp(suite, "lock-misuse") == 0) {
        Lock lock("unowned lock");
        lock.Release();
    } else if (strcmp(suite, "guard-null") == 0) {
        LockGuard guard(static_cast<Lock*>(nullptr));
    } else if (strcmp(suite, "join") == 0) {
        JoinRegressionTest();
#ifdef USER_PROGRAM
    } else if (strcmp(suite, "usermem") == 0) {
        UserMemoryRegressionTest();
#endif
#ifdef FILESYS
    } else if (strcmp(suite, "filesys") == 0) {
        FileSystemRegressionTest();
#endif
#ifdef NETWORK
    } else if (strcmp(suite, "network") == 0) {
        NetworkRegressionTest();
#endif
    } else {
        printf("Unknown or unavailable regression suite: %s\n", suite);
        ASSERT(false);
    }
}
