////////////////////////////////////////////////////////////////////////////////
// Description  : Shared memory Interface Libary
// File Name    : shm.c
// Author       :
// Notes        :
//━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
// Date         :
////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define PERMS 0666    /* -wr-wr-wr- */

/******************************************************************************
 * Function 	: Attach region area to processor region
 * Prototype	: int Attachshm(int shmid,char *vaddr,int flag)
 * Remark	: System Call shmat
 * Return Value : On success , reginon aread vertural address
 *		  Otherwise,   error NULL
 *  See also 	: Getshmid Openshm Makeshm Attachshm Detachshm Removeshm
 ******************************************************************************/
char *Attachshm(int shmid, char *shmaddr, int flag)
{
	/* ## After a shared memory segment has been created or opened by shmget,
		we attach it to our address spae by calling shmat. ## */
	/* ## Returns : starting address of mapped region if OK, -1 on error ## */
	return shmat(shmid, shmaddr, flag);
}

/******************************************************************************
 * Function 	: Detach region area from processor region
 * Prototype	: int Detachshm(char *vaddr);
 * Remark	: System Call shmdt
 * Return Value : On success , positive value
 *		  Otherwise,   error -1
 *  See also 	: Getshmid Openshm Makeshm Attachshm Detachshm Removeshm
 ******************************************************************************/
int Detachshm(char *vaddr)
{
	int rtn;

	/* ## When a process is finished with a shared memory segment,
		it detaches the segment by calling shmdt. 			       ## */
	/* ## Note that this call does not delete the shared memory segment.
		Deletion is accomplished by calling shmctl with a command of IPC_RMID. ## */
	rtn = shmdt(vaddr);
	if(rtn < 0) return -1;

	return 1;
}

/******************************************************************************
 * Function 	: Get shmid
 * Prototype	: int Getshmid(key_t shmkey);
 * Remark	: if not shmkey exist error, System Call shmget
 * Return Value : On success , positive value int type shmid
 *		  Otherwise,   error -1
 *  See also 	: Openshm Makeshm Attachshm Detachshm Removeshm
 ******************************************************************************/
int Getshmid(key_t shmkey)
{
	int shmid;
	long size = 0;

	/* ## A shared memory segment is created, or an existing one is accessed, by the shmget function. ## */
	/* ## If an existing shared memory segment is being referenced, size should be 0 ## */
	shmid = shmget(shmkey, size, PERMS | IPC_EXCL);
	if(shmid < 0) return -1;

	return shmid;
}

/******************************************************************************
 * Function 	: Remove shared memory by shmkey
 * Prototype	: int Removeshm(key_t shmkey);
 * Remark	:
 * Return Value : Return Value: On success , positive value
 *		  Otherwise,   error -1
 *  See also 	: Getshmid Openshm Makeshm Attachshm Detachshm Removeshm
 ******************************************************************************/
int Removeshm(key_t shmkey)
{
	int shmid, rtn;

	shmid = Getshmid(shmkey);
	if(shmid < 0) return -1;

	rtn = shmctl(shmid, IPC_RMID, NULL);
	if(rtn < 0) return -1;

	return 1;
}

/******************************************************************************
 * Function 	: Make shared memory area
 * Prototype	: int Makeshm(key_t shmkey,long nbyte);
 * Remark	:
 * Return Value : Return Value: On success , positive value int type shmid
 *		  Otherwise,   error -1
 *  See also 	: Getshmid Openshm Makeshm Attachshm Detachshm Removeshm
 ******************************************************************************/
int Makeshm(key_t shmkey, long nbyte)
{
	int shmid;
	if(shmkey == IPC_PRIVATE) return -1;

	shmid = Getshmid(shmkey);
	if(shmid > 0) {/* 기존에 같은 shmkey의 Shared memory가 존재하면 삭제한다. */
		if(Removeshm(shmkey) < 0) return -2;
	}

	/* ## A shared memory segment is created, or an existing one is accessed, by the shmget function.## */
	/* ## When a new shared memory segment is created, it it initialized to size bytes of 0.	 ## */
	shmid = shmget(shmkey, nbyte, PERMS|IPC_CREAT);
	if(shmid < 0) return -3;

	return shmid;
}
////////////////////////////////////////////////////////////////////////////////
// Program End
////////////////////////////////////////////////////////////////////////////////
