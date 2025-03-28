////////////////////////////////////////////////////////////////////////////////
// Description  : Terminal�� no echo mode�� ����
// File Name    : termnoecho.c
// Author       :
// Notes        :
//������������������������������������������������������������������������������
// Date         : 
////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <termio.h>
#include <unistd.h>

/*******************************************************************************
 * Terminal�� no echo mode�� �����Ѵ�.
 * Prototype : in TermSetNoecho(ttyfd)
 * Argument  : int ttyfd; Terminal FD
 * Return    : 1 : SUCCESS, -1 : FAIL
 ******************************************************************************/
int TermSetNoecho(int ttyfd)
{
struct termio tsave;	

	if(ioctl(ttyfd,TCGETA,&tsave)==-1) return -1;
	tsave.c_lflag &= ~(ECHO);
	if(ioctl(ttyfd,TCSETAW,&tsave)==-1) return -1;
	return 1;
}
////////////////////////////////////////////////////////////////////////////////
// Program End
////////////////////////////////////////////////////////////////////////////////
