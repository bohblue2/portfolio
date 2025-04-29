/* ############################################ */
/* # UNIX Application event library		*/
/* # 		(Using select())		*/
/* # NAME   : event.c				*/
/* # Author : Kiseung Koo			*/
/* ############################################ */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <errno.h>

#ifdef _RS6000_
#include <sys/select.h>
#endif

#include "event.h"

#define DEF_TIMEOUT    20000 // AppEventInit() > second 
//#define START_ID       1000

static int Id = 1000; // AppAddEventAutoId()

/******************************************************************************/
/* Time out Processing                                                        */
/* Prototype : static void _TimeoutProcessing()                               */
/* Arguments : void                                                           */
/* Return    : void                                                           */
/* Remarks   : local function                                                 */
/******************************************************************************/
static void _TimeoutProcessing(event)
EVENT *event;
{
register EVENT_LIST *p;

	if(!event->Totalcnt) return;

	p  = event->Eventlist;
	while(p) {
		p->rtime -= event->Seconds; // p->rtime : 혹시 남아있는 시간인가??
		p = (EVENT_LIST *)p->next;
	}

	p  = event->Eventlist;
	while(p){
		if(p->rtime <= 0){
			if(p->answer)
				p->handler(event, p->fd, p->event_id * -1);
			p->rtime = p->tout;
		}
		p = (EVENT_LIST *)p->next;
	}

	return;
}

/******************************************************************************/
/* Clear deleted event item in linked list.                                   */
/* Prototype : static void _ClearDelEvent()                                   */
/* Arguments : void                                                           */
/* Return    : int                                                            */
/*             NO Event entry : 0, SUCESS : 1                                 */
/* Remarks   : local function                                                 */
/******************************************************************************/
static void _ClearDelEvent(event)
EVENT *event;
{
register EVENT_LIST *p, *b;
register int         cnt = 0;

	if(!event->Totalcnt) return;
	b = p = event->Eventlist;

	while(p) {
		if(p->del) { // p->del==1(삭제) 일때..
			if(!cnt) { // EVENT 바로뒤에 EVENTLIST를 삭제할때..
				event->Totalcnt --;
				if(!event->Totalcnt) { // EVENTLIST가 하나도 안 남았을때..
					free(event->Eventlist);
					event->Eventlist = NULL;
					p = NULL;
				} else {
					event->Eventlist = (EVENT_LIST *)p->next;
					free(p);
					p = (EVENT_LIST *)event->Eventlist->next;
				}
				// return; 아닌것 같당...!!
			} else {
				b->next = p->next;
				free(p);
				p = (EVENT_LIST *)b->next;
				event->Totalcnt --;
			}
		} else { // p->del==0 (동작) 일때..
			cnt++;
			b = p;
			p = (EVENT_LIST *)p->next;
		}
	}

	return;
}

/******************************************************************************/
/* Make event fd list for select()                                            */
/* Prototype : void _MakeEventSet()                                           */
/* Arguments : void                                                           */
/* Return    : int                                                            */
/*             NO Event entry : 0, SUCESS : 1                                 */
/* Remarks   : local function                                                 */
/******************************************************************************/
static int _MakeEventSet(event)
EVENT *event;
{
register EVENT_LIST *p;

	if(!event->Totalcnt) return event->Totalcnt; // EVENT_LIST가 남은게 없으면 return event->Totalcnt
	p = event->Eventlist;

	FD_ZERO(&event->EventEntry); // clear all bits in fdset : 모든 소켓 기술자를 세트에서 제거.
	event->Maxfd = 0;
	event->Seconds = p->tout;

	while(p) {
		FD_SET(p->fd, &event->EventEntry); // turn on the bit for fd in fdset : 지정된 소켓 기술자를 세트에 추가.
		if(event->Maxfd < p->fd) event->Maxfd = p->fd; // event->Maxfd를 제일큰 fd값으로 유지.
		if(p->answer && (event->Seconds > p->tout)) event->Seconds = p->tout;
		p = (EVENT_LIST *)p->next;
	}

	return 1;
}

