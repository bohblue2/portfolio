////////////////////////////////////////////////////////////////////////////////
// Description  : Terminal value set/get
// File Name    : termval.c
// Author       :
// Notes        :
//收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收
// Date         : 
////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <termio.h>
#include <string.h>

/*******************************************************************************
 * set Terminal value 
 * Prototype : int TermSetValue(ttyfd, value)
 * Argument  : int ttyfd; Terminal FD
 *             struct termio *value; terminal infomation value pointer
 * Return    : SUCCESS : 1, FAIL : -1
 ******************************************************************************/
int TermSetVal(int ttyfd, struct termio *termval)
{
	if(ioctl(ttyfd,TCSETAW,termval)==-1) return(-1);
	else return(1);
}

/*******************************************************************************
 * Get terminal information value
 * Prototype : int TermGetVal(ttyfd, value)
 * Argument  : int ttyfd; Terminal FD
 *             struct termio *value; terminal infomation value pointer
 * Return    : SUCCESS : 1, FAIL : -1
 ******************************************************************************/
int TermGetVal(int ttyfd, struct termio *termval)
{
	if(ioctl(ttyfd,TCGETA,termval)==-1) return(-1);
	else return(1);
}
////////////////////////////////////////////////////////////////////////////////
// Program End
////////////////////////////////////////////////////////////////////////////////

