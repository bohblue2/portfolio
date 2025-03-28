/***********************************************************************/
/* Write stream socket                                                 */
/* NAME    : writest.c                                                 */
/* CREATE  : 1996.10.31                                                */
/* REMARKS : WriteSize() : 1998.04.16                                  */
/*           - BLOCKING MOD�ΰ�쵵 ��Ȯ�� size�� ���� ���ϴ� ��� ���*/
/***********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/ioctl.h>
#include <sys/time.h>

#ifndef MAX_BUFF
#define MAX_BUFF 62580 /* 255 * 255 + 255 */
#endif

/*******************************************************************************
 * ��Ȯ�� size�� �� �� ���� return ���� �ʴ´�.
 * Prototype : int WriteSize(fd, buff, size)
 * Arguments : int fd, size; char *buff;
 * Return    : ���� : 1, ���� : 0
 ******************************************************************************/
int WriteSize(fd, buff, sz)
int fd, sz;
char *buff;
{
int rtn;
char *p;
    p = buff;

    do {
        rtn = write(fd, p, sz);
        if(rtn < sz) {
        	sz -=rtn;
        	p += rtn;
        }
        else if(rtn == sz) break;
        else return 0;
    } while(1);

    return 1;
}

/*******************************************************************************
 * ��Ȯ�� size�� �� �� ���� return ���� �ʴ´�.
 * Prototype : int WriteSize2(fd, vptr, n)
 * Arguments : int fd, const void *vptr, size_t n;
 * Return    : ���� : 1, ���� : 0
 ******************************************************************************/
int WriteSize2(int fd, const void *vptr, size_t n) // writen
{
	size_t		nleft;
	ssize_t		nwritten;
	const char	*ptr;
	
	ptr = vptr;
	nleft = n;
	while (nleft > 0) {
		if ((nwritten = write(fd, ptr, nleft)) <= 0) {
			if (errno == EINTR)
				nwritten = 0;	/* and call write() again */
			else
				return 0;	/* error */
		}

		nleft -= nwritten;
		ptr   += nwritten;
	}
	
	return 1;
}

/*******************************************************************************
 * ��Ȯ�� size�� �� �� ���� return ���� �ʴ´�.
 * Prototype : int WriteSize3(fd, ptr, nbytes)
 * Arguments : int fd, const void *ptr, int nbytes;
 * Return    : ���� : write�� byte, ���� : write()�� ���ϰ�
 ******************************************************************************/
int WriteSize3(fd, ptr, nbytes)
register int fd;
register char *ptr;
register int nbytes;
{
	int nleft,nwritten;
	
	nleft=nbytes;
	while(nleft>0) {
		nwritten = write(fd,ptr,nleft);
		if(nwritten <= 0)
			return(nwritten);
		nleft-=nwritten;
		ptr+=nwritten;
	}
	return(nbytes-nleft);
}

/******************************************************************************/
/* Write data                                                                 */
/* Prototype : int WriteStream(fd, buff, sz)                                  */
/* Arguments : int   fd; Socket FD(I)                                         */
/*             char *buff;Data buffer(I)                                      */
/*             int   sz;  Data size                                           */
/* Return    : int ; SUCESS : write size, FAIL : errno                        */
/******************************************************************************/
int WriteStream(fd, buff, sz)
int fd, sz;
char *buff;
{
int  rtn;
char temp[MAX_BUFF];

	memcpy(temp, (char *)&sz, sizeof(int));	
	memcpy(temp + sizeof(int), buff, sz);
	sz += sizeof(int);

	//+----+--------------
	//|SIZE| DATA...
	//+----+--------------

	rtn = write(fd, temp, sz);
	if(rtn <= 0) return  -1;

	return sz - sizeof(int); // write�� DATA�� ũ��..
}

/******************************************************************************/
/* Write data                                                                 */
/* Prototype : int WriteStream2(fd, buff, sz)                                 */
/* Arguments : int   fd; Socket FD(I)                                         */
/*             char *buff;Data buffer(I)                                      */
/*             int   sz;  Data size                                           */
/* Return    : int ; SUCESS : write size, FAIL : errno                        */
/******************************************************************************/
int WriteStream2(fd, buff, sz)
int fd, sz;
char *buff;
{
int           rtn;
unsigned char fs, ls, temp[MAX_BUFF];

	fs = (unsigned char)(sz / 255);
	ls = (unsigned char)(sz - fs * 255);
	temp[0] = fs;
	temp[1] = ls;

	memcpy(temp + 2, buff, sz);

	rtn = write(fd, temp, sz + 2);
	if(rtn <= 0)return -1;

	return sz;
}
