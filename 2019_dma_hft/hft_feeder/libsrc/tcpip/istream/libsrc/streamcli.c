/***********************************************************************/
/* INET Family Stream socket LIB. (CLIENT)                             */
/* NAME    : streamcli.c                                               */
/* CREATE  : 1995.10.30.                                               */
/* REMARKS :                                                           */
/***********************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX_BUFF_LEN    4096

/******************************************************************************/
/* Open Ineternet Stream Client                                               */
/* Prototype  : int OpenInetStreamClient(host, port)                          */
/* Arguments  : char *host; int port;                                         */
/* Return     : int    sockfd;                                                */
/******************************************************************************/
int OpenInetStreamClient(host, port)
char    *host;
int      port;
{
int                 sockfd, buflen, on = 1;
struct sockaddr_in  serv_addr;
struct hostent     *hp;

	hp = gethostbyname(host); /* get the host info */
	if(!hp) return -1;

	bzero(&serv_addr, sizeof(serv_addr));
	serv_addr.sin_family        = AF_INET;
	serv_addr.sin_addr.s_addr   = ((struct in_addr *)(hp->h_addr))->s_addr;
	serv_addr.sin_port          = htons(port);

   	if((sockfd=socket(AF_INET,SOCK_STREAM,0)) <0) {
		fprintf(stderr,"Can't Create CLIENT stream socket:PORT[%d]\n", port);
		return -3001;
	}

	if(connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) <0){
		fprintf(stderr,"CLIENT Internet Stream socket Connect Error\n");
		close(sockfd);
		return -3003;
	}

	buflen = MAX_BUFF_LEN;
	setsockopt(sockfd, SOL_SOCKET, SO_RCVBUF, (char *)&buflen, sizeof(buflen));
	setsockopt(sockfd, SOL_SOCKET, SO_SNDBUF, (char *)&buflen, sizeof(buflen));
	setsockopt(sockfd, SOL_SOCKET, SO_KEEPALIVE, (char *)&on, sizeof(on));

	return sockfd;
}