/******************************************************************************/
/* Branch into Event handler                                                  */
/* Prototype : int  _BranchHandler()                                          */
/* Arguments : void;                                                          */
/* Return    : int; Result of handler()                                       */
/* Remarks   :                                                                */
/******************************************************************************/
static int _BranchHandler(event)
EVENT *event;
{
register EVENT_LIST *p;
static   int currcnt;

	if(!event->Totalcnt) return 0;

	currcnt = event->Totalcnt; // 현재 보유하고 있는 이벤트 수 만큼만 실행

	p  = event->Eventlist;
	while(currcnt){
		if(FD_ISSET(p->fd, &event->EventEntry)){ // EVENTLIST의 fd가 FD_SET에 있을때..
			p->rtime = p->tout;
			/* 재 진입 방지를 위함 */
			if(!p->del) p->handler(event, p->fd, p->event_id);
		}
		p = (EVENT_LIST *)p->next;
		currcnt --;
	}

	return 0;
}

/*******************************************************************************
 * Drop Event structure
 * Prototype : void _DropEvent(event)
 * Argument  : EVENT *event;
 * Return    : void
 ******************************************************************************/
static void _DropEvent(event)
EVENT *event;
{
EVENT_LIST *p = NULL, *n;

	p = event->Eventlist;

	while(p){
		n = p->next;
		free(p);
		p = n;
	}

	free(event); 

	return;
}

/******************************************************************************/
/* Check exist Event id                                                       */
/* Prototype : int _IsExistEventId(id)                                        */
/* Arguments : int id; 존재검사 할 Event id                                   */
/* Return    : int; Exist:1, Did't exist :0                                   */
/* Remarks   :                                                                */
/******************************************************************************/
int _IsExistEventId(event,id)
EVENT *event;
int id;
{
register EVENT_LIST *p;

	p = event->Eventlist;

	while(p){
		if(id == p->event_id && !p->del) return 1; // Exist:1 return
		p = (EVENT_LIST *)p->next;
	}

	return 0; // Did't exist:0 return
}

/******************************************************************************/
/* Event configuration initialization                                         */
/* Prototype : EVENT * AppEventInit()                                         */
/* Arguments : void                                                           */
/* Return    : int; SUCESS:EVENT *, FAIL:NULL                                 */
/* Remarks   : Make event struct and environment for event handling           */
/******************************************************************************/
EVENT *AppEventInit()
{
EVENT *event = NULL;

	event = (EVENT *) calloc(1, sizeof(EVENT));

	if(!event) return (EVENT *)NULL;

	/* ## EVENT configuration initialization ## */
	memset((void *)event, 0x00, sizeof(EVENT));

	FD_ZERO(&event->EventEntry);
	event->Seconds = DEF_TIMEOUT; /* DEF_TIMEOUT  20000 */
	event->RUNNING = 1;

	return event;
}


