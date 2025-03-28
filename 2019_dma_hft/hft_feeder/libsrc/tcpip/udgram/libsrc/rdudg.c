/***********************************************************************/
/* Read data to UNIX DGRAM                                             */
/* NAME    : rdudg.c                                                   */
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
/* Read data to UNIX DGRAM SOCKET                                             */
/* Prototype : int ReadUnixDgram(fd, data, len)                               */
/* Argument  : int fd; Socket fd                                              */
/*             char *data; Send data                                          */
/*             int   len; Data length                                         */
/* Return    : >0 : Sended length, < 0 : FAIL (errno * -1)                    */
/******************************************************************************/
int ReadUnixDgram(fd, data, len)
int fd,len;
char *data;
{
int rtn;
	rtn = read(fd, data, len, 0);
	if(rtn <= 0) return (errno * -1);
	return rtn;
}
