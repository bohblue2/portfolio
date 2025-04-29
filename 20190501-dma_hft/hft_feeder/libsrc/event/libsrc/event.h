/* ############################################ */
/* # Event header 				*/
/* # 		(Using select())		*/
/* # NAME   : event.h				*/
/* # Author : Kiseung Koo			*/
/* ############################################ */

#if !defined (_EVNET_H_)
#define _EVENT_H_

#ifdef _RS6000_
#include <sys/select.h>
#endif
#include <sys/types.h>
#include <sys/time.h>
#include <unistd.h>

typedef struct _EVENT_LIST {
	int	fd;		// Event fd (I)  
	int	event_id;	// Event identifier(I)
	int	tout;		// Timeout Value (Microsecond:1sec/100)
	int	rtime;
	int	answer;		// Need reporting timeout
	int	del;		// 1:delete 0:live
	int	(*handler)();	// Event processing function.(I)
	struct _EVENT_LIST *next;
} EVENT_LIST; 

/*
typedef struct fd_set {
        u_int   fd_count;		// how many are SET?   : 설정하는 소켓의 번호
        SOCKET  fd_array[FD_SETSIZE];	// an array of SOCKETs : 설정된 소켓의 배열 // #define __FD_SETSIZE	1024
} fd_set;

struct timeval
  {
    __time_t tv_sec;		// Seconds.
    __time_t tv_usec;		// Microseconds.
  };
*/

typedef struct _EVENT {
	fd_set	EventEntry;	
	struct timeval Timeout;
	int	Totalcnt;	// 만들어진 EVENT_LIST의 Count..
	int	Maxfd;
	int	RUNNING;	// AppEventLoop()에서 RUNNING==1 동안 반복 실행..
	long	Seconds;
	EVENT_LIST *Eventlist;
} EVENT;

extern EVENT *AppEventInit        ();
extern int    AppAddEventAutoId   (EVENT *, int, int, int, int (*)());
extern int    AppAddEvent         (EVENT *, int, int, int, int, int (*)());
extern int    AppDelEvent         (EVENT *, int);
extern void   AppEventLoopShutdown(EVENT *);
extern void   AppEventLoop        (EVENT *);

void  AppChangeEventTimeout(EVENT *, long);
int   AppGetFdByEventId(EVENT *, int);
int   AppGetEventIdByFd(EVENT *, int);

#endif
