////////////////////////////////////////////////////////////////////////////////
// Description  :
// File Name    : sema.c	
// Author       :
// Notes        :
//━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
// Date         : 
////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <errno.h>

#define PERMS 0666    /* -wr-wr-wr- */

/******************************************************************************
 * Function 	: Initialize Semaphore
 * Prototype	: int InitSemaphore(key_t key)
 * Remark	: 
 * Return Value : 
 *  See also 	:
 ******************************************************************************/
int InitSemaphore(key_t key)
{
int id, rtn;
int semarg = 1;

	/* ## The semget function creates a semaphore set or accesses an existing semaphore set. ## */
	/* ## Returns : nonnegative identifier if OK, -1 on error				 ## */

	id = semget(key, 1, PERMS | IPC_CREAT | IPC_EXCL);
	if(id < 0){
		if(errno == EEXIST) id = semget(key, 1, 0); /* 이미 존재할 경우에 식별자만 얻는다. */
		else return (errno * -1);
	} else {
		/* ## SETVAL : Set the value of semval to arg.val. If this is successful, the semaphore adjustment value for this semaphore is set to 0 in all process. ## */
		rtn = semctl(id, 0, SETVAL, semarg); /* 세마포어를 생성한 프로세스만 그 값을 초기화 */
		if(rtn < 0) return (errno * -1);
	}

//	rtn = semctl(id, 0, SETVAL, semarg);
//	if(rtn < 0) return (errno * -1);

	return id;
}

/******************************************************************************
 * Function 	: Semaphore Operation
 * Prototype	: int SemaphoreOperation(int id, int op)
 * Remark	: 
 * Return Value : 
 *  See also 	:
 ******************************************************************************/
int SemaphoreOperation(int id, int op)
{
struct sembuf pv;

	pv.sem_num = 0;
	if(op == 1) pv.sem_op  = -1; /* semaphore on  : P() */
	else 	    pv.sem_op  =  1; /* semaphore off : V() */

	pv.sem_flg = SEM_UNDO;

	if(semop(id, &pv, 1) == -1) return (errno * -1);
	else 			    return 1;
}

/******************************************************************************
 * Function 	: Delete Semaphore
 * Prototype	: int DelSemaphore(int id)
 * Remark	: 
 * Return Value : 
 *  See also 	:
 ******************************************************************************/
int DelSemaphore(int id)
{
int rtn;

	rtn = semctl(id, 0, IPC_RMID);
	if(rtn < 0) return (errno * -1);

	return 1;
}
////////////////////////////////////////////////////////////////////////////////
// Program End
////////////////////////////////////////////////////////////////////////////////
