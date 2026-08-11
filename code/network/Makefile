# NOTE: this is a GNU Makefile.  You must use "gmake" rather than "make".
#
# Makefile for the network assignment
#    Defines set up assuming this assignment is done last 
#    If not, use the "bare bones"  defines below. 
#
# Copyright (c) 1992 The Regents of the University of California.
# All rights reserved.  See copyright.h for copyright notice and limitation 
# of liability and disclaimer of warranty provisions.

DEFINES = -DUSER_PROGRAM -DVM -DFILESYS_NEEDED -DFILESYS -DNETWORK
INCPATH = -I../network -I../bin -I../filesys -I../vm -I../userprog -I../threads -I../machine
HFILES = $(THREAD_H) $(USERPROG_H) $(VM_H) $(FILESYS_H) $(NETWORK_H)
CFILES = $(THREAD_C) $(USERPROG_C) $(VM_C) $(FILESYS_C) $(NETWORK_C)
C_OFILES = $(THREAD_O) $(USERPROG_O) $(VM_O) $(FILESYS_O) $(NETWORK_O)

# bare bones version
# DEFINES =-DTHREADS -DNETWORK
# INCPATH = -I../network -I../threads -I../machine
# HFILES = $(THREAD_H) $(NETWORK_H)
# CFILES = $(THREAD_C) $(NETWORK_C)
# C_OFILES = $(THREAD_O) $(NETWORK_O)

include ../Makefile.common
include ../Makefile.dep
#-----------------------------------------------------------------
# DO NOT DELETE THIS LINE -- make depend uses it
# DEPENDENCIES MUST END AT END OF FILE
main.o: ../threads/main.cc ../threads/copyright.h ../threads/utility.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/stdint.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/__config \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/__config_site \
  /Library/Developer/CommandLineTools/usr/lib/clang/16/include/stdint.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stdint.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int8_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int16_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int32_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int64_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint8_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint16_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint32_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint64_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/cdefs.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_symbol_aliasing.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_posix_availability.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/arm/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_pthread/_pthread_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_intptr_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_uintptr_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_intmax_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uintmax_t.h \
  ../machine/sysdep.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/Availability.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/AvailabilityVersions.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/AvailabilityInternal.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/AvailabilityInternalLegacy.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_va_list.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/arm/types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int8_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int16_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int32_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int64_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_size_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_null.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_printf.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_seek_set.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_ctermid.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_off_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_ssize_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/string.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/string.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_string.h \
  ../threads/system.h ../threads/thread.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/ucontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/ucontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/_mcontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/arm/_mcontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/appleapiopts.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/mach/machine/_structs.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/mach/arm/_structs.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_ucontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_sigaltstack.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_sigset_t.h \
  ../machine/machine.h ../machine/translate.h ../machine/disk.h \
  ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h \
  ../threads/scheduler.h ../threads/list.h ../machine/interrupt.h \
  ../machine/stats.h ../machine/timer.h ../filesys/synchdisk.h \
  ../threads/synch.h ../network/post.h ../machine/network.h \
  ../threads/synchlist.h
list.o: ../threads/list.cc ../threads/copyright.h ../threads/list.h \
  ../threads/utility.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/stdint.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/__config \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/__config_site \
  /Library/Developer/CommandLineTools/usr/lib/clang/16/include/stdint.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stdint.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int8_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int16_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int32_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int64_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint8_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint16_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint32_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint64_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/cdefs.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_symbol_aliasing.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_posix_availability.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/arm/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_pthread/_pthread_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_intptr_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_uintptr_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_intmax_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uintmax_t.h \
  ../machine/sysdep.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/Availability.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/AvailabilityVersions.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/AvailabilityInternal.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/AvailabilityInternalLegacy.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_va_list.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/arm/types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int8_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int16_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int32_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int64_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_size_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_null.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_printf.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_seek_set.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_ctermid.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_off_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_ssize_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/string.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/string.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_string.h
scheduler.o: ../threads/scheduler.cc ../threads/copyright.h \
  ../threads/scheduler.h ../threads/list.h ../threads/utility.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/stdint.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/__config \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/__config_site \
  /Library/Developer/CommandLineTools/usr/lib/clang/16/include/stdint.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stdint.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int8_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int16_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int32_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int64_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint8_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint16_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint32_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint64_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/cdefs.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_symbol_aliasing.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_posix_availability.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/arm/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_pthread/_pthread_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_intptr_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_uintptr_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_intmax_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uintmax_t.h \
  ../machine/sysdep.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/Availability.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/AvailabilityVersions.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/AvailabilityInternal.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/AvailabilityInternalLegacy.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_va_list.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/arm/types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int8_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int16_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int32_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int64_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_size_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_null.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_printf.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_seek_set.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_ctermid.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_off_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_ssize_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/string.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/string.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_string.h \
  ../threads/thread.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/ucontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/ucontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/_mcontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/arm/_mcontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/appleapiopts.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/mach/machine/_structs.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/mach/arm/_structs.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_ucontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_sigaltstack.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_sigset_t.h \
  ../machine/machine.h ../machine/translate.h ../machine/disk.h \
  ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h \
  ../threads/system.h ../machine/interrupt.h ../machine/stats.h \
  ../machine/timer.h ../filesys/synchdisk.h ../threads/synch.h \
  ../network/post.h ../machine/network.h ../threads/synchlist.h
