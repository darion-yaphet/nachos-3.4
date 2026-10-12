// usermem.cc
//	Implementation of safe user-memory access routines.

#include "copyright.h"
#include "usermem.h"
#include "machine.h"
#include "system.h"

namespace UserMem {

bool ReadString(int virtAddr, char* kernelBuf, int maxBytes)
{
    if (kernelBuf == nullptr || maxBytes <= 0) {
        return false;
    }

    int i = 0;
    while (i < maxBytes - 1) {
        int val = 0;
        if (!machine->ReadMem(virtAddr + i, 1, &val)) {
            kernelBuf[i] = '\0';
            return false;
        }
        char ch = static_cast<char>(val);
        kernelBuf[i] = ch;
        if (ch == '\0') {
            return true;
        }
        i++;
    }
    kernelBuf[maxBytes - 1] = '\0';
    return false;
}

bool CopyFromUser(int virtAddr, void* kernelBuf, int count)
{
    if (kernelBuf == nullptr || count < 0) {
        return false;
    }
    char* dest = static_cast<char*>(kernelBuf);
    for (int i = 0; i < count; i++) {
        int val = 0;
        if (!machine->ReadMem(virtAddr + i, 1, &val)) {
            return false;
        }
        dest[i] = static_cast<char>(val);
    }
    return true;
}

bool CopyToUser(const void* kernelBuf, int virtAddr, int count)
{
    if (kernelBuf == nullptr || count < 0) {
        return false;
    }
    const char* src = static_cast<const char*>(kernelBuf);
    for (int i = 0; i < count; i++) {
        if (!machine->WriteMem(virtAddr + i, 1, src[i])) {
            return false;
        }
    }
    return true;
}

} // namespace UserMem
