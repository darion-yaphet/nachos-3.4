// process_regression.cc
//	Focused lifecycle and process-table regression coverage.

#include "copyright.h"

#ifdef USER_PROGRAM

#include "process.h"
#include "system.h"

#include <memory>

namespace {

constexpr int ConcurrentCreators = 8;
constexpr int ProcessesPerCreator = 8;

struct CreationBatch {
    std::shared_ptr<Process>* slots;
};

void CreateProcesses(intptr_t argument)
{
    auto* batch = reinterpret_cast<CreationBatch*>(argument);
    for (int i = 0; i < ProcessesPerCreator; ++i) {
        batch->slots[i] = ProcessManager::Instance().CreateProcess();
        ASSERT(batch->slots[i] != nullptr);
        currentThread->Yield();
    }
}

void ExitProcessAfterYield(intptr_t argument)
{
    auto* process = reinterpret_cast<Process*>(argument);
    currentThread->Yield();
    ASSERT(process->Exit(42));
}

void TestCapacityAndStableHandles()
{
    auto& manager = ProcessManager::Instance();
    std::shared_ptr<Process> processes[MaxProcesses - 1];

    for (auto& process : processes) {
        process = manager.CreateProcess();
        ASSERT(process != nullptr);
    }
    ASSERT(manager.CreateProcess() == nullptr);

    const int reusablePid = processes[10]->GetPid();
    std::shared_ptr<Process> stableHandle = processes[10];
    ASSERT(manager.RemoveProcess(stableHandle));
    ASSERT(manager.GetProcess(reusablePid) == nullptr);

    std::shared_ptr<Process> reused = manager.CreateProcess();
    ASSERT(reused != nullptr);
    ASSERT(reused->GetPid() == reusablePid);
    ASSERT(stableHandle->GetPid() == reusablePid);
    ASSERT(stableHandle != reused);
    ASSERT(!manager.RemoveProcess(stableHandle));
    ASSERT(manager.GetProcess(reusablePid) == reused);

    for (auto& process : processes) {
        if (process != stableHandle) {
            ASSERT(manager.RemoveProcess(process));
        }
        process.reset();
    }
    ASSERT(manager.RemoveProcess(reused));
}

void TestConcurrentCreation()
{
    auto& manager = ProcessManager::Instance();
    std::shared_ptr<Process> processes[ConcurrentCreators * ProcessesPerCreator];
    CreationBatch batches[ConcurrentCreators];
    ThreadJoinHandle creatorHandles[ConcurrentCreators];

    for (int i = 0; i < ConcurrentCreators; ++i) {
        batches[i].slots = &processes[i * ProcessesPerCreator];
        auto* creator = new Thread("process creator", true);
        creatorHandles[i] = creator->GetJoinHandle();
        creator->Fork(CreateProcesses,
                      reinterpret_cast<intptr_t>(&batches[i]));
    }
    for (const auto& handle : creatorHandles) {
        ASSERT(handle.Join() == 0);
    }

    for (int i = 0; i < ConcurrentCreators * ProcessesPerCreator; ++i) {
        ASSERT(processes[i] != nullptr);
        ASSERT(manager.GetProcess(processes[i]->GetPid()) == processes[i]);
        for (int j = i + 1; j < ConcurrentCreators * ProcessesPerCreator; ++j) {
            ASSERT(processes[i]->GetPid() != processes[j]->GetPid());
        }
    }
    for (auto& process : processes) {
        ASSERT(manager.RemoveProcess(process));
    }
}

void TestWaitAndExitStatus()
{
    auto& manager = ProcessManager::Instance();
    std::shared_ptr<Process> parent = manager.CreateProcess();
    ASSERT(parent != nullptr);
    std::shared_ptr<Process> process = manager.CreateProcess(parent);
    ASSERT(process != nullptr);

    int status = -1;
    ASSERT(process->TryWait(parent, &status) == ProcessWaitResult::Running);

    const int parentPid = parent->GetPid();
    ASSERT(manager.RemoveProcess(parent));
    std::shared_ptr<Process> allocated[MaxProcesses - 2];
    std::shared_ptr<Process> reusedParentPid;
    for (auto& candidate : allocated) {
        candidate = manager.CreateProcess();
        ASSERT(candidate != nullptr);
        if (candidate->GetPid() == parentPid) {
            reusedParentPid = candidate;
        }
    }
    ASSERT(reusedParentPid != nullptr);
    ASSERT(process->TryWait(reusedParentPid, &status) ==
           ProcessWaitResult::NotChild);
    ASSERT(process->Wait(reusedParentPid, &status) ==
           ProcessWaitResult::NotChild);
    ASSERT(process->TryWait(parent, nullptr) ==
           ProcessWaitResult::InvalidArgument);

    auto* exitingThread = new Thread("process exit", true);
    process->SetThreadHandle(exitingThread->GetJoinHandle());
    exitingThread->Fork(ExitProcessAfterYield,
                        reinterpret_cast<intptr_t>(process.get()));
    ASSERT(process->Wait(parent, &status) == ProcessWaitResult::Exited);
    ASSERT(status == 42);
    ThreadJoinHandle exitHandle = process->GetThreadHandle();
    ASSERT(exitHandle.IsValid());
    ASSERT(exitHandle.Join() == 0);
    ASSERT(exitHandle.Join() == 0);

    status = -1;
    ASSERT(process->Wait(parent, &status) == ProcessWaitResult::Exited);
    ASSERT(status == 42);
    status = -1;
    ASSERT(process->TryWait(parent, &status) == ProcessWaitResult::Exited);
    ASSERT(status == 42);
    ASSERT(!process->Exit(99));
    ASSERT(process->GetExitStatus() == 42);
    ASSERT(manager.RemoveProcess(process));
    for (auto& candidate : allocated) {
        ASSERT(manager.RemoveProcess(candidate));
    }
}

void TestMultipleWaiters()
{
    auto& manager = ProcessManager::Instance();
    auto parent = manager.CreateProcess();
    auto child = manager.CreateProcess(parent);
    ASSERT(parent != nullptr && child != nullptr);
    struct Waiter {
        std::shared_ptr<Process> child;
        std::shared_ptr<Process> parent;
        int status{-1};
    } waiters[3];
    ThreadJoinHandle handles[3];
    for (int i = 0; i < 3; ++i) {
        waiters[i].child = child;
        waiters[i].parent = parent;
        Thread* waiter = new Thread("process waiter", true);
        handles[i] = waiter->GetJoinHandle();
        waiter->Fork([](intptr_t arg) {
            auto* waiter = reinterpret_cast<Waiter*>(arg);
            ASSERT(waiter->child->Wait(waiter->parent, &waiter->status) ==
                   ProcessWaitResult::Exited);
        }, reinterpret_cast<intptr_t>(&waiters[i]));
    }
    currentThread->Yield();
    ASSERT(child->Exit(-7));
    for (int i = 0; i < 3; ++i) {
        ASSERT(handles[i].Join() == 0);
        ASSERT(waiters[i].status == -7);
    }
    ASSERT(manager.RemoveProcess(child));
    ASSERT(manager.RemoveProcess(parent));
}

} // namespace

void ProcessRegressionTest()
{
    TestCapacityAndStableHandles();
    TestConcurrentCreation();
    TestWaitAndExitStatus();
    TestMultipleWaiters();
    printf("Process lifecycle tests PASSED\n");
}

#endif // USER_PROGRAM
