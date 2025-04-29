/***********************************************************************/
/* Stream socket LIB. (SERVER&CLIENT)                                  */
/* NAME    : kpalive.c                                                 */
/* CREATE  : 1997.01.14.                                               */
/* REMARKS :                                                           */
/***********************************************************************/
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <errno.h>

#define MAX_BUFF_LEN 4096

void SetSocketOption(fd)
int fd;
{
int on = 1, buflen;
	buflen = MAX_BUFF_LEN;
	setsockopt(fd, SOL_SOCKET, SO_RCVBUF, (char *)&buflen, sizeof(buflen));
	setsockopt(fd, SOL_SOCKET, SO_SNDBUF, (char *)&buflen, sizeof(buflen));
	setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, (char *)&on, sizeof(on));
	setsockopt(fd, SOL_SOCKET, SO_KEEPALIVE, (char *)&on, sizeof(on));
}
