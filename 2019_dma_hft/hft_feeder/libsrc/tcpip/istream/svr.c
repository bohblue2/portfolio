/***********************************************************************/
/* Stream socket Server                                                */
/* NAME    : svr.c                                                     */
/* DATE    : 2002-09-25                                                */
/* REMARKS : usage :  svr [port]                                       */
/***********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/uio.h>
#include "event.h"

EVENT *Event;
char *pname;

/*******************************************************************************
 * Data Handler function
 * Prototype : int DataHandler2(EVENT *, int, int)
 * Argument  : EVENT *event, int fd, int type;
 * Return    : SUCCESS return 1;
 ******************************************************************************/
int DataHandler2(event, fd, type)
EVENT *event;
int fd, type;
{
int rtn;
char buff[1024];
FILE *fp;
	rtn= ReadStream2(fd, buff);
	if(rtn <= 0){
		printf("%s : connection close!\n", pname);
		AppDelEvent(event, type);
		close(fd);
		return 1;
	}
	fp = fopen("LOG.Dat", "at+");
	printf("[%.*s]\n", rtn, buff);
	fprintf(fp, "[%.*s]\n", rtn, buff);
	fclose(fp);
	
	printf("Client close!!!\n\n\n");
	
	return 1;
}

/*******************************************************************************
 * Connect Handler function
 * Prototype : int ConnectHandler(EVENT *, int, int)
 * Argument  : EVENT *event, int fd, int type;
 * Return    : SUCCESS return 1;
 ******************************************************************************/
int ConnectHandler(event, fd, type)
EVENT *event;
int    fd;
int    type;
{
char addr[32];
int newfd;
	newfd = WaitConnect(fd, addr);
	if(newfd < 0){
		printf("%s : Accept error! errno[%d]\n", pname, errno);
		return 1;
	}

	printf("CONNECT FROM [%s]\n", addr);

	AppAddEventAutoId(event, newfd, 1000, 0, DataHandler2);

	return 1;
}

/*******************************************
 main function
/*******************************************/
main(argc, argv)
int argc;
char **argv;
{
int fd;
char addr[32];

	pname = argv[0];
	if(argc != 2){
		printf("%s <port>\n", pname);	
		exit(0);
	}


	// 그냥한번 해볼려구... 
	GetMyHostCharAddress(addr);
	printf("%s : GetMyHostCharAddress[%s]\n", pname, addr);

	Event = AppEventInit();

	fd = OpenInetStreamServer(atoi(argv[1]));
	if(fd < 0){
		printf("%s : Open error! port[%s]\n", pname, argv[1]);
		exit(0);
	}

	AppAddEventAutoId(Event, fd, 3000, 0, ConnectHandler);

	AppEventLoop(Event);
}
