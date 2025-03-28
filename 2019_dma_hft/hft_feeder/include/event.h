/*
 * Event header 
 * Name : event.h
 * Date : 1997.10.18
 * By   : PentaSoft Co.,Ltd. (Sagittarius)
 */
#if !defined (_EVNET_H_)
#define _EVENT_H_

#ifdef _RS6000_
#include <sys/select.h>
#endif
#include <sys/types.h>
#include <sys/time.h>
#include <unistd.h>

typedef struct _EVENT_LIST{
	int                fd;
	int                event_id;
	int                tout, rtime, answer;
	int                del;
	int                (*handler)();
	struct _EVENT_LIST *next;
}EVENT_LIST; 
typedef struct _EVENT{
	fd_set         EventEntry;
	struct timeval Timeout;
	int            Totalcnt;
	int            Maxfd;
	int            RUNNING;
	long           Seconds;
	EVENT_LIST    *Eventlist;
}EVENT;
extern EVENT *AppEventInit        ();
extern int    AppAddEventAutoId   (EVENT *, int, int, int, int (*)());
extern int    AppAddEvent         (EVENT *, int, int, int, int, int (*)());
extern int    AppDelEvent         (EVENT *, int);
extern void   AppEventLoopShutdown(EVENT *);
extern void   AppEventLoop        (EVENT *);
#endif
