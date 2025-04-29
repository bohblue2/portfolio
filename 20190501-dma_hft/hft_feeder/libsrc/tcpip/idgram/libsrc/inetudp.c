/***********************************************************************/
/* INET Family UDP LIB.                                                */
/* NAME    : inetudp.c                                                 */
/* CREATE  : 2002.10.16.                                               */
/* REMARKS :                                                           */
/***********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <sys/fcntl.h>
#include <sys/errno.h>
#include <netinet/in.h>
#include <net/if.h>
#include <netdb.h>

#define TRUE 1
#define FALSE 0

extern int errno;

typedef struct _NET_ADDR
{
	unsigned char a1;
	unsigned char a2;
	unsigned char a3;
	unsigned char a4;
} NET_ADDR;

/*******************************************************************************
 * Convert to Str Addr
 ******************************************************************************/
int Convert2StrAddr(addr, buff)
unsigned long addr;
char         *buff;
{
NET_ADDR *p;

	p = (NET_ADDR *)&addr;
	sprintf(buff, "%d.%d.%d.%d", p->a1, p->a2, p->a3, p->a4);
}

/*******************************************************************************
 * Send UDP Data
 ******************************************************************************/
SendUDPData(sockfd, serv, data, len)
int		sockfd;
char	*data, *serv;
int		len;
{
struct ifconf ifc;
struct ifreq  *ifr;
struct sockaddr_in dst;
struct servent     *se;
char	buf[BUFSIZ];
int		n;

	ifc.ifc_len = sizeof(buf);
	ifc.ifc_buf = buf;

	if (ioctl(sockfd, SIOCGIFCONF, (char *)&ifc) < 0) {
		fprintf(stderr, "SIOCGIFCONF ioctl error\n");
		return FALSE;
	}

	ifr = ifc.ifc_req;
	for (n = ifc.ifc_len/sizeof(struct ifreq); --n >= 0; ifr++) {
		if (ifr->ifr_addr.sa_family != AF_INET) continue;
		if (ioctl(sockfd, SIOCGIFFLAGS, (char *)ifr) < 0) {
			fprintf(stderr, "SIOCGIFFLAGS ioctl error [%d]\n", errno);
			continue;
		}
		if ( (ifr->ifr_flags & IFF_UP) == 0 ||
			 (ifr->ifr_flags & IFF_LOOPBACK)||
			 (ifr->ifr_flags & ( IFF_BROADCAST | IFF_POINTOPOINT)) == 0)
			 continue;

		if (ifr->ifr_flags & IFF_POINTOPOINT) {
			if (ioctl(sockfd, SIOCGIFDSTADDR, (char *)ifr) < 0) {
				fprintf(stderr, "pointopoint SIOCGIFDSTADDR ioctl error [%d]\n",
						errno);
				continue;
			}
			memcpy((char *)&dst, (char *) &ifr->ifr_dstaddr, 
					sizeof(ifr->ifr_dstaddr));
		} else if (ifr->ifr_flags & IFF_BROADCAST) {
			if (ioctl(sockfd, SIOCGIFBRDADDR, (char *)ifr) < 0) {
				fprintf(stderr, "Broadcast SIOCGIFDSTADDR ioctl error [%d]\n", 
						errno);
				continue;
			}
			memcpy((char *)&dst, (char *) &ifr->ifr_broadaddr, 
					sizeof(ifr->ifr_broadaddr));
		}

		se = getservbyname(serv, "udp");
		if(!se){
			fprintf(stderr,"[ERR] SendUDPData : Check /etc/services[%s]\n", serv);
			return -2;
		}

		/* Broadcast Port¸¦ ÁöÁ¤. */
		dst.sin_port = htons(se->s_port);

		if (sendto(sockfd, data, len, 0, 
				(struct sockaddr *)&dst, sizeof(dst)) != len) {
				fprintf(stderr, "UDP Socket Send Error[%d]\n", len);
			return FALSE;
		}
	}

	return TRUE;
}

