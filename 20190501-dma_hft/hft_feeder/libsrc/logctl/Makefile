LD_HOME     = $(HOME)
INCDIR      = $(LD_HOME)/include
include  $(INCDIR)/Make.defines

#user define */
LIBS            = libdatlog.a
OBJS            = logctl.o

all : lib

lib : $(OBJS)
	$(AR) $(ARFLAGS) $(LIB_DIR)/$(LIBS) $(OBJS)

clean :
	 rm -f *.o core
