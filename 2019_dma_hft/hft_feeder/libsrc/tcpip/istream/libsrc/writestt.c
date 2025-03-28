/*
 * Write stream socket
 * Name : writest.c
 * Date : 1996.10.31
 * By   : Penta_soft Co.,Ltd(Sagittarius)
 * -. 1998.04.16
 *  WriteSize()추가 .
 *  BLOCKING MOD인경우도 정확한 size를 쓰지 못하는 경우가 발생.
 * -. 2001.06.25 배성남
 *  TIMEOUT 추가.. 상대편이 죽을 경우 무한루프를 타서,
 *  초단위내에 i/o를 완료하지 못하면 에러리턴한다.
 */
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#ifndef MAX_BUFF
#define MAX_BUFF 62580 /* 255 * 255 + 255 */
#endif
/*******************************************************************************
 * 정확한 size를 쓸 때 까지 return 하지 않는다.
 * Prototype : int WriteSizeT(fd, buff, size)
 * Arguments : int fd, size; char *buff; int sec;
 * Return    : 성공 : 1, 실패 : 0
 ******************************************************************************/
int WriteSizeT(fd, buff, sz, sec)
int fd, sz;
char *buff;
int   sec;
{
int rtn;
char *p;
fd_set wfds;
struct timeval rtv;

    /* fd 설정 */
    FD_ZERO(&wfds);
    FD_SET(fd, &wfds);

    if(sec < 0) return -200;

    /* timeout 시간 설정 */
    rtv.tv_sec = sec;
    rtv.tv_usec = 0;

    p = buff;
    do{

        /* select 시작 */
        rtn = select(fd+1, NULL, &wfds, NULL, &rtv);
        if(!rtn)         /* Time out   */
            return -100;
        else if(rtn < 0) /* Select Err */
            return -999;

        /* fd에서 값 읽기 */
	if(FD_ISSET(fd, &wfds)) {
            rtn=send(fd, p, sz, 0 );
            if(rtn >=0 && rtn < sz){ sz -=rtn;p += rtn;}
            else if(rtn == sz) break;
	    else if(rtn < 0) return -1;
            else return 0;
	}
    }while(1);

    return 1;
}
/******************************************************************************/
/* Write data                                                                 */
/* Prototype : int WriteStreamT(fd, buff, sz, sec)                            */
/* Arguments : int   fd; Socket FD(I)                                         */
/*             char *buff;Data buffer(I)                                      */
/*             int   sz;  Data size                                           */
/*             int   sec; TimeOut sec                                         */
/* Return    : int ; SUCESS : write size, FAIL : errno                        */
/******************************************************************************/
int WriteStreamT(fd, buff, sz, sec)
int fd, sz;
char *buff;
int sec;
{
int  rtn;
char temp[MAX_BUFF];
	memcpy(temp, (char *)&sz, sizeof(int));
	memcpy(temp + sizeof(int), buff, sz);
	sz += sizeof(int);
	rtn = WriteSizeT(fd, temp, sz, sec);
	if(rtn <= 0)return  -1;
	return sz - sizeof(int);
}
/******************************************************************************/
/* Write data                                                                 */
/* Prototype : int WriteStream2T(fd, buff, sz)                                 */
/* Arguments : int   fd; Socket FD(I)                                         */
/*             char *buff;Data buffer(I)                                      */
/*             int   sz;  Data size                                           */
/*             int   sec; TimeOut sec                                         */
/* Return    : int ; SUCESS : write size, FAIL : errno                        */
/******************************************************************************/
int WriteStream2T(fd, buff, sz, sec)
int fd, sz;
char *buff;
int sec;
{
int           rtn;
unsigned char fs, ls, temp[MAX_BUFF];
	fs = (unsigned char)(sz / 255);
	ls = (unsigned char)(sz - fs * 255);
	temp[0] = fs;temp[1] = ls;
	memcpy(temp + 2, buff, sz);
	rtn = WriteSizeT(fd, temp, sz + 2, sec);
	if(rtn <= 0)return -1;
	return sz;
}
