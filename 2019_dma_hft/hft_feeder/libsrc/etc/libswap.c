/*
 * Name :  libswap.c
 * Date :  2000.04.21
 * By : Sagittarius (PentaSoft Co.,Ltd)
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

#include "zconf.h"

double  Str2Dbl(char *str, int size, int point);
int     Str2Int(char *str, int size);

double  Str2d(char *str, int size, int point);
long    Str2l(char *str, int size);

long Str2l(char *str, int size)
{
	char 	tmp[64];
	char 	*ptr;
	long	fdata, ldata;
	int		i;
	
	if(size > 63) 	
		size = 63;
	else if(size < 0) 		
		size = 0;
	
	memset(&tmp,0x00,sizeof(tmp));
	for (i=0;i<size;i++) 
	{
		if(memcmp((char*)&str[i], "0", 1) != 0)
		{
			memcpy(tmp, str+i, size-i);
			break;
		}
	}
	tmp[strlen(tmp)] = '\0';
	ldata = atol(tmp);
	return(ldata);		
}

/*******************************************************************************
 * 설명      :
 * Prototype : short swap 
 * Arguments :
 * Return    : 
 *             1 2 -> 2 1
 ******************************************************************************/
void SwShort(sh)
short *sh;
{
register unsigned char *p1, *p2;
unsigned char tp;
	p1= (unsigned char *)sh;
	p2 = p1 +1 ; tp = *p1; *p1= *p2; *p2 = tp;	
}
/*******************************************************************************
 * 설명      :
 * Prototype  Long Swap 
 * Arguments :
 * Return    :
 *           1 2 3 4 -> 4 3 2 1
 ******************************************************************************/
void SwLong(lg)
long *lg;
{
register unsigned char *p1, *p2, *p3, *p4;
unsigned char tp;
	p1= (unsigned char *)lg;
	p2 = p1 +1 ; p3 = p2 +1 ; p4 = p3 +1 ; 

	tp = *p1; *p1= *p4; *p4 = tp;	
	tp = *p2; *p2= *p3; *p3 = tp;	
}

/*******************************************************************************
 * 설명      :
 * Prototype : int con_i(data, len)
 * Arguments :
 * Return    :
 ******************************************************************************/
int con_i(data, len)
char *data;
int len;
{
char ibuf[32];
	
	memset(ibuf,0x00,sizeof(ibuf));

	if(len >= sizeof(ibuf)) return -1;
	
	memcpy(ibuf, data, len );
	return atoi(ibuf);
	
}

/*******************************************************************************
 * 설명      :
 * Prototype : int con_l(data, len)
 * Arguments :
 * Return    :
 ******************************************************************************/
long con_l(data, len)
char *data;
int len;
{
char ibuf[32];
	
	memset(ibuf,0x00,sizeof(ibuf));

	if(len >= sizeof(ibuf)) return -1;
	
	memcpy(ibuf, data, len );
	return atol(ibuf);
}


/*******************************************************************************
 * 설명      :
 * Prototype : short con_s(data, len)
 * Arguments :
 * Return    :
 ******************************************************************************/
short con_s(data, len)
char *data;
int len;
{
char ibuf[32];
	
	memset(ibuf,0x00,sizeof(ibuf));

	if(len >= sizeof(ibuf)) return -1;
	
	memcpy(ibuf, data, len);
	return (short) atoi(ibuf);
	
}


/*****************************************************************************
 * 설명      : 문자열을 double형으로 전환
 * Prototype : double con_f(str, size1, size2)
 * Arguments : char *str, int size1, int size2
 * Return    : double
 ****************************************************************************/
double con_f(str, size1, size2)
char *str;
int size1;
int size2;
{
    char buff[32];
    memset(buff, 0x00, sizeof(buff));

    sprintf(buff, "%.*s.%.*s", size1, str, size2, str + size1);
	
	return (double)atof(buff);
}


/*****************************************************************************
* 설명      : 문자열을 double형으로 전환
* Prototype : double con_double(str, size1, size2)
* Arguments : char *str, int size1, int size2
* Return    : double
****************************************************************************/
/**
double con_double(str, size1, size2)
char *str;
int size1;
int size2;
{
       char buff[32];
       memset(buff, 0x00, sizeof(buff));
   
       sprintf(buff, "%.*s.%.*s", size1, str, size2, str + size1);
       return (double)atof(buff);
}
***/