synch.o: ../threads/synch.cc ../threads/copyright.h ../threads/synch.h \
  ../threads/thread.h ../threads/utility.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/stdint.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/__config \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/__config_site \
  /Library/Developer/CommandLineTools/usr/lib/clang/16/include/stdint.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stdint.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int8_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int16_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int32_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int64_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint8_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint16_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint32_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint64_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/cdefs.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_symbol_aliasing.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_posix_availability.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/arm/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_pthread/_pthread_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_intptr_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_uintptr_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_intmax_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uintmax_t.h \
  ../machine/sysdep.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/Availability.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/AvailabilityVersions.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/AvailabilityInternal.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/AvailabilityInternalLegacy.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_va_list.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/arm/types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int8_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int16_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int32_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int64_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_size_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_null.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_printf.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_seek_set.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_ctermid.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_off_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_ssize_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/string.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/string.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_string.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/ucontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/ucontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/_mcontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/arm/_mcontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/appleapiopts.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/mach/machine/_structs.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/mach/arm/_structs.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_ucontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_sigaltstack.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_sigset_t.h \
  ../machine/machine.h ../machine/translate.h ../machine/disk.h \
  ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h \
  ../threads/list.h ../threads/system.h ../threads/scheduler.h \
  ../machine/interrupt.h ../machine/stats.h ../machine/timer.h \
  ../filesys/synchdisk.h ../network/post.h ../machine/network.h \
  ../threads/synchlist.h
synchlist.o: ../threads/synchlist.cc ../threads/copyright.h \
  ../threads/synchlist.h ../threads/list.h ../threads/utility.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/stdint.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/__config \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/__config_site \
  /Library/Developer/CommandLineTools/usr/lib/clang/16/include/stdint.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stdint.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int8_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int16_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int32_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int64_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint8_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint16_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint32_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint64_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/cdefs.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_symbol_aliasing.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_posix_availability.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/arm/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_pthread/_pthread_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_intptr_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_uintptr_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_intmax_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uintmax_t.h \
  ../machine/sysdep.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/Availability.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/AvailabilityVersions.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/AvailabilityInternal.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/AvailabilityInternalLegacy.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_va_list.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/arm/types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int8_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int16_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int32_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int64_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_size_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_null.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_printf.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_seek_set.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_ctermid.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_off_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_ssize_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/string.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/string.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_string.h \
  ../threads/synch.h ../threads/thread.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/ucontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/ucontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/_mcontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/arm/_mcontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/appleapiopts.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/mach/machine/_structs.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/mach/arm/_structs.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_ucontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_sigaltstack.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_sigset_t.h \
  ../machine/machine.h ../machine/translate.h ../machine/disk.h \
  ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h
system.o: ../threads/system.cc ../threads/copyright.h ../threads/system.h \
  ../threads/utility.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/stdint.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/__config \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/__config_site \
  /Library/Developer/CommandLineTools/usr/lib/clang/16/include/stdint.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stdint.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int8_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int16_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int32_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int64_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint8_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint16_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint32_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint64_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/cdefs.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_symbol_aliasing.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_posix_availability.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/arm/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_pthread/_pthread_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_intptr_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_uintptr_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_intmax_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uintmax_t.h \
  ../machine/sysdep.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/Availability.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/AvailabilityVersions.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/AvailabilityInternal.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/AvailabilityInternalLegacy.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_va_list.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/arm/types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int8_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int16_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int32_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int64_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_size_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_null.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_printf.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_seek_set.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_ctermid.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_off_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_ssize_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/string.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/string.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_string.h \
  ../threads/thread.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/ucontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/ucontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/_mcontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/arm/_mcontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/appleapiopts.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/mach/machine/_structs.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/mach/arm/_structs.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_ucontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_sigaltstack.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_sigset_t.h \
  ../machine/machine.h ../machine/translate.h ../machine/disk.h \
  ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h \
  ../threads/scheduler.h ../threads/list.h ../machine/interrupt.h \
  ../machine/stats.h ../machine/timer.h ../filesys/synchdisk.h \
  ../threads/synch.h ../network/post.h ../machine/network.h \
  ../threads/synchlist.h
thread.o: ../threads/thread.cc ../threads/copyright.h ../threads/thread.h \
  ../threads/utility.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/stdint.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/__config \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/__config_site \
  /Library/Developer/CommandLineTools/usr/lib/clang/16/include/stdint.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stdint.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int8_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int16_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int32_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int64_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint8_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint16_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint32_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint64_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/cdefs.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_symbol_aliasing.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_posix_availability.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/arm/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_pthread/_pthread_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_intptr_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_uintptr_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_intmax_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uintmax_t.h \
  ../machine/sysdep.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/Availability.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/AvailabilityVersions.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/AvailabilityInternal.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/AvailabilityInternalLegacy.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_va_list.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/arm/types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int8_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int16_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int32_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int64_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_size_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_null.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_printf.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_seek_set.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_ctermid.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_off_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_ssize_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/string.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/string.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_string.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/ucontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/ucontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/_mcontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/arm/_mcontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/appleapiopts.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/mach/machine/_structs.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/mach/arm/_structs.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_ucontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_sigaltstack.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_sigset_t.h \
  ../machine/machine.h ../machine/translate.h ../machine/disk.h \
  ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h \
  ../threads/switch.h ../threads/synch.h ../threads/list.h \
  ../threads/system.h ../threads/scheduler.h ../machine/interrupt.h \
  ../machine/stats.h ../machine/timer.h ../filesys/synchdisk.h \
  ../network/post.h ../machine/network.h ../threads/synchlist.h
