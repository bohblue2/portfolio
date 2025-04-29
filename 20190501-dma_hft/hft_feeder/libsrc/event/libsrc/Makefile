LD_HOME     = $(HOME)
INCDIR	    = $(LD_HOME)/include
include  $(INCDIR)/Make.defines

#user define
LIBS            = libdatevent.a
OBJS            = event.o

all : lib

lib : $(OBJS)
	$(AR) $(ARFLAGS) $(LIB_DIR)/$(LIBS) $(OBJS)

clean :
	rm -f *.o core
