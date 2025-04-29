LD_HOME     = $(HOME)
INCDIR      = $(LD_HOME)/include
include  $(INCDIR)/Make.defines

#user define
LIBS = libdatnet.a
OBJS = getmyaddr.o  readst.o  readstt.o  setdelay.o  streamcli.o  streamsvr.o  waitreq.o  writest.o  writestt.o

all : $(LIBS)

$(LIBS) : $(OBJS)
	$(AR) $(ARFLAGS) $(LIB_DIR)/$(LIBS) $(OBJS)
	rm -f *.o

clean :
	rm -f *.o core
         
