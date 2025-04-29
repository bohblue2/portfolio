LD_HOME     = $(HOME)
INCDIR	    = $(LD_HOME)/include
include  $(INCDIR)/Make.defines

#user define
LIBS            = libdatterm.a
OBJS            = delaymode.o termclear.o termgetsd.o termnoecho.o termsetup.o termval.o winsize.o

all : $(LIBS)

$(LIBS) : $(OBJS)
	$(AR) $(ARFLAGS) $(LIB_DIR)/$(LIBS) $(OBJS)
	rm -f *.o

clean :
	rm -f *.o core
