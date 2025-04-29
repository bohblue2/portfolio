LD_HOME     = $(HOME)
INCDIR	    = $(LD_HOME)/include
include  $(INCDIR)/Make.defines

#user define
LIBS            = libdatspy.a
OBJS            = debug.o 

all : $(LIBS)

$(LIBS) : $(OBJS)
	$(AR) $(ARFLAGS) $(LIB_DIR)/$(LIBS) $(OBJS)
	rm -f *.o

clean :
	rm -f *.o core
