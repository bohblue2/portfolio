/***********************************************************************/
/* INET Family Stream socket LIB. (SERVER)                             */
/* NAME    : streamsvr.c                                               */
/* CREATE  : 1995.10.30.                                               */
/* REMARKS :                                                           */
/***********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/ioctl.h>
#include <netdb.h>

#define MAX_BUFF_LEN   4096
#define BACK_LOG       200  // listen function backlog argument..

/******************************************************************************/
/* Open Ineternet Stream Server                                               */
/* Prototype  : int OpenInetStreamServer(port)                                */
/* Arguments  : int      port;                                                */
/* Return     : int    sockfd;                                                */
/******************************************************************************/
int OpenInetStreamServer(port)
int      port;
{
int                sockfd, buflen, on = 1;
struct sockaddr_in serv_addr;

	bzero(&serv_addr, sizeof(serv_addr));
	serv_addr.sin_family      = AF_INET; // AF_INET : IPv4 protocols
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY); // INADDR_ANY[0] : �ڽ��� �ּҸ� ��ǻ�Ͱ� ã���ش�.
	serv_addr.sin_port        = htons(port);

   	if((sockfd=socket(AF_INET,SOCK_STREAM,0)) <0) { // SOCK_STREAM : stream socket
		fprintf(stderr,"Can't Create SERVER stream socket:PORT[%d]\n", port);
		return -3001;
	}

	buflen = MAX_BUFF_LEN;
	setsockopt(sockfd, SOL_SOCKET, SO_RCVBUF, (char *)&buflen, sizeof(buflen));	// ���� ������ ũ�� ���� : �����͸� �����ϱ� ���� �� ���۰����� ����մϴ�. SO_MAX_MSG_SIZE�� TCP Window�� ũ��� ����� �����ϴ�.
	setsockopt(sockfd, SOL_SOCKET, SO_SNDBUF, (char *)&buflen, sizeof(buflen));	// �۽� ������ ũ�� ���� : �����͸� �����ϱ� ���� �� ���۰����� ����մϴ�. SO_MAX_MSG_SIZE�� TCP Window�� ũ��� ����� �����ϴ�.
	setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, (char *)&on, sizeof(on));		// �ּ��� ���� ���� : �̹� ���ǰ� �ִ� ��巹���� ���ε� �� �� �ֵ��� �մϴ�.
	setsockopt(sockfd, SOL_SOCKET, SO_KEEPALIVE, (char *)&on, sizeof(on));		// TCP�� �������� Ȯ�θ��� ���� : 

	on = bind(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr));
	if(on < 0){
		fprintf(stderr,"SERVER Internet Stream socket Bind Error\n");
		close(sockfd);
		return -1;
	}

	listen(sockfd, BACK_LOG); // The second argument to this function specifies the maximum number of connection that the kernel should queue for this socket.
	// Linux allowed an unlimited number of connections for a backlog of 0, indicating a bug.

	return sockfd;
}
