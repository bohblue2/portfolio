/*
 * Test unix dgram lib
 * Name : tsvr.c
 * Date : 1997.01.13
 * By   : PentaSoft Co.,Ltd(Sagittarius)
 */
#include <stdio.h>
#include <stdlib.h>
#include "event.h"

//#define DGRAM_NAME "DGRAM.UNIX"
#define DGRAM_NAME "/home/kskoo/log/unixfd/fdDGRAM"

EVENT  *Event;

int Handler(event, fd, type)
EVENT  *event;
int fd, type;
{
char buff[1024];
int  rtn;
	memset(buff, 0x00, 1024);
	rtn = ReadUnixDgram(fd, buff, 1024);
	if(rtn <= 0){
		printf("Error! ReadUdp() rtn[%d]\n", rtn);
		AppDelEvent(event, type);
		//AppEventLoopShutdown();
		return -1;
	}
	printf("Read[%.*s]\n", rtn, buff);
	return 1;
}

main(argc, argv)
int argc;
char **argv;
{
int fd;

	Event = AppEventInit();

	fd = OpenUnixDgramServer(DGRAM_NAME);
	if(fd < 0){
		printf("Error! OpenUnixDgramServer Rtn[%d]\n", fd);
		exit(0);
	}

	AppAddEventAutoId(Event, fd, 3000, 0, Handler);
	AppEventLoop(Event);

	exit(0);
}
