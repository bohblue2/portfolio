/*
 * Chaos Header file 
 * Name : chaos.h
 * Date : 1997.06.27
 * By   : PentaSoft Co.,Ltd. Sagittarius
 */
#if !defined (_CHAOS_H_)
#define _CHAOS_H_

#define ONCE_MODE    0
#define FOREVER_MODE 1
#define CONTROL_TYPE 1000
#define TIME_OUT     1

#define CHAOS_PORT   16102      /* lgchaos/tcp port */ 
#define MAX_PROC_CNT  1024       /* 관리 가능한 최대 process수 */

#define BASE_EVENT_TYPE 3000

#define CMD_KILL     "KILL"
#define CMD_START    "STAT"
#define CMD_SHUTDOWN "DOWN"
#define CMD_RESTART  "REST"
#define CMD_RELOAD   "RELO"
#define CMD_END      "END "
#define CMD_LIST_REQ "LREQ"
#define CMD_CH_DATE  "DATE"
#define CMD_KILL_ID  "KIID"
#define CMD_START_ID "STID"
#define CMD_NULL     ""

#define SHM_ZCHAOS_KEY  0x40010000
#define SEMA_ZCHAOS_KEY 0x40020000

/* FetchXXXX()사용시 필요한 값들 */
typedef enum{GE=1, GT,LE,LT,EQ}QMODE;
typedef enum{
    KEY_INDEX = 1, 
    KEY_NAME,
    KEY_PID
}QKEY;

/* Shared memory Header */
typedef struct _SHM_HEADER{
        char   infor[16]; /* 생성일 yyyymmdd:HHMMSS */
        int    cnt      ; /* Item 갯수              */
}SHM_HEADER;

typedef struct _PROC_STRUCT{
	char   id       [12]; /* Process ID                  */
	char   name     [20]; /* Process name                */
	char   magic        ; /* magic value (reload시 사용) */
	int    mode         ; /* 가동 MODE FOREVER:1, ONCE:0 */
	int    pid          ; /* Process id                  */
	int    start        ; /* Proc 개시시각               */
	int    end          ; /* Proc 종료시각               */
	int    stime        ; /* Proc 최종기동 시각          */
	int    stcnt        ; /* 기동 횟수                   */
	char   path    [255]; /* Default에 대한 상대 PATH    */
	char   *Argv   [255]; /* 기동시 Arguments            */

	/* tr 통계정보 */
	/* 카오스만 기록 가능함 */
	int    chkcnt       ; /* 카오스 체크 횟수            */
	int    chktime      ; /* 카오스 체크 타임            */
	
	/* ap프로세스만 기록 가능함 */
	int    trpid        ; /* tr이 진행중인 ap thread id  */
	int    trcnt        ; /* tr이 넘어간 횟수            */
	int    trsttime       ; /* tr이 넘어간 최근시간        */
	int    trrttime    ; /* tr이 넘어간 최근시간        */
	int    errcnt       ; /* 에러가 발생한 tr건수        */
	int    errtime      ; /* 에러 tr이 발생한 최근시간   */
}PROC_STRUCT;

typedef struct _LIST_CTL_PK{
	char   type  [4];
	char   total [4];
	char   cnt   [4];
}LIST_CTL_PK;

/* 상태요구 Client에 전송하는 format */
typedef struct _PROC_LIST_PK{
	char   index [4];    /* PROCESS INDEX   */ 
	char   id    [12];    /* Process uniq id */
	char   name  [20];   /* Process name    */
	char   mode  [1];    /* Running mode    */
	char   pid   [6];    /* Process id      */
	char   start [6];    /* Start time      */
	char   end   [6];    /* End time        */
	char   stime [6];    /* 최종 Start time */
	char   stcnt [4];    /* Start count     */
}PROC_LIST_PK;
typedef struct _PROC_CTL_PK{
	char    type [4];
	char    index[6];
}PROC_CTL_PK;
typedef struct _PROC_CTLID_PK{
	char    type [4];
	char    id[20];
}PROC_CTLID_PK;
typedef struct _REQ_LIST_PK{
	char     type[4];
	char     from[4];
	char     cnt [4];
}REQ_LIST_PK;
typedef union _CHAOS_CMD_PK{
	char         index[4]     ; /* Process index               */
	PROC_LIST_PK list         ;
	LIST_CTL_PK  lctl         ;
	PROC_CTL_PK  pctl         ;
	REQ_LIST_PK  rlst         ;
	PROC_CTLID_PK pctlid      ;
}CHAOS_CMD_PK;

typedef struct _CONTROL_LIST{
	char    type[4];
	int     (*fun)();
}CONTROL_LIST;
#endif
