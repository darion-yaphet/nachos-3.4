// stats.h 
//	Data structures for gathering statistics about Nachos performance.
//
// DO NOT CHANGE -- these stats are maintained by the machine emulation
//
//
// Copyright (c) 1992-1993 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation 
// of liability and disclaimer of warranty provisions.

#ifndef STATS_H
#define STATS_H

#include "copyright.h"

// The following class defines the statistics that are to be kept
// about Nachos behavior -- how much time (ticks) elapsed, how
// many user instructions executed, etc.
//
// The fields in this class are public to make it easier to update.

class Statistics {
  public:
    int totalTicks{0};      	// Total time running Nachos
    int idleTicks{0};       	// Time spent idle (no threads to run)
    int systemTicks{0};	 	// Time spent executing system code
    int userTicks{0};       	// Time spent executing user code
				// (this is also equal to # of
				// user instructions executed)

    int numDiskReads{0};		// number of disk read requests
    int numDiskWrites{0};		// number of disk write requests
    int numConsoleCharsRead{0};	// number of characters read from the keyboard
    int numConsoleCharsWritten{0}; // number of characters written to the display
    int numPageFaults{0};		// number of virtual memory page faults
    int numPacketsSent{0};		// number of packets sent over the network
    int numPacketsRecvd{0};	// number of packets received over the network

    Statistics() = default; 	// initialize everything to zero
    Statistics(const Statistics&) = delete;
    Statistics& operator=(const Statistics&) = delete;

    void Print() const;		// print collected statistics
};

// Constants used to reflect the relative time an operation would
// take in a real system.  A "tick" is a just a unit of time -- if you 
// like, a microsecond.
//
// Since Nachos kernel code is directly executed, and the time spent
// in the kernel measured by the number of calls to enable interrupts,
// these time constants are none too exact.

constexpr int UserTick = 1; 	// advance for each user-level instruction 
constexpr int SystemTick = 10; 	// advance each time interrupts are enabled
constexpr int RotationTime = 500; 	// time disk takes to rotate one sector
constexpr int SeekTime = 500;    	// time disk takes to seek past one track
constexpr int ConsoleTime = 100;	// time to read or write one character
constexpr int NetworkTime = 100;   	// time to send or receive one packet
constexpr int TimerTicks = 100;    	// (average) time between timer interrupts

#endif // STATS_H
