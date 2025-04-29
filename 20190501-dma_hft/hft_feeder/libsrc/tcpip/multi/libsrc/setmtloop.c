/***********************************************************************/
/* Set Multicasting loop Enable/Disable                                */
/* NAME    : setmtloop.c                                               */
/* CREATE  : 2002.10.16.                                               */
/* REMARKS :                                                           */
/***********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>

/*******************************************************************************
 * Multicasting의 LOOP Back을 결정한다.
 * Default는 Enable이다
 * PROTOTYPE : int SetMulticastLoopBack(fd, onoff)
 * ARGUMENTS : int fd; socket fd
 *             int onoff : ON : 1, OFF:0
 * RETURN    :
 * REMARKS   :
 ******************************************************************************/
int SetMulticastLoopBack(fd, onoff)
int fd, onoff;
{
unsigned char on ;

	on = (unsigned char )onoff;
	// IP_MULTICAST_LOOP : enable or disable loopback of outgoing multicast
	return setsockopt(fd, IPPROTO_IP, IP_MULTICAST_LOOP, (void *)&on, sizeof(on));
}
