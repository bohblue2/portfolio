LD_HOME    = $(HOME)/DAT
CC         = gcc -m32 
PROC       =
SUBDIRS    =
LIBPATH    = $(LD_HOME)/lib
INCLUDE    = $(LD_HOME)/include
CFLAGS     = -g -c -I$(INCLUDE)
PROCFLAGS  =

.SUFFIXES:.c .o .pc
.c.o:
	$(CC) $(CFLAGS) $*.c
.c.pc:
	$(PROC) $(PROCFLAGS) iname=$*.pc include=$(INCLUDE)

LIBOBJS    =
LIBNAME    =

LD_LIBS    = -L$(LIBPATH) -ldatevent

EXECS      = event_main

all::$(EXECS)

event_main : event_main.o
	$(CC) -o $@ $@.o  $(LD_LIBS)

clean :
	rm -f *.o core a.out Makefile.old