/*### 동적 메모리 함수 ######################################################### 

(1) mallco()
① 바이트 단위로 필요한 메모리를 할당한다.
  - malloc은 메모리 힙으로부터 size 바이트의 블록을 할당한다. 그것은 프로그램으로 하여금 필요로 하는 메모리의 정확한 양을 할당하도록 해준다. 힙은 메모리의 다양한 크기의 블록을 동적으로 사용한는데 쓰인다.
  - Tree나 List와 같은 데이터 구조들은 자연적으로 힙 메모리 할당에 의존하게 된다.
  - small 데이터 모델에서는 스택의 바로 윗부분의 약간의 여역을 제외하고는 데이터 세그먼트에서 프로그램 스택 위까지의 공간을 전부 사용할 수 있다. 그 약간의 영역은 DOS에서 필요로 하는 경우 스택을 추가로 늘릴 수 있는 여지를 제공하기 위한 것이다.
  - large 데이터 모델에서는 프로그램의 스택에서부터 메모리의 끝가지를 힙으로 사용할 수 있다.
② 형식 : void *malloc(size_t size)
③ 반환값 : 할당된 메모리의 시작 번지(NULL이면 할당 실패)를 반환
  - 성공하는 경우 malloc은 새로 할당된 메모리 블록 포인터를 반환한다.
  - 만약 새로운 블록을 위한 공간이 충분히 존재하지 않으면 NULL을 반환한다. 블록의 내용은 바뀌지 않고 그대로 남아있다.
  - size == 0이면 NULL을 반환한다.

 □ 예제
	--------------------------------------------------------------------
	#include <stdio.h>
	#include <string.h>
	#include <alloc.h>
	#include <process.h>
	
	int main(void)
	{
		char *str;
		
		// allocate memory for string
		if ((str = (char *) malloc(10)) == NULL)
		{
			printf("Not enough memory to allocate buffer\n");
			exit(1);  // terminate program if out of memory
		}
		
		// copy "Hello" into string
		strcpy(str, "Hello");
		
		// display string
		printf("String is %s\n", str);
		
		// free memory
		free(str);
		
		return 0;
	}
	--------------------------------------------------------------------

(2) free()
① 할당받은 메모리를 해제
② 형식 : void free(void *ptr)
③ 반환값 : 없음
 
 □ 예제
 	--------------------------------------------------------------------
	#include <string.h>
	#include <stdio.h>
	#include <alloc.h>
	
	int main(void)
	{
		char *str;
		
		// allocate memory for string
		str = (char *) malloc(10);
		
		// copy "Hello" to string
		strcpy(str, "Hello");
		
		// display string
		printf("String is %s\n", str);
		
		// free memory
		free(str);
		
		return 0;
	}
 	--------------------------------------------------------------------

(3) calloc()
① 데이터형을 단위로 해서 메모리를 할당한다.
  - calloc는 C 메모리 힙에 접근할 수 있도록 해준다.  힙은 메모리의 내의 다양한 크기의 블록들이 동적인 할당을 할 수 있는 곳이다.  트리나 리스트 같은 데이터 구조들이 힙 메모리 할당에 쓰인다.
  - 데이터 세그먼트의 끝 부분과 프로그램 스택 머리 부분 사이의 남는 공간(스택 머리 부분의 바로 앞 공간을 제외하고는)은 작은 데이터 모델(tiny,small, medium) 안에서 쓰인다.
  - 이런 남는 공간은 스택에서 쓰이거나, DOS에 의해 요구되는 작은 크기의 어플리케이션을 이해 허용된다.
  - 큰 데이터 모델의 경우(compact, large, huge) 물리적 메모리의 끝부분으로 들어온 프로그램 스택 이외의 공간들은 힙을 위해 쓰여진다.
  - calloc은 블록을 nitemsXszie 크리고 할당한다.  블록은 0으로 채워진다.  사용자가 64K보다 큰 블록을 할당하고 싶다면 farcalloc을 사용하면 된다.
② 형식 : void *calloc(size_t number_items, size_t block_size)
  - number_items : 데이터의 개수
  - block_size : 메모리 블록의 사이즈
③ 반환값 : calloc는 새로 할당된 블록에 포인터를 반환한다.
            새 블록을 위한 공간이 충분치 않거나 number_items, size 등이 0일 때는 NULL을 반환한다.
 
 □ 예제
 	--------------------------------------------------------------------
	#include <stdio.h>
	#include <alloc.h>
	#include <string.h>
	
	int main(void)
	{
		ahr *str = NULL;
		
		// allocate memory for string
		str = (char *) calloc(10, sizeof(char));
		
		// copy "Hello" into string
		strcpy(str, "Hello");
		
		// display string
		printf("String is %s\n",str);
		
		// free memory
		free(str);
		return 0;
	}

 	--------------------------------------------------------------------

④ malloc()와 차이점

malloc()는 메모리를 할당할 때 초기화하지 않지만 calloc()는 0으로 초기화
malloc()보다 호환성이 좋다.

(4) realloc()
① 이전의 할당된 메모리의 사이즈를 조정한다.
  - realloc은 이전에 할당된 블록을 size 바이트로 축소 또는 확장하려고 시도한다.
  - 인수 originalblock은 malloc,calloc,realloc 호출에 의해 이전에 얻어진 메모리 블록을 가리킨다.
  - originalblock이 널 포인터일 경우, realloc는  malloc와 똑같이 동작한다.
  - realloc는 필요하면 내용을 새 위치에 복사하여 할당된 블록의 크기를 size로 조절한다.

② 형식 : void *realloc(void *originalblock, size_t size);
  - originalblock : 이전의 할당된 블록의 시작 주소
  - size : 변경될 사이즈
③ 반환값 : realloc는 재할당된 블록의 번지를 반환하는데, 이 번지는 원래의 번지와 다를 수 있다.
            블록이 재 할당될 수 없거나 size==0일 경우, realloc는 널을 반환한다.
 □ 예제
 	--------------------------------------------------------------------
	#include <stdio.h>
	#include <alloc.h>
	#include <string.h>
	
	int main(void)
	{
		char *str;
		
		// allocate memory for string
		str = (char *) malloc(10);
		
		// copy "Hello" into string
		strcpy(str, "Hello");
		
		printf("String is %s\n  Address is %p\n", str, str);
		str = (char *) realloc(str, 20);
		printf("String is %s\n  New address is %p\n", str, str);
		
		// free memory
		free(str);
		
		return 0;
	}
 	--------------------------------------------------------------------


##############################################################################*/