utility.o: ../threads/utility.cc ../threads/copyright.h \
  ../threads/utility.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/stdint.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/__config \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/__config_site \
  /Library/Developer/CommandLineTools/usr/lib/clang/16/include/stdint.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stdint.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int8_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int16_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int32_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int64_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint8_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint16_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint32_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint64_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/cdefs.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_symbol_aliasing.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_posix_availability.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/arm/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_pthread/_pthread_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_intptr_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_uintptr_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_intmax_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uintmax_t.h \
  ../machine/sysdep.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/Availability.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/AvailabilityVersions.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/AvailabilityInternal.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/AvailabilityInternalLegacy.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_va_list.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/arm/types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int8_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int16_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int32_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int64_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_size_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_null.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_printf.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_seek_set.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_ctermid.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_off_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_ssize_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/string.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/string.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_string.h \
  /Library/Developer/CommandLineTools/usr/lib/clang/16/include/stdarg.h \
  /Library/Developer/CommandLineTools/usr/lib/clang/16/include/__stdarg_header_macro.h \
  /Library/Developer/CommandLineTools/usr/lib/clang/16/include/__stdarg___gnuc_va_list.h \
  /Library/Developer/CommandLineTools/usr/lib/clang/16/include/__stdarg_va_list.h \
  /Library/Developer/CommandLineTools/usr/lib/clang/16/include/__stdarg_va_arg.h \
  /Library/Developer/CommandLineTools/usr/lib/clang/16/include/__stdarg___va_copy.h \
  /Library/Developer/CommandLineTools/usr/lib/clang/16/include/__stdarg_va_copy.h
threadtest.o: ../threads/threadtest.cc ../threads/copyright.h \
  ../threads/system.h ../threads/utility.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/stdint.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/__config \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/__config_site \
  /Library/Developer/CommandLineTools/usr/lib/clang/16/include/stdint.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stdint.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int8_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int16_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int32_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int64_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint8_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint16_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint32_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint64_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/cdefs.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_symbol_aliasing.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_posix_availability.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/arm/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_pthread/_pthread_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_intptr_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_uintptr_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_intmax_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uintmax_t.h \
  ../machine/sysdep.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/Availability.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/AvailabilityVersions.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/AvailabilityInternal.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/AvailabilityInternalLegacy.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_va_list.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/arm/types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int8_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int16_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int32_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int64_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_size_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_null.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_printf.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_seek_set.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_ctermid.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_off_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_ssize_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/string.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/string.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_string.h \
  ../threads/thread.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/ucontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/ucontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/_mcontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/arm/_mcontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/appleapiopts.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/mach/machine/_structs.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/mach/arm/_structs.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_ucontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_sigaltstack.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_sigset_t.h \
  ../machine/machine.h ../machine/translate.h ../machine/disk.h \
  ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h \
  ../threads/scheduler.h ../threads/list.h ../machine/interrupt.h \
  ../machine/stats.h ../machine/timer.h ../filesys/synchdisk.h \
  ../threads/synch.h ../network/post.h ../machine/network.h \
  ../threads/synchlist.h
interrupt.o: ../machine/interrupt.cc ../threads/copyright.h \
  ../machine/interrupt.h ../threads/list.h ../threads/utility.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/stdint.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/__config \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/__config_site \
  /Library/Developer/CommandLineTools/usr/lib/clang/16/include/stdint.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stdint.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int8_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int16_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int32_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int64_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint8_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint16_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint32_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint64_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/cdefs.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_symbol_aliasing.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_posix_availability.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/arm/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_pthread/_pthread_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_intptr_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_uintptr_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_intmax_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uintmax_t.h \
  ../machine/sysdep.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/Availability.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/AvailabilityVersions.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/AvailabilityInternal.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/AvailabilityInternalLegacy.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_va_list.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/arm/types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int8_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int16_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int32_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int64_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_size_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_null.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_printf.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_seek_set.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_ctermid.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_off_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_ssize_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/string.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/string.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_string.h \
  ../threads/system.h ../threads/thread.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/ucontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/ucontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/_mcontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/arm/_mcontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/appleapiopts.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/mach/machine/_structs.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/mach/arm/_structs.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_ucontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_sigaltstack.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_sigset_t.h \
  ../machine/machine.h ../machine/translate.h ../machine/disk.h \
  ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h \
  ../threads/scheduler.h ../machine/stats.h ../machine/timer.h \
  ../filesys/synchdisk.h ../threads/synch.h ../network/post.h \
  ../machine/network.h ../threads/synchlist.h
sysdep.o: ../machine/sysdep.cc ../threads/copyright.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/__config \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/__config_site \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/cdefs.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_symbol_aliasing.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_posix_availability.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/Availability.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/AvailabilityVersions.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/AvailabilityInternal.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/AvailabilityInternalLegacy.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/arm/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_pthread/_pthread_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_va_list.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/arm/types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int8_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int16_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int32_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int64_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int8_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int16_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int32_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int64_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_intptr_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_uintptr_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_size_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_null.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_printf.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_seek_set.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_ctermid.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_off_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_ssize_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/stdlib.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stdlib.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_stdlib.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/wait.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_pid_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_id_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/signal.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/appleapiopts.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/signal.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/arm/signal.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/_mcontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/arm/_mcontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/mach/machine/_structs.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/mach/arm/_structs.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_pthread/_pthread_attr_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_sigaltstack.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_ucontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_sigset_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_uid_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/resource.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_timeval.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_wchar_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/malloc/_malloc.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/malloc/_ptrcheck.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_abort.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/string.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/string.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_string.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/signal.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_pthread/_pthread_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/endian.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/arm/endian.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_caddr_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_dev_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_blkcnt_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_blksize_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_gid_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_in_addr_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_in_port_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_ino_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_key_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_mode_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_nlink_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_clock_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_time_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_useconds_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_suseconds_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_pthread/_pthread_cond_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_pthread/_pthread_condattr_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_pthread/_pthread_mutex_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_pthread/_pthread_mutexattr_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_pthread/_pthread_once_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_pthread/_pthread_rwlock_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_pthread/_pthread_rwlockattr_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_pthread/_pthread_key_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_fsblkcnt_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_fsfilcnt_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/time.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_fd_def.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_timespec.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_fd_setsize.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_fd_set.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_fd_clr.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_fd_isset.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_fd_zero.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_select.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/socket.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/constrained_ctypes.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/_param.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/arm/_param.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/net/net_kev.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_sa_family_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_socklen_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_iovec_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/file.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/fcntl.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_o_sync.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_o_dsync.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_s_ifmt.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/unistd.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_posix_vdisable.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/queue.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/un.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/mman.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/unistd.h \
  ../machine/interrupt.h ../threads/list.h ../threads/utility.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/stdint.h \
  /Library/Developer/CommandLineTools/usr/lib/clang/16/include/stdint.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stdint.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint8_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint16_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint32_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint64_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_intmax_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uintmax_t.h \
  ../machine/sysdep.h ../threads/system.h ../threads/thread.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/ucontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/ucontext.h \
  ../machine/machine.h ../machine/translate.h ../machine/disk.h \
  ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h \
  ../threads/scheduler.h ../machine/stats.h ../machine/timer.h \
  ../filesys/synchdisk.h ../threads/synch.h ../network/post.h \
  ../machine/network.h ../threads/synchlist.h
