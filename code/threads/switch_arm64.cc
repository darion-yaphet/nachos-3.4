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
    (void) swapcontext(oldThread->GetContext(), newThread->GetContext());
}
