/***********************************************************************/
/* Wait connect from client                                            */
/* NAME    : waitreq.c                                                 */
/* CREATE  : 1996.10.31.                                               */
/* BY      : Penta_soft     Co,Ltd. (Sagittarius)                      */
/* REMARKS :                                                           */
/***********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <errno.h>

extern int errno;

/******************************************************************************/
/* Wait Client Connection                                                     */
/* Prototype : int WaitConnect(fd, buff)                                      */
/* Arguments : int   fd; int socket discriptor                                */
/*             char *buff; Client address buffer                              */
/* Return    : new socket fd                                                  */
/******************************************************************************/
int WaitConnect(fd, buff)
int fd;
char *buff;
{
int                newfd;
socklen_t	   clilen;
struct sockaddr_in cli_addr;
unsigned char     *p;

	clilen = sizeof(cli_addr);

	newfd=accept(fd,(struct sockaddr *)&cli_addr, &clilen);
	if(!buff) return newfd;

	p = (unsigned char *)&cli_addr.sin_addr;
	sprintf(buff, "%3d.%3d.%3d.%3d", *p, *(p+1), *(p+2), *(p+3));

	return newfd;
}
