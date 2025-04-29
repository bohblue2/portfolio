#################################
# Author : Kiseung Koo		#
# Name   : Prg idgram Makefile 	#
# Date   : 2002-10-16		#
#################################

LD_HOME         = $(HOME)

CC		= gcc -m32

INCLUDE         = -I$(LD_HOME)/include
LIB_PATH        = -L$(LD_HOME)/lib

CFLAGS          = -g -c $(INCLUDE)

LIBS            = -lsanet

.SUFFIXES       : .c .o

.c.o            :
	$(CC) $(CFLAGS) $*.c

all::tcli tsvr

tcli        : tcli.o
	$(CC) -o $@ $@.o $(LIB_PATH) $(LIBS)

tsvr        : tsvr.o
	$(CC) -o $@ $@.o $(LIB_PATH) $(LIBS)

clean           :
	 rm -f *.o core tsvr tcli
