LD_HOME     = $(HOME)
INCDIR      = $(LD_HOME)/include
include  $(INCDIR)/Make.defines

#user define
LIBS            = libdatnet.a
OBJS            = rdudg.o  sndudg.o  udgramcli.o  udgramsvr.o

all : $(LIBS)

$(LIBS) : $(OBJS)
	$(AR) $(ARFLAGS) $(LIB_DIR)/$(LIBS) $(OBJS)
	rm -f *.o

clean :
	rm -f *.o core
         
