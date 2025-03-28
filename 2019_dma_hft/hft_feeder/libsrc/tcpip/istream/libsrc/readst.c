/***********************************************************************/
/* Read stream socket                                                  */
/* NAME    : readst.c                                                  */
/* CREATE  : 1996.10.31                                                */
/* REMARKS : ReadSize() : 1998.04.16                                   */
/*           - BLOCKING MOD�ΰ�쵵 ��Ȯ�� size�� ���� ���ϴ� ��� ���*/
/***********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/time.h>

/*******************************************************************************
 * ��Ȯ�� size�� ���� �� ���� return ���� �ʴ´�.
 * Prototype : int ReadSize(fd, buff, size)
 * Arguments : int fd, size; char *buff;
 * Return    : ���� : 1, ���� : 0 or ����
 ******************************************************************************/
int ReadSize(fd, buff, sz)
int fd, sz;
char *buff;
{
int rtn;
char *p;
	p = buff;
	do {
		rtn= read(fd, p, sz);
		if(rtn <=0) return errno * -1;
		if(rtn < sz) {
			sz -=rtn;
			p += rtn;
		}
		else if(rtn == sz) break;
	} while(1);

	return 1;
}

/*******************************************************************************
 * ��Ȯ�� size�� ���� �� ���� return ���� �ʴ´�.
 * Prototype : int ReadSize(fd, buff, size)
 * Arguments : int fd, size; char *buff;
 * Return    : ���� : 1, ���� : 0 or ����
 ******************************************************************************/
int ReadSize2(int fd, void *vptr, size_t n)
{
	size_t	nleft;
	ssize_t	nread;
	char	*ptr;
	
	ptr = vptr;
	nleft = n;
	while (nleft > 0) {
		if ((nread = read(fd, ptr, nleft)) < 0) {
			if (errno == EINTR)
				nread = 0;	/* and call read() again */
			else
				return errno * -1;
		} else if (nread == 0)
			break;			/* EOF */

		nleft -= nread;
		ptr   += nread;
	}

	return 1;
}

/*******************************************************************************
 * ��Ȯ�� size�� ���� �� ���� return ���� �ʴ´�.
 * Prototype : int ReadSize3(fd, ptr, nbytes)
 * Arguments : int fd, nbytes; char *ptr;
 * Return    : ���� : read�� byte, ���� : read()�� ���ϰ�
 ******************************************************************************/
int ReadSize3(fd,ptr,nbytes)
register int fd;
register char *ptr;
register int nbytes;
{
	int nleft,nread;

	nleft=nbytes;
	while(nleft>0) {
		nread=read(fd,ptr,nleft);
		if(nread<0)
			return(nread);
		else if(nread==0)
			break;
		nleft-=nread;
		ptr+=nread;
	}
	return(nbytes-nleft);
}

/******************************************************************************/
/* Read data                                                                  */
/* Prototype : int ReadStream(fd, buff)                                       */
/* Arguments : int   fd; Socket FD(I)                                         */
/*             char *buff;Data buffer(O)                                      */
/* Return    : int ; Received Data size                                       */
/******************************************************************************/
int ReadStream(fd, buff)
int   fd;
char *buff;
{
int sz, rtn;

	rtn = ReadSize(fd, (char *)&sz, sizeof(int));
	if(rtn <= 0) return rtn;

	rtn = ReadSize(fd, (char *)buff, sz);
	if(rtn <= 0) return rtn;

	return sz;
}

/******************************************************************************/
/* Read data                                                                  */
/* Prototype : int ReadStream2(fd, buff)                                      */
/* Arguments : int   fd; Socket FD(I)                                         */
/*             char *buff;Data buffer(O)                                      */
/* Return    : int ; Received Data size                                       */
/******************************************************************************/
int ReadStream2(fd, buff)
int   fd;
char *buff;
{
int sz, rtn;
unsigned char size[2];

	rtn = ReadSize(fd, (char *)size, sizeof(size));
	if(rtn <= 0) return rtn;

	sz = size[0] * 255 + size[1];

	rtn = ReadSize(fd, buff, sz);
	if(rtn <= 0) return rtn;

	return sz;
}
