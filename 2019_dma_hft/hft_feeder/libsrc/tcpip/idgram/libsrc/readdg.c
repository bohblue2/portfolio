/***********************************************************************/
/* Read from UDP                                                       */
/* NAME    : readdg.c                                                  */
/* CREATE  : 2002.10.16.                                               */
/* REMARKS :                                                           */
/***********************************************************************/
#include <stdio.h> 
#include <stdlib.h> 
#include <errno.h> 
#include <string.h> 
#include <sys/types.h> 
#include <netinet/in.h> 
#include <sys/socket.h> 
#include <sys/wait.h>

/******************************************************************************/
/* Read data from UDP socket                                                  */
/* Prototype : int ReadUdp(fd, buff, rlen)                                    */
/* Argument  : int fd; socket file discriptor                                 */
/*             char *buff; data buffer                                        */
/*             int   rlen; Want length                                        */
/* return    : int; > 0 : Read data length, < 0 : Fail( errno * -1)           */
/******************************************************************************/
int ReadUdp(fd, buff, len)
int   fd;
char *buff;
int   len;
{
int                rtn, addr_len;
struct sockaddr_in their_addr; /* connector's address information */

	addr_len = sizeof(struct sockaddr);
	rtn = recvfrom(fd, buff, len, 0, (struct sockaddr *)&their_addr, &addr_len);
	if(rtn <= 0) return (errno * -1);

	return rtn;
}
