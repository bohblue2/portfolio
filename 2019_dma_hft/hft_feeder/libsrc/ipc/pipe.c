////////////////////////////////////////////////////////////////////////////////
// Description  : Named Pipe Interface Libary
// File Name    : pipe.c
// Author       :
// Notes        :
//━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
// Date         :
////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define PERM 0666

/******************************************************************************
 * Function 	: Open named pipe 
 * Prototype	: int Opennamedpipe(uchar *path ,int mode);
 * Remark	: permission default 0666 
 *		  path -> pipe name path	
 * 		  mode -> O_RDONLY O_WRONLY O_RDWR O_NDELAY ...	
 * Return Value : On success , positive value int type file descriptor
 *		  Otherwise,   error -1
 *  See also 	: Makenamedpipe Opennamedpipe,Closenamedpipe,Deletenamedpipe
 *		  Serverpipe,Clientpipe
 ******************************************************************************/
int Opennamedpipe(char *path, int mode)
{
	int pipe;

	pipe=open((char *)path, mode);
	if(pipe < 0)	return -1;

	return pipe;
}

/******************************************************************************
 * Function 	: Client processor open name pipe
 * Prototype	: int Clientpipe(uchar *path );
 * Remark	: default mode set O_RDWR
 *		  path -> pipe name path
 * 		  Ineternal Call Opennamedpipe
 * Return Value : On success , positive value int type File descriptor
 *		  Otherwise,   error -1
 *  See also 	: Makenamedpipe Opennamedpipe,Closenamedpipe,Deletenamedpipe
 *		  Serverpipe,Clientpipe
 ******************************************************************************/
int Clientpipe(char *pname)
{
	int pipe;

	/* O_WRONLY : 파일은 쓰기전용으로  열린다. */
	/* O_NDELAY : 파일은 비블록 모드로 열린다. */
	pipe= Opennamedpipe(pname,O_WRONLY|O_NDELAY);
	if(pipe<0) return -1;

	return (pipe);
}

/******************************************************************************
 * Function 	: Close name pipe 
 * Prototype	: int Closenamedpipe(int pipe);
 * Remark	: 
 * Return Value : On success , positive value 
 *		  Otherwise,   error -1
 *  See also 	: Makenamedpipe Opennamedpipe,Closenamedpipe,Deletenamedpipe
 *		  Serverpipe,Clientpipe
 ******************************************************************************/
int Closenamedpipe(int pipe)
{
	if(close(pipe) < 0) return -1;

	return 1;
}

/******************************************************************************
 * Function 	: Delete name pipe 
 * Prototype	: int Deletenamedpipe(int pipe,uchar *path); 
 * Remark	: path -> pipe name path	
 *		  system call unlink
 * Return Value : Return Value: On success , positive value 
 *		  Otherwise,   error -1
 *  See also 	: Makenamedpipe Opennamedpipe,Closenamedpipe,Deletenamedpipe
 *		  Serverpipe,Clientpipe
 ******************************************************************************/
int Deletenamedpipe(int pipe, char *pname)
{
	close(pipe);

	if(unlink(pname)<0) return -1;

	return 1;
}

/******************************************************************************
 * Function 	: Make named pipe 
 * Prototype	: int Makenamedpipe(uchar *path ,int mode);
 * Remark	: permission default 0666 
 *		  path -> pipe name path	
 * 		  mode -> O_RDONLY O_WRONLY O_RDWR O_NDELAY ...	
 * Return Value : On success , positive value int type file descriptor
 *		  Otherwise,   error -1
 *  See also 	: Makenamedpipe Opennamedpipe,Closenamedpipe,Deletenamedpipe
 *		  Serverpipe,Clientpipe
 ******************************************************************************/
int Makenamedpipe(char *path, int mode) 
{
int pipe;

	/* ## mknod - make block or character special files ## */
	/* S_IFIFO : 이 매크로는 FIFO 나 pipe를 위한 파일 타입 코드의 값을 나타낸다. */
	if(mknod((char *)path, S_IFIFO, 0) < 0) return -1;

	chmod((char *)path, PERM);

	pipe=open((char *)path,mode);
	if(pipe<0) return -1;

	return pipe;
}

/******************************************************************************
 * Function 	: Read Data from named pipe 
 * Prototype	: int Readdatafromnpipe(fd, uchar *data);
 * Remark	: 
 * Return Value : 
 *  See also 	: Makenamedpipe Opennamedpipe,Closenamedpipe,Deletenamedpipe
 *		  Serverpipe,Clientpipe
 ******************************************************************************/
