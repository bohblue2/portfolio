/**********************************************************************/
/* 프로그램  명 : TERMINAL CONTROL Library(crtlib) V1.0               */
/* SOURCE    명 : crtlib.c                                            */
/* 작 성  일 자 : 1993. 04. 20 -                                      */
/* 작   성   자 : 임 기 철                                            */
/**********************************************************************/
#include <stdio.h>

#ifdef __STDC__
#	include <stdarg.h>
#else
#	include <varargs.h>
#endif

#ifdef _HPUX_
#	include <sys/ioctl.h>
#endif

#include <fcntl.h>
#include <termio.h>
#include <string.h>
#include <memory.h>
#include <signal.h>
#include <string.h>
#include <sys/types.h>

#ifdef _SUN_ 
#	include <sys/time.h>
#else
#ifdef _HPUX_
#	include <sys/time.h>
#else
#ifdef _SUN1_
#	include <sys/time.h>
#else 
#ifdef _SSM6000_
#	include "6000_types.h"
#	include <sgtty.h>
#else
#	include <sys/select.h>
#	include <sgtty.h>
#endif
#endif
#endif
#endif

#include <sys/ttold.h>
#define FALSE	0
#define TRUE	1
#define ERROR   -1
 
/*---- TERMINAL CONTROL STFRUCTURE ----*/
static struct termio tsave[2];
static int StdOut = 1;
static int StdIn = 0;

/*---- Read a character from terminal ----*/
int t_getc()
{
    unsigned char tmp[4];

    if(read(StdIn,tmp,1)==0) return -1;
    return (int)tmp[0];
}

/* Second , Micro Second */
t_get_time(stime, mtime)
	int  stime, mtime;
{
	struct 	timeval timeout;
	fd_set 	evnt;
	int 	n, maxfd;

	timeout.tv_sec = stime;		/* Second */
	timeout.tv_usec = mtime;	/* Micro Second */

	FD_ZERO(&evnt);
	FD_SET(StdIn,&evnt);				
	maxfd = StdIn + 1;

	n = select(maxfd, &evnt, 0, 0,(struct timeval *) &timeout); 
	if(n > 0) {
		if(FD_ISSET(StdIn, &evnt)) {
			return t_getc();
		}
	}
	return -1;
}
/*---- Write a character to terminal ----*/
void t_putc(c)
	unsigned char c;
{
retry :	
    if(write(StdOut,&c,1)<0) goto retry;
}

/*---- Write string to terminal ----*/
void t_puts(p)
	unsigned char *p;
{
retry :	
    if(write(StdOut,p,strlen(p))<0) goto retry;
}

/*---- Write string to terminal ----*/
t_puts_len(p, len)
	unsigned char *p;
	int len;
{
	int		send_len = 0;

retry :	
    if((send_len = write(StdOut,p,len)) < len) {
		Debug("TERM Write Error %d", send_len);
		if(send_len > 0) {
			p += send_len;
			len -= send_len;
		}
		sleep(1);
		goto retry;
	}
	return send_len;
}
#ifdef __STDC__
void t_fputs(const char *fmt,...)
{
	va_list args;
	char buff[512];
	int  len;

	va_start(args, fmt);
	len = vsprintf(buff,fmt,args);
	va_end(args);

	t_puts(buff);
}
#else
void t_fputs(fmt, va_alist)
	char *fmt;
	va_dcl
{
	va_list args;
	char buff[512];
	int  len;

	va_start(args);
	len = (int)vsprintf(buff, fmt, args);
	va_end(args);

	t_puts(buff);
}
#endif

/*-------- TTY CHECK ---------------*/
int chk_tty(name)
char *name;
{
	char buff[50];

	sprintf(buff,"/dev/%s",name);

    /*open Input terminal line*/
    if((StdIn = open(buff,O_RDONLY))== ERROR){
        write(1,"Could not open outward line  ", 30);
        return -1;
    }

    /*open output terminal line*/
    if((StdOut = open(buff,O_WRONLY))== ERROR){
        write(1,"Could not open outward line  ", 30);
        return -1;
    }

    /*check line is terminal*/
    if(!isatty(StdIn)){
        write(1,"device given is not a terminal", 30);
        return -1;
    }
    return StdOut;
}

int GetTTYSpeed()
{
	struct termio tmp;

	if(ioctl(StdOut,TCGETA,&tmp) == -1) return -1;

	tmp.c_cflag &= CBAUD;
	if(B38400==(tmp.c_cflag & B38400)) 	return 38400;
	if(B19200==(tmp.c_cflag & B19200)) 	return 19200;
	if(B9600==(tmp.c_cflag & B9600)) 	return 9600;
	if(B4800==(tmp.c_cflag & B4800)) 	return 4800;
	if(B2400==(tmp.c_cflag & B2400)) 	return 2400;
	if(B1200==(tmp.c_cflag & B1200)) 	return 1200;
	if(B600 ==(tmp.c_cflag & B600)) 	return 600;
	if(B300 ==(tmp.c_cflag & B300)) 	return 300;
	return -1;
}

