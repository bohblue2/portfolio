#####################################################################
LD_HOME     = $(HOME)
INCDIR      = $(LD_HOME)/include
include  $(INCDIR)/Make.defines

all : multisnd multircv

multisnd : multisnd.o
	$(CC) -o $@ $@.o $(LIB_PATH) $(ULIBS)

multircv : multircv.o
	$(CC) -o $@ $@.o $(LIB_PATH) $(ULIBS)

server : server.o
	$(CC) -o $@ $@.o $(LIB_PATH) $(ULIBS)

client : client.o
	$(CC) -o $@ $@.o $(LIB_PATH) $(ULIBS)

clean   :
	 rm -f *.o core multisnd multircv
