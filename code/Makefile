# Copyright (c) 1992 The Regents of the University of California.
# All rights reserved.  See copyright.h for copyright notice and limitation 
# of liability and disclaimer of warranty provisions.

MAKE ?= make
LPR = lpr

all: 
	$(MAKE) -C threads depend
	$(MAKE) -C threads nachos
	$(MAKE) -C userprog depend 
	$(MAKE) -C userprog nachos 
	$(MAKE) -C vm depend
	$(MAKE) -C vm nachos 
	$(MAKE) -C filesys depend
	$(MAKE) -C filesys nachos 
	$(MAKE) -C network depend
	$(MAKE) -C network nachos 
	$(MAKE) -C bin all

userprog-test:
	@if [ -n "$$(which mips-linux-gnu-gcc 2>/dev/null)" ]; then \
		$(MAKE) -C test all; \
	else \
		echo "Skipping MIPS user-program build: no MIPS cross-compiler is configured."; \
	fi

clean:
	rm -f */core */nachos */DISK */*.o */swtch.s */makedep */eddep
	rm -f test/*.coff bin/coff2flat bin/coff2noff bin/disassemble bin/out

print:
	/bin/csh -c "$(LPR) Makefile* */Makefile"
	/bin/csh -c "$(LPR) threads/*.h threads/*.cc threads/*.s"
	/bin/csh -c "$(LPR) userprog/*.h userprog/*.cc" 
	/bin/csh -c "$(LPR) filesys/*.h filesys/*.cc
	/bin/csh -c "$(LPR) network/*.h network/*.cc 
	/bin/csh -c "$(LPR) machine/*.h machine/*.cc
	/bin/csh -c "$(LPR) bin/noff.h bin/coff.h bin/coff2noff.c"
	/bin/csh -c "$(LPR) test/*.h test/*.c test/*.s"
