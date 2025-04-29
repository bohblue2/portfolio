/***********************************************************************/
/* INET Family UDP LIB.                                                */
/* NAME    : iudpcli.c                                                 */
/* CREATE  : 2002.10.16.                                               */
/* REMARKS :                                                           */
/***********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define    MAX_BUFF_LEN  4096

/******************************************************************************/
/* Open Ineternet UDP Server                                                  */
/* Prototype  : int OpenInetUdpClient()                                       */
/* Arguments  : none                                                          */
/* Return     : int    sfd;                                                   */
/******************************************************************************/
int OpenInetUdpClient()
{
int                 sfd,rtn;
struct sockaddr_in  myaddr;
int                 buflen;

	sfd = socket(AF_INET, SOCK_DGRAM, 0);
	if(sfd < 0){
		fprintf(stderr, "[DGRAM CLIENT]- Can't Create SERVER stream socket\n");
		return -3001; /* -3001 */
	}

	return sfd;
}