stats.o: ../machine/stats.cc ../threads/copyright.h ../threads/utility.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/stdint.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/__config \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/__config_site \
  /Library/Developer/CommandLineTools/usr/lib/clang/16/include/stdint.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stdint.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int8_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int16_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int32_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int64_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint8_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint16_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint32_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint64_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/cdefs.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_symbol_aliasing.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_posix_availability.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/arm/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_pthread/_pthread_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_intptr_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_uintptr_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_intmax_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uintmax_t.h \
  ../machine/sysdep.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/Availability.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/AvailabilityVersions.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/AvailabilityInternal.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/AvailabilityInternalLegacy.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_va_list.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/arm/types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int8_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int16_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int32_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int64_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_size_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_null.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_printf.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_seek_set.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_ctermid.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_off_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_ssize_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/string.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/string.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_string.h \
  ../machine/stats.h
timer.o: ../machine/timer.cc ../threads/copyright.h ../machine/timer.h \
  ../threads/utility.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/stdint.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/__config \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/__config_site \
  /Library/Developer/CommandLineTools/usr/lib/clang/16/include/stdint.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stdint.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int8_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int16_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int32_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int64_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint8_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint16_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint32_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint64_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/cdefs.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_symbol_aliasing.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_posix_availability.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/arm/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_pthread/_pthread_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_intptr_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_uintptr_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_intmax_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uintmax_t.h \
  ../machine/sysdep.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/Availability.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/AvailabilityVersions.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/AvailabilityInternal.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/AvailabilityInternalLegacy.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_va_list.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/arm/types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int8_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int16_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int32_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int64_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_size_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_null.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_printf.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_seek_set.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_ctermid.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_off_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_ssize_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/string.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/string.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_string.h \
  ../threads/system.h ../threads/thread.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/ucontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/ucontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/_mcontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/arm/_mcontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/appleapiopts.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/mach/machine/_structs.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/mach/arm/_structs.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_ucontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_sigaltstack.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_sigset_t.h \
  ../machine/machine.h ../machine/translate.h ../machine/disk.h \
  ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h \
  ../threads/scheduler.h ../threads/list.h ../machine/interrupt.h \
  ../machine/stats.h ../filesys/synchdisk.h ../threads/synch.h \
  ../network/post.h ../machine/network.h ../threads/synchlist.h
addrspace.o: ../userprog/addrspace.cc ../threads/copyright.h \
  ../threads/system.h ../threads/utility.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/stdint.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/__config \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/__config_site \
  /Library/Developer/CommandLineTools/usr/lib/clang/16/include/stdint.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stdint.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int8_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int16_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int32_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int64_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint8_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint16_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint32_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint64_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/cdefs.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_symbol_aliasing.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_posix_availability.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/arm/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_pthread/_pthread_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_intptr_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_uintptr_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_intmax_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uintmax_t.h \
  ../machine/sysdep.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/Availability.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/AvailabilityVersions.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/AvailabilityInternal.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/AvailabilityInternalLegacy.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_va_list.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/arm/types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int8_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int16_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int32_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int64_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_size_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_null.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_printf.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_seek_set.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_ctermid.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_off_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_ssize_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/string.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/string.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_string.h \
  ../threads/thread.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/ucontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/ucontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/_mcontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/arm/_mcontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/appleapiopts.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/mach/machine/_structs.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/mach/arm/_structs.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_ucontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_sigaltstack.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_sigset_t.h \
  ../machine/machine.h ../machine/translate.h ../machine/disk.h \
  ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h \
  ../threads/scheduler.h ../threads/list.h ../machine/interrupt.h \
  ../machine/stats.h ../machine/timer.h ../filesys/synchdisk.h \
  ../threads/synch.h ../network/post.h ../machine/network.h \
  ../threads/synchlist.h ../bin/noff.h
bitmap.o: ../userprog/bitmap.cc ../threads/copyright.h \
  ../userprog/bitmap.h ../threads/utility.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/stdint.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/__config \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/__config_site \
  /Library/Developer/CommandLineTools/usr/lib/clang/16/include/stdint.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stdint.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int8_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int16_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int32_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int64_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint8_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint16_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint32_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint64_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/cdefs.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_symbol_aliasing.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_posix_availability.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/arm/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_pthread/_pthread_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_intptr_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_uintptr_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_intmax_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uintmax_t.h \
  ../machine/sysdep.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/Availability.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/AvailabilityVersions.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/AvailabilityInternal.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/AvailabilityInternalLegacy.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_va_list.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/arm/types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int8_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int16_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int32_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int64_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_size_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_null.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_printf.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_seek_set.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_ctermid.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_off_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_ssize_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/string.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/string.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_string.h \
  ../filesys/openfile.h
