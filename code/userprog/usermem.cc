// usermem.cc
//	Implementation of safe user-memory access routines.

#include "copyright.h"
#include "usermem.h"
#include "machine.h"
#include "system.h"
#include <climits>

namespace UserMem {

// Kernel copies report bad mappings without invoking the user-mode handler.
// Page-in and retry policy belongs to the VM lab.
static bool TranslateByte(int virtAddr, int* physicalAddr, bool writing)
{
    return virtAddr >= 0 &&
        machine->Translate(virtAddr, physicalAddr, 1, writing) == NoException;
}

static bool ValidRange(int virtAddr, int count)
{
    return virtAddr >= 0 && count >= 0 &&
        (count == 0 || virtAddr <= INT_MAX - (count - 1));
}

bool ReadString(int virtAddr, char* kernelBuf, int maxBytes)
{
    if (kernelBuf == nullptr || maxBytes <= 0) {
        return false;
    }

    kernelBuf[0] = '\0';
    for (int i = 0; i < maxBytes; ++i) {
        int physicalAddr = 0;
        if (virtAddr < 0 || virtAddr > INT_MAX - i ||
            !TranslateByte(virtAddr + i, &physicalAddr, false)) {
            kernelBuf[i] = '\0';
            return false;
        }
        char ch = machine->mainMemory[physicalAddr];
        if (ch == '\0') {
            kernelBuf[i] = '\0';
            return true;
        }
        if (i == maxBytes - 1) {
            break; // leave room for a trailing NUL
        }
        kernelBuf[i] = ch;
    }
    kernelBuf[maxBytes - 1] = '\0';
    return false;
}

bool CopyFromUser(int virtAddr, void* kernelBuf, int count)
{
    if (kernelBuf == nullptr || !ValidRange(virtAddr, count)) {
        return false;
    }
    char* dest = static_cast<char*>(kernelBuf);
    for (int i = 0; i < count; i++) {
        int physicalAddr = 0;
        if (!TranslateByte(virtAddr + i, &physicalAddr, false)) {
            return false;
        }
        dest[i] = machine->mainMemory[physicalAddr];
    }
    return true;
}

bool CopyToUser(const void* kernelBuf, int virtAddr, int count)
{
    if (kernelBuf == nullptr || !ValidRange(virtAddr, count)) {
        return false;
    }
    const char* src = static_cast<const char*>(kernelBuf);
    for (int i = 0; i < count; i++) {
        int physicalAddr = 0;
        if (!TranslateByte(virtAddr + i, &physicalAddr, true)) {
            return false;
        }
        machine->mainMemory[physicalAddr] = src[i];
    }
    return true;
}

} // namespace UserMem