/**********************************************************************
	desc   ASCII 값을 INT 로 len만큼 치환한다
	arg    buff(I) : Int로 치환하려는 Buff
	       len(I)  : Size
	ret    atoi(buff) (buff값에 대한 int)
 **********************************************************************/
int latoin(char *buff, int len)
{
	char tmp[512];

	if(len > 10){
		Log("int 는 10 Byte 까지 허용 합니다 ...\n");
		return -1;
	}

	memcpy(tmp, buff, len); tmp[len] = 0x00;

	return (int)atoi(tmp);
}

/***************************************************************************
	desc   ASCII 값을 INT 로 구분자 cmd까지  치환한다
	arg    buff(I) : 치환하려는 Buff
	       cmd(I)  : 구분자
	ret    atoi(buff) (buff값에 대한 int)
 ***************************************************************************/
int latoicmd(char *buff, char *cmd)
{
	int   len;
	char *tmp;
	char  temp[512];

	if((tmp = strstr(buff, cmd)) != NULL)	len = strlen(buff) - strlen(tmp);
	else									len = strlen(buff);

	if(len > 10){
		Log("int 는 10 Byte 까지 허용 합니다 ...\n");
		return -1;
	}

	memcpy(temp, buff, len); temp[len] = 0x00;

	return (int)atoi(temp);
}

/***************************************************************************
	desc   strncpy와 처리가 같으나 마지막에 NULL값 처리
	arg    buff1(O) : Dest
           buff2(I) : Source
           len(I)   : Size
	ret
 ***************************************************************************/
void lstrncpy(char *buff1, char *buff2, int len)
{
	strncpy(buff1, buff2, len); buff1[len] = 0x00;

	return ;
}

/***************************************************************************
	desc   strncpy와 처리가 같으나 n-byte 가 아닌 구분자 cmd까지 처리
	arg    buff1(O) : Dest
           buff2(I) : Source
           cmd(I)   : 구분자
	ret
 ***************************************************************************/
void lstrcmd(char *buff1, char *buff2, char *cmd)
{
	int   len;
	char *tmp;

	if((tmp = strstr(buff2, cmd)) != NULL)	len = strlen(buff2) - strlen(tmp);
	else									len = strlen(buff2);
	strncpy(buff1, buff2, len); buff1[len] = 0x00;

	return ;
}

/**********************************************************************/
/* 01. FUNCTION명 : Long2Date()                                       */
/* 02. 작  성  자 : 김 태 호.                                         */
/* 03. 작  성  일 : 1998. 8.                                          */
/* 04. 기      능 : long형의 값을 일자시간(YYYYMMDD[hhmmss])의 형태로.*/
/*     리  턴  값 : 0:성공, -1:실패.                                  */
/* 05. 헤더화일명 :                                                   */
/* 06. Library 명 :                                                   */
/* 07. Remark사항 :                                                   */
/**********************************************************************/
int     Long2Date(long ldate, char *cdate)
{
	struct tm *t;
	int rt = 14;
	t = localtime(&ldate);

	sprintf(cdate,"%4d%02d%02d%02d%02d%02d", t->tm_year+1900,
                                             t->tm_mon + 1,
                                             t->tm_mday,
                                             t->tm_hour,
                                             t->tm_min,
                                             t->tm_sec);
    if (rt != strlen(cdate)) rt = -1;
	else rt = 0;

	return (rt);
}

/***************************************************************************
	desc   6자리 날짜를 8자리 형태로
	arg    buff1(O) : Dest
           buff2(I) : Source
	ret
 ***************************************************************************/
void lConvDate(char *cdate, int ldate)
{
	sprintf(cdate, "%08d", ldate);

	return ;
}


/*#@
**	Function 	: Calcuater x to power of y 
**	Syntax   	: double Pow(int x,int y);
**  Prototype in: strcnv.h
**  Libary    in: libbasic.a 
**	Remark		:  
**				  pow calculate X**y 
**	Return Value: On success , calculate X**y 
**  See also 	: Pow Str2Dbl,Str2Int,Str2Float,Str2Long,
**				  Str2Hex, Str2Oct  Float2Str,Double2Str,Long2Str,Int2Str
**#$ 
*/

double Pow(x,y)
int x,y;
{
	double d=0;
	if(y>0){ 
		y--;
		d = Pow(x,y);
		d = d * (double)x;
	}else d = 1;
	return ((double)d); 
}

