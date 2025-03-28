LD_HOME         = $(HOME)
USER_HOME         = /usr

SYSTEM_INCL     =
COMMON_INCL     = -I$(LD_HOME)/include
LOCAL_INCL      = -I$(USER_HOME)/include
INCLUDE         = $(LOCAL_INCL) $(COMMON_INCL) $(SYSTEM_INCL)

SYSTEM_LIB_PATH =
COMMON_LIB_PATH = -L$(LD_HOME)/lib
LOCAL_LIBPATH   =
LIB_PATH        = $(SYSTEM_LIB_PATH) $(COMMON_LIB_PATH) $(LOCAL_LIB_PATH)

CC		= gcc -m32
CFLAGS          = -g -c $(INCLUDE)

SYSTEM_LIBS     =
RDB_LIBS        =
COMMON_LIBS     =
LOCAL_LIBS      = -levent -lsanet 
LIBS            = $(LOCAL_LIBS) $(COMMON_LIBS) $(RDB_LIBS) $(SYSTEM_LIBS)

.SUFFIXES       : .c .o .cp

.c.o            :
	$(CC) $(CFLAGS) $*.c

all:tusvr tucli

tusvr : tusvr.o
	$(CC) -o $@ $@.o $(LIB_PATH) $(LIBS)

tucli : tucli.o
	$(CC) -o $@ $@.o $(LIB_PATH) $(LIBS)

clean           :
	 rm -f *.o core tusvr tucli
