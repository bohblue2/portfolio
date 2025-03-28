////////////////////////////////////////////////////////////////////////////////
// Description  : TTY의 Window size를 구함
// File Name    : winsize.c
// Author       :
// Notes        :
//━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
// Date         : 
////////////////////////////////////////////////////////////////////////////////
#include <sys/ioctl.h>
#include <termio.h>
#include <unistd.h>

/*******************************************************************************
 * TTY의 Window size를 character단위로 구한다.
 * Prototype : int GetWindowSize(fd, x, y)
 * Argument  : int fd; TTY fd
 *             int *x, *y; X/Y의 크기
 * Return    : 성공 : 1
 *             실패 : -1 (tty가 아닌경우)
 ******************************************************************************/
int GetWindowSize(fd, x, y)
int fd, *x, *y;
{
struct winsize wsz;
	if(!isatty(fd)) return -1;
	ioctl(fd, TIOCGWINSZ, &wsz);
	*x = wsz.ws_col;
	*y = wsz.ws_row;
	return 1;
}
////////////////////////////////////////////////////////////////////////////////
// Program End
////////////////////////////////////////////////////////////////////////////////
