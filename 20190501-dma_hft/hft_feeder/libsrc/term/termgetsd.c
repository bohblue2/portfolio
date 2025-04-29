////////////////////////////////////////////////////////////////////////////////
// Description  :
// File Name    : termgetsd.c
// Author       :
// Notes        :
//━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
// Date         : 
////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <termio.h>
#include <string.h>
#include <unistd.h>

/*******************************************************************************
 * Terminal의 현제 speed를 얻는다.
 * Prototype : int TermGetSpeed(ttyfd)
 * Argument  : int ttyfd : Terminal FD
 * Return    : int ; speed value.(B300-B38400)
 ******************************************************************************/
int TermGetSpeed(int ttyfd)
{
int rtn;
struct termio tsave;

	if((rtn=ioctl(ttyfd,TCGETA,&tsave))==-1) return 0;

	tsave.c_cflag &= CBAUD;
	if(B38400 ==(tsave.c_cflag & B38400)) return B38400;
	if(B19200 ==(tsave.c_cflag & B19200)) return B19200;
	if(B9600  ==(tsave.c_cflag & B9600 )) return B9600;
	if(B4800  ==(tsave.c_cflag & B4800 )) return B4800;
	if(B2400  ==(tsave.c_cflag & B2400 )) return B2400;
	if(B1200  ==(tsave.c_cflag & B1200 )) return B1200;
	if(B600   ==(tsave.c_cflag & B600  )) return B600;
	if(B300   ==(tsave.c_cflag & B300  )) return B300;
	return 0;
}
////////////////////////////////////////////////////////////////////////////////
// Program End
////////////////////////////////////////////////////////////////////////////////
