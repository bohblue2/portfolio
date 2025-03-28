/***********************************************************************/
/* Multicasting client open		                               */
/* NAME    : openmtcli.c                                               */
/* CREATE  : 2002.10.16.                                               */
/* REMARKS :                                                           */
/***********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <errno.h>

#include <arpa/inet.h>

/*******************************************************************************
 * Create multicasting send socket
 * Prototype : int OpenInetMultiClient(addr, port, group, ttl)
 * Arguments : struct sockaddr_in *addr;
 *             int                 port;
 *             char               *group; Multicasting group
 *             uchar               ttl; time to live
 * Return    : socket fd
 * Remarks   :
 ******************************************************************************/
int OpenInetMultiClient(addr, port, group, ttl)
struct sockaddr_in *addr;
int                 port;
char               *group;
unsigned char       ttl;
{
int           sfd, rtn;
unsigned int  i1, i2, i3, i4;

	// group input ex) 224.0.1.1
	if(sscanf(group, "%u.%u.%u.%u", &i4, &i3, &i2, &i1) != 4) {
		fprintf(stderr, "OpenInetMultiClient() Multicasting group error![%s]\n", group);
		return -1;
	}

	sfd = socket(AF_INET, SOCK_DGRAM, 0);
	if(sfd < 0){
		fprintf(stderr, "OpenInetMultiClient() socket open error! errno[%d]\n", errno);
		return -1;
	}

	memset((char *)addr, 0x00, sizeof(*addr));
	addr->sin_port = htons((unsigned short)port);
	addr->sin_addr.s_addr = htonl((i4<<24)|(i3<<16)|(i2<<8)|i1);
	addr->sin_family = AF_INET;

	// IP_MULTICAST_TTL : specify TTL for outgoing multicasts
	// - Set the IPv4 TTL or the IPv6 hop limit for outgoing multicast datagrams.
	// - If this is not specified, both defatlt to 1, which restricts the datagram to the local subnet.
	rtn = setsockopt(sfd, IPPROTO_IP, IP_MULTICAST_TTL, (void *)&ttl, sizeof(unsigned char));
	if(rtn == -1){
		fprintf(stderr, "OpenInetMultiClient() IP_MULTICAST_TTL Error! errno[%d]\n", errno);
		return -1;
	}

	return sfd;
}
