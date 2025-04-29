/***********************************************************************/
/* INET Family UDP Server.                                             */
/* NAME    : tsvr.c                                                    */
/* CREATE  : 2002.10.16.                                               */
/* REMARKS :                                                           */
/***********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define  TEST_PORT 33199

/***********************************************************************/
/***********************************************************************/
int DataProc(fd)
int  fd;
{
struct timeval tout;
fd_set  sock, readable;
int     maxfd;
int     n, sz, addr_len;
char    buff[1024], addr[16];
struct sockaddr_in cli;

	FD_ZERO(&sock);
	FD_SET(fd, &sock);
	maxfd = fd;

	while(1) {
		tout.tv_sec = 30;
		tout.tv_usec = 0;
		readable = sock;
		n = select(maxfd + 1, &readable, NULL, NULL, &tout);
		if(n < 0) fprintf(stderr, "SELECT ERROR\n");
		else {
			if(n == 0) {
				printf("TIME OUT 30sec FD[%d]\n", fd);
				continue;
			}
			if(FD_ISSET(fd, &readable)) {
				memset(buff, 0x00, sizeof(buff));
				memset(addr, 0x00, sizeof(addr));

				/* [1] */
				addr_len = sizeof(struct sockaddr);
				sz = recvfrom(fd, buff, sizeof(buff), 0, (struct sockaddr *)&cli, &addr_len);
				Convert2StrAddr(cli.sin_addr.s_addr, addr);
				printf("--READ FD[%d] FROM[%s]DATA[%s]\n",fd, addr, buff);

				/* [2] */
				//sz = ReadUdp(fd, buff, sizeof(buff));
				//if(sz<0) {
				//	printf("ReadUdp Error!! FD[%d]\n", fd);
				//}
				//printf("--READ FD[%d] DATA[%s]\n",fd, buff);
			}
		}
	}
}


/***********************************************************************/
/***********************************************************************/
main(argc, argv)
int   argc;
char **argv;
{
int    sfd, sz, port;
char  *pname;
char   buff[1024];

	pname = argv[0];

	sfd = OpenInetUdpServer(TEST_PORT);
	if(sfd < 0){
		fprintf(stderr, "FAIL RETURNED CODE [%d] prot[%d]\n", sfd, argv[1]);
		exit(1);
	}

	printf("OpenInetUdpServer OK socket fd[%d] port[%d] PID[%d]\n", sfd, TEST_PORT, getpid());

	DataProc(sfd);

	close(sfd);
}
