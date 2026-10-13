// Stable parent-owned completion handles, exercised with nachos -T handles.
#include "system.h"
#include "synch.h"

void JoinHandleRegressionTest()
{
    Thread* child = new Thread("handle child", true);
    ThreadJoinHandle handle = child->GetJoinHandle();
    child->Fork([](intptr_t) {
        currentThread->Yield();
        currentThread->SetExitStatus(73);
    }, 0);
    ASSERT(handle.IsValid());
    ASSERT(handle.Join() == 73);
    ASSERT(handle.Join() == 73);
    ThreadJoinHandle copy = handle;
    ASSERT(copy.Join() == 73);
    ASSERT(interrupt->getLevel() == IntOn);

    // Dropping the last external handle must not retain a finished stack.
    Thread* unobserved = new Thread("dropped handle child", true);
    {
        ThreadJoinHandle dropped = unobserved->GetJoinHandle();
        unobserved->Fork([](intptr_t) {}, 0);
    }
    currentThread->Yield();
    ASSERT(threadToBeDestroyed == nullptr);

    Thread* early = new Thread("completed handle child", true);
    ThreadJoinHandle completed = early->GetJoinHandle();
    early->Fork([](intptr_t) { currentThread->SetExitStatus(-5); }, 0);
    currentThread->Yield();
    IntStatus oldLevel = interrupt->SetLevel(IntOff);
    ASSERT(completed.Join() == -5);
    ASSERT(completed.Join() == -5);
    ASSERT(interrupt->getLevel() == IntOff);
    (void) interrupt->SetLevel(oldLevel);
    printf("Stable join handle tests PASSED\n");
}

void NonParentJoinRegressionTest(bool completed)
{
    static Semaphore gate("child stays alive", 0);
    Thread* child = new Thread("parent-only child", true);
    ThreadJoinHandle handle = child->GetJoinHandle();
    child->Fork([](intptr_t done) { if (!done) gate.P(); }, completed);
    if (completed)
        currentThread->Yield();
    Thread* stranger = new Thread("non-parent joiner");
    stranger->Fork([](intptr_t arg) {
        reinterpret_cast<ThreadJoinHandle*>(arg)->Join();
    }, reinterpret_cast<intptr_t>(&handle));
    currentThread->Yield();
}