/******************************************************************************/
/* Add event                                                                  */
/* Prototype : int AppAddEventAutoId(event, fd, tout, answer, handler)        */
/* Argumemts : int fd; Event fd (I)                                           */
/*             int tout; Timeout Value (Microsecond:1sec/100)                 */
/*             int answer; Need reporting timeout                             */
/*             int (*handler)(); Event processing function.(I)                */
/* Return    : Error occur : -1, SUCESS : int id; Event identifier(O)         */
/* Remarks   : usage : id = AppAddEventAutoId(Event, fd, 3000, 0 ,Func);      */
/******************************************************************************/
int AppAddEventAutoId(event, fd, tout, answer, handler)
EVENT *event;
int fd, tout, answer, (*handler)();
{
/* 
Event = AppEventInit();
id = AppAddEventAutoId(Event, fd, 3000, 0 ,Func);

static int Id = 1000;
*/
register EVENT_LIST *p;
register int        id;

	id = Id;
	
	if(!event->Totalcnt) { /* ## 처음생성일때 ## */
		event->Eventlist = (EVENT_LIST *) calloc(1, sizeof(EVENT_LIST));
		if(!event->Eventlist) return -1;

		/* ## EVENT_LIST configuration initialization ## */
		event->Eventlist->fd        = fd;
		event->Eventlist->event_id  = id;
		event->Eventlist->tout      = tout;
		event->Eventlist->rtime     = tout;
		event->Eventlist->answer    = answer;
		event->Eventlist->del       = 0;
		event->Eventlist->handler   = handler;
		event->Totalcnt ++;

		Id ++; Id = Id % 10000; // global ID increase

		return id; // current id return
	}

	// p = event->Eventlist;
	/*********** ID 결정 ****************************/
	while(_IsExistEventId(event, id)) { // global Event id가 비어있는 id인지 확인한다..
		id++;
		id = id % 10000;
	}

	/*********** Link 추가 **************************/
	p = event->Eventlist;
	while(p->next) p = (EVENT_LIST *)p->next; // 처음부터 List의 빈곳까지 뒤진다..
	/* [1] ## p : 마지막 만들어진 EVENT_LIST ## */
	p->next = (struct _EVENT_LIST *) calloc((size_t)1, (size_t)sizeof(struct _EVENT_LIST));
	if(!p->next) return -1;
	p = (EVENT_LIST *)p->next;
	/* [2] ## p : 새롭게 만들어진 EVENT_LIST ## */

	/* ## EVENT_LIST configuration initialization ## */
	p->fd        = fd;
	p->event_id  = id;
	p->tout      = tout;
	p->rtime     = tout;
	p->answer    = answer;
	p->del       = 0;
	p->handler   = handler;
	event->Totalcnt ++;

	Id = id + 1; Id = Id % 10000; // global ID increase

	return id; // current id return
}

