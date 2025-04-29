////////////////////////////////////////////////////////////////////////////////
// Description  : MySQL Library Common Header
// File Name    : zprodb.h
// Author       :
// Notes        :
//━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
// Date         :
////////////////////////////////////////////////////////////////////////////////
#ifndef _MDB_H_
#define _MDB_H_

#include <mysql/mysql.h>
#include <stdbool.h>
#include "zconf.h"

////////////////////////////////////////////////////////////////////////////////
// common structure ----------------------------------------------------------//
////////////////////////////////////////////////////////////////////////////////

typedef struct _MYDB_CONFIG {
    char    host    [32];   // mysql host
    char    user    [32];   // mysql user
    char    password[32];   // mysql password
    char    database[32];   // mysql database
} MYDB_CONFIG;

typedef struct _MYDB_CONNECT {
    MYSQL  *mysql;          // mysql connect pointer
    int     work ;          // mysql work gb : work: 1, rest: -1
    int     alive;          // mysql alive check : alive: 1, die: -1
} MYDB_CONNECT;

////////////////////////////////////////////////////////////////////////////////
// LIBRARY      : libdatmdb.a
// DIRECTORY    :
// DESCRIPTION  : MySQL 라이브러리
// FILE         :
//───────────────────────────────────────
// NOTES        :
////////////////////////////////////////////////////////////////////////////////
int  OpenAutoMyDB(MYSQL **mysql, char *filename, char *category);
int  OpenAutoRetryMyDB(MYSQL **mysql, char *filename, char *category);
int  OpenMyDB(MYSQL **mysql, const char *host, const char *user, const char *password, const char *database);
void CloseMyDB(MYSQL *mysql);
int  CommitMyDB(MYSQL *mysql);
int  RollbackMyDB(MYSQL *mysql);
int  TranStartMyDB(MYSQL *mysql);
int  TranEndMyDB(MYSQL *mysql);
void ErrorMsgMyDB(MYSQL *mysql);
int  ExecSqlMyDB(MYSQL *mysql, const char *query);
int  CursorUseMyDB(MYSQL *mysql, MYSQL_RES **recset, const char *query);
int  CursorStoreMyDB(MYSQL *mysql, MYSQL_RES **recset, const char *query);
void CursorFreeMyDB(MYSQL_RES **recset);
int CursorFetchMyDB(MYSQL_RES **recset, MYSQL_ROW *row);
int  PingMyDB(MYSQL *mysql);
int  ReadConfigMyDB(char *filename, char *category, MYDB_CONFIG *mydb_config);

//extern int  FetchOnceSqlMyDB(MYSQL *mysql, MYSQL_ROW *row, const char *query);

#endif
////////////////////////////////////////////////////////////////////////////////
// Program End
////////////////////////////////////////////////////////////////////////////////
