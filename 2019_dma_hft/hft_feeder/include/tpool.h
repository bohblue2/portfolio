////////////////////////////////////////////////////////////////////////////////
// Description  : Thread Pool Library Header
// File Name    : tpool.h
// Author       :
// Notes        :
//收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收
// Date         : 
////////////////////////////////////////////////////////////////////////////////
#ifndef _TPOOL_H_
#define _TPOOL_H_

typedef struct tpool_work {
	void               (*routine)();
	void                *arg;
	struct tpool_work   *next;
} tpool_work_t;

typedef struct tpool {
	/* pool characteristics */
	int                 num_threads;		/* number of worker threads	*/
    int                 max_queue_size;		/* request queue size 		*/
    int                 do_not_block_when_full;	/* 0:block 1:don't block	*/
    /* pool state 		*/
	pthread_t           *threads;			/* threads pointer		*/
    int                 cur_queue_size;		/* current queue size		*/
	tpool_work_t        *queue_head;		/* current queue head		*/
	tpool_work_t        *queue_tail;		/* current queue tail		*/
	int                 queue_closed;		/* 0:active 1:closed 		*/
    int                 shutdown;			/* 0:active 1:shutdown 		*/
	/* pool synchronization */
    pthread_mutex_t     queue_lock;			/* mutex variable 		*/
    pthread_cond_t      queue_not_empty;		/* condition variable		*/
    pthread_cond_t      queue_not_full;		/* condition variable		*/
    pthread_cond_t      queue_empty;		/* condition variable		*/
} *tpool_t;


extern void Log(char *format, ...);

#endif
////////////////////////////////////////////////////////////////////////////////
// Program End
////////////////////////////////////////////////////////////////////////////////
