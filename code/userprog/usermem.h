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
// A positive-capacity buffer is always NUL-terminated, including on failure.
bool ReadString(int virtAddr, char* kernelBuf, int maxBytes);

// Copy count bytes from user virtual memory into kernel buffer.
// Returns true if all bytes successfully read, false otherwise.
// Failure may leave a copied prefix in kernelBuf.
bool CopyFromUser(int virtAddr, void* kernelBuf, int count);

// Copy count bytes from kernel buffer into user virtual memory.
// Returns true if all bytes successfully written, false otherwise.
// Failure may leave a written prefix in user memory.
bool CopyToUser(const void* kernelBuf, int virtAddr, int count);

// Access is non-trapping: invalid, read-only (on writes), unmapped, and TLB-miss
// addresses return false. These helpers do not resolve page faults or retry them.
// Buffers must be non-null; zero-byte copies succeed for nonnegative addresses.

} // namespace UserMem

#endif // USERMEM_H
