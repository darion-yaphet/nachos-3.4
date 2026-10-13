// process.cc
//	Implementation of Process Control Block (PCB) and ProcessManager.

#include "copyright.h"
#include "process.h"
#include "synch.h"
#include "system.h"

#include <utility>

Process::Process(int processId,
                 const std::shared_ptr<Process>& parentProcess)
    : pid(processId),
      parentPid(parentProcess != nullptr ? parentProcess->GetPid() : InvalidPid),
      parent(parentProcess),
      exitSem(std::make_unique<Semaphore>("procExitSem", 0))
{
}

Process::~Process() = default;

int Process::GetExitStatus() const noexcept
{
    IntStatus oldLevel = interrupt->SetLevel(IntOff);
    const int status = exitStatus;
    (void) interrupt->SetLevel(oldLevel);
    return status;
}

bool Process::HasExited() const noexcept
{
    IntStatus oldLevel = interrupt->SetLevel(IntOff);
    const bool exited = hasExited;
    (void) interrupt->SetLevel(oldLevel);
    return exited;
}

void Process::SetThreadHandle(ThreadJoinHandle handle) noexcept
{
    IntStatus oldLevel = interrupt->SetLevel(IntOff);
    threadHandle = std::move(handle);
    (void) interrupt->SetLevel(oldLevel);
}

ThreadJoinHandle Process::GetThreadHandle() const noexcept
{
    IntStatus oldLevel = interrupt->SetLevel(IntOff);
    ThreadJoinHandle handle = threadHandle;
    (void) interrupt->SetLevel(oldLevel);
    return handle;
}

void Process::SetSpace(std::shared_ptr<AddrSpace> ownedSpace) noexcept
{
    IntStatus oldLevel = interrupt->SetLevel(IntOff);
    space.swap(ownedSpace);
    (void) interrupt->SetLevel(oldLevel);
}

std::shared_ptr<AddrSpace> Process::GetSpace() const noexcept
{
    IntStatus oldLevel = interrupt->SetLevel(IntOff);
    std::shared_ptr<AddrSpace> ownedSpace = space;
    (void) interrupt->SetLevel(oldLevel);
    return ownedSpace;
}

bool Process::Exit(int status)
{
    IntStatus oldLevel = interrupt->SetLevel(IntOff);
    if (hasExited) {
        (void) interrupt->SetLevel(oldLevel);
        return false;
    }

    exitStatus = status;
    hasExited = true;
    for (int i = 0; i < waitingCount; ++i) {
        exitSem->V();
    }
    (void) interrupt->SetLevel(oldLevel);
    return true;
}

ProcessWaitResult Process::TryWait(
    const std::shared_ptr<Process>& caller, int* status) const noexcept
{
    if (status == nullptr) {
        return ProcessWaitResult::InvalidArgument;
    }

    IntStatus oldLevel = interrupt->SetLevel(IntOff);
    ProcessWaitResult result = ProcessWaitResult::Running;
    if (caller == nullptr || parent.lock() != caller) {
        result = ProcessWaitResult::NotChild;
    } else if (hasExited) {
        *status = exitStatus;
        result = ProcessWaitResult::Exited;
    }
    (void) interrupt->SetLevel(oldLevel);
    return result;
}

ProcessWaitResult Process::Wait(
    const std::shared_ptr<Process>& caller, int* status)
{
    if (status == nullptr) {
        return ProcessWaitResult::InvalidArgument;
    }

    IntStatus oldLevel = interrupt->SetLevel(IntOff);
    if (caller == nullptr || parent.lock() != caller) {
        (void) interrupt->SetLevel(oldLevel);
        return ProcessWaitResult::NotChild;
    }

    if (!hasExited) {
        ++waitingCount;
        exitSem->P();
        --waitingCount;
    }

    *status = exitStatus;
    (void) interrupt->SetLevel(oldLevel);
    return ProcessWaitResult::Exited;
}

ProcessManager::ProcessManager() = default;

ProcessManager& ProcessManager::Instance()
{
    static ProcessManager instance;
    return instance;
}

std::shared_ptr<Process> ProcessManager::CreateProcess(
    const std::shared_ptr<Process>& parent)
{
    IntStatus oldLevel = interrupt->SetLevel(IntOff);
    std::shared_ptr<Process> process;

    for (int count = 1; count < MaxProcesses; ++count) {
        const int candidate = nextPid;
        ++nextPid;
        if (nextPid >= MaxProcesses) {
            nextPid = 1;
        }
        if (processes[candidate] == nullptr) {
            process = std::shared_ptr<Process>(
                new Process(candidate, parent));
            processes[candidate] = process;
            break;
        }
    }

    (void) interrupt->SetLevel(oldLevel);
    return process;
}

std::shared_ptr<Process> ProcessManager::GetProcess(int pid) const noexcept
{
    if (pid <= 0 || pid >= MaxProcesses) {
        return nullptr;
    }

    IntStatus oldLevel = interrupt->SetLevel(IntOff);
    std::shared_ptr<Process> process = processes[pid];
    (void) interrupt->SetLevel(oldLevel);
    return process;
}

bool ProcessManager::RemoveProcess(
    const std::shared_ptr<Process>& process) noexcept
{
    if (process == nullptr) {
        return false;
    }
    const int pid = process->GetPid();
    if (pid <= 0 || pid >= MaxProcesses) {
        return false;
    }

    std::shared_ptr<Process> removed;
    IntStatus oldLevel = interrupt->SetLevel(IntOff);
    if (processes[pid] == process) {
        removed = std::move(processes[pid]);
    }
    (void) interrupt->SetLevel(oldLevel);
    return removed != nullptr;
}
