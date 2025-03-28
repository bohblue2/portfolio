////////////////////////////////////////////////////////////////////////////////
// Description  : ioctl�� �̿��� delay/nodelay mode ����
// File Name    : delaymode.c
// Author       :
// Notes        :
//������������������������������������������������������������������������������
// Date         : 
////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>

/*******************************************************************************
 * fd�� Delay mode/Nodelay mode�� �ٲ۴�.
 * Prototype : int SetNodelayMode(fd, mode)
 * Argument  : int fd; FD
 *             int mode; 0:Delay, 1:NoDelay 
 * Return    : int ; SUCCESS : 0 , FAIL : -1
 ******************************************************************************/
int SetNodelayMode(int fd, int mode)
{
	return ioctl(fd, FIONBIO, &mode);
}
////////////////////////////////////////////////////////////////////////////////
// Program End
////////////////////////////////////////////////////////////////////////////////
