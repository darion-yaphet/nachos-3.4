// utility.cc 
//	Debugging routines.  Allows users to control whether to 
//	print DEBUG statements, based on a command line argument.
//
// Copyright (c) 1992-1993 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation 
// of liability and disclaimer of warranty provisions.

#include "copyright.h"
#include "utility.h"
#include "thread.h"
#include "stats.h"
#include <unistd.h>
#include <cstdarg>
#include <cstring>
#include <cstdio>

extern Thread *currentThread;
extern Statistics *stats;

static const char *enableFlags = nullptr; // controls which DEBUG messages are printed 

//----------------------------------------------------------------------
// DebugInit
//      Initialize so that only DEBUG messages with a flag in flagList 
//	will be printed.
//
//	If the flag is "+", we enable all DEBUG messages.
//
// 	"flagList" is a string of characters for whose DEBUG messages are 
//		to be enabled.
//----------------------------------------------------------------------

void
DebugInit(const char *flagList)
{
    enableFlags = flagList;
}

//----------------------------------------------------------------------
// DebugIsEnabled
//      Return true if DEBUG messages with "flag" are to be printed.
//----------------------------------------------------------------------

bool
DebugIsEnabled(char flag)
{
    if (enableFlags != nullptr) {
       return (strchr(enableFlags, flag) != nullptr) 
		|| (strchr(enableFlags, '+') != nullptr);
    }
    return false;
}

//----------------------------------------------------------------------
// DEBUG
//      Print a debug message, if flag is enabled.  Like printf,
//	only with an extra argument on the front.
//----------------------------------------------------------------------

void 
DEBUG(char flag, const char *format, ...)
{
    if (DebugIsEnabled(flag)) {
	va_list ap;
	va_start(ap, format);
	vfprintf(stdout, format, ap);
	va_end(ap);
	fflush(stdout);
    }
}

//----------------------------------------------------------------------
// LogMessage
//      Print modern structured pedagogical log with tick, thread context,
//      ANSI terminal color coding, and log levels.
//----------------------------------------------------------------------

void
LogMessage(LogLevel level, char flag, const char* format, ...)
{
    if (!DebugIsEnabled(flag)) {
        return;
    }

    const char* colorCode = "";
    const char* levelStr = "INFO";
    bool useColor = (isatty(fileno(stdout)) != 0);

    switch (level) {
        case LogLevel::DEBUG_LEVEL:
            levelStr = "DEBUG";
            colorCode = useColor ? "\033[36m" : ""; // Cyan
            break;
        case LogLevel::INFO_LEVEL:
            levelStr = "INFO";
            colorCode = useColor ? "\033[32m" : ""; // Green
            break;
        case LogLevel::WARN_LEVEL:
            levelStr = "WARN";
            colorCode = useColor ? "\033[33m" : ""; // Yellow
            break;
        case LogLevel::ERROR_LEVEL:
            levelStr = "ERROR";
            colorCode = useColor ? "\033[31m" : ""; // Red
            break;
    }

    const char* resetCode = useColor ? "\033[0m" : "";

    int currentTick = -1;
    const char* threadName = "kernel";
    if (stats != nullptr) {
        currentTick = stats->totalTicks;
    }
    if (currentThread != nullptr && currentThread->getName() != nullptr) {
        threadName = currentThread->getName();
    }

    if (currentTick >= 0) {
        printf("%s[%5d][%-10s][%s][%c]%s ", colorCode, currentTick, threadName, levelStr, flag, resetCode);
    } else {
        printf("%s[init ][%-10s][%s][%c]%s ", colorCode, threadName, levelStr, flag, resetCode);
    }

    va_list ap;
    va_start(ap, format);
    vfprintf(stdout, format, ap);
    va_end(ap);
    fflush(stdout);
}