int Readdatafromnpipe(int fd, unsigned char *buff)
{
int size, rtn;

  /*-------+-------+-------------------+---------*
           | (int) |                   |
     FIFO  |  size |       data        |
   *-------+-------+-------------------+---------*/
	rtn = read(fd, &size, sizeof(int)); 
	if(rtn < 0) return rtn;

	return read(fd, buff, size);
}

/******************************************************************************
 * Function 	: Send Data to named pipe 
 * Prototype	: int Senddata2npipe(fd, uchar *data ,int size);
 * Remark	: 
 * Return Value : 
 *  See also 	: Makenamedpipe Opennamedpipe,Closenamedpipe,Deletenamedpipe
 *		  Serverpipe,Clientpipe
 ******************************************************************************/
int Senddata2npipe(int fd, unsigned char *data, int size)
{
unsigned char buff[4096];
int  rtn;
	memset(buff, 0x00, sizeof(buff));
	memcpy(buff, (unsigned char *)&size, sizeof(int));
	memcpy(buff + sizeof(int), data, size);

  /*-------+-------+-------------------+---------*
           | (int) |                   |
     FIFO  |  size |       data        |
   *-------+-------+-------------------+---------*/

	size += sizeof(int);
	rtn = write(fd, buff, size);

	if(rtn > 0) return rtn - sizeof(int);
	else        return rtn;
}

/******************************************************************************
 * Function 	: Server processor make name pipe 
 * Prototype	: int Serverpipe(uchar *path,int *wpipe, delay);
 * Remark	: Ineternal Call Makenamedpipe
 *		  path -> pipe name path	
 * 		  wpipe -> Not use file descriptor (open WRONLY )
 * 		  delay -> 1 : Default, 0 : O_NDELAY mode.
 * Return Value : On success , positive value int type File descriptor 
 *		  Otherwise,   error -1
 *  See also 	: Makenamedpipe Opennamedpipe,Closenamedpipe,Deletenamedpipe
 *		  Serverpipe,Clientpipe
 ******************************************************************************/
int Serverpipe(char *pname, char *wpipe, int delay)
{
int pipe, st = 0;
	unlink(pname);	

	/* ## mknod - make block or character special files ## */
	/* S_IFIFO : 이 매크로는 FIFO 나 pipe를 위한 파일 타입 코드의 값을 나타낸다. */
	if(mknod(pname, S_IFIFO | PERM, 0) < 0) return -1;	

	chmod(pname, PERM); /* PERM 0666 */

	/* O_WRONLY : 파일은 쓰기전용으로  열린다. */
	/* O_NDELAY : 파일은 비블록 모드로 열린다. */
	pipe = Opennamedpipe(pname, O_RDWR | O_NDELAY);
	if(pipe < 0) return -1;

	/* ## 1 : Default, 0 : O_NDELAY mode ## */
	if(delay) {
		st = fcntl(pipe, F_GETFL); /* F_GETFL : file descriptor의 flag를 읽는다. (모든 플래그(.BR open (2)에 의해 설정된)들은 리턴된다.) */
		st &= ~O_NDELAY;
		fcntl(pipe, F_SETFL, st);  /* F_SETFL : arg 에 의해 지정된 값을 기술자의 플래그로 설정한다. 오직 O_APPEND, O_NONBLOCK 그리고 O_ASYNC 이 설정될 수 있다. 다른 플래그들은 영향을 받지 않는다. */
	}

	*wpipe = Opennamedpipe(pname,O_WRONLY);

	return (pipe);
}

/******************************************************************************
 * Function 	:  Server processor make name pipe 
 * Prototype	: int Serverpipe2(pname, wpipe, delay)
 * Remark	: 
 * Return Value : 
 *  See also 	:
 *
 ******************************************************************************/
int Serverpipe2(char *pname, char *wpipe, int delay)
{
int pipe;

	unlink(pname);	

	if(delay)  pipe = Makenamedpipe(pname, O_RDONLY);
	else       pipe = Makenamedpipe(pname, O_RDONLY|O_NDELAY);

	*wpipe = Opennamedpipe(pname,O_WRONLY);

	return (pipe);
}
////////////////////////////////////////////////////////////////////////////////
// Program End
////////////////////////////////////////////////////////////////////////////////