exception.o: ../userprog/exception.cc ../threads/copyright.h \
  ../threads/system.h ../threads/utility.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/stdint.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/__config \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/__config_site \
  /Library/Developer/CommandLineTools/usr/lib/clang/16/include/stdint.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stdint.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int8_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int16_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int32_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int64_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint8_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint16_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint32_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint64_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/cdefs.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_symbol_aliasing.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_posix_availability.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/arm/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_pthread/_pthread_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_intptr_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_uintptr_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_intmax_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uintmax_t.h \
  ../machine/sysdep.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/Availability.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/AvailabilityVersions.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/AvailabilityInternal.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/AvailabilityInternalLegacy.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_va_list.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/arm/types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int8_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int16_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int32_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int64_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_size_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_null.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_printf.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_seek_set.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_ctermid.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_off_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_ssize_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/string.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/string.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_string.h \
  ../threads/thread.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/ucontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/ucontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/_mcontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/arm/_mcontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/appleapiopts.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/mach/machine/_structs.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/mach/arm/_structs.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_ucontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_sigaltstack.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_sigset_t.h \
  ../machine/machine.h ../machine/translate.h ../machine/disk.h \
  ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h \
  ../threads/scheduler.h ../threads/list.h ../machine/interrupt.h \
  ../machine/stats.h ../machine/timer.h ../filesys/synchdisk.h \
  ../threads/synch.h ../network/post.h ../machine/network.h \
  ../threads/synchlist.h ../userprog/syscall.h
progtest.o: ../userprog/progtest.cc ../threads/copyright.h \
  ../threads/system.h ../threads/utility.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/stdint.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/__config \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/__config_site \
  /Library/Developer/CommandLineTools/usr/lib/clang/16/include/stdint.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stdint.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int8_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int16_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int32_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int64_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint8_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint16_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint32_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint64_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/cdefs.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_symbol_aliasing.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_posix_availability.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/arm/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_pthread/_pthread_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_intptr_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_uintptr_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_intmax_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uintmax_t.h \
  ../machine/sysdep.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/Availability.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/AvailabilityVersions.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/AvailabilityInternal.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/AvailabilityInternalLegacy.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_va_list.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/arm/types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int8_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int16_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int32_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int64_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_size_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_null.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_printf.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_seek_set.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_ctermid.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_off_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_ssize_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/string.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/string.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_string.h \
  ../threads/thread.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/ucontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/ucontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/_mcontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/arm/_mcontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/appleapiopts.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/mach/machine/_structs.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/mach/arm/_structs.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_ucontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_sigaltstack.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_sigset_t.h \
  ../machine/machine.h ../machine/translate.h ../machine/disk.h \
  ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h \
  ../threads/scheduler.h ../threads/list.h ../machine/interrupt.h \
  ../machine/stats.h ../machine/timer.h ../filesys/synchdisk.h \
  ../threads/synch.h ../network/post.h ../machine/network.h \
  ../threads/synchlist.h ../machine/console.h
console.o: ../machine/console.cc ../threads/copyright.h \
  ../machine/console.h ../threads/utility.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/stdint.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/__config \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/__config_site \
  /Library/Developer/CommandLineTools/usr/lib/clang/16/include/stdint.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stdint.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int8_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int16_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int32_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int64_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint8_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint16_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint32_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint64_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/cdefs.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_symbol_aliasing.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_posix_availability.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/arm/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_pthread/_pthread_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_intptr_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_uintptr_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_intmax_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uintmax_t.h \
  ../machine/sysdep.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/Availability.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/AvailabilityVersions.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/AvailabilityInternal.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/AvailabilityInternalLegacy.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_va_list.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/arm/types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int8_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int16_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int32_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int64_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_size_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_null.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_printf.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_seek_set.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_ctermid.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_off_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_ssize_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/string.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/string.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_string.h \
  ../threads/system.h ../threads/thread.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/ucontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/ucontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/_mcontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/arm/_mcontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/appleapiopts.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/mach/machine/_structs.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/mach/arm/_structs.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_ucontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_sigaltstack.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_sigset_t.h \
  ../machine/machine.h ../machine/translate.h ../machine/disk.h \
  ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h \
  ../threads/scheduler.h ../threads/list.h ../machine/interrupt.h \
  ../machine/stats.h ../machine/timer.h ../filesys/synchdisk.h \
  ../threads/synch.h ../network/post.h ../machine/network.h \
  ../threads/synchlist.h
machine.o: ../machine/machine.cc ../threads/copyright.h \
  ../machine/machine.h ../threads/utility.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/stdint.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/__config \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/__config_site \
  /Library/Developer/CommandLineTools/usr/lib/clang/16/include/stdint.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stdint.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int8_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int16_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int32_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int64_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint8_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint16_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint32_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint64_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/cdefs.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_symbol_aliasing.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_posix_availability.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/arm/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_pthread/_pthread_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_intptr_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_uintptr_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_intmax_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uintmax_t.h \
  ../machine/sysdep.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/Availability.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/AvailabilityVersions.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/AvailabilityInternal.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/AvailabilityInternalLegacy.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_va_list.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/arm/types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int8_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int16_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int32_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int64_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_size_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_null.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_printf.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_seek_set.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_ctermid.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_off_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_ssize_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/string.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/string.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_string.h \
  ../machine/translate.h ../machine/disk.h ../threads/system.h \
  ../threads/thread.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/ucontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/ucontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/_mcontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/arm/_mcontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/appleapiopts.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/mach/machine/_structs.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/mach/arm/_structs.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_ucontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_sigaltstack.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_sigset_t.h \
  ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h \
  ../threads/scheduler.h ../threads/list.h ../machine/interrupt.h \
  ../machine/stats.h ../machine/timer.h ../filesys/synchdisk.h \
  ../threads/synch.h ../network/post.h ../machine/network.h \
  ../threads/synchlist.h
