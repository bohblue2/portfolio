////////////////////////////////////////////////////////////////////////////////
// Description  : TTY line을 setup한다. 
// File Name    : termsetup.c
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
#include "terminal.h"

#pragma GCC diagnostic ignored "-Warray-bounds"

/*******************************************************************************
 * Prototype : static int Str2Bspeed(speed)
 * Argument  : 
 * Return    : 
 *
 ******************************************************************************/
static int Str2Bspeed(char *speed)
{
	if(strncmp(speed,"38400",	5)==0) return B38400;
	if(strncmp(speed,"19200",	5)==0) return B19200;
	if(strncmp(speed,"9600",	4)==0) return B9600;
	if(strncmp(speed,"4800",	4)==0) return B4800;
	if(strncmp(speed,"2400",	4)==0) return B2400;
	if(strncmp(speed,"1200",	4)==0) return B1200;
	if(strncmp(speed,"600",		3)==0) return B600;
	if(strncmp(speed,"300",		3)==0) return B300;
	return 0;	
}

/*******************************************************************************
 * Terminal setup
 * Prototype : int TermSetupLine(tyfd, setbit, speed)
 * Argument  : int ttyfd; Terminal FD
 *             unsigned int setbit; DATA_BIT|STOP_BIT|PARITY_BIT
 *             defined in "~/inclue/term.h"
 *             DATA_BIT   -> DATABIT7, DATABIT8
 *             STOP_BIT   -> STOPBIT1, STOPBIT2
 *             PARITY_BIT -> PARINONE, PARIODD, PARIEVEN
 *             char         *speed; 9600 or 2400
 * Return    : SUCCESS : 1, FAIL : -1
 ******************************************************************************/
int TermSetupLine(int ttyfd,unsigned int setbit,char *speed)
{
struct termio tsave;

	if(ioctl(ttyfd,TCGETA,&tsave)==-1) return(-1);

	memset(&tsave,0,sizeof(tsave));
	/*---- Input mode 정의 -------*/
	/*
	tsave.c_iflag &= ~(BRKINT|INLCR |ICRNL|IGNCR | IUCLC | IGNPAR | ISTRIP);
	tsave.c_iflag &= ~(IXON | IXOFF | IXANY);
	*/
	tsave.c_iflag = 0;
	tsave.c_iflag |= IGNCR; /* CR을 무시하라 */

	tsave.c_cflag |= (CLOCAL);
	tsave.c_cflag &= ~CSIZE ;
	/*------ Data bit Set  --------------------*/
	if(setbit&DATABIT7)		 tsave.c_cflag |= (CS7);
	else if(setbit&DATABIT8) tsave.c_cflag |= (CS8);

	/*------ Parity_bit Set -------------------*/
	/*
	if(setbit&PARINONE)	tsave.c_cflag &= ~(PARENB|PARODD);	
	else if(setbit&PARIODD){
		tsave.c_cflag |= (PARENB); 
		tsave.c_cflag &= (PARODD); 
	}
	if(setbit&PARIEVEN){
		tsave.c_cflag |= (PARENB); 
		tsave.c_cflag &= ~(PARODD); 
	}
	*/

	/*------- Line Speed ----------------------*/
	tsave.c_cflag &= ~CBAUD;
	tsave.c_cflag |= Str2Bspeed(speed);

	/*------ Optout mode 정의 ----------------*/
	tsave.c_oflag &= ~OPOST; /* 문자를 변화 없이 출력 */

	tsave.c_lflag &= ~(ICANON | ISIG | ECHO);
	tsave.c_cc[VEOF] = '\01';
	tsave.c_cc[VEOL] = '\0';
	tsave.c_cc[VMIN]  = 1;
	tsave.c_cc[VTIME] = 0;
	
	if(ioctl(ttyfd,TCSETAW,&tsave)== -1 ){
		if(ioctl(ttyfd,TCSETAW,&tsave)==-1) return -1;
	}
	ioctl(ttyfd,TCFLSH,2);
	return(1);
}
////////////////////////////////////////////////////////////////////////////////
// Program End
////////////////////////////////////////////////////////////////////////////////
