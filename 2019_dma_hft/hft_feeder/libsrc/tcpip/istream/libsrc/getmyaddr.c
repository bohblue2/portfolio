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

	gethostname(name, sizeof(name));// �迭 name�� host�� �̸��� ��ȯ�Ѵ�

	ent = gethostbyname(name);	// �־��� host name�� �����ϴ� hostentŸ���� ����ü�� ��ȯ�Ѵ�

	strcpy(addr,inet_ntoa(*((struct in_addr *)*ent->h_addr_list)));

	return;
}
