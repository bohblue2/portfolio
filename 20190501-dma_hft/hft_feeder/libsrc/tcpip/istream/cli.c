/***********************************************************************/
/* Stream socket Server                                                */
/* NAME    : cli.c                                                     */
/* DATE    : 2002-09-25                                                */
/* REMARKS : usage :  cli [host] [port] [cnt]                          */
/***********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define SOCK_TIMEOUT  5

/*******************************************
 main function
/*******************************************/
main(argc, argv)
int argc;
char **argv;
{
int fd;
char buff[1024];
int  i, cnt, rtn;
	if(argc != 4){
		printf("%s <host> <port> <cnt>\n", argv[0]);
		exit(0);
	}
	fd = OpenInetStreamClient(argv[1], atoi(argv[2]));
	if(fd < 0){
		printf("%s : <%s> <%s> open error!\n", argv[0], argv[1], argv[2]);
		exit(0);
	}

	cnt = atoi(argv[3]);

	for(i = 0; i < cnt; i++){
		memset(buff, 0x00, 1024);
		sprintf(buff, "INDEX[%8d]", i);
		memset(buff + 15, 'M', 900);

		rtn = WriteStream2(fd, buff, strlen(buff));

		printf("INDEX[%d]rtn[%d]\n", i, rtn);
	}

	close(fd);
}
