/***********************************************************************/
/* Get my address                                                      */
/* NAME    : getmyaddr.c                                               */
/* CREATE  : 1997.10.16                                                */
/* REMARKS :                                                           */
/***********************************************************************/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

/*******************************************************************************
 * Get my host address
 * Prototype : void GetMyHostCharAddress(buff)
 * Argument  : char *buff; Host address buffer
 * Return    : void
 ******************************************************************************/
void GetMyHostCharAddress(addr)
char *addr;
{
char name[512];
struct hostent *ent;

	gethostname(name, sizeof(name));// 배열 name에 host의 이름을 반환한다

	ent = gethostbyname(name);	// 주어진 host name에 상응하는 hostent타입의 구조체를 반환한다

	strcpy(addr,inet_ntoa(*((struct in_addr *)*ent->h_addr_list)));

	return;
}
