/***********************************************************************/
/* UNIX Stream Socket Accept                                           */
/* NAME    : unaccept.c                                                */
/* CREATE  : 1996.12.10.                                               */
/* REMARKS :                                                           */
/***********************************************************************/
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>

int UnStrAccept(sfd)
int sfd;
{
int                newsfd, clilen;
struct sockaddr_un cli_addr;

	clilen = sizeof(cli_addr);

	newsfd = accept(sfd,(struct sockaddr *)&cli_addr,&clilen);
	if(newsfd < 0)
	{
		fprintf(stderr,"UnStrAccept Error\n");
		return(-1);
	}
	return (newsfd);
}
