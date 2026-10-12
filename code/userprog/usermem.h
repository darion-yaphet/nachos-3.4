// usermem.h
//	Safe helper routines to access user-level memory from the kernel.
//	Prevents kernel panics / segfaults when user programs pass invalid pointers.

#ifndef USERMEM_H
#define USERMEM_H

#include "copyright.h"
#include <cstddef>

namespace UserMem {

// Read null-terminated string from user virtual address into kernel buffer.
// Returns true on success, false if invalid address or buffer capacity exceeded.
bool ReadString(int virtAddr, char* kernelBuf, int maxBytes);

// Copy count bytes from user virtual memory into kernel buffer.
// Returns true if all bytes successfully read, false otherwise.
bool CopyFromUser(int virtAddr, void* kernelBuf, int count);

// Copy count bytes from kernel buffer into user virtual memory.
// Returns true if all bytes successfully written, false otherwise.
bool CopyToUser(const void* kernelBuf, int virtAddr, int count);

} // namespace UserMem

#endif // USERMEM_H
