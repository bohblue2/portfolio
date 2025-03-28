////////////////////////////////////////////////////////////////////////////////
// Description  : 로깅 라이브러리
// File Name    : logctl.c
// Author       :
// Notes        :
//━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
// Date         :
////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/stat.h>
#include <libgen.h> /* basename */
#include <sys/timeb.h>

#define LOG_SIZE 	9215

static char *log_filename = NULL;
static char buffer[64];
static FILE *logfp = NULL;

int CleanLogfile(char *pt, char *f, int gdate);


// 출처: https://arrkaize86.tistory.com/entry/현재-시간의-밀리세컨드-구하는-방법 [송군함대]
void GetMilSecStr(char *dt)
{
    struct timeb itb;
    struct tm *lt;

    ftime(&itb);
    lt = localtime(&itb.time);
    memset(dt , 0x00 , sizeof(dt));
    // format : YYMMDDhhmmssuuuuuu
    /*
    sprintf(dt, "%04d%02d%02d%02d%02d%02d%03d"
            , lt->tm_year + 1900
            , lt->tm_mon + 1
            , lt->tm_mday
            , lt->tm_hour, lt->tm_min, lt->tm_sec
            , itb.millitm);
     */
     sprintf(dt, "%02d%02d%02d%03d"
            , lt->tm_hour, lt->tm_min, lt->tm_sec
            , itb.millitm);            
} 





/*******************************************************************************
 * LOG file을 생성한다.
 * Prototype : int ErrorLog(char *pathname, char *filename, int gdate)
 * Argument  : char *pathname, char *filename, int gdate;
 * Return    : 파일생성 완료 :  1
 *             파일생성 실패 : -1
 ******************************************************************************/
int InitDebugLog(char *pathname, char *filename, int gdate)
{
	int	pathlen, filelen, rtn;
	char	string[10];
	char	path[255], fname[255];

	time_t now;
	struct tm *l_time;

	memset(buffer, 0x00, sizeof(buffer));
	memset(string, 0x00, sizeof(string));

	memset(path  , 0x00, sizeof(path  ));
	memset(fname , 0x00, sizeof(fname ));

	pathlen = strlen(pathname);
	filelen = strlen(filename);
	if(pathlen == 0 || filelen == 0) return -1;

	if(pathname[pathlen-1] == '/') {
		pathname[pathlen-1] = 0x00;
		pathlen--;
	}

    printf("## path[%s] fname[%s] [%s]gdate[%d]\n", pathname, filename, basename(filename), gdate);
    
	// Clean log file
	/*
	if(gdate > 0) {

		// Directory
		#if 0
		//if(pathname[0] == '/')
		//	sprintf(path, "%s%s" , getenv("HOME"), pathname);
		//else	sprintf(path, "%s/%s", getenv("HOME"), pathname);
		#else
		sprintf(path, "%s", pathname);
		#endif

		// Logfilename
		sprintf(fname, "%s", basename(filename));
		//sprintf(fname+filelen, "%2.2s", ".*");

        
		rtn = CleanLogfile(path, fname, gdate);
		
		//printf("CleanLogfile : path[%s] fname[%s] gdate[%d] rtn[%d]\n",
		//	path, fname, gdate, rtn);
		//printf("## AFTER ## path[%s] fname[%s] rtn[%d] gdate[%d]\n", path, fname, rtn, gdate);
	}
    */
    
    printf("## path[%s] fname[%s] gdate[%d]\n", path, basename(filename), gdate);

	setlocale(LC_TIME, "");
	now = time((time_t *)NULL);
	l_time = localtime(&now);
	strftime(string, sizeof string, "%m%d", l_time);

	// Logging File
	#if 0
	//if(pathname[0] == '/')
	//	sprintf(buffer, "%s%s/%s.%s" , getenv("HOME"), pathname, filename, string);
	//else 	sprintf(buffer, "%s/%s/%s.%s", getenv("HOME"), pathname, filename, string);
	#else
	sprintf(buffer, "%s/%s.%s" , pathname, basename(filename), string);
	#endif

#if 0
printf("pathname[%s]filename[%s]path[%s]buffer[%s]\n", pathname, filename, path, buffer);
sleep(5);
#endif

	log_filename = buffer;

	return 1;
}

/*******************************************************************************
 * LOG 찍는 함수
 * Prototype : void DebugLog(char *format, ...)
 * Argument  : 가변길이 arguments
 * Return    : void
 ******************************************************************************/
void Log(char *format, ...)
{
	char buf[LOG_SIZE]; /* ## Error Msg의 크기 ## */

	int status;
	va_list arglist;

	memset(buf, 0x00, sizeof(buf));
	va_start(arglist, format);
	status = vsprintf(buf, format, arglist);
	va_end(arglist);

	if(strlen(buf) + 1 > sizeof(buf) || status == EOF) {
		printf("[Err] ErrorLog(): Message is too long or invalid.");
		return;
	}

	if(log_filename != NULL) { /* Log를 찍을 파일이 확인(INIT)되었을 경우만 수행 */
		FILE *fp;

		if((fp = fopen(log_filename, "at")) == NULL) {
			printf("[Err] DebugLog(): Log file[%s] open Error!!\n", log_filename);
			return;
		} else {
			///////////////////////////////////
			char timestr[18];
			/*
			time_t tl;
			struct tm *tm;

			tl = time(NULL);
			tm = localtime(&tl);
			strftime(timestr, sizeof(timestr), "%H%M%S", tm);
            */
            
			memset(timestr, 0x00, sizeof(timestr));
			GetMilSecStr(timestr);
			fprintf(fp, "%s>%s", timestr, buf);
			fclose(fp);
			///////////////////////////////////
		}
	} else {
		printf("[Err] ErrorLog(): Log file is not define!!\n");
		return;
	}

	// return;
}