mipssim.o: ../machine/mipssim.cc ../threads/copyright.h \
  ../machine/machine.h ../threads/utility.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/stdint.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/__config \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/__config_site \
  /Library/Developer/CommandLineTools/usr/lib/clang/16/include/stdint.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stdint.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int8_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int16_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int32_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int64_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint8_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint16_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint32_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint64_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/cdefs.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_symbol_aliasing.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_posix_availability.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/arm/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_pthread/_pthread_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_intptr_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_uintptr_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_intmax_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uintmax_t.h \
  ../machine/sysdep.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/Availability.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/AvailabilityVersions.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/AvailabilityInternal.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/AvailabilityInternalLegacy.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_va_list.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/arm/types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int8_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int16_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int32_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int64_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_size_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_null.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_printf.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_seek_set.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_ctermid.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_off_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_ssize_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/string.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/string.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_string.h \
  ../machine/translate.h ../machine/disk.h ../machine/mipssim.h \
  ../threads/system.h ../threads/thread.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/ucontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/ucontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/_mcontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/arm/_mcontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/appleapiopts.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/mach/machine/_structs.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/mach/arm/_structs.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_ucontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_sigaltstack.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_sigset_t.h \
  ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h \
  ../threads/scheduler.h ../threads/list.h ../machine/interrupt.h \
  ../machine/stats.h ../machine/timer.h ../filesys/synchdisk.h \
  ../threads/synch.h ../network/post.h ../machine/network.h \
  ../threads/synchlist.h
translate.o: ../machine/translate.cc ../threads/copyright.h \
  ../machine/machine.h ../threads/utility.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/stdint.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/__config \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/__config_site \
  /Library/Developer/CommandLineTools/usr/lib/clang/16/include/stdint.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stdint.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int8_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int16_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int32_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int64_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint8_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint16_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint32_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint64_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/cdefs.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_symbol_aliasing.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_posix_availability.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/arm/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_pthread/_pthread_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_intptr_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_uintptr_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_intmax_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uintmax_t.h \
  ../machine/sysdep.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/Availability.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/AvailabilityVersions.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/AvailabilityInternal.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/AvailabilityInternalLegacy.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_va_list.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/arm/types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int8_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int16_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int32_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int64_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_size_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_null.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_printf.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_seek_set.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_ctermid.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_off_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_ssize_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/string.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/string.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_string.h \
  ../machine/translate.h ../machine/disk.h ../userprog/addrspace.h \
  ../filesys/filesys.h ../filesys/openfile.h ../threads/system.h \
  ../threads/thread.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/ucontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/ucontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/_mcontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/arm/_mcontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/appleapiopts.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/mach/machine/_structs.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/mach/arm/_structs.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_ucontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_sigaltstack.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_sigset_t.h \
  ../threads/scheduler.h ../threads/list.h ../machine/interrupt.h \
  ../machine/stats.h ../machine/timer.h ../filesys/synchdisk.h \
  ../threads/synch.h ../network/post.h ../machine/network.h \
  ../threads/synchlist.h
directory.o: ../filesys/directory.cc ../threads/copyright.h \
  ../threads/utility.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/stdint.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/__config \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/__config_site \
  /Library/Developer/CommandLineTools/usr/lib/clang/16/include/stdint.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stdint.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int8_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int16_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int32_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int64_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint8_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint16_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint32_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint64_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/cdefs.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_symbol_aliasing.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_posix_availability.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/arm/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_pthread/_pthread_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_intptr_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_uintptr_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_intmax_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uintmax_t.h \
  ../machine/sysdep.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/Availability.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/AvailabilityVersions.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/AvailabilityInternal.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/AvailabilityInternalLegacy.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_va_list.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/arm/types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int8_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int16_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int32_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int64_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_size_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_null.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_printf.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_seek_set.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_ctermid.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_off_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_ssize_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/string.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/string.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_string.h \
  ../filesys/filehdr.h ../machine/disk.h ../userprog/bitmap.h \
  ../filesys/openfile.h ../filesys/directory.h
filehdr.o: ../filesys/filehdr.cc ../threads/copyright.h \
  ../threads/system.h ../threads/utility.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/stdint.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/__config \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/__config_site \
  /Library/Developer/CommandLineTools/usr/lib/clang/16/include/stdint.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stdint.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int8_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int16_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int32_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int64_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint8_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint16_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint32_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint64_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/cdefs.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_symbol_aliasing.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_posix_availability.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/arm/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_pthread/_pthread_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_intptr_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_uintptr_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_intmax_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uintmax_t.h \
  ../machine/sysdep.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/Availability.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/AvailabilityVersions.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/AvailabilityInternal.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/AvailabilityInternalLegacy.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_va_list.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/arm/types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int8_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int16_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int32_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int64_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_size_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_null.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_printf.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_seek_set.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_ctermid.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_off_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_ssize_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/string.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/string.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_string.h \
  ../threads/thread.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/ucontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/ucontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/_mcontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/arm/_mcontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/appleapiopts.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/mach/machine/_structs.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/mach/arm/_structs.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_ucontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_sigaltstack.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_sigset_t.h \
  ../machine/machine.h ../machine/translate.h ../machine/disk.h \
  ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h \
  ../threads/scheduler.h ../threads/list.h ../machine/interrupt.h \
  ../machine/stats.h ../machine/timer.h ../filesys/synchdisk.h \
  ../threads/synch.h ../network/post.h ../machine/network.h \
  ../threads/synchlist.h ../filesys/filehdr.h ../userprog/bitmap.h
