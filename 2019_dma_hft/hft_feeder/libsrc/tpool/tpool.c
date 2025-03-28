////////////////////////////////////////////////////////////////////////////////
// Description  : Thread Pool Library Header
// File Name    : tpool.h
// Author       :
// Notes        : 
//������������������������������������������������������������������������������
// Date         : 
////////////////////////////////////////////////////////////////////////////////
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <pthread.h>

#include "zconf.h"

////////////////////////////////////////////////////////////////////////////////
// PROTOTYPE    : void *tpool_thread(void *arg)
// ARGUMENTS    :
// RETURN VALUE :
// NOTES        :
//������������������������������������������������������������������������������
// USAGE        :
////////////////////////////////////////////////////////////////////////////////
void *tpool_thread(void *arg)
{
	tpool_t tpool = (tpool_t)arg; 
	int rtn;
	tpool_work_t	*my_workp;

	for(;;) {
		/*************************************************/
		/* Check queue for work 			 */
		/*************************************************/
		if ((rtn = pthread_mutex_lock(&(tpool->queue_lock))) != 0)
			Log("pthread_mutex_lock %d",rtn), exit(1);

		while ((tpool->cur_queue_size == 0) && (!tpool->shutdown)) {
			//Log("worker %d: I'm sleeping again\n", pthread_self());

			//When a worker looks at the queue and finds it empty, 
			// it sleeps on the 'queue_not_empty' condition variable.
			//When a caller in 'tpool_add_work' adds an item to an empty queue,
			// it wakes up a sleeping worker by signaling the 'queue_not_empty' condition.

			if ((rtn = pthread_cond_wait(&(tpool->queue_not_empty), &(tpool->queue_lock))) != 0)
				Log("pthread_cond_wait %d",rtn), exit(1);
		}

		// sleep(5); 
		// Log("worker %d: I'm awake\n", pthread_self());

		/*************************************************/
		/* Has a shutdown started while i was sleeping?  */
		/*************************************************/
		if (tpool->shutdown == 1) {
			if ((rtn = pthread_mutex_unlock(&(tpool->queue_lock))) != 0)
				Log("pthread_mutex_unlock %d",rtn), exit(1);
			pthread_exit(NULL);
		}

		/*************************************************/
		/* Get to work, dequeue the next item 		 */ 
		/*************************************************/
		my_workp = tpool->queue_head;
		tpool->cur_queue_size--;
		if (tpool->cur_queue_size == 0)
			tpool->queue_head = tpool->queue_tail = NULL;
		else
			tpool->queue_head = my_workp->next;

		// �αװ� �ʹ� ���Ƽ� ���δ�. 
	    	if(tpool->cur_queue_size > 128) {
		    	Log("worker %d: dequeing item %d queue_size %d\n",
		    		pthread_self(), my_workp->next, tpool->cur_queue_size);
		}

		/*************************************************/
		/* Handle waiting add_work threads 		 */
		/*************************************************/
		if ((!tpool->do_not_block_when_full) && 
			(tpool->cur_queue_size ==  (tpool->max_queue_size - 1))) 
			if ((rtn = pthread_cond_broadcast(&(tpool->queue_not_full))) != 0)
				Log("pthread_cond_broadcast %d",rtn), exit(1);

		/*************************************************/
		/* Handle waiting destroyer threads 		 */
		/*************************************************/
		if (tpool->cur_queue_size == 0)
			if ((rtn = pthread_cond_signal(&(tpool->queue_empty))) != 0)
				Log("pthread_cond_signal %d",rtn), exit(1);

		if ((rtn = pthread_mutex_unlock(&(tpool->queue_lock))) != 0)
			Log("pthread_mutex_unlock %d",rtn), exit(1);

		/*************************************************/
		/* Do this work item 				 */
		/*************************************************/
		(*(my_workp->routine))(pthread_self(),my_workp->arg); /* �ٲ�κ�!! */

		free(my_workp);
	} // for end

	return (NULL);
}

