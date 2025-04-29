////////////////////////////////////////////////////////////////////////////////
// Description  : Message Queue
// File Name    : msgque.c
// Author       :
// Notes        :
//━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
// Date         : 
////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>

#define PERMS 0666    /* -wr-wr-wr- */
#define MAX_QLEN 4096

typedef struct _MSGQDATA {
	int  type;
	char data[4096];
} MSGQDATA;

/******************************************************************************/
/* Destroy message queue                                                      */
/* Library in   : libsaipc.a                                                  */
/* Prototype    : void CloseMsgqueue(id)                                      */
/* Arguments    : int              id;  Queue ID                              */
/* Return value : int                                                         */
/******************************************************************************/
int CloseMsgqueue(int id)
{
	/* IPC_RMID : Remove the message queue specified by msgid from the system. Any message currently on the queue are discarded. */
	return msgctl(id, IPC_RMID, NULL);
}

/******************************************************************************/
/* Change Max bytes of Message Queue                                          */
/* Library in   : libsaipc.a                                                  */
/* Prototype    : int ChangeQueueSize(id, size)                               */
/* Arguments    : unsigned short size;  Queue size                            */
/*                int              id;  Queue ID                              */
/* Return value : void                                                        */
/******************************************************************************/
int ChangeQueueSize(int id, unsigned short size)
{
struct msqid_ds st;

	if(msgctl(id, IPC_STAT, &st) < 0)
		return 0;

	if(st.msg_qbytes < size){
		st.msg_qbytes = size;
		msgctl(id, IPC_SET, &st);
	}

	return 1;
}

/******************************************************************************/
/* Make message queue                                                         */
/* Library in   : libsaipc.a                                                  */
/* Prototype    : int MakeMsgqueue(key)                                       */
/* Arguments    : key_t key;            IPC key (int)                         */
/*                unsigned short size;  Queue size                            */
/* Return value : int                   Queue ID                              */
/******************************************************************************/
int MakeMsgqueue(key_t key, unsigned short size)
{
int id;

	/* ## A new message queue is created, or an existing message queue is accessed with msgget function ## */
	id = msgget(key, 0);
	if(id > 0) /* 기존에 Message Queue가 존재하면 삭제한다. */
		msgctl(id, IPC_RMID, NULL);

	/* ## Message Queue Creat ## */
	id = msgget(key, PERMS | IPC_CREAT);
	if(!id) {
		msgctl(id, IPC_RMID, NULL);
		id = msgget(key, PERMS | IPC_CREAT);
	}

	if(id < 0) return -1;

	ChangeQueueSize(id, size);

	return id;
}

/******************************************************************************/
/* Get Message Queue ID for Client processor.                                 */
/* PROTOTYPE : int OpenMsgqueue(key)                                          */
/* ARGUMENT  :                                                                */
/*           key_t key; Message Access key (unsigned long).                   */
/* RETURN    : int                                                            */
/*           rtn < 0  : Can't get Message Queue ID.                           */
/*           rtn > 0  : Message Queue ID.                                     */
/* LIBRARY   : libsaipc.a                                                     */
/******************************************************************************/
int OpenMsgqueue(key_t key)
{
int id;
	id = msgget(key, 0);
	if(id < 0) return -1;
	return id;
}

/******************************************************************************/
/* Read Data from Message Queue                                               */
/* PROTOTYPE : int ReadMsgqueue(id, type, rtype, mode, buff)                  */
/* ARGUMENT  :                                                                */
/*           int   id;    Message Queue ID                                    */
/*           int   type;  Message Type for read.                              */
/*           int  *rtype; Received data type.                                 */
/*           int   mode;  WAIT : 1, NO_WAIT : 0                               */
/*           char *buff;  Received Data buffer                                */
/* RETURN    : int                                                            */
/*           rtn < 0  : Message Queue was removed,                            */
/*                       or Error occured.                                    */
/*           rtn > 0  : Read size                                             */
/*           rtn = 0  : if mode = NO_WAIT, did not received data.             */
/* LIBRARY   : libsaipc.a                                                     */
/******************************************************************************/
int ReadMsgqueue(id, type, rtype, mode, buff)
int   id, type, mode, *rtype;
char *buff;
{
MSGQDATA data;
int     rtn, flag = 0;

	flag = MSG_NOERROR; /* MSG_NOERROR : MAX_QLEN byte보다 크다면 메세지 텍스트를 잘리며 잘려진 부분을 잃는다. */

	if(!mode) { /* mode: WAIT:1, NO_WAIT:0 */
		flag |= IPC_NOWAIT;
	}

/* *********************************************************************************************************
. If type is 0, the first message on the queue is returned.
. If type is greater then 0, the first message whose type equals type is returned.
. If type is less then 0, the first message with the lowest type that is less then or qeual to the absolute value of the type argument is returned.
* **********************************************************************************************************/
	rtn = msgrcv(id, &data, MAX_QLEN, type, flag);

	if(rtn < 0 && errno == ENOMSG) {
		/* msgrcv() Fail : return -1 */
		/* ENOMSG : IPC_NOWAIT가 msgflg 에 지정되어 있고 요청된 타입의 메세지가 메세지 큐에 존재하지 않는다. */
		return 0;
	}

	memcpy(buff, data.data, rtn);
	*rtype =  data.type;

	return rtn; /* 실제로 복사된 바이트수를 반환한다. */
}

/******************************************************************************/
/* Write data to Message Queue                                                */
/* PROTOTYPE : int WriteMsgqueue(id, type, size, mode, buff)                  */
/* ARGUMENT  :                                                                */
/*           int   id;    Message Queue ID                                    */
/*           int   type;  Message Type                                        */
/*           int   size;  Data length.                                        */
/*           int   mode;  WAIT : 1, NO_WAIT : 0                               */
/*           char *buff;  Send Data buffer Pointer                            */
/* RETURN    : int                                                            */
/*           rtn < 0  : Message Queue was removed,                            */
/*                       or Error occured(errno)                              */
/*           rtn  = 1  : Write ok.                                            */
/* LIBRARY   : libsaipc.a                                                     */
/* REMARKS   :                                                                */
/******************************************************************************/
int WriteMsgqueue(int id, int type, int size, int mode, char *buff)
{
MSGQDATA data;
int rtn, flag =0;

	memset((char *)&data, 0x00, sizeof(MSGQDATA));
	data.type = type;
	memcpy(data.data, buff, size);

	if(!mode) { /* mode: WAIT:1, NO_WAIT:0 */
		flag = IPC_NOWAIT; /* flag : 0 or IPC_NOWAIT*/
	}

	/* ## Once a message queue is opened by msgget, we put a message onto the queue using msgsnd. ## */
	rtn = msgsnd(id, (void *)&data, size, flag);
	if(rtn < 0) {
		//printf("[Err] msgsnd error occur!! errno[%d]", errno);
		return (errno * -1);
	}

	return 1;
}
////////////////////////////////////////////////////////////////////////////////
// Program End
////////////////////////////////////////////////////////////////////////////////
