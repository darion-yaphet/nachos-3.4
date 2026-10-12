// utility.h 
//	Miscellaneous useful definitions, including debugging routines.
//
//	The debugging routines allow the user to turn on selected
//	debugging messages, controllable from the command line arguments
//	passed to Nachos (-d).  You are encouraged to add your own
//	debugging flags.  The pre-defined debugging flags are:
//
//	'+' -- turn on all debug messages
//   	't' -- thread system
//   	's' -- semaphores, locks, and conditions
//   	'i' -- interrupt emulation
//   	'm' -- machine emulation (USER_PROGRAM)
//   	'd' -- disk emulation (FILESYS)
//   	'f' -- file system (FILESYS)
//   	'a' -- address spaces (USER_PROGRAM)
//   	'n' -- network emulation (NETWORK)
//
// Copyright (c) 1992-1993 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation 
// of liability and disclaimer of warranty provisions.

#ifndef UTILITY_H
#define UTILITY_H

#include "copyright.h"
#include <cstdint>
#include <cstddef>

// Miscellaneous useful routines

// Modern C++ provides bool as a built-in type.
#ifndef TRUE
#define TRUE true
#endif
#ifndef FALSE
#define FALSE false
#endif

// Safe constexpr template functions replacing legacy preprocessor macros
template <typename T, typename U>
constexpr auto min(const T& a, const U& b) {
    return (a < b) ? a : b;
}

template <typename T, typename U>
constexpr auto max(const T& a, const U& b) {
    return (a > b) ? a : b;
}

// Divide and either round up or down 
template <typename T, typename S>
constexpr auto divRoundDown(T n, S s) noexcept {
    return static_cast<decltype(n / s)>(n / s);
}

template <typename T, typename S>
constexpr auto divRoundUp(T n, S s) noexcept {
    return static_cast<decltype(n / s)>((n / s) + (((n % s) > 0) ? 1 : 0));
}

// Modern function pointer aliases
using VoidFunctionPtr = void (*)(intptr_t arg); 
using VoidNoArgFunctionPtr = void (*)(); 

// Include interface that isolates us from the host machine system library.
// Requires definition of bool, and VoidFunctionPtr
#include "sysdep.h"				

// Interface to debugging routines.
extern void DebugInit(const char* flags);	// enable printing debug messages
extern bool DebugIsEnabled(char flag); 	// Is this debug flag enabled?
extern void DEBUG(char flag, const char* format, ...) __attribute__((__format__(__printf__, 2, 3)));  	// Print debug message 

// Modern pedagogical structured logging
enum class LogLevel {
    DEBUG_LEVEL,
    INFO_LEVEL,
    WARN_LEVEL,
    ERROR_LEVEL
};

extern void LogMessage(LogLevel level, char flag, const char* format, ...) __attribute__((__format__(__printf__, 3, 4)));

#define LOG_DEBUG(flag, format, ...) LogMessage(LogLevel::DEBUG_LEVEL, flag, format, ##__VA_ARGS__)
#define LOG_INFO(flag, format, ...)  LogMessage(LogLevel::INFO_LEVEL, flag, format, ##__VA_ARGS__)
#define LOG_WARN(flag, format, ...)  LogMessage(LogLevel::WARN_LEVEL, flag, format, ##__VA_ARGS__)
#define LOG_ERROR(flag, format, ...) LogMessage(LogLevel::ERROR_LEVEL, flag, format, ##__VA_ARGS__)

//----------------------------------------------------------------------
// ASSERT
//      If condition is false, print a message and dump core.
//      Uses do-while(0) to prevent dangling else ambiguities.
//----------------------------------------------------------------------
#define ASSERT(condition)                                                     \
    do {                                                                      \
        if (!(condition)) {                                                   \
            fprintf(stderr, "Assertion failed: line %d, file \"%s\"\n",       \
                    __LINE__, __FILE__);                                      \
            fflush(stderr);                                                   \
            Abort();                                                          \
        }                                                                     \
    } while (0)

#endif // UTILITY_H