int SetTTYSpeed(speed)
	char *speed;
{
	int		sp;
	struct termio tmp;

	if(ioctl(StdOut,TCGETA,&tmp) == -1) return FALSE;

	tmp.c_cflag &= ~CBAUD;
	sp = atoi(speed);
	switch(sp) {
		case 38400  : tmp.c_cflag |= B38400; 	break;
		case 19200	: tmp.c_cflag |= B19200;	break;
		case  9600	: tmp.c_cflag |= B9600;		break;
		case  4800	: tmp.c_cflag |= B4800;		break;
		case  2400	: tmp.c_cflag |= B2400;		break;
		case  1200 	: tmp.c_cflag |= B1200;		break;
		case   600 	: tmp.c_cflag |= B600;		break;
		case   300 	: tmp.c_cflag |= B300;		break;
		default   	: tmp.c_cflag |= B9600;		break;
	}
	if(ioctl(StdOut,TCSETAW,&tmp) == -1 ) {	/* ReTry */
		if(ioctl(StdOut,TCSETAW,&tmp) ==-1) return FALSE;
	}
	ioctl(StdOut,TCFLSH,2); 
	return TRUE;
}

int	tty_clear()
{
	ioctl(StdOut,TCFLSH,0);
}

int tty_reset()
{
	if(ioctl(StdOut,TCSETAW,&tsave[0])==-1) {	/* Retry */
		if(ioctl(StdOut,TCSETAW,&tsave[0])==-1) return FALSE;
		/*
		if(ioctl(StdOut,TCSETAF,&tsave[0])==-1) return FALSE;
		*/
	}
	ioctl(StdOut,TCFLSH,2);
	return TRUE;
}

int tty_set()
{
	if( ioctl(StdIn,TCGETA,&tsave[0]) == -1 ) return FALSE;
	if( ioctl(StdIn,TCGETA,&tsave[1]) == -1 ) return FALSE;

	tsave[1].c_iflag = 0;
	tsave[1].c_oflag = 0;
/*
	tsave[1].c_iflag &= ~(BRKINT|INLCR |ICRNL|IGNCR | IUCLC | IGNPAR | ISTRIP);
	tsave[1].c_iflag &= ~(IXON | IXOFF | IXANY); 
*/
/*
	tsave[1].c_cflag |= (CLOCAL);
	tsave[1].c_cflag &= ~CSIZE ;
	tsave[1].c_cflag |= (CS8);
	
	tsave[1].c_cflag &= ~(PARENB | PARODD );
	tsave[1].c_cflag &= ~BRKINT;
	tsave[1].c_cflag &= ~CBAUD;
	speed = GetTTYSpeed();
	if(speed == -1) speed = B9600;
	tsave[1].c_cflag |= speed;
	tsave[1].c_oflag &= ~OPOST; 
	tsave[1].c_oflag &= ~(OLCUC | ONLCR | OCRNL | ONOCR | ONLRET);
*/
	tsave[1].c_lflag &= ~(ICANON | ISIG | ECHO);
/*
	tsave[1].c_cc[VINTR] = '\0';
	tsave[1].c_cc[VQUIT] = '\0';
	tsave[1].c_cc[VKILL] = '\0';
*/
	tsave[1].c_cc[VMIN]	 = '\1';
	tsave[1].c_cc[VTIME] = '\1';
/*
	tsave[1].c_cc[VEOF]  = '\1';
	tsave[1].c_cc[VEOL]  = '\1';
*/
	if(ioctl(StdIn,TCSETAW,&tsave[1]) == -1 ) {	/* ReTry */
		if(ioctl(StdIn,TCSETAW,&tsave[1]) ==-1) return FALSE;
	}
	ioctl(StdIn,TCFLSH,2);

	return TRUE;
}

static struct sgttyb tty_mode;

int tty_raw_master(fd)
	int fd;
{
	struct sgttyb temp_mode;

	if (ioctl(fd, TIOCGETP, (char *)&temp_mode) < 0) return (-1);

	tty_mode = temp_mode;

	temp_mode.sg_flags |= O_RAW;
	temp_mode.sg_flags &= ~ECHO;
	if (ioctl(fd, TIOCSETP, (char *)&temp_mode) < 0) return (-1);

	return (0);
}

int tty_reset_master(fd)
	int fd;
{
	if (ioctl(fd, TIOCSETP, (char *)&tty_mode) < 0) return (-1);

	return 0;
}

