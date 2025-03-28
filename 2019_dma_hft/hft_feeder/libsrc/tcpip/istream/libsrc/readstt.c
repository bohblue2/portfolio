/*
 * Read stream socket 
 * Name : readst.c
 * Date : 1996.10.31
 * By   : Penta_soft Co.,Ltd(Sagittarius)
 * -. 1998.04.16
 *  ReadSize()�߰� .
 *  BLOCKING MOD�ΰ�쵵 ��Ȯ�� size�� ���� ���ϴ� ��찡 �߻�.
 * -. 2001.06.25 �輺��
 *  TIMEOUT �߰�.. ������� ���� ��� ���ѷ����� Ÿ��,
 *  �ʴ������� i/o�� �Ϸ����� ���ϸ� ���� �����Ѵ�.
 */
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

/*******************************************************************************
 * ��Ȯ�� size�� ���� �� ���� return ���� �ʴ´�.
 * Timeout ���� (������ �ð�(��)���� read�� �Ϸ����� ���ϸ� ��������...
 * Prototype : int ReadSizeT(fd, buff, size, sec)
 * Arguments : int fd, size; char *buff;
 * Return    : ���� : 1, ���� : 0 or ����
 ******************************************************************************/
int ReadSizeT(fd, buff, sz, sec)
int fd, sz;
int sec;
char *buff;
{
int rtn;
char *p;
fd_set rfds;
struct timeval rtv;

    /* fd ���� */
    FD_ZERO(&rfds);
    FD_SET(fd, &rfds);

    if(sec < 0) return -200;
    
    /* timeout �ð� ���� */
    rtv.tv_sec = sec;
    rtv.tv_usec = 0;

    p = buff;
    do{
	/* select ���� */
        rtn = select(fd+1, &rfds, NULL, NULL, &rtv);
	/* DebugLog ("timeout sec[%d], usec[%d]", rtv.tv_sec, rtv.tv_usec); */
	
	if(!rtn)         /* Time out   */
            return -100;
        else if(rtn < 0) /* Select Err */
            return -999; 
	
	/* fd���� �� �б� */
	if(FD_ISSET(fd, &rfds)) {
            rtn=recv(fd, p, sz,0);
            if(rtn <=0) return errno * -1;
            if(rtn < sz){ sz -=rtn;p += rtn;}
            else if(rtn == sz) break;
	}
    }while(1);
    return 1;
}
/******************************************************************************/
/* Read data                                                                  */
/* Prototype : int ReadStreamT(fd, buff, sec)                                  */
/* Arguments : int   fd; Socket FD(I)                                         */
/*             char *buff;Data buffer(O)                                      */
/*             int  sec; timeout sec                                          */
/* Return    : int ; Received Data size                                       */
/******************************************************************************/
int ReadStreamT(fd, buff, sec)
int   fd;
char *buff;
int   sec;
{
int sz, rtn;
	rtn = ReadSizeT(fd, (char *)&sz, sizeof(int), sec);
	if(rtn <= 0) return rtn;
	rtn = ReadSizeT(fd, (char *)buff, sz, sec);
	if(rtn <= 0) return rtn;
	return sz;
}
/******************************************************************************/
/* Read data                                                                  */
/* Prototype : int ReadStream2T(fd, buff)                                     */
/* Arguments : int   fd; Socket FD(I)                                         */
/*             char *buff;Data buffer(O)                                      */
/*             int  sec; timeout sec                                          */
/* Return    : int ; Received Data size                                       */
/******************************************************************************/
int ReadStream2T(fd, buff, sec)
int   fd;
char *buff;
int   sec;
{
int sz, rtn;
unsigned char size[2];
	rtn = ReadSizeT(fd, (char *)size, 2, sec);
	if(rtn <= 0) return rtn;
	sz = size[0] * 255 + size[1];
	rtn = ReadSizeT(fd, buff, sz, sec);
	if(rtn <= 0) return rtn;
	return sz;
}