////////////////////////////////////////////////////////////////////////////////
// PROTOTYPE    : void tpool_init(tpool_t *, int , int , int )
// ARGUMENTS    :
// RETURN VALUE :
// NOTES        :
//������������������������������������������������������������������������������
// USAGE        :
////////////////////////////////////////////////////////////////////////////////
void tpool_init(tpool_t *tpoolp, int num_worker_threads, int max_queue_size, int do_not_block_when_full)
{
	int i, rtn;
	tpool_t tpool;

	/**********************************/
	/* allocate a pool data structure */ 
	/**********************************/

	if ((tpool = (tpool_t )malloc(sizeof(struct tpool))) == NULL)
		perror("malloc"), exit(1);

	/**********************************/
	/* initialize th fields 	  */
	/**********************************/

	/* [1] pool characteristics */
	tpool->num_threads = num_worker_threads;
	tpool->max_queue_size = max_queue_size;
	tpool->do_not_block_when_full = do_not_block_when_full;

        /* [2] pool state           */
  	if((tpool->threads = (pthread_t *)malloc(sizeof(pthread_t)*num_worker_threads)) == NULL)
		perror("malloc"), exit(1);
	tpool->cur_queue_size = 0;
	tpool->queue_head = NULL; 
	tpool->queue_tail = NULL;
	tpool->queue_closed = 0;  
	tpool->shutdown = 0; 

	/* [3] pool synchronization */
	if ((rtn = pthread_mutex_init(&(tpool->queue_lock), NULL)) != 0)
		Log("pthread_mutex_init %s",strerror(rtn)), exit(1);

	if ((rtn = pthread_cond_init(&(tpool->queue_not_empty), NULL)) != 0)
		Log("pthread_cond_init %s",strerror(rtn)), exit(1);

	if ((rtn = pthread_cond_init(&(tpool->queue_not_full), NULL)) != 0)
		Log("pthread_cond_init %s",strerror(rtn)), exit(1);

	if ((rtn = pthread_cond_init(&(tpool->queue_empty), NULL)) != 0)
		Log("pthread_cond_init %s",strerror(rtn)), exit(1);

	/**********************************/
	/* create threads                 */
	/**********************************/
	for (i = 0; i != num_worker_threads; i++) {
		if ((rtn = pthread_create( &(tpool->threads[i]), NULL, tpool_thread, (void *)tpool)) != 0)
			Log("pthread_create %d",rtn), exit(1);
	}

	*tpoolp = tpool;
	
	return;
}

////////////////////////////////////////////////////////////////////////////////
// PROTOTYPE    : int tpool_add_work(tpool_t tpool, void (*routine)(), void *arg)
// ARGUMENTS    :
// RETURN VALUE :
// NOTES        :
//������������������������������������������������������������������������������
// USAGE        :
////////////////////////////////////////////////////////////////////////////////
int tpool_add_work(tpool_t tpool, void (*routine)(), void *arg)
{
	int rtn, queue_size;
	tpool_work_t *workp;

	if ((rtn = pthread_mutex_lock(&(tpool->queue_lock))) != 0)
		Log("pthread_mutex_lock %d",rtn), exit(1);

	/*************************************************/
	/* no space and this caller doesn't want to wait */
	/*************************************************/
	if ((tpool->cur_queue_size == tpool->max_queue_size) && tpool->do_not_block_when_full) {
		if ((rtn = pthread_mutex_unlock(&(tpool->queue_lock))) != 0)
			Log("pthread_mutex_unlock %d",rtn), exit(1);
		return -1;
	}

	while( (tpool->cur_queue_size == tpool->max_queue_size) && 
					(!(tpool->shutdown || tpool->queue_closed))  ) {
		if ((rtn = pthread_cond_wait(&(tpool->queue_not_full), &(tpool->queue_lock))) != 0)
			Log("pthread_cond_wait %d",rtn), exit(1);
	}

	/*************************************************/
	/* the pool is in the process of being destroyed */
	/*************************************************/
	if (tpool->shutdown || tpool->queue_closed) {
		if ((rtn = pthread_mutex_unlock(&(tpool->queue_lock))) != 0)
			Log("pthread_mutex_unlock %d",rtn), exit(1);
		return -1;
	}

	/*************************************************/
	/* allocate work structure 			 */
        /*     ����������������������������������	 */
        /*     ��void        ��void��tpool_work��	 */
        /*     ��(*routine)()��*arg��  *next   ��	 */
        /*     ����������������������������������	 */
	/*************************************************/
	if ((workp = (tpool_work_t *)malloc(sizeof(tpool_work_t))) == NULL)
		perror("malloc"), exit(1);

	workp->routine = routine;
	workp->arg = arg;
	workp->next = NULL;
                                     
	/* Log("adder: adding an item %d queue_size %d\n", workp->routine, tpool->cur_queue_size); */

	if (tpool->cur_queue_size == 0) {
		tpool->queue_tail = tpool->queue_head = workp;
		/* Log("adder: queue == 0, waking all workers\n"); */
		if ((rtn = pthread_cond_broadcast(&(tpool->queue_not_empty))) != 0)
			Log("pthread_cond_signal %d",rtn), exit(1);;
	} else {
		tpool->queue_tail->next = workp;
		tpool->queue_tail = workp;
	}

	queue_size = tpool->cur_queue_size++; 

	if ((rtn = pthread_mutex_unlock(&(tpool->queue_lock))) != 0)
		Log("pthread_mutex_unlock %d",rtn), exit(1);

	return queue_size;
}

