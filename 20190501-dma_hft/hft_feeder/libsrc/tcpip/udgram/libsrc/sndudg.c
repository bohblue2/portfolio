/***********************************************************************/
/* Send data to UNIX DGRAM                                             */
/* NAME    : sndudg.c                                                  */
/* CREATE  : 2002.10.16.                                               */
/* REMARKS :                                                           */
/***********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#ifdef _SUN_
#include <errno.h>
#else
#include <sys/errno.h>
#endif

/******************************************************************************/
/* Send data to UNIX DGRAM SOCKET                                             */
/* Prototype : int SendUnixDgram(fd, data, len)                               */
/* Argument  : int fd; Socket fd                                              */
/*             char *data; Send data                                          */
/*             int   len; Data length                                         */
/* Return    : >0 : Sended length, < 0 : FAIL (errno * -1)                    */
/******************************************************************************/
int SendUnixDgram(fd, data, len)
int fd,len;
char *data;
{
int rtn;
	rtn = send(fd, data, len, 0);
	if(rtn <= 0) return (errno * -1);
	return rtn;
}
