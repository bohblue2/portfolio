LD_HOME     = $(HOME)
INCDIR	    = $(LD_HOME)/include
include  $(INCDIR)/Make.defines

#user define
LIBS            = libdatthread.a
OBJS            = tpool.o

all : lib

lib : $(OBJS)
	rm -f $(LIB_DIR)/$(LIBS)
	$(AR) $(ARFLAGS) $(LIB_DIR)/$(LIBS) $(OBJS)
	rm -f *.o core

clean :
	rm -f *.o core
