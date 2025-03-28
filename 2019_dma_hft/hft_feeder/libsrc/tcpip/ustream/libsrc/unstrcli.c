/***********************************************************************/
/* UNIX Family Stream socket LIB. (CLIENT)                             */
/* NAME    : unstrcli.c                                                */
/* CREATE  : 1996.12.10.                                               */
/* REMARKS :                                                           */
/***********************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <errno.h>

#define MAX_BUFF_LEN 4096

int OpenUnixStreamClient(unistr_path)
char *unistr_path;
{
struct sockaddr_un  serv_addr;
int                 sockfd, buflen, on=1;
int                 sverlen;

	memset(&serv_addr,NULL,sizeof(serv_addr));
	serv_addr.sun_family        = AF_UNIX;
	strcpy(serv_addr.sun_path,unistr_path);

	sverlen = strlen(serv_addr.sun_path) + sizeof(serv_addr.sun_family);

   	if((sockfd=socket(AF_UNIX,SOCK_STREAM,0)) < 0)
	{
		fprintf(stderr,"Can't Create CLIENT stream socket\n");
		return (-1); 
	}

	buflen = MAX_BUFF_LEN;
	setsockopt(sockfd, SOL_SOCKET, SO_RCVBUF, (char *)&buflen, sizeof(buflen));
	setsockopt(sockfd, SOL_SOCKET, SO_SNDBUF, (char *)&buflen, sizeof(buflen));
	setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, (char *)&on, sizeof(on));
	setsockopt(sockfd, SOL_SOCKET, SO_KEEPALIVE, (char *)&on, sizeof(on));

	if(connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0)
	{
		fprintf(stderr,"SERVER Unix Stream socket Connect Error\n");
		close(sockfd);
		return (-2);
	}

	return (sockfd);
}
