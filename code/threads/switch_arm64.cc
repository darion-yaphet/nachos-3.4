// switch_arm64.cc
//	Context switching implementation for Darwin on Apple Silicon.

#include "copyright.h"
#include "thread.h"
#include "system.h"

extern "C" void
ThreadRoot()
{
    currentThread->RunThreadRoot();
}

extern "C" void
SWITCH(Thread *oldThread, Thread *newThread)
{
#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
#endif
    (void) swapcontext(oldThread->GetContext(), newThread->GetContext());
#if defined(__clang__)
#pragma clang diagnostic pop
#endif
}
