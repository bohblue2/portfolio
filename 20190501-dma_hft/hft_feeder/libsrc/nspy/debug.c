////////////////////////////////////////////////////////////////////////////////
// Description  : 네트워크 로깅 라이브러리
// File Name    : debug.c
// Author       :
// Notes        :
//━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
// Date         :
////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <time.h>

#define NETSPY_PATH "NETSPY.UDP.SAGIT"
#define NETSPY_FILE "NETSPY.LOG"

#define MAX_BUFF_LEN  4096

static int Spyfd = -1;

/******************************************************/
/* initialize Net spy                                 */
/* Prototype : static int InitNetspy()                */
/* Return    : SUCCESS return 1, FAIL return -1       */
/******************************************************/
static int InitNetspy()
{
    struct  sockaddr_un serv_addr;
    int     sockfd, sverlen;
	char 	unixpath[96];

	/*
        if(getenv("OD_HOME") != NULL)
                sprintf(unixpath, "%s/log/%s", getenv("OD_HOME"), NETSPY_PATH);
        else    sprintf(unixpath, "%s/data/log/%s", getenv("HOME"), NETSPY_PATH);
	*/
	sprintf(unixpath, "%s/log/%s", getenv("HOME"), NETSPY_PATH);

	//printf("unixpath[%s][%d]\n", unixpath, __LINE__); 

	memset(&serv_addr, 0x00, sizeof(serv_addr));
	serv_addr.sun_family = AF_UNIX;
	sprintf(serv_addr.sun_path, "%s", unixpath);
	sverlen = strlen(serv_addr.sun_path) + sizeof(serv_addr.sun_family);

        if((sockfd=socket(AF_UNIX, SOCK_DGRAM, 0)) < 0) {
                fprintf(stderr,"Can't Create CLIENT stream socket\n");
                return -2;
        }

        int     buflen = MAX_BUFF_LEN;
        setsockopt(sockfd, SOL_SOCKET, SO_RCVBUF, (char *)&buflen, sizeof(buflen));
        setsockopt(sockfd, SOL_SOCKET, SO_SNDBUF, (char *)&buflen, sizeof(buflen));

        if(connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) {
                close(sockfd);
                return -3;
        }
        Spyfd = sockfd;

        return 1;
}

/******************************************************/
/* Debug Net spy                                      */
/* Prototype : Debug(va_alist)                        */
/* Return    : SUCCESS return 1                       */
/******************************************************/
void Debug(char *format, ...)
{
FILE    *fp;
char    dumpfile[96], buff[4096], temp[20];
va_list arglist;
int	plen = 0;

    memset(buff, 0x00, sizeof(buff));
    memset(temp, 0x00, sizeof(temp));
    
    /* make logging packet	*/
    va_start(arglist, format);
    vsprintf(buff, format, arglist);
    va_end(arglist);

	plen = strlen(buff);

    if(Spyfd < 0) {
    	if(InitNetspy() < 0) {
    
    		time_t	tl = time(NULL);			
    
    		/* file open	*/
    		strftime(temp, 5, "%m%d", localtime(&tl));
        		/*
        		if(getenv("OD_HOME") != NULL)
        		        sprintf(dumpfile, "%s/log/%s.%s", getenv("OD_HOME"), NETSPY_FILE, temp);
        		else    sprintf(dumpfile, "%s/data/log/%s.%s", getenv("HOME"), NETSPY_FILE, temp);
    		*/
    		sprintf(dumpfile, "%s/log/%s.%s", getenv("HOME"), NETSPY_FILE, temp);
    		//printf("dumpfile[%s][%d]\n", dumpfile, __LINE__); 
    
        		fp = fopen(dumpfile, "atc+");
    
    		/* file logging */
    		strftime(temp, 11, "[%H:%M:%S]", localtime(&tl));
        		if(buff[plen - 1] != '\n')
        		        fprintf(fp, "%s %s\n", temp, buff);
        		else 	fprintf(fp, "%s %s", temp, buff);
    
    		fflush(fp);
    		fclose(fp);
    
    		return;
    	}
    }

    /* network logging */
	send(Spyfd, buff, plen, 0);

	return;
}

/******************************************************/
/* Net spy Close                                      */
/* Prototype : NetspyClose()                          */
/* Return    : return                                 */
/******************************************************/
void NetspyClose()
{
    if(Spyfd >=0)
        close(Spyfd);

    Spyfd = -1;

    return;
}
////////////////////////////////////////////////////////////////////////////////
// Program End
////////////////////////////////////////////////////////////////////////////////
