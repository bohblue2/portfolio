#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <errno.h>
#include <time.h>

#include <arpa/inet.h>
#include "event.h"

// test ip ÁöÁ¤
#define MULTI_ADDR  "224.1.1.1"
#define SPORT       41000

EVENT	*Event;
char *pname;

/*
./multircv 224.1.1.1 41000
./multisnd 224.1.1.1 41000 10 10     
*/
 
/*******************************************************************************
 MAIN FUNCTION
 *****************************************************************************/
main(argc, argv)
int argc;
char **argv;
{
int sfd, i, cnt, rtn;
struct sockaddr_in addr;
char buff[300], tmp[20];
FILE *fp;

	pname = argv[0];

	if(argc != 3){
		fprintf(stderr, "%s <multicasting group> <port>\n", pname);
		exit(0);
	}

	sfd = OpenInetMultiServer(atoi(argv[2]), argv[1]);
	if(sfd < 0) {
		printf("## OpenInetMultiServer CREATE Error!! [%d]\n", rtn);
		exit(0);
	}

    memset(buff, 0x00, 300);
	for(;;) {
		rtn=recvfrom(sfd, buff, 300, 0, (struct sockaddr *)NULL, (int  *)NULL);
		if(rtn > 0) {
    	    printf("RCV[%.*s]\n", rtn, buff);
        } else {
            printf("RCV ERROR[%.*s]\n", rtn, buff);
        }	
	}
}
