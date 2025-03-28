/*
 * Test unix stream lib
 * Name : tusvr.c
 * Date : 1997.01.13
 * By   : PentaSoft Co.,Ltd(Sagittarius)
 */
#include <stdio.h>
#include <stdlib.h>
#include "event.h"

#define PATH_UNIXFD "/home/kskoo/log/unixfd/fdUNIX"

EVENT  *Event;

int Handler(event, fd, type)
EVENT *event;
int fd, type;
{
char buff[1024];
int  rtn;
	memset(buff, 0x00, sizeof(buff));

	rtn = ReadStream2(fd, buff);
	if(rtn <= 0){
		printf("[Err] ClientDataHandler Connect Close!! fd[%d] rtn[%d] type[%d]\n", fd, rtn, type);
		AppDelEvent(event, type);
		//AppEventLoopShutdown(event);
		return -1;
	}

	printf("Handler Read[%d][%s]\n", rtn, buff);
	return 1;
}

int Connect(event, fd, type)
EVENT *event;
int fd, type;
{
int newfd;
char buff[1024];

	newfd = WaitConnect(fd, buff);
	if(newfd < 0){
		printf("Error Accept!\n");
		//AppEventLoopShutdown(event);
		return 1;
	}

	/*
	SetSocketOption(newfd);
	*/
//	AppAddEvent(newfd, 1001, 30000, 0, Handler);
	AppAddEventAutoId(event, newfd, 3000, 0, Handler);
	return 1;
}

main(argc, argv)
int argc;
char **argv;
{
int fd;
	Event = AppEventInit();

	fd = OpenUnixStreamServer(PATH_UNIXFD);
	if(fd < 0){
		printf("Error! OpenUnixDgramServer Rtn[%d]\n", fd);
		exit(0);
	}

	AppEventInit();
//	AppAddEvent(fd, 1000, 30000, 0, Connect);
	AppAddEventAutoId(Event, fd, 3000, 0, Connect);
	AppEventLoop(Event);
	exit(0);
}
