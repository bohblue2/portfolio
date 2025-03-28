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
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY); // INADDR_ANY[0] : 자신의 주소를 컴퓨터가 찾아준다.
	serv_addr.sin_port        = htons(port);

   	if((sockfd=socket(AF_INET,SOCK_STREAM,0)) <0) { // SOCK_STREAM : stream socket
		fprintf(stderr,"Can't Create SERVER stream socket:PORT[%d]\n", port);
		return -3001;
	}

	buflen = MAX_BUFF_LEN;
	setsockopt(sockfd, SOL_SOCKET, SO_RCVBUF, (char *)&buflen, sizeof(buflen));	// 수신 버퍼의 크기 변경 : 데이터를 수신하기 위한 총 버퍼공간을 명시합니다. SO_MAX_MSG_SIZE나 TCP Window의 크기와 상관이 없습니다.
	setsockopt(sockfd, SOL_SOCKET, SO_SNDBUF, (char *)&buflen, sizeof(buflen));	// 송신 버퍼의 크기 변경 : 데이터를 수신하기 위한 총 버퍼공간을 명시합니다. SO_MAX_MSG_SIZE나 TCP Window의 크기와 상관이 없습니다.
	setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, (char *)&on, sizeof(on));		// 주소의 재사용 선택 : 이미 사용되고 있는 어드레스를 바인드 할 수 있도록 합니다.
	setsockopt(sockfd, SOL_SOCKET, SO_KEEPALIVE, (char *)&on, sizeof(on));		// TCP의 연결유지 확인모드로 동작 : 

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
