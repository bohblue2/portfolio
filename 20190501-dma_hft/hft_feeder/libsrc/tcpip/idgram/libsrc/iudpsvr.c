/***********************************************************************/
/* INET Family UDP LIB.                                                */
/* NAME    : iudpsvr.c                                                 */
/* CREATE  : 2002.10.16.                                               */
/* REMARKS :                                                           */
/***********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define    MAX_BUFF_LEN  4096

/******************************************************************************/
/* Open Ineternet UDP Server                                                  */
/* Prototype  : int OpenInetUdpServer(port)                                   */
/* Arguments  : int    port;                                                  */
/* Return     : int    sfd;                                                   */
/******************************************************************************/
int OpenInetUdpServer(port)
int port;
{
int                 sfd, rtn, buflen;
struct sockaddr_in  myaddr;
struct servent     *sp;

	sfd = socket(AF_INET, SOCK_DGRAM, 0);
	if(sfd < 0) return -3001; /* -3001 */

	bzero(&myaddr, sizeof(myaddr));
	myaddr.sin_family      = AF_INET; // AF_INET : IPv4 protocols
	myaddr.sin_addr.s_addr = htonl(INADDR_ANY); // INADDR_ANY[0] : 자신의 주소를 컴퓨터가 찾아준다.
	myaddr.sin_port        = htons(port);

	buflen = MAX_BUFF_LEN;
	setsockopt(sfd, SOL_SOCKET, SO_RCVBUF, (char *)&buflen, sizeof(buflen));
	setsockopt(sfd, SOL_SOCKET, SO_SNDBUF, (char *)&buflen, sizeof(buflen));

	rtn = bind(sfd, (struct sockaddr *)&myaddr, sizeof(struct sockaddr));
	if(rtn < 0) {
		fprintf(stderr,"SERVER Internet UDP socket Bind Error\n");
		close(sfd);
		return -3002;
	}

	return sfd;
}
