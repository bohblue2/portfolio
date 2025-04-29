/***********************************************************************/
/* INET Family UDP Client.                                             */
/* NAME    : iudpsvr.c                                                 */
/* CREATE  : 2002.10.16.                                               */
/* REMARKS :                                                           */
/***********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <sys/socket.h>

/***********************************************************************/
/***********************************************************************/
main(argc, argv)
int   argc;
char **argv;
{
int    sfd;
int    i = 0, rtn;
char   buff[1024];

	if(argc < 2){
		fprintf(stderr, "%s <message>\n", argv[0]);
		fprintf(stderr, "%s sendmessages...\n", argv[0]);
		exit(0);
	}

	sfd = OpenInetUdpClient();
	if(sfd < 0) {
		fprintf(stderr, "FAIL RETURNED CODE [%d]\n", sfd);
		exit(1);
	}
	
	printf("OpenInetUdpClient OK socket fd[%d] PID[%d]\n", sfd, getpid());
	sleep(1);

	while(i < 5) {
		sprintf(buff, "%03d:%s", i, argv[1]);
		/**********************************
		rtn = SendInetUdpToSvr(sfd, argv[2], argv[1], buff, strlen(buff));
		rtn = WriteUdp(sfd, argv[2], argv[1], buff, strlen(buff));
		**********************************/
		//rtn = SendInetUdpToSvr(sfd, "BCAST", "kskoo", buff, strlen(buff)); // UDP or Broadcasting..
		rtn = WriteUdp(sfd, "fnreal1", "kskoo", buff, strlen(buff)); // UDP..
		if(rtn < 0) {
			printf("## udp 전송 실패  [%d]\n", rtn);
			continue;
		}
		printf("SEND [%d][%s]\n ", i, buff);
		i++;
		if(!(i%30))sleep(1);
	}

	close(sfd);
}