////////////////////////////////////////////////////////////////////////////////
// PROTOTYPE    : int tpool_destroy(tpool_t tpool, int finish)
// ARGUMENTS    :
// RETURN VALUE :
// NOTES        :
//������������������������������������������������������������������������������
// USAGE        :
////////////////////////////////////////////////////////////////////////////////
int tpool_destroy(tpool_t tpool, int finish)
{
	int i, rtn;
	tpool_work_t *cur_nodep;
  

	if ((rtn = pthread_mutex_lock(&(tpool->queue_lock))) != 0)
		Log("pthread_mutex_lock %d",rtn), exit(1);

	/*************************************************/
	/* Is a shutdown already in progress? 		 */
	/*************************************************/
	if (tpool->queue_closed || tpool->shutdown) {
		if ((rtn = pthread_mutex_unlock(&(tpool->queue_lock))) != 0)
			Log("pthread_mutex_unlock %d",rtn), exit(1);
		return 0;
	}


	//The 'queue_closed' flag is used in combination with the 'queue_empty' contion variable
	// to support a delayed shutdown.
	//The delayed shutdown allows the currently queued work to complete.
	tpool->queue_closed = 1;

	/**************************************************************/
	/* If the finish flag is set, wait for workers to drain queue */
	/**************************************************************/
	if (finish == 1) {
		while (tpool->cur_queue_size != 0) {
			if ((rtn = pthread_cond_wait(&(tpool->queue_empty), &(tpool->queue_lock))) != 0)
				Log("pthread_cond_wait %d",rtn), exit(1);
		}
	}

	tpool->shutdown = 1;

	if ((rtn = pthread_mutex_unlock(&(tpool->queue_lock))) != 0)
		Log("pthread_mutex_unlock %d",rtn), exit(1);


	/**************************************************************/
	/* Wake up any workers so they recheck shutdown flag 	      */
	/**************************************************************/
	if ((rtn = pthread_cond_broadcast(&(tpool->queue_not_empty))) != 0)
		Log("pthread_cond_broadcast %d",rtn), exit(1);
	if ((rtn = pthread_cond_broadcast(&(tpool->queue_not_full))) != 0)
		Log("pthread_cond_broadcast %d",rtn), exit(1);

	/*************************************************/
	/* Wait for workers to exit 			 */
	/*************************************************/
	for(i=0; i < tpool->num_threads; i++) {
		if ((rtn = pthread_join(tpool->threads[i],NULL)) != 0)
			Log("pthread_join %d",rtn), exit(1);
	}

	/*************************************************/
	/* Now free pool structures 			 */
	/*************************************************/
	free(tpool->threads);
	while(tpool->queue_head != NULL) {
		cur_nodep = tpool->queue_head->next; 
		tpool->queue_head = tpool->queue_head->next;
		free(cur_nodep);
	}

	free(tpool); 
	
	return 0;
}
////////////////////////////////////////////////////////////////////////////////
// Program End
////////////////////////////////////////////////////////////////////////////////