/******************************************************************************/
/* Add event                                                                  */
/* Prototype : int AppAddEvent(event, fd, id, tout, answer, handler)          */
/* Argumemts : int fd; Event fd (I)                                           */
/*             int id; Event identifier(I)                                    */
/*             int tout; Timeout Value (Microsecond:1sec/100)                 */
/*             int answer; Need reporting timeout                             */
/*             int (*handler)(); Event processing function.(I)                */
/* Return    : DUP_ID : 0, Other Error occur : -1, SUCESS : 1                 */
/*             DUP_ID : Duplicate identifier                                  */
/* Remarks   :                                                                */
/******************************************************************************/
int AppAddEvent(event, fd, id, tout, answer, handler)
EVENT *event;
int fd, id, tout, answer;
int (*handler)();
{
register EVENT_LIST *p;

	if(!event->Totalcnt){ /* ## 처음생성일때 ## */
		event->Eventlist = (EVENT_LIST *)calloc(1, sizeof(EVENT_LIST));
		if(!event->Eventlist) return -1;

		event->Eventlist->fd        = fd;
		event->Eventlist->event_id  = id;
		event->Eventlist->tout      = tout;
		event->Eventlist->rtime     = tout;
		event->Eventlist->answer    = answer;
		event->Eventlist->del       = 0;
		event->Eventlist->handler   = handler;
		event->Totalcnt ++;
		return 1;
	}

	/*************** Link 추가 *********************/
	p = event->Eventlist;
	while(p->next) {
		/* Error duplication ID */
		if(id == p->event_id && !p->del) return 0;
		p = (EVENT_LIST *)p->next;
	}

	p->next = (struct _EVENT_LIST *)calloc((size_t)1, (size_t)sizeof(struct _EVENT_LIST));
	p = (EVENT_LIST *)p->next;

	/* ## EVENT_LIST configuration initialization ## */
	p->fd        = fd;
	p->event_id  = id;
	p->tout      = tout;
	p->rtime     = tout;
	p->answer    = answer;
	p->del       = 0;
	p->handler   = handler;
	event->Totalcnt ++;

	return 1;
}

/******************************************************************************/
/* Delete Event                                                               */
/* Prototype : int AppDelEvent(id)                                            */
/* Argumemts : int id; Event identifier(I)                                    */
/* Return    : Error occur : 0, Del SUCESS : 1                                */
/* Remarks   : 96.12.10(Sagittarius)                                          */
/* -. 96.12.10(Sagittarius)                                                   */
/*    _BranchHandler에서 Delete를 수행하기 때문에 여기에서 Delete를 하면      */
/*    다음 Link에 있는 pointer 이상으로 문제가 발생한다. 때문에 이 routine    */
/*    단순히 p->del = 1을 해서 AppEventLoop()에서 정리 할 수 있도록 한다.     */
/******************************************************************************/
int AppDelEvent(event, id)
EVENT *event;
int id;
{
register EVENT_LIST *p;
	if(!event->Totalcnt) return 1;
	p = event->Eventlist;

	while(p){
		if (p->event_id == id) {
			p->del = 1;
			return 1;
		}
		p = (EVENT_LIST *)p->next;
	}

	return 0;
}

/******************************************************************************/
/* Application Event Loop Shutdown                                            */
/* Prototype : void AppEventLoopShutdown()                                    */
/* Argument  : void;                                                          */
/* Return    : void                                                           */
/* Remarks   :                                                                */
/******************************************************************************/
void AppEventLoopShutdown(event)
EVENT *event;
{
	event->RUNNING = 0;
	return;
}

/******************************************************************************/
/* Change Application Event Loop select() timeout Value                       */
/* Prototype : void AppChangeEventTimeout(micro)                              */
/* Argument  : long micro;(Microseconds)                                      */
/* Return    : void                                                           */
/* Remarks   :                                                                */
/******************************************************************************/
void AppChangeEventTimeout(event, micro)
EVENT *event;
long micro;
{
	event->Seconds  = micro;
	return;
}

/*******************************************************************************
 * Event ID로 Fd얻기
 * Prototype : int AppGetFdByEventId(event, type)
 * Arguments : EVENT *event; int type;
 * Return    : int fd; Fail = -1;
 ******************************************************************************/