/*#@
**	Function 	: Conversion String to Double value 
**	Syntax   	: double Str2Dbl(char *str,int size,int point); *
**  Prototype in: strcnv.h
**  Libary    in: libbasic.a 
**	Remark		:  
**	Return Value: On success , conversion double value 
**  See also 	: Pow Str2Dbl,Str2Int,Str2Float,Str2Long,
**				  Str2Hex, Str2Oct  Float2Str,Double2Str,Long2Str,Int2Str
**#$ 
*/

double Str2Dbl(str,size,point)
char *str;
int size,point; 
{
	char tmp[64];
	char *ptr;
	double fdata,ldata;

	if(size>64) 	size=64;
	if(size<0) 		size=0;
	memcpy(tmp,str,size);tmp[size]=0;

	ptr= &tmp[size];
	ldata = strtod(tmp,&ptr);
	fdata = ((double)ldata/(Pow(10,point)));
	return(fdata);
}

double Str2d(char *str, int size, int point)
{
	char 	tmp[64];
	char 	*ptr;
	double 	fdata, ldata;
	int		i;
	
	if(size > 63) 	
		size = 63;
	else if(size < 0) 		
		size = 0;
	
	memset(&tmp,0x00,sizeof(tmp));
	for (i=0;i<size;i++) {
		if(memcmp((char*)&str[i], "0", 1) != 0)
		{
			memcpy(tmp, str+i, size-i);
			break;
		}
	}
	
	tmp[strlen(tmp)] = '\0';
	tmp[size-i]=0;
	ptr   = &tmp[size-i];
	fdata = strtod(tmp, &ptr);

	for (i=0;i<point;i++)
	{
		fdata /= (double)10.0;
	}

	return(fdata);
}


double Str2SignDouble(str,size,point)
char *str;
int size,point; 
{
	char tmp[101];
	char *ptr;
	double fdata,ldata;
	int  Flag=0;

	if(size>100) 	size=100;
	if(size<0) 		size=0;
	if(memcmp(str, "-", 1) == 0) {
		size--;
		memcpy(tmp, str+1, size);
		Flag = 1;
	}
	else
		memcpy(tmp,str,size);tmp[size]=0;

	ptr= &tmp[size];
	ldata = strtod(tmp,&ptr);
	fdata = ((double)ldata/(Pow(10,point)));
	if(Flag == 1)
		fdata = fdata * (-1);
	return(fdata);
}
/*#@
**	Function 	: Conversion String to Float value 
**	Syntax   	: float Str2Float(char *str,int size,int point); 
**  Prototype in: strcnv.h
**  Libary    in: libbasic.a 
**	Remark		:  
**	Return Value: On success , conversion float value 
**  See also 	: Pow Str2Dbl,Str2Int,Str2Float,Str2Long,
**				  Str2Hex, Str2Oct  Float2Str,Double2Str,Long2Str,Int2Str
**#$ 
*/


float Str2Float(str,size,point)
char *str;
int size,point; 
{
	char tmp[101];
	int idata;
	float fdata;
	char *ptr;

	if(size>100) 	size=100;
	if(size<0) 		size=0;
	memcpy(tmp,str,size);tmp[size]=0;
	ptr= &tmp[size];
	idata = (int)strtol(tmp,&ptr,10);
	fdata = (float)((float)idata/((float)Pow(10,point)));
	return(fdata);
}

float Str2SignFloat(str,size,point)
char *str;
int size,point; 
{
	char tmp[101];
	int idata, Flag=0;
	float fdata;
	char *ptr;

	if(size>100) 	size=100;
	if(size<0) 		size=0;
	if(memcmp(str, "-", 1) == 0) {
		size--;
		memcpy(tmp, str+1, size); tmp[size]=0;
		Flag = 1;
	}
	else
		memcpy(tmp,str,size);tmp[size]=0;
	ptr= &tmp[size];
	idata = (int)strtol(tmp,&ptr,10);
	fdata = (float)((float)idata/((float)Pow(10,point)));
	if(Flag == 1)
		fdata = fdata * (-1);
	return(fdata);
}
/*#@
**	Function 	: Conversion String to Long value 
**	Syntax   	: long Str2Long(char *str,int size);
**  Prototype in: strcnv.h
**  Libary    in: libbasic.a 
**	Remark		:  
**	Return Value: On success , conversion long value 
**  See also 	: Pow Str2Dbl,Str2Int,Str2Float,Str2Long,
**				  Str2Hex, Str2Oct  Float2Str,Double2Str,Long2Str,Int2Str
**#$ 
*/

