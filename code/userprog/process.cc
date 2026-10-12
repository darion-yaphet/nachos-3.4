// process.cc
//	Implementation of Process Control Block (PCB) and ProcessManager.

#include "copyright.h"
#include "process.h"
#include "synch.h"
#include "system.h"

Process::Process(int processId, int parentProcessId)
    : pid(processId), parentPid(parentProcessId),
      exitSem(std::make_unique<Semaphore>("procExitSem", 0))
{
}

Process::~Process() = default;

void Process::Exit(int status)
{
    exitStatus = status;
    hasExited = true;
    if (exitSem != nullptr) {
        exitSem->V();
    }
}

int Process::Wait()
{
    if (!hasExited && exitSem != nullptr) {
        exitSem->P();
    }
    return exitStatus;
}

ProcessManager::ProcessManager() = default;

ProcessManager& ProcessManager::Instance()
{
    static ProcessManager instance;
    return instance;
}

int ProcessManager::AllocatePid()
{
    for (int i = 0; i < MaxProcesses; i++) {
        int candidate = nextPid++;
        if (nextPid >= MaxProcesses) {
            nextPid = 1;
        }
        if (candidate > 0 && candidate < MaxProcesses && processes[candidate] == nullptr) {
            return candidate;
        }
    }
    return InvalidPid;
}

bool ProcessManager::RegisterProcess(std::unique_ptr<Process> proc)
{
    if (proc == nullptr) {
        return false;
    }
    int candidatePid = proc->GetPid();
    if (candidatePid <= 0 || candidatePid >= MaxProcesses || processes[candidatePid] != nullptr) {
        return false;
    }
    processes[candidatePid] = std::move(proc);
    return true;
}

Process* ProcessManager::GetProcess(int pid)
{
    if (pid <= 0 || pid >= MaxProcesses) {
        return nullptr;
    }
    return processes[pid].get();
}

void ProcessManager::RemoveProcess(int pid)
{
    if (pid > 0 && pid < MaxProcesses) {
        processes[pid].reset();
    }
}
