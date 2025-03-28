////////////////////////////////////////////////////////////////////////////////
// Description  : �α� ���̺귯��
// File Name    : logctl.c
// Author       :
// Notes        :
//������������������������������������������������������������������������������
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


// ��ó: https://arrkaize86.tistory.com/entry/����-�ð���-�и�������-���ϴ�-��� [�۱��Դ�]
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
 * LOG file�� �����Ѵ�.
 * Prototype : int ErrorLog(char *pathname, char *filename, int gdate)
 * Argument  : char *pathname, char *filename, int gdate;
 * Return    : ���ϻ��� �Ϸ� :  1
 *             ���ϻ��� ���� : -1
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
 * LOG ��� �Լ�
 * Prototype : void DebugLog(char *format, ...)
 * Argument  : �������� arguments
 * Return    : void
 ******************************************************************************/
void Log(char *format, ...)
{
	char buf[LOG_SIZE]; /* ## Error Msg�� ũ�� ## */

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

	if(log_filename != NULL) { /* Log�� ���� ������ Ȯ��(INIT)�Ǿ��� ��츸 ���� */
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
 * filename�� ���Ѵ�.
 * Prototype : static int _Comparefilename(hstr, tstr, fname)
 * Argument  : char *hstr, *tstr, *fname;
 *     ����) ��� arguments�� NULL�� ������ ���ڿ� �̾�߸� �Ѵ�.
 * Return    : ���� ���� : 1
 *             �ٸ� ���� : 0
 ******************************************************************************/
static int _Comparefilename(hstr, tstr, fname)
char *hstr;  /* �� ������ "*" ���� string*/
char *tstr;  /* �� ������ "*" ���� string*/
char *fname; /* �񱳴�� file name         */
{
char *p = NULL;
	if(!strlen(hstr) && !strlen(tstr)) return 0;
	if(!strlen(hstr)){		/* "*"�� ��ó�� �ִ� ����    */
		p = (char *)strstr(fname, tstr);
		if(!p) return 0;
		if(strlen(p) == strlen(tstr)) return 1;
		else return 0;
	}else if(!strlen(tstr)){	/* "*"�� �� ���߿� �ִ� ���� */
		if( strncmp(hstr, fname, strlen(hstr)) ) return 0;
		else return 1;
	}else{				/* "*"�� �߰��� �ִ� ���    */
		if( strncmp(hstr, fname, strlen(hstr)) ) return 0;

		p = (char *)strstr(fname, tstr);
		if(!p) return 0;
		if(strlen(p) == strlen(tstr)) return 1;
		else return 0;
	}
}

/*******************************************************************************
 * ���ڸ� ����Ѵ�.(���̸� return �Ѵ�)
 * Prototype : static int _DiffDate(time1, time2)
 * Argument  : time_t time1, time2;
 * Return    : int ; ���� ��
 *             �ϴ��� ������� ������ ����.
 *             time1 > time2  : ���
 *             time1 < time2  : ����
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
	if(d1 == d2) return 0; /* ���� �� */
	difd = d1 - d2;
	return difd;
}

/*******************************************************************************
 * Log�� �����. 
 * ���ú��� ���ϰ��� log file�� �����Ѵ�.
 * Prototype : void CleanLogfile(path, fname, gdate)
 * Argument  : char *path; Directory
 *             char *fname; Logfilename ����
 *               Meta character�� �ϳ��� �����Ѵ�.
 *             ex) "SISE.LOG.03.*", "SISE.LOG.*.03", "*.LOG.1207.03"
 *             int   gdate; �����ϼ� (������ ������ �����ϼ�)
 * Return    : int; SUCCESS : ���� logfile ����
 *                  FAIL    : -1 -> DIR open error!
 * ����) �ذ� �Ѿ logfile�� ������ �����.
 ******************************************************************************/
int CleanLogfile(pt, f, gdate)
char *pt;	/* Directory                          */
char *f;	/* Logfilename ����                   */
int   gdate;	/* �����ϼ� (������ ������ �����ϼ�)  */
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