filesys.o: ../filesys/filesys.cc ../threads/copyright.h ../machine/disk.h \
  ../threads/utility.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/stdint.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/__config \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/__config_site \
  /Library/Developer/CommandLineTools/usr/lib/clang/16/include/stdint.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stdint.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int8_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int16_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int32_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int64_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint8_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint16_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint32_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint64_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/cdefs.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_symbol_aliasing.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_posix_availability.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/arm/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_pthread/_pthread_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_intptr_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_uintptr_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_intmax_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uintmax_t.h \
  ../machine/sysdep.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/Availability.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/AvailabilityVersions.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/AvailabilityInternal.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/AvailabilityInternalLegacy.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_va_list.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/arm/types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int8_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int16_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int32_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int64_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_size_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_null.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_printf.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_seek_set.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_ctermid.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_off_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_ssize_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/string.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/string.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_string.h \
  ../userprog/bitmap.h ../filesys/openfile.h ../filesys/directory.h \
  ../filesys/filehdr.h ../filesys/filesys.h
fstest.o: ../filesys/fstest.cc ../threads/copyright.h \
  ../threads/utility.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/stdint.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/__config \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/__config_site \
  /Library/Developer/CommandLineTools/usr/lib/clang/16/include/stdint.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stdint.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int8_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int16_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int32_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int64_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint8_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint16_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint32_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint64_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/cdefs.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_symbol_aliasing.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_posix_availability.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/arm/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_pthread/_pthread_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_intptr_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_uintptr_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_intmax_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uintmax_t.h \
  ../machine/sysdep.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/Availability.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/AvailabilityVersions.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/AvailabilityInternal.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/AvailabilityInternalLegacy.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_va_list.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/arm/types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int8_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int16_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int32_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int64_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_size_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_null.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_printf.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_seek_set.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_ctermid.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_off_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_ssize_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/string.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/string.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_string.h \
  ../filesys/filesys.h ../filesys/openfile.h ../threads/system.h \
  ../threads/thread.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/ucontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/ucontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/_mcontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/arm/_mcontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/appleapiopts.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/mach/machine/_structs.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/mach/arm/_structs.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_ucontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_sigaltstack.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_sigset_t.h \
  ../machine/machine.h ../machine/translate.h ../machine/disk.h \
  ../userprog/addrspace.h ../threads/scheduler.h ../threads/list.h \
  ../machine/interrupt.h ../machine/stats.h ../machine/timer.h \
  ../filesys/synchdisk.h ../threads/synch.h ../network/post.h \
  ../machine/network.h ../threads/synchlist.h
openfile.o: ../filesys/openfile.cc ../threads/copyright.h \
  ../filesys/filehdr.h ../machine/disk.h ../threads/utility.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/stdint.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/__config \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/__config_site \
  /Library/Developer/CommandLineTools/usr/lib/clang/16/include/stdint.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stdint.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int8_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int16_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int32_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int64_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint8_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint16_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint32_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint64_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/cdefs.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_symbol_aliasing.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_posix_availability.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/arm/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_pthread/_pthread_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_intptr_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_uintptr_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_intmax_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uintmax_t.h \
  ../machine/sysdep.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/Availability.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/AvailabilityVersions.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/AvailabilityInternal.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/AvailabilityInternalLegacy.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_va_list.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/arm/types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int8_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int16_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int32_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int64_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_size_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_null.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_printf.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_seek_set.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_ctermid.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_off_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_ssize_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/string.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/string.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_string.h \
  ../userprog/bitmap.h ../filesys/openfile.h ../threads/system.h \
  ../threads/thread.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/ucontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/ucontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/_mcontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/arm/_mcontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/appleapiopts.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/mach/machine/_structs.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/mach/arm/_structs.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_ucontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_sigaltstack.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_sigset_t.h \
  ../machine/machine.h ../machine/translate.h ../userprog/addrspace.h \
  ../filesys/filesys.h ../threads/scheduler.h ../threads/list.h \
  ../machine/interrupt.h ../machine/stats.h ../machine/timer.h \
  ../filesys/synchdisk.h ../threads/synch.h ../network/post.h \
  ../machine/network.h ../threads/synchlist.h
synchdisk.o: ../filesys/synchdisk.cc ../threads/copyright.h \
  ../filesys/synchdisk.h ../machine/disk.h ../threads/utility.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/stdint.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/__config \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/__config_site \
  /Library/Developer/CommandLineTools/usr/lib/clang/16/include/stdint.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stdint.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int8_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int16_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int32_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int64_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint8_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint16_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint32_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint64_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/cdefs.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_symbol_aliasing.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_posix_availability.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/arm/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_pthread/_pthread_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_intptr_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_uintptr_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_intmax_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uintmax_t.h \
  ../machine/sysdep.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/Availability.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/AvailabilityVersions.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/AvailabilityInternal.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/AvailabilityInternalLegacy.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_va_list.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/arm/types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int8_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int16_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int32_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int64_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_size_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_null.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_printf.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_seek_set.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_ctermid.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_off_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_ssize_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/string.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/string.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_string.h \
  ../threads/synch.h ../threads/thread.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/ucontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/ucontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/_mcontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/arm/_mcontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/appleapiopts.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/mach/machine/_structs.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/mach/arm/_structs.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_ucontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_sigaltstack.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_sigset_t.h \
  ../machine/machine.h ../machine/translate.h ../userprog/addrspace.h \
  ../filesys/filesys.h ../filesys/openfile.h ../threads/list.h
