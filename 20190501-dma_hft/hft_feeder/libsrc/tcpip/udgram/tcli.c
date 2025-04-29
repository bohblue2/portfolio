/*
 * Test UNIX DGRAM SOCKET
 * Name : tcli.c
 * Date : 1997.01.13
 * By   : PentaSoft CO.,Ltd(Sagittarius)
 */
#include <stdio.h>
#include <stdlib.h>

//#define DGRAM_NAME "DGRAM.UNIX"
#define DGRAM_NAME "/home/kskoo/log/unixfd/fdDGRAM"

main(argc, argv)
int argc;
char **argv;
{
char buff[1024];
int  rtn, fd, i;
	fd = OpenUnixDgramClient(DGRAM_NAME);	
	if(fd < 0){
		printf("Error! OpenUnixDgramClient() rtn[%d]\n", fd);
		exit(0);
	}
	memset(buff, 0x00, 1024);
	for(i = 0; i < 10; i++){
		sprintf(buff, "INDEX[%06d]", i);
		SendUnixDgram(fd, buff, strlen(buff));
	}
	close(fd);
}