int AppGetFdByEventId(event, type)
EVENT *event;
int type;
{
register EVENT_LIST *p;
	if(!event->Totalcnt) return -1;
	p = event->Eventlist;
	while(p){
		if (p->event_id == type){ return p->fd;}
		p = (EVENT_LIST *)p->next;
	}
	return -1;
}

/*******************************************************************************
 * fd로 EventID 얻기
 * Prototype : int AppGetEventIdByFd(event, fd)
 * Arguments : EVENT *event; int fd;
 * Return    : int fd; Fail = -1;
 ******************************************************************************/
int AppGetEventIdByFd(event, fd)
EVENT *event;
int fd;
{
register EVENT_LIST *p;
	if(!event->Totalcnt) return -1;
	p = event->Eventlist;
	while(p){
		if (p->fd == fd){ return p->event_id;}
		p = (EVENT_LIST *)p->next;
	}
	return -1;
}

/******************************************************************************/
/* Application Event Loop                                                     */
/* Prototype : void AppEventLoop()                                            */
/* Argument  : void;                                                          */
/* Return    : void                                                           */
/* Remarks   :                                                                */
/******************************************************************************/
void AppEventLoop(event)
EVENT *event;
{
register int rtn;

	while(event->RUNNING) {
		_ClearDelEvent(event); // p->del==1 인 EVENTLIST 삭제
		_MakeEventSet(event);  // FD_SET(fd list) 재설정 
		event->Timeout.tv_sec   = event->Seconds; // second 
		event->Timeout.tv_usec  = 0;		  // microsecond

		// select() : This function allows the process to instruct the kernel to wait for any one of multiple events to occur and to wake up the process only when one or more of these eventss occurs or when a specified amount of time has passed.
		// int select(int n, fd_set *readfds, fd_set *writefds, fd_set *exceptfds, struct timeval *timeout); 
		rtn = select(event->Maxfd + 1, 
			&event->EventEntry, (fd_set *)NULL, (fd_set *)NULL, 
			&event->Timeout);
		if(!rtn) { // return 0 : timeout
			_TimeoutProcessing(event);
		 	continue;
		} else if(rtn < 0) { // return -1 : error
			continue;
		}

		_BranchHandler(event); // event가 발생한 fd의 handler처리..
	}

	_DropEvent(event); // event->RUNNING == 0 이면 종료한다..

	return;
}

/*### select() 함수 ############################################################ 

select 함수는 한개 또는 그 이상의 소켓 상태를 결정하고, 동기 입출력을 수행 하기위해 필요할 경우 대기 하는 함수입니다.

int select(int nfds,
        fd_set FAR * readfds,
        fd_set FAR * writefds,
        fd_set FAR * exceptfds,  
        const struct timeval FAR * timeout
);

Returns: positive count of ready descriptors, 0 on timeout, -1 on error

############
Parameters
############
nfds
[입력] 버클리 소켓과 호환되는 소켓을 제외 하고는 이 매개변수는 무시됩니다.
버클리 소켓에서 이 매개변수는 I/O 변화를 감지 할 총 소켓의 갯수+1 의 값을 지정하는 용도로 사용합니다.

readfds
[입/출력] 읽기상태의 변화를 감지할 소켓을 지정합니다.

writefds
[입/출력] 쓰기상태의 변화를 감지할 소켓을 지정합니다.

exceptfds
[입/출력] 예외상태 변화를 감지할 소켓을 지정합니다.

timeout
[입력] select 함수가 기다리기 위한 시간입니다.
NULL 일경우 지정한 I/O변화가 발생했을 때까지 계속 기다립니다.



FD_CLR(s, *set)
    지정된 소켓 기술자(descriptor)를 세트에서 제거 합니다.

FD_ISSET(s, *set)
    지정된 소켓 기술자가 세트에 있을 경우 0이 아닌값을 반환하고, 없을 경우 0을 반환합니다.

FD_SET(s, *set)
    지정된 소켓 기술자를 세트에 추가 합니다.

FD_ZERO(*set)
    모든 소켓 기술자를 세크에서 제거합니다.




  ##############################################################################*/

/************************************************************************/
/* Program End								*/
/************************************************************************/