long Str2Long(str,size)
char *str;
int size;
{
	char tmp[64];
	char *ptr;
	if(size>64) 	size=64;
	if(size<0) 		size=0;
	memcpy(tmp,str,size);tmp[size]=0;
	ptr=&tmp[size];
	return(strtol(tmp,&ptr,10));		
}

long Str2SignLong(str,size)
char *str;
int size;
{
	char tmp[30];
	char *ptr;
	long value;
	int  Flag=0;
	if(size>100) 	size=100;
	if(size<0) 		size = 0;
	if(memcmp(str, "-", 1) == 0) {
		size--;
		memcpy(tmp, str+1, size); tmp[size]=0;
		Flag = 1;
	}
	else
		memcpy(tmp,str,size);tmp[size]=0;
	ptr=&tmp[size];
	value = strtol(tmp,&ptr,10);		
	if(Flag == 1)
		value = value * (-1);
	return (value);
}

/*#@
**	Function 	: Conversion String to Int value 
**	Syntax   	: int Str2Int(char *str,int size);
**  Prototype in: strcnv.h
**  Libary    in: libbasic.a 
**	Remark		:  
**	Return Value: On success , conversion int value 
**  See also 	: Pow Str2Dbl,Str2Int,Str2Float,Str2Long,
**				  Str2Hex, Str2Oct  Float2Str,Double2Str,Long2Str,Int2Str
**#$ 
*/

int Str2Int(char *str, int size)
{
	char tmp[10];
	int  val;
	char *ptr;

	if(size>10) 	size=10;
	if(size<0)		size=0;
	memcpy(tmp,str,size);tmp[size]=0;
	ptr = &tmp[size];
	val =(int)strtol(tmp,&ptr,10);
	return(val);
}

/*#@
**	Function 	: Conversion String to Hexa value 
**	Syntax   	: long Str2Hex(char *str,int size);
**  Prototype in: strcnv.h
**  Libary    in: libbasic.a 
**	Remark		:  
**	Return Value: On success , conversion hexa value 
**  See also 	: Pow Str2Dbl,Str2Int,Str2Float,Str2Long,
**				  Str2Hex, Str2Oct  Float2Str,Double2Str,Long2Str,Int2Str
**#$ 
*/

long Str2Hex(data,size)  
char 	*data;
int		size;
{
	char tmp[101];	
	long val;
	char	*ptr;

	memset(tmp,0,101);
	memcpy(tmp,data,size);tmp[size]=0;
	size = strlen(tmp);
	ptr = &tmp[size];
	val =  strtol(tmp,&ptr,16);
	return (val);
}

/*#@
**	Function 	: Conversion String to Octal value 
**	Syntax   	: int Str2Oct(char *str,int size);
**  Prototype in: strcnv.h
**  Libary    in: libbasic.a 
**	Remark		:  
**	Return Value: On success , conversion Octal value 
**  See also 	: Pow Str2Dbl,Str2Int,Str2Float,Str2Long,
**				  Str2Hex, Str2Oct  Float2Str,Double2Str,Long2Str,Int2Str
**#$ 
*/

long Str2Oct(data,size)  
char 	*data;
int		size;
{
	char tmp[101];	
	long val;
	char	*ptr;

	memset(tmp,0,101);
	memcpy(tmp,data,size);tmp[size]=0;
	size = strlen(tmp);
	ptr = &tmp[size];
	val =  strtol(tmp,&ptr,8);
	return (val);
}

/*#@
**	Function 	: Conversion Float to String value 
**	Syntax   	: char *Float2Str(float fval,char *str,int size,int point);
**  Prototype in: strcnv.h
**  Libary    in: libbasic.a 
**	Remark		:  
**				  Fill left value '0'          
**	Return Value: 
**				  Conversion  string pointer    	
**  See also 	: Pow Str2Dbl,Str2Int,Str2Float,Str2Long,
**				  Str2Hex, Str2Oct  Float2Str,Double2Str,Long2Str,Int2Str
**#$ 
*/

