#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <errno.h>
#include <time.h>

#include <arpa/inet.h>

//test ip ÁöÁ¤
#define MULTI_ADDR  "224.1.1.1"
#define SPORT       41000

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
char buff[1024], tmp[20];

	pname = argv[0];
	if(argc != 5){
		fprintf(stderr, "%s <multicasting group> <port> <cnt> <usleep>\n", pname);
		exit(0);
	}
	sfd = OpenInetMultiClient(&addr, atoi(argv[2]), argv[1], 64);
	if(sfd < 0) {
		printf("## OpenInetMultiClient CREATE Error!!\n");
		exit(0);
	}

	cnt = atoi(argv[3]);
	memset(buff, 0x00, 1024);
	memset(buff, 'M', 500);

	for(i = 0; i < cnt; i++){
		sprintf(tmp, "INDEX[%8d]", i);
		strncpy(buff, tmp, strlen(tmp));
		rtn=sendto(sfd, buff, strlen(buff), 0, (struct sockaddr *)&addr, sizeof(struct sockaddr));
		printf("INDEX[%8d] rtn[%d]\n", i, rtn);
		usleep(atoi(argv[4]));
	}
	printf("----------------------- sleep(10)\n");
	sleep(1);
	close(sfd);
}
