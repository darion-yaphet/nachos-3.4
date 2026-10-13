// process.h
//	Process Control Block (PCB) and Process Table Manager.
//	Provides foundational abstractions for multiprogramming, process lifecycle,
//	and parent-child waiting synchronization in Lab 2.

#ifndef PROCESS_H
#define PROCESS_H

#include "copyright.h"
#include "thread.h"
#include <memory>

class AddrSpace;
class Semaphore;

constexpr int MaxProcesses = 128;
constexpr int InvalidPid = -1;

enum class ProcessWaitResult {
    Exited,
    Running,
    NotChild,
    InvalidArgument
};

class Process {
  public:
    ~Process();

    Process(const Process&) = delete;
    Process& operator=(const Process&) = delete;

    [[nodiscard]] int GetPid() const noexcept { return pid; }
    [[nodiscard]] int GetParentPid() const noexcept { return parentPid; }
    [[nodiscard]] int GetExitStatus() const noexcept;
    [[nodiscard]] bool HasExited() const noexcept;

    // The handle observes stable completion state and remains safe after the
    // scheduler reclaims the Thread object.
    void SetThreadHandle(ThreadJoinHandle handle) noexcept;
    [[nodiscard]] ThreadJoinHandle GetThreadHandle() const noexcept;

    // Process and Thread may both execute in the same address space, so that
    // ownership is shared explicitly rather than represented by raw aliases.
    void SetSpace(std::shared_ptr<AddrSpace> ownedSpace) noexcept;
    [[nodiscard]] std::shared_ptr<AddrSpace> GetSpace() const noexcept;

    // The first Exit wins and wakes every current waiter. Later calls leave
    // the original status unchanged and return false.
    [[nodiscard]] bool Exit(int status);

    // Only the original parent object may wait; a different process that later
    // reuses the same numeric PID is rejected. TryWait is nonblocking; Wait
    // blocks until exit. Both may query the same exit status repeatedly.
    [[nodiscard]] ProcessWaitResult TryWait(
        const std::shared_ptr<Process>& caller, int* status) const noexcept;
    [[nodiscard]] ProcessWaitResult Wait(
        const std::shared_ptr<Process>& caller, int* status);

  private:
    friend class ProcessManager;

    explicit Process(int processId,
                     const std::shared_ptr<Process>& parentProcess);

    int pid{InvalidPid};
    int parentPid{InvalidPid};
    std::weak_ptr<Process> parent;
    ThreadJoinHandle threadHandle;
    std::shared_ptr<AddrSpace> space;
    int exitStatus{0};
    bool hasExited{false};
    int waitingCount{0};
    std::unique_ptr<Semaphore> exitSem;
};

class ProcessManager {
  public:
    static ProcessManager& Instance();

    ProcessManager(const ProcessManager&) = delete;
    ProcessManager& operator=(const ProcessManager&) = delete;

    // Allocation and insertion are atomic. Returned handles remain valid if
    // the table entry is removed and its PID is later reused.
    [[nodiscard]] std::shared_ptr<Process> CreateProcess(
        const std::shared_ptr<Process>& parent = nullptr);
    [[nodiscard]] std::shared_ptr<Process> GetProcess(int pid) const noexcept;
    // Identity matching prevents a stale handle from removing a newer process
    // after its numeric PID has been reused.
    [[nodiscard]] bool RemoveProcess(
        const std::shared_ptr<Process>& process) noexcept;

  private:
    ProcessManager();
    ~ProcessManager() = default;

    std::shared_ptr<Process> processes[MaxProcesses];
    int nextPid{1};
};

#ifdef USER_PROGRAM
void ProcessRegressionTest();
#endif

#endif // PROCESS_H