/*******************************************************************************
 * filename을 비교한다.
 * Prototype : static int _Comparefilename(hstr, tstr, fname)
 * Argument  : char *hstr, *tstr, *fname;
 *     주의) 모든 arguments는 NULL로 끝나는 문자열 이어야만 한다.
 * Return    : 같은 유형 : 1
 *             다른 유형 : 0
 ******************************************************************************/
static int _Comparefilename(hstr, tstr, fname)
char *hstr;  /* 비교 형태의 "*" 이전 string*/
char *tstr;  /* 비교 형태의 "*" 이후 string*/
char *fname; /* 비교대상 file name         */
{
char *p = NULL;
	if(!strlen(hstr) && !strlen(tstr)) return 0;
	if(!strlen(hstr)){		/* "*"가 맨처음 있는 형태    */
		p = (char *)strstr(fname, tstr);
		if(!p) return 0;
		if(strlen(p) == strlen(tstr)) return 1;
		else return 0;
	}else if(!strlen(tstr)){	/* "*"가 맨 나중에 있는 형태 */
		if( strncmp(hstr, fname, strlen(hstr)) ) return 0;
		else return 1;
	}else{				/* "*"가 중간에 있는 경우    */
		if( strncmp(hstr, fname, strlen(hstr)) ) return 0;

		p = (char *)strstr(fname, tstr);
		if(!p) return 0;
		if(strlen(p) == strlen(tstr)) return 1;
		else return 0;
	}
}

/*******************************************************************************
 * 일자를 계산한다.(차이를 return 한다)
 * Prototype : static int _DiffDate(time1, time2)
 * Argument  : time_t time1, time2;
 * Return    : int ; 차이 일
 *             일단위 계산으로 다음과 같다.
 *             time1 > time2  : 양수
 *             time1 < time2  : 음수
 *             time1 == time2 : 0
 ******************************************************************************/
static  int _DiffDate(time1, time2)
time_t time1, time2;
{
int  difd, d1, d2;
char date1[30], date2[30];
	strftime(date1, 30, "%j", localtime(&time1));
	strftime(date2, 30, "%j", localtime(&time2));
	d1 = atoi(date1); d2 = atoi(date2);
	if(d1 == d2) return 0; /* 같은 날 */
	difd = d1 - d2;
	return difd;
}

/*******************************************************************************
 * Log를 지운다. 
 * 오늘부터 몇일간의 log file만 보관한다.
 * Prototype : void CleanLogfile(path, fname, gdate)
 * Argument  : char *path; Directory
 *             char *fname; Logfilename 형태
 *               Meta character를 하나만 지원한다.
 *             ex) "SISE.LOG.03.*", "SISE.LOG.*.03", "*.LOG.1207.03"
 *             int   gdate; 보관일수 (오늘을 포함한 보관일수)
 * Return    : int; SUCCESS : 지운 logfile 갯수
 *                  FAIL    : -1 -> DIR open error!
 * 주의) 해가 넘어간 logfile은 무조건 지운다.
 ******************************************************************************/
int CleanLogfile(pt, f, gdate)
char *pt;	/* Directory                          */
char *f;	/* Logfilename 형태                   */
int   gdate;	/* 보관일수 (오늘을 포함한 보관일수)  */
{
int            cnt = 0, dif;
DIR           *dir;
struct dirent *ent;
struct stat    st;
char           fname[255], hstr[255], tstr[255], *namep, *p;
time_t         curr;
	
	time(&curr);

	dir = opendir(pt);
	if(!dir) return -1;

	memset(hstr, 0x00, 255); 
	memset(tstr, 0x00, 255);

	if(*f == '*') strcpy(tstr, f + 1);
	else if(*(f + strlen(f) -1 ) == '*')
		strncpy(hstr, f, strlen(f) - 1);
	else{
		p = (char *)strchr(f, '*');
		if(!p) strcpy(hstr, f);
		else {
			*p= 0x00; 
			strcpy(hstr, f); 
			strcpy(tstr, p+1); 
		}
	}

	while( (ent = readdir(dir)) != NULL){
		if(!ent->d_ino) continue;

		namep = (char *)ent->d_name;
		sprintf(fname, "%s/%s", pt, namep);
		stat(fname, &st);
		if(st.st_mode & S_IFDIR) continue;
		if(!_Comparefilename(hstr, tstr, namep)) continue;
		dif = abs(_DiffDate(curr, st.st_mtime));
		if(!gdate && dif != gdate){unlink(fname); cnt++;}
		else if(gdate < dif) {unlink(fname); cnt++;}
	}
	closedir(dir);
	return cnt;
}
////////////////////////////////////////////////////////////////////////////////
// Program End
////////////////////////////////////////////////////////////////////////////////

