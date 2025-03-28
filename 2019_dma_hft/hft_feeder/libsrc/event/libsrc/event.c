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
		p->rtime -= event->Seconds; // p->rtime : Ȥ�� �����ִ� �ð��ΰ�??
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
		if(p->del) { // p->del==1(����) �϶�..
			if(!cnt) { // EVENT �ٷεڿ� EVENTLIST�� �����Ҷ�..
				event->Totalcnt --;
				if(!event->Totalcnt) { // EVENTLIST�� �ϳ��� �� ��������..
					free(event->Eventlist);
					event->Eventlist = NULL;
					p = NULL;
				} else {
					event->Eventlist = (EVENT_LIST *)p->next;
					free(p);
					p = (EVENT_LIST *)event->Eventlist->next;
				}
				// return; �ƴѰ� ����...!!
			} else {
				b->next = p->next;
				free(p);
				p = (EVENT_LIST *)b->next;
				event->Totalcnt --;
			}
		} else { // p->del==0 (����) �϶�..
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

	if(!event->Totalcnt) return event->Totalcnt; // EVENT_LIST�� ������ ������ return event->Totalcnt
	p = event->Eventlist;

	FD_ZERO(&event->EventEntry); // clear all bits in fdset : ��� ���� ����ڸ� ��Ʈ���� ����.
	event->Maxfd = 0;
	event->Seconds = p->tout;

	while(p) {
		FD_SET(p->fd, &event->EventEntry); // turn on the bit for fd in fdset : ������ ���� ����ڸ� ��Ʈ�� �߰�.
		if(event->Maxfd < p->fd) event->Maxfd = p->fd; // event->Maxfd�� ����ū fd������ ����.
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

	currcnt = event->Totalcnt; // ���� �����ϰ� �ִ� �̺�Ʈ �� ��ŭ�� ����

	p  = event->Eventlist;
	while(currcnt){
		if(FD_ISSET(p->fd, &event->EventEntry)){ // EVENTLIST�� fd�� FD_SET�� ������..
			p->rtime = p->tout;
			/* �� ���� ������ ���� */
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
/* Arguments : int id; ����˻� �� Event id                                   */
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


/*### ���� �޸� �Լ� ######################################################### 

(1) mallco()
�� ����Ʈ ������ �ʿ��� �޸𸮸� �Ҵ��Ѵ�.
  - malloc�� �޸� �����κ��� size ����Ʈ�� ����� �Ҵ��Ѵ�. �װ��� ���α׷����� �Ͽ��� �ʿ�� �ϴ� �޸��� ��Ȯ�� ���� �Ҵ��ϵ��� ���ش�. ���� �޸��� �پ��� ũ���� ����� �������� ����Ѵµ� ���δ�.
  - Tree�� List�� ���� ������ �������� �ڿ������� �� �޸� �Ҵ翡 �����ϰ� �ȴ�.
  - small ������ �𵨿����� ������ �ٷ� ���κ��� �ణ�� ������ �����ϰ�� ������ ���׸�Ʈ���� ���α׷� ���� �������� ������ ���� ����� �� �ִ�. �� �ణ�� ������ DOS���� �ʿ�� �ϴ� ��� ������ �߰��� �ø� �� �ִ� ������ �����ϱ� ���� ���̴�.
  - large ������ �𵨿����� ���α׷��� ���ÿ������� �޸��� �������� ������ ����� �� �ִ�.
�� ���� : void *malloc(size_t size)
�� ��ȯ�� : �Ҵ�� �޸��� ���� ����(NULL�̸� �Ҵ� ����)�� ��ȯ
  - �����ϴ� ��� malloc�� ���� �Ҵ�� �޸� ��� �����͸� ��ȯ�Ѵ�.
  - ���� ���ο� ����� ���� ������ ����� �������� ������ NULL�� ��ȯ�Ѵ�. ����� ������ �ٲ��� �ʰ� �״�� �����ִ�.
  - size == 0�̸� NULL�� ��ȯ�Ѵ�.

 �� ����
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
�� �Ҵ���� �޸𸮸� ����
�� ���� : void free(void *ptr)
�� ��ȯ�� : ����
 
 �� ����
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
�� ���������� ������ �ؼ� �޸𸮸� �Ҵ��Ѵ�.
  - calloc�� C �޸� ���� ������ �� �ֵ��� ���ش�.  ���� �޸��� ���� �پ��� ũ���� ��ϵ��� ������ �Ҵ��� �� �� �ִ� ���̴�.  Ʈ���� ����Ʈ ���� ������ �������� �� �޸� �Ҵ翡 ���δ�.
  - ������ ���׸�Ʈ�� �� �κа� ���α׷� ���� �Ӹ� �κ� ������ ���� ����(���� �Ӹ� �κ��� �ٷ� �� ������ �����ϰ��)�� ���� ������ ��(tiny,small, medium) �ȿ��� ���δ�.
  - �̷� ���� ������ ���ÿ��� ���̰ų�, DOS�� ���� �䱸�Ǵ� ���� ũ���� ���ø����̼��� ���� ���ȴ�.
  - ū ������ ���� ���(compact, large, huge) ������ �޸��� ���κ����� ���� ���α׷� ���� �̿��� �������� ���� ���� ��������.
  - calloc�� ����� nitemsXszie ũ���� �Ҵ��Ѵ�.  ����� 0���� ä������.  ����ڰ� 64K���� ū ����� �Ҵ��ϰ� �ʹٸ� farcalloc�� ����ϸ� �ȴ�.
�� ���� : void *calloc(size_t number_items, size_t block_size)
  - number_items : �������� ����
  - block_size : �޸� ����� ������
�� ��ȯ�� : calloc�� ���� �Ҵ�� ��Ͽ� �����͸� ��ȯ�Ѵ�.
            �� ����� ���� ������ ���ġ �ʰų� number_items, size ���� 0�� ���� NULL�� ��ȯ�Ѵ�.
 
 �� ����
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

�� malloc()�� ������

malloc()�� �޸𸮸� �Ҵ��� �� �ʱ�ȭ���� ������ calloc()�� 0���� �ʱ�ȭ
malloc()���� ȣȯ���� ����.

(4) realloc()
�� ������ �Ҵ�� �޸��� ����� �����Ѵ�.
  - realloc�� ������ �Ҵ�� ����� size ����Ʈ�� ��� �Ǵ� Ȯ���Ϸ��� �õ��Ѵ�.
  - �μ� originalblock�� malloc,calloc,realloc ȣ�⿡ ���� ������ ����� �޸� ����� ����Ų��.
  - originalblock�� �� �������� ���, realloc��  malloc�� �Ȱ��� �����Ѵ�.
  - realloc�� �ʿ��ϸ� ������ �� ��ġ�� �����Ͽ� �Ҵ�� ����� ũ�⸦ size�� �����Ѵ�.

�� ���� : void *realloc(void *originalblock, size_t size);
  - originalblock : ������ �Ҵ�� ����� ���� �ּ�
  - size : ����� ������
�� ��ȯ�� : realloc�� ���Ҵ�� ����� ������ ��ȯ�ϴµ�, �� ������ ������ ������ �ٸ� �� �ִ�.
            ����� �� �Ҵ�� �� ���ų� size==0�� ���, realloc�� ���� ��ȯ�Ѵ�.
 �� ����
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
	
	if(!event->Totalcnt) { /* ## ó�������϶� ## */
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
	/*********** ID ���� ****************************/
	while(_IsExistEventId(event, id)) { // global Event id�� ����ִ� id���� Ȯ���Ѵ�..
		id++;
		id = id % 10000;
	}

	/*********** Link �߰� **************************/
	p = event->Eventlist;
	while(p->next) p = (EVENT_LIST *)p->next; // ó������ List�� ������� ������..
	/* [1] ## p : ������ ������� EVENT_LIST ## */
	p->next = (struct _EVENT_LIST *) calloc((size_t)1, (size_t)sizeof(struct _EVENT_LIST));
	if(!p->next) return -1;
	p = (EVENT_LIST *)p->next;
	/* [2] ## p : ���Ӱ� ������� EVENT_LIST ## */

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

	if(!event->Totalcnt){ /* ## ó�������϶� ## */
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

	/*************** Link �߰� *********************/
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
/*    _BranchHandler���� Delete�� �����ϱ� ������ ���⿡�� Delete�� �ϸ�      */
/*    ���� Link�� �ִ� pointer �̻����� ������ �߻��Ѵ�. ������ �� routine    */
/*    �ܼ��� p->del = 1�� �ؼ� AppEventLoop()���� ���� �� �� �ֵ��� �Ѵ�.     */
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
 * Event ID�� Fd���
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
 * fd�� EventID ���
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
		_ClearDelEvent(event); // p->del==1 �� EVENTLIST ����
		_MakeEventSet(event);  // FD_SET(fd list) �缳�� 
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

		_BranchHandler(event); // event�� �߻��� fd�� handleró��..
	}

	_DropEvent(event); // event->RUNNING == 0 �̸� �����Ѵ�..

	return;
}

/*### select() �Լ� ############################################################ 

select �Լ��� �Ѱ� �Ǵ� �� �̻��� ���� ���¸� �����ϰ�, ���� ������� ���� �ϱ����� �ʿ��� ��� ��� �ϴ� �Լ��Դϴ�.

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
[�Է�] ��Ŭ�� ���ϰ� ȣȯ�Ǵ� ������ ���� �ϰ�� �� �Ű������� ���õ˴ϴ�.
��Ŭ�� ���Ͽ��� �� �Ű������� I/O ��ȭ�� ���� �� �� ������ ����+1 �� ���� �����ϴ� �뵵�� ����մϴ�.

readfds
[��/���] �б������ ��ȭ�� ������ ������ �����մϴ�.

writefds
[��/���] ��������� ��ȭ�� ������ ������ �����մϴ�.

exceptfds
[��/���] ���ܻ��� ��ȭ�� ������ ������ �����մϴ�.

timeout
[�Է�] select �Լ��� ��ٸ��� ���� �ð��Դϴ�.
NULL �ϰ�� ������ I/O��ȭ�� �߻����� ������ ��� ��ٸ��ϴ�.



FD_CLR(s, *set)
    ������ ���� �����(descriptor)�� ��Ʈ���� ���� �մϴ�.

FD_ISSET(s, *set)
    ������ ���� ����ڰ� ��Ʈ�� ���� ��� 0�� �ƴѰ��� ��ȯ�ϰ�, ���� ��� 0�� ��ȯ�մϴ�.

FD_SET(s, *set)
    ������ ���� ����ڸ� ��Ʈ�� �߰� �մϴ�.

FD_ZERO(*set)
    ��� ���� ����ڸ� ��ũ���� �����մϴ�.




  ##############################################################################*/

/************************************************************************/
/* Program End								*/
/************************************************************************/
