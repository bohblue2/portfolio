/* ############################################ */
/* # Library test for message queue. (client)	*/
/* # NAME   : event_main.c			*/
/* # Author : Kiseung Koo			*/
/* ############################################ */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>
#include <signal.h>

#include "event.h"

#define DSRC __FILE__
#define DLIN __LINE__

EVENT *Event = NULL;
char  *pname = NULL;
int Func(){}

/******************************************************************************
#extern EVENT *AppEventInit        ();
#extern int    AppAddEventAutoId   (EVENT *, int, int, int, int (*)());
#extern int    AppAddEvent         (EVENT *, int, int, int, int, int (*)());
#extern int    AppDelEvent         (EVENT *, int);

extern void   AppEventLoopShutdown(EVENT *);
extern void   AppEventLoop        (EVENT *);
 ******************************************************************************/
main(int argc, char **argv)
{
int  rtn, fd= 3, i, id;
	Event = AppEventInit();
	for( i = 0; i < 100; i++, fd ++){
		id = AppAddEventAutoId(Event, fd, 3000, 0 ,Func);
		if(id < 0) {
			printf("[Err] AppAddEventAutoId Error occur!! i[%4d] id[%4d]\n", i, id);
		}

		rtn = AppDelEvent(Event, id);
		if(rtn != 1) {
			printf("[Err] AppDelEvent Error occur!! i[%4d] id[%4d]\n", i, id);
		}
		printf("INDEX[%4d] AutoId[%4d]\n", i, id);
	}

	sleep(2);

	for( i = 0; i < 100; i++, fd ++){
		id = i;
		rtn = AppAddEvent(Event, fd, id, 3000, 0 ,Func);
		if(rtn != 1) {
			printf("[Err] AppAddEvent Error occur!! i[%4d] rtn[%4d]\n", i, rtn);
		}

		rtn = AppDelEvent(Event, id);
		if(rtn != 1) {
			printf("[Err] AppDelEvent Error occur!! i[%4d] id[%4d]\n", i, id);
		}
		printf("INDEX[%4d] rtn[%4d]\n", i, rtn);
	}

//	AppEventLoopShutdown(Event);

}