char *Float2Str(fval,str,size,point)
float fval; 
char *str;
int size;
int point;
{
	char sval[100];
	char *cp;
	int i;

	sprintf(sval,"%*.*f",size,point,fval);
	memset(str,0,size);

	if(point!=0){
		cp=(char *)strtok(sval,".");	
		while(cp!=NULL){
			strcat(str,cp);	
			cp = (char *)strtok(NULL,".");
		}
	}else memcpy(str,sval,strlen(sval));
	cp=str;
	for(i=0;i<strlen(str);i++){
		if(*cp==' ') *cp ='0'; 
		cp++;
	}

	return(str);
}

/*#@
**	Function 	: Conversion Double to String value 
**	Syntax   	: char *Double2Str(double fval,char *str,int size,int point);
**  Prototype in: strcnv.h
**  Libary    in: libbasic.a 
**	Remark		:  
**				  Fill left value '0'          
**	Return Value: 
**				  Conversion  string pointer    	
**  See also 	: Pow Str2Dbl,Str2Int,Str2Float,Str2Long,
**				  Str2Hex, Str2Oct  Float2Str,Double2Str,Long2Str,Int2Str
**#$ 
*/

char *Double2Str(dval,str,size,point)
double dval; 
char *str;
int size;
int point;
{
	int i;
	char sval[100];
	char *cp;

	sprintf(sval,"%*.*lf",size,point,dval);
	memset(str,0,size);

	if(point!=0){
		cp=(char *)strtok(sval,".");	
		while(cp!=NULL){
			strcat(str,cp);	
			cp = (char *)strtok(NULL,".");
		}
	}else memcpy(str,sval,strlen(sval));
	cp=str;
	for(i=0;i<strlen(str);i++){
		if(*cp==' ') *cp ='0'; 
		cp++;
	}
	return(str);
}

/*#@
**	Function 	: Conversion Long to String value 
**	Syntax   	: char *Long2Str(float fval,char *str,int size);
**  Prototype in: strcnv.h
**  Libary    in: libbasic.a 
**	Remark		:  
**				  Fill left value '0'          
**	Return Value: 
**				  Conversion  string pointer    	
**  See also 	: Pow Str2Dbl,Str2Int,Str2Float,Str2Long,
**				  Str2Hex, Str2Oct  Float2Str,Double2Str,Long2Str,Int2Str
**#$ 
*/

char *Long2Str(lval,str,size)
long lval;
char *str;
int size;
{
	memset(str,0,size);
	sprintf(str,"%#0**ld",size,size,lval);
	return(str);
}

/*#@
**	Function 	: Conversion Int to String value 
**	Syntax   	: char *Int2Str(int ival,char *str,int size);
**  Prototype in: strcnv.h
**  Libary    in: libbasic.a 
**	Remark		:  
**				  Fill left value '0'          
**	Return Value: 
**				  Conversion  string pointer    	
**  See also 	: Pow Str2Dbl,Str2Int,Str2Float,Str2Long,
**				  Str2Hex, Str2Oct  Float2Str,Double2Str,Long2Str,Int2Str
**#$ 
*/
char *Int2Str(ival,str,size)
int ival;
char *str;
int size;
{
	memset(str,0,size);
	sprintf(str,"%#0**d",size,size,ival);
	return(str);
}


double Asc2Double(str,size)
char *str;
int  size;
{
	char tmp[101];
	char *ptr;

	if(size>100) 	size=100;
	if(size<0)		size=0;
	memcpy(tmp,str,size);tmp[size]=0;
	ptr = &tmp[size];
	return(strtod(tmp,&ptr));
}

float Asc2Float(str,size)
char *str;
int  size;
{
	char tmp[101];
	char *ptr;
	if(size>100) 	size=100;
	if(size<0)		size=0;
	memcpy(tmp,str,size);tmp[size]=0;
	ptr = &tmp[size];
	return((float)strtod(tmp, &ptr)); 
	/* AIX 6000 
	return(strtof(tmp,ptr)); 
	*/
}

int Long2CommaStr(value,dest)
long value;
char *dest;
{
	short i,len,p,index=0;	
	char tmp[100],*cp;

	sprintf(tmp,"%ld",value);

	if((len = strlen(tmp)) <=0 || len>100) return 0;	
	for(i=0,p=len;i<len;i++,p--){
		dest[index++] = tmp[i];
		if(!((p-1)%3) && p > 3) {
			dest[index++]=',';
		}
	}
	dest[index]=0;
	
	return 1;
	//return TRUE;
}
