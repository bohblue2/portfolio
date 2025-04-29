LD_HOME     = $(HOME)
INCDIR	    = $(LD_HOME)/include
include  $(INCDIR)/Make.defines

#user define
LIBS            = libdatmdb.a
OBJS            = mdb.o

all : $(LIBS)

$(LIBS) : $(OBJS)
	rm -f $(LIB_DIR)/$(LIBS)
	$(AR) $(ARFLAGS) $(LIB_DIR)/$(LIBS) $(OBJS)
	rm -f *.o core

clean :
	rm -f *.o core