/*******************************************************************************
 * Send Inet Udp To Port
 ******************************************************************************/
int SendInetUdpToPort(fd, host, port, buff, len)
char    *host, *buff;
int      port, len, fd;
{
struct sockaddr_in svr;
struct hostent     *he;
int                 sz, on;
	
	on = strncmp(host, "BCAST", 5);
	if(on) on = 0; else on = 1;

	bzero(&svr, sizeof(svr));
	svr.sin_family      = AF_INET;

	if(!on){
		he = gethostbyname(host);
		if(!he){
			fprintf(stderr,"[ERR] SendInetUdpToPort : Check /etc/hosts[%s]\n", host);
			return -1;
		}

		svr.sin_addr.s_addr = ((struct in_addr *)(he->h_addr))->s_addr;
	}else{
		svr.sin_addr.s_addr = htonl(INADDR_ANY);
		setsockopt(fd, SOL_SOCKET, SO_BROADCAST, &on, sizeof(on));
	}

	svr.sin_port = port;	

	sz = sendto(fd, buff, len, 0, &svr, sizeof(struct sockaddr_in));
	if(sz < 0){
	char  temp[16];
		memset(temp, 0x00, 16);
		Convert2StrAddr(svr.sin_addr.s_addr, temp);
		printf("Send FAIL PORT[%d] SVR_ADDR[0x%08x][%s]\n", 
			svr.sin_port, svr.sin_addr.s_addr, temp);
	}	

	if(on){
		on = 0;
		setsockopt(fd, SOL_SOCKET, SO_BROADCAST, &on, sizeof(on));
	}

	return sz;
}

/*******************************************************************************
 * Send Inet Udp To Svr
 ******************************************************************************/
int SendInetUdpToSvr(fd, host, serv, buff, len)
char    *host, *buff, *serv;
int      len, fd;
{
struct sockaddr_in svr;
struct hostent     *he;
struct servent     *se;
int                 sz, on;
	
	on = strncmp(host, "BCAST", 5);
	if(on) on = 0; else on = 1;

	bzero(&svr, sizeof(svr));
	svr.sin_family      = AF_INET;

	if(!on){
		he = gethostbyname(host);
		if(!he){
			fprintf(stderr,"[ERR] SendInetUdpToSvr : Check /etc/hosts[%s]\n", host);
			return -1;
		}

		svr.sin_addr.s_addr = ((struct in_addr *)(he->h_addr))->s_addr;
	}else{
		svr.sin_addr.s_addr = htonl(INADDR_ANY);
		setsockopt(fd, SOL_SOCKET, SO_BROADCAST, &on, sizeof(on));
	}

	se = getservbyname(serv, "udp");
	if(se == NULL){
		fprintf(stderr,"[ERR] SendInetUdpToSvr : Check /etc/services[%s]\n", serv);
		return -2;
	}
	svr.sin_port = se->s_port;	

	sz = sendto(fd, buff, len, 0, &svr, sizeof(struct sockaddr_in));
	if(sz < 0){
	char  temp[16];
		memset(temp, 0x00, 16);
		Convert2StrAddr(svr.sin_addr.s_addr, temp);
		printf("Send FAIL PORT[%d] SVR_ADDR[0x%08x][%s]\n", 
			svr.sin_port, svr.sin_addr.s_addr, temp);
	}	
	if(on){
		on = 0;
		setsockopt(fd, SOL_SOCKET, SO_BROADCAST, &on, sizeof(on));
	}
	return sz;
}

/*******************************************************************************
 * BroadCasting
 ******************************************************************************/
int BroadCasting(fd, port, buff, len)
char     *buff;
int      len, fd, port;
{
struct sockaddr_in svr;
struct servent     *se;
int                 sz;
	
	bzero(&svr, sizeof(svr));
	svr.sin_family      = AF_INET;
	svr.sin_addr.s_addr = htonl(INADDR_ANY);
	svr.sin_port        = htons(port);

	sz = sendto(fd, buff, len, 0, &svr, sizeof(struct sockaddr_in));

	return sz;
}
