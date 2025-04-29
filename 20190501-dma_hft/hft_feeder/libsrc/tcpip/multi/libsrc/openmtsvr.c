/***********************************************************************/
/* Multicasting Server open		                               */
/* NAME    : openmtsvr.c                                               */
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
 * Prototype : int OpenInetMultiServer(port, group)
 * Arguments : int                 port;
 *             char               *group; Multicasting group
 * Return    : socket fd
 * Remarks   : IP 224.0.0.1 : all-host group, IP 221.0.0.2 : all-routers group
 ******************************************************************************/
int OpenInetMultiServer(port, group)
int   port;
char *group; /* IP address style "224.0.1.1" = "i4.i3.i2.i1" */
{
struct sockaddr_in addr;
int i1, i2, i3, i4, sfd, rtn, on=1;
struct hostent *hp;
struct ip_mreq imr;
char    myhost[255];

	if(sscanf(group, "%u.%u.%u.%u", &i4, &i3, &i2, &i1) != 4){
		fprintf(stderr, "OpenInetMultiServer(): Invalid group %s\n", group);
		return -1;
	}

	if((sfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0){
		fprintf(stderr, "OpenInetMultiServer():Cannot create datagram socket\n");
		return -1;
	}

	gethostname(myhost, 255);
	if((hp=gethostbyname(myhost)) == 0) {
		fprintf(stderr, "Unknown host %s\n", myhost);
		return -1;
	}
    
    printf("OpenInetMultiServer(): group %s\n", group);
    
	
	imr.imr_multiaddr.s_addr = (i4<<24) | (i3<<16) | (i2<<8) | i1;
	imr.imr_multiaddr.s_addr = htonl(imr.imr_multiaddr.s_addr);
	imr.imr_interface.s_addr = htonl(INADDR_ANY); // 233.37.54.111 추가
	if(hp->h_addr_list == NULL) {
		fprintf(stderr, "No addresses in h_addr_list for %s\n", myhost);
		return -1;
	}
	
	// 233.37.54.111 추가 제외
	//memcpy((char *)&imr.imr_interface.s_addr, hp->h_addr, hp->h_length);

	// IP_ADD_MEMBERSHIP : join a multicast group on a specified local interface..
	// - We specify the local interface with one of its unicast addresses for IPv4 or with the interface index for IPv6.
	rtn = setsockopt(sfd, IPPROTO_IP, IP_ADD_MEMBERSHIP, (char *) &imr, sizeof(struct ip_mreq));
	if(rtn == -1){
		fprintf(stderr, "OpenInetMultiServer() IP_ADD_MEMBERSHIP Error! errno[%d]\n", errno);
		return -1;
	}
	
	
	setsockopt(sfd, SOL_SOCKET, SO_REUSEADDR, (char *) &on, sizeof(on));
	
	bzero((char *)&addr, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = htonl(INADDR_ANY); // INADDR_ANY
	addr.sin_port = htons((u_short)port);

	if (bind(sfd, (struct sockaddr *)&addr, sizeof(struct sockaddr)) < 0){
		fprintf(stderr, "Cannot bind socket to %d port\n", port);
		return -1;
	} else {
	    printf("bind to socket for INADDR_LOOPBACK.... OK\n");
	}

	return sfd;
}

