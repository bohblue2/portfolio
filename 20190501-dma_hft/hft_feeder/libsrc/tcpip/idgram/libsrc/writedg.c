/***********************************************************************/
/* Write data to UDP socket                                            */
/* NAME    : writedg.c                                                 */
/* CREATE  : 2002.10.16.                                               */
/* REMARKS :                                                           */
/***********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/errno.h>
#include <netinet/in.h>
#include <netdb.h>

/******************************************************************************/
/* Write data to UDP socket                                                   */
/* Prototype : int WriteUdp(fd, host, serv, buff, len)                        */
/* Argument  : int fd; socket file discriptor                                 */
/*             char *host; Host name or address                               */
/*             char *serv; Services name                                      */
/*             char *buff; data buffer                                        */
/*             int   len;  Data length                                        */
/* return    : int; 1: SUCESS, < 0 : Fail( errno * -1)                        */
/******************************************************************************/
int WriteUdp(fd, host, serv, buff, len)
char    *host, *buff, *serv;
int      len, fd;
{
struct sockaddr_in svr;
struct hostent     *he;
struct servent     *se;
int                 sz;

	he = gethostbyname(host); // [/etc/hosts] 참조
	if(!he) return -3002;

	se = getservbyname(serv, "udp"); // [etc/services] 참조
	if(!se) return -3003;

	bzero(&svr, sizeof(svr));
	svr.sin_family      = AF_INET; // AF_INET : IPv4 protocols
	svr.sin_addr.s_addr = ((struct in_addr *)(he->h_addr))->s_addr;
	svr.sin_port = se->s_port;

	// sendto return : number of bytes read if OK, -1 on error
	sz = sendto(fd, buff, len, 0, (struct sockaddr *)&svr, sizeof(struct sockaddr));
	if(sz <= 0) return (errno * -1);

	return 1;
}


/*******************************************************************************
 * Send Inet Udp To Port
 * remark : 지정한 port로 UDP 또는 BROADCAST로 Write 한다..
 ******************************************************************************/
int SendInetUdpToPort(fd, host, port, buff, len)
char    *host, *buff;
int      len, fd, port;
{
struct sockaddr_in svr;
struct hostent     *he;
int                 sz, on;
	
	on = strncmp(host, "BCAST", 5); // (host==BCAST) : BROADCAST를 원하는지 점검한다..
	if(on)	on = 0; // UDP
	else	on = 1; // BROADCAST

	bzero(&svr, sizeof(svr));
	svr.sin_family = AF_INET;
	if(!on) { // UDP
		he = gethostbyname(host);
		if(!he){
			fprintf(stderr,"[ERR] SendInetUdpToPort : Check /etc/hosts[%s]\n", host);
			return -1;
		}
		svr.sin_addr.s_addr = ((struct in_addr *)(he->h_addr))->s_addr;
	} else { // BROADCAST
		svr.sin_addr.s_addr = htonl(INADDR_ANY);
		setsockopt(fd, SOL_SOCKET, SO_BROADCAST, (char *)&on, sizeof(on));
	}
	svr.sin_port = port;

	sz = sendto(fd, buff, len, 0, (struct sockaddr *)&svr, sizeof(struct sockaddr_in));
	if(sz < 0)
		printf("Send FAIL! UDP PORT[%d]\n", svr.sin_port);

	if(on) { // BROADCAST
		on = 0;
		setsockopt(fd, SOL_SOCKET, SO_BROADCAST, (char *)&on, sizeof(on));
	}

	return sz;
}

/*******************************************************************************
 * Send Inet Udp To Svr
 * remark : 지정한 serv로 UDP 또는 BROADCAST로 Write 한다..
 ******************************************************************************/
int SendInetUdpToSvr(fd, host, serv, buff, len)
char    *host, *buff, *serv;
int      len, fd;
{
struct sockaddr_in svr;
struct hostent     *he;
struct servent     *se;
int                 sz, on;
	
	on = strncmp(host, "BCAST", 5);  // (host==BCAST) : BROADCAST를 원하는지 점검한다..
	if(on) on = 0;
	else   on = 1;

	bzero(&svr, sizeof(svr));
	svr.sin_family      = AF_INET;
	if(!on) { // UDP
		he = gethostbyname(host);
		if(!he){
			fprintf(stderr,"[ERR] SendInetUdpToSvr : Check /etc/hosts[%s]\n", host);
			return -1;
		}
		svr.sin_addr.s_addr = ((struct in_addr *)(he->h_addr))->s_addr;
	} else { // BROADCAST
		svr.sin_addr.s_addr = htonl(INADDR_ANY);
		setsockopt(fd, SOL_SOCKET, SO_BROADCAST, (char *)&on, sizeof(on));
	}

	se = getservbyname(serv, "udp");
	if(!se){
		fprintf(stderr,"[ERR] SendInetUdpToSvr : Check /etc/services[%s]\n", serv);
		return -2;
	}
	svr.sin_port = se->s_port;	

	sz = sendto(fd, buff, len, 0, (struct sockaddr *)&svr, sizeof(struct sockaddr));
	if(sz < 0)
		printf("Send FAIL! UDP PORT[%d]\n", svr.sin_port);

	if(on) { // BROADCAST
		on = 0;
		setsockopt(fd, SOL_SOCKET, SO_BROADCAST, (char *)&on, sizeof(on));
	}

	return sz;
}

/*******************************************************************************
 * Set broadcasting 
 ******************************************************************************/
void SetBroadcasting(int fd)
{
int on = 1;
	setsockopt(fd, SOL_SOCKET, SO_BROADCAST, (char *)&on, sizeof(on));
}

/*******************************************************************************
 * ResetBraodcasting
 ******************************************************************************/
void ResetBroadcasting(int fd)
{
int on = 0;
	setsockopt(fd, SOL_SOCKET, SO_BROADCAST, (char *)&on, sizeof(on));
}

/*******************************************************************************
 * Broadcasting data 
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
	svr.sin_addr.s_addr = htonl(INADDR_BROADCAST);
	svr.sin_port        = htons(port);
	sz = sendto(fd, buff, len, 0, (struct sockaddr *)&svr, sizeof(struct sockaddr));

	return sz;
}
