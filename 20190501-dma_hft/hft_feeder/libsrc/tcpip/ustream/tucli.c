/*
 * Test UNIX STREAM SOCKET
 * Name : tucli.c
 * Date : 1997.01.13
 * By   : PentaSoft CO.,Ltd(Sagittarius)
 */
#include <stdio.h>
#include <stdlib.h>

#define PATH_UNIXFD "/home/kskoo/log/unixfd/fdUNIX"

main(argc, argv)
int argc;
char **argv;
{
char buff[1024];
int  fd, i;

	fd = OpenUnixStreamClient(PATH_UNIXFD);	
	if(fd < 0){
		printf("Error! OpenUnixStreamClient() fd[%d]\n", fd);
		exit(0);
	}

	memset(buff, 0x00, sizeof(buff));
	for(i = 0; i < 10; i++){
		sprintf(buff, "INDEX[%06d]", i);
		WriteStream2(fd, buff, strlen(buff));
	}
	close(fd);
}
