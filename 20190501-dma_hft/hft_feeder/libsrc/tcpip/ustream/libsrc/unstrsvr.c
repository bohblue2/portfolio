/***********************************************************************/
/* UNIX Family Stream socket LIB. (SERVER)                             */
/* NAME    : unstrsvr.c                                                */
/* CREATE  : 1996.12.10.                                               */
/* REMARKS :                                                           */
/***********************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <errno.h>

#define MAX_BUFF_LEN 4096

int OpenUnixStreamServer(unistr_path)
char *unistr_path;
{
int                 sockfd;
int                 servlen, buflen, on=1;
struct sockaddr_un  serv_addr;

	memset(&serv_addr, NULL, sizeof(serv_addr));
	serv_addr.sun_family        = AF_UNIX;
	strcpy(serv_addr.sun_path,unistr_path);

	servlen = strlen(serv_addr.sun_path) + sizeof(serv_addr.sun_family);

   	if((sockfd=socket(AF_UNIX,SOCK_STREAM,0)) < 0)
	{
		fprintf(stderr,"Can't Create SERVER stream socket\n"); 
		return (-1);
	}

	buflen = MAX_BUFF_LEN;
	setsockopt(sockfd, SOL_SOCKET, SO_RCVBUF, (char *)&buflen, sizeof(buflen));
	setsockopt(sockfd, SOL_SOCKET, SO_SNDBUF, (char *)&buflen, sizeof(buflen));
	setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, (char *)&on, sizeof(on));
	setsockopt(sockfd, SOL_SOCKET, SO_KEEPALIVE, (char *)&on, sizeof(on));

	if(bind(sockfd,(struct sockaddr *)&serv_addr,servlen) < 0)
	{
		unlink(unistr_path);
		if(bind(sockfd,(struct sockaddr *)&serv_addr,servlen) < 0)
		{
			fprintf(stderr,"SERVER Unix Stream socket Bind Error\n");
			close(sockfd);
			return(-2);
		}		
	}

	listen(sockfd,10);

	return(sockfd);
}