disk.o: ../machine/disk.cc ../threads/copyright.h ../machine/disk.h \
  ../threads/utility.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/stdint.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/__config \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/__config_site \
  /Library/Developer/CommandLineTools/usr/lib/clang/16/include/stdint.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stdint.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int8_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int16_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int32_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int64_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint8_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint16_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint32_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint64_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/cdefs.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_symbol_aliasing.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_posix_availability.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/arm/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_pthread/_pthread_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_intptr_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_uintptr_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_intmax_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uintmax_t.h \
  ../machine/sysdep.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/Availability.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/AvailabilityVersions.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/AvailabilityInternal.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/AvailabilityInternalLegacy.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_va_list.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/arm/types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int8_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int16_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int32_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int64_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_size_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_null.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_printf.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_seek_set.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_ctermid.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_off_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_ssize_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/string.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/string.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_string.h \
  ../threads/system.h ../threads/thread.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/ucontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/ucontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/_mcontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/arm/_mcontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/appleapiopts.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/mach/machine/_structs.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/mach/arm/_structs.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_ucontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_sigaltstack.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_sigset_t.h \
  ../machine/machine.h ../machine/translate.h ../userprog/addrspace.h \
  ../filesys/filesys.h ../filesys/openfile.h ../threads/scheduler.h \
  ../threads/list.h ../machine/interrupt.h ../machine/stats.h \
  ../machine/timer.h ../filesys/synchdisk.h ../threads/synch.h \
  ../network/post.h ../machine/network.h ../threads/synchlist.h
nettest.o: ../network/nettest.cc ../threads/copyright.h \
  ../threads/system.h ../threads/utility.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/stdint.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/__config \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/__config_site \
  /Library/Developer/CommandLineTools/usr/lib/clang/16/include/stdint.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stdint.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int8_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int16_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int32_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int64_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint8_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint16_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint32_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint64_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/cdefs.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_symbol_aliasing.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_posix_availability.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/arm/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_pthread/_pthread_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_intptr_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_uintptr_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_intmax_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uintmax_t.h \
  ../machine/sysdep.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/Availability.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/AvailabilityVersions.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/AvailabilityInternal.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/AvailabilityInternalLegacy.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_va_list.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/arm/types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int8_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int16_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int32_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int64_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_size_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_null.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_printf.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_seek_set.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_ctermid.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_off_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_ssize_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/string.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/string.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_string.h \
  ../threads/thread.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/ucontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/ucontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/_mcontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/arm/_mcontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/appleapiopts.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/mach/machine/_structs.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/mach/arm/_structs.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_ucontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_sigaltstack.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_sigset_t.h \
  ../machine/machine.h ../machine/translate.h ../machine/disk.h \
  ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h \
  ../threads/scheduler.h ../threads/list.h ../machine/interrupt.h \
  ../machine/stats.h ../machine/timer.h ../filesys/synchdisk.h \
  ../threads/synch.h ../network/post.h ../machine/network.h \
  ../threads/synchlist.h
post.o: ../network/post.cc ../threads/copyright.h ../network/post.h \
  ../machine/network.h ../threads/utility.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/stdint.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/__config \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/__config_site \
  /Library/Developer/CommandLineTools/usr/lib/clang/16/include/stdint.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stdint.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int8_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int16_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int32_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int64_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint8_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint16_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint32_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint64_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/cdefs.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_symbol_aliasing.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_posix_availability.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/arm/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_pthread/_pthread_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_intptr_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_uintptr_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_intmax_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uintmax_t.h \
  ../machine/sysdep.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/Availability.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/AvailabilityVersions.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/AvailabilityInternal.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/AvailabilityInternalLegacy.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_va_list.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/arm/types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int8_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int16_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int32_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int64_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_size_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_null.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_printf.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_seek_set.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_ctermid.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_off_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_ssize_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/string.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/string.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_string.h \
  ../threads/synchlist.h ../threads/list.h ../threads/synch.h \
  ../threads/thread.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/ucontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/ucontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/_mcontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/arm/_mcontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/appleapiopts.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/mach/machine/_structs.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/mach/arm/_structs.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_ucontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_sigaltstack.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_sigset_t.h \
  ../machine/machine.h ../machine/translate.h ../machine/disk.h \
  ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h
network.o: ../machine/network.cc ../threads/copyright.h \
  ../threads/system.h ../threads/utility.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/stdint.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/__config \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/__config_site \
  /Library/Developer/CommandLineTools/usr/lib/clang/16/include/stdint.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stdint.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int8_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int16_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int32_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int64_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint8_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint16_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint32_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint64_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/cdefs.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_symbol_aliasing.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_posix_availability.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/arm/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_pthread/_pthread_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_intptr_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_uintptr_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_intmax_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uintmax_t.h \
  ../machine/sysdep.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/Availability.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/AvailabilityVersions.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/AvailabilityInternal.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/AvailabilityInternalLegacy.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_va_list.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/arm/types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int8_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int16_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int32_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int64_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_size_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_null.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_printf.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_seek_set.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_ctermid.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_off_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_ssize_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/string.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/string.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_string.h \
  ../threads/thread.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/ucontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/ucontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/_mcontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/arm/_mcontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/appleapiopts.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/mach/machine/_structs.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/mach/arm/_structs.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_ucontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_sigaltstack.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_sigset_t.h \
  ../machine/machine.h ../machine/translate.h ../machine/disk.h \
  ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h \
  ../threads/scheduler.h ../threads/list.h ../machine/interrupt.h \
  ../machine/stats.h ../machine/timer.h ../filesys/synchdisk.h \
  ../threads/synch.h ../network/post.h ../machine/network.h \
  ../threads/synchlist.h
# DEPENDENCIES MUST END AT END OF FILE
# IF YOU PUT STUFF HERE IT WILL GO AWAY
# see make depend above
