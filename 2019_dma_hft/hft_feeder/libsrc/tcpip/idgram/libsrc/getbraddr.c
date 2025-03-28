/***********************************************************************/
/* Broadcasting address를 구한다.                                      */
/* NAME    : getbraddr.c                                               */
/* CREATE  : 2002.10.16.                                               */
/* REMARKS :                                                           */
/***********************************************************************/
#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <netdb.h>
#include <net/if.h>

/*******************************************************************************
 * Broadcasting address를 구한다.
 * Prototype : int GetBroadcatingAddr(socketfd, addr)
 * Arguments : int socketfd; Socket fd
 *             char *interface; interface name ex) "en0","le0"
 *             char *addr; Address buffer
 * Return    : 1:SUCCESS, -:FAIL
 * Remarks   :
 ******************************************************************************/
int GetBroadcastingAddr(fd, dev, addr)
int   fd;
char *dev;
char *addr;
{
struct ifreq  ifreq;
struct sockaddr_in *sa;
int   rtn;

	memset(&ifreq, 0x00, sizeof(ifreq));	
	strcpy(ifreq.ifr_name, dev);
	rtn = ioctl(fd, SIOCGIFBRDADDR, &ifreq);
	if(rtn < 0) return errno * -1;
	sa = (struct sockaddr_in *)&ifreq.ifr_ifru.ifru_broadaddr;

	strcpy(addr, (char *)inet_ntoa(ifreq.ifr_ifru.ifru_broadaddr));

	return 1;
}

