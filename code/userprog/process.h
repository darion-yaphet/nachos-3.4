// process.h
//	Process Control Block (PCB) and Process Table Manager.
//	Provides foundational abstractions for multiprogramming, process lifecycle,
//	and parent-child waiting synchronization in Lab 2.

#ifndef PROCESS_H
#define PROCESS_H

#include "copyright.h"
#include <memory>

class Thread;
class AddrSpace;
class Semaphore;

constexpr int MaxProcesses = 128;
constexpr int InvalidPid = -1;

class Process {
  public:
    explicit Process(int processId, int parentProcessId = InvalidPid);
    ~Process();

    // Non-copyable
    Process(const Process&) = delete;
    Process& operator=(const Process&) = delete;

    [[nodiscard]] int GetPid() const noexcept { return pid; }
    [[nodiscard]] int GetParentPid() const noexcept { return parentPid; }
    [[nodiscard]] int GetExitStatus() const noexcept { return exitStatus; }
    [[nodiscard]] bool HasExited() const noexcept { return hasExited; }

    void SetThread(Thread* t) noexcept { thread = t; }
    [[nodiscard]] Thread* GetThread() const noexcept { return thread; }

    void SetSpace(AddrSpace* sp) noexcept { space = sp; }
    [[nodiscard]] AddrSpace* GetSpace() const noexcept { return space; }

    void Exit(int status);
    int Wait();

  private:
    int pid{InvalidPid};
    int parentPid{InvalidPid};
    Thread* thread{nullptr};
    AddrSpace* space{nullptr};
    int exitStatus{0};
    bool hasExited{false};
    std::unique_ptr<Semaphore> exitSem;
};

class ProcessManager {
  public:
    static ProcessManager& Instance();

    ProcessManager(const ProcessManager&) = delete;
    ProcessManager& operator=(const ProcessManager&) = delete;

    int AllocatePid();
    bool RegisterProcess(std::unique_ptr<Process> proc);
    Process* GetProcess(int pid);
    void RemoveProcess(int pid);

  private:
    ProcessManager();
    ~ProcessManager() = default;

    std::unique_ptr<Process> processes[MaxProcesses];
    int nextPid{1};
};

#endif // PROCESS_H
