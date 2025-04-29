////////////////////////////////////////////////////////////////////////////////
// Description  : MySQL Common Library
// File Name    : 
// Author       :
// Notes        : first release
//━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
// Date         : 2015-07-25 오후 6:19:21
////////////////////////////////////////////////////////////////////////////////
//#include <my_global.h>
//#include <my_sys.h>

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <mysql/mysql.h>

#include "zconf.h"
#include "mdb.h"

////////////////////////////////////////////////////////////////////////////////
// function prototype --------------------------------------------------------//
////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
// PROTOTYPE    : int ReadConfigMyDB(char *filename, char *category, char *MYDB_CONFIG)
// DESCRIPTION  : connect to mysql by config file info
// RETURN VALUE :
// NOTES        :
//───────────────────────────────────────
// USAGE        :
////////////////////////////////////////////////////////////////////////////////
int ReadConfigMyDB(char *filename, char *category, MYDB_CONFIG *mydb_config)
{
    if(ReadConfig(filename, category, "host"     , mydb_config->host    ) < 0) return -1101;
    if(ReadConfig(filename, category, "user"     , mydb_config->user    ) < 0) return -1102;
    if(ReadConfig(filename, category, "password" , mydb_config->password) < 0) return -1103;
    if(ReadConfig(filename, category, "database" , mydb_config->database) < 0) return -1104;

    return 1;
}

////////////////////////////////////////////////////////////////////////////////
// PROTOTYPE    : int OpenAutoMyDB(MYSQL **mysql, char *filename, char *category)
// DESCRIPTION  : connect to DB server by config file info
// RETURN VALUE :
// NOTES        :
//───────────────────────────────────────
// USAGE        :
////////////////////////////////////////////////////////////////////////////////
int OpenAutoMyDB(MYSQL **mysql, char *filename, char *category)
{
    // connection flags
    unsigned int flags = 0;

    // connection vars
    char host[32], user[32], password[32], database[32];

    memset(host    , 0x00, sizeof(host    ));
    memset(user    , 0x00, sizeof(user    ));
    memset(password, 0x00, sizeof(password));
    memset(database, 0x00, sizeof(database));

    if(ReadConfig(filename, category, "host"     , host    ) < 0) return -1101;
    if(ReadConfig(filename, category, "user"     , user    ) < 0) return -1102;
    if(ReadConfig(filename, category, "password" , password) < 0) return -1103;
    if(ReadConfig(filename, category, "database" , database) < 0) return -1104;

    // initialize client library
    if(mysql_library_init(0, NULL, NULL))
    {
        Log("[Err] : (%s) could not initialize MySQL library\n", __func__);

        return -1001;
    }

    // initialize connection handler
    if((*mysql = mysql_init(NULL)) == NULL)
    {
        Log("[Err] : (%s) mysql_init() failed (probably out of memory)\n", __func__);

        return -1002;
    }

    if(mysql_options(*mysql, MYSQL_SET_CHARSET_NAME, "euckr") < 0)
    {
        Log("[Err] : (%s) mysql_options() MYSQL_SET_CHARSET_NAME failed : Error %u (%s): %s\n",
                __func__, mysql_errno(*mysql),mysql_sqlstate(*mysql),mysql_error(*mysql));
    }
    mysql_options(*mysql, MYSQL_INIT_COMMAND, "SET NAMES euckr");
    //mysql_options(*mysql, MYSQL_INIT_COMMAND, "SET collation_connection=utf8_general_ci");
    
    flags |= CLIENT_MULTI_STATEMENTS|CLIENT_FOUND_ROWS;

#if 0
    my_bool reconnect = true;
    mysql_options(*mysql, MYSQL_OPT_RECONNECT, &reconnect);
#endif

    /* 2019.04 (char *)NULL 한글 문제
    connect to server with option CLIENT_MULTI_STATEMENTS
    if(mysql_real_connect(*mysql, (char *)host, (char *)user, (char *)password, (char *)database, 0, (char *)NULL, flags) == NULL)
    */
    if(mysql_real_connect(*mysql, (char *)host, (char *)user, (char *)password, (char *)database, 0, (char *)NULL, flags) == NULL)
    {
        Log("[Err] : (%s) mysql_real_connect() failed : Error %u (%s): %s\n",
                __func__, mysql_errno(*mysql),mysql_sqlstate(*mysql),mysql_error(*mysql));
        mysql_close(*mysql);

        return -1003;
    }
    
    Log("[Msg] : (%s) MySQL Connect Success!\n", __func__);

    return 1;
}

////////////////////////////////////////////////////////////////////////////////
// PROTOTYPE    : int OpenMyDB(MYSQL **mysql, const char *host, const char *user,
//                             const char *password, const char *database)
// DESCRIPTION  : connect to server
// RETURN VALUE :
// NOTES        :
//───────────────────────────────────────
// USAGE        :
////////////////////////////////////////////////////////////////////////////////
int OpenMyDB(MYSQL **mysql, const char *host, const char *user, const char *password, const char *database)
{
    // connection flags
    unsigned int flags = 0;

    // initialize client library
    if(mysql_library_init(0, NULL, NULL))
    {
            Log("[Err] : (%s) mysql_library_init() failed\n", __func__);

            return -1001;
    }

    // initialize connection handler
    if((*mysql = mysql_init(NULL)) == NULL)
    {
            Log("[Err] : (%s) mysql_init() failed (probably out of memory)\n", __func__);

            return -1002;
    }

    flags |= CLIENT_MULTI_STATEMENTS|CLIENT_FOUND_ROWS;

#if 0
    my_bool reconnect = true;
    mysql_options(*mysql, MYSQL_OPT_RECONNECT, &reconnect);
#endif

    // connect to server with option CLIENT_MULTI_STATEMENTS
    if(mysql_real_connect(*mysql, host, user, password, database, 0, (char *)NULL, flags) == NULL)
    {
            Log("[Err] : (%s) mysql_real_connect() failed : Error %u (%s): %s\n",
                    __func__, mysql_errno(*mysql),mysql_sqlstate(*mysql),mysql_error(*mysql));
            mysql_close(*mysql);

            return -1003;
    }

    Log("[Msg] : (%s) MySQL Connect Success!\n", __func__);

    return 1;
}

////////////////////////////////////////////////////////////////////////////////
// PROTOTYPE    : void CloseMyDB(MYSQL *mysql)
// DESCRIPTION  : disconnect from server, terminate client library
// RETURN VALUE :
// NOTES        :
//───────────────────────────────────────
// USAGE        :
////////////////////////////////////////////////////////////////////////////////
void CloseMyDB(MYSQL *mysql)
{
    if(mysql != NULL)
    {
        mysql_close(mysql);
        //mysql_thread_end();
        mysql_library_end();
    }
}

////////////////////////////////////////////////////////////////////////////////
// PROTOTYPE    : int CommitMyDB(MYSQL *mysql)
// DESCRIPTION  :
// RETURN VALUE :
// NOTES        :
//───────────────────────────────────────
// USAGE        :
////////////////////////////////////////////////////////////////////////////////
int CommitMyDB(MYSQL *mysql)
{
    if(mysql_commit(mysql)!=(my_bool)0)
    {
        Log("[Err] : (%s) mysql_commit() failed : Error %u (%s): %s\n",
                __func__, mysql_errno(mysql),mysql_sqlstate(mysql),mysql_error(mysql));

        return -1001;
    }

    if(mysql_autocommit(mysql,(my_bool)1)!=(my_bool)0) // set autocommit to true
    {
        Log("[Err] : (%s) mysql_autocommit() failed : Error %u (%s): %s\n",
                __func__, mysql_errno(mysql),mysql_sqlstate(mysql),mysql_error(mysql));

        return -1002;
    }

    return 1;
}

////////////////////////////////////////////////////////////////////////////////
// PROTOTYPE    : int RollbackMyDB(MYSQL *mysql)
// DESCRIPTION  :
// RETURN VALUE :
// NOTES        :
//───────────────────────────────────────
// USAGE        :
////////////////////////////////////////////////////////////////////////////////
int RollbackMyDB(MYSQL *mysql)
{
    if(mysql_rollback(mysql)!=(my_bool)0)
    {
        Log("[Err] : (%s) mysql_commit() failed : Error %u (%s): %s\n",
                __func__, mysql_errno(mysql),mysql_sqlstate(mysql),mysql_error(mysql));

        return -1001;
    }

    if(mysql_autocommit(mysql,(my_bool)1)!=(my_bool)0) // set autocommit to true
    {
        Log("[Err] : (%s) mysql_autocommit() failed : Error %u (%s): %s\n",
                __func__, mysql_errno(mysql),mysql_sqlstate(mysql),mysql_error(mysql));

        return -1002;
    }

    return 1;
}

////////////////////////////////////////////////////////////////////////////////
// PROTOTYPE    : int TranStartMyDB(MYSQL *mysql)
// DESCRIPTION  :
// RETURN VALUE :
// NOTES        :
//───────────────────────────────────────
// USAGE        :
////////////////////////////////////////////////////////////////////////////////
int TranStartMyDB(MYSQL *mysql)
{
    if(mysql_autocommit(mysql, (my_bool)0)==(my_bool)0) // set autocommit to false
            return 1;                                   // start transaction
    else    return -1;
}

////////////////////////////////////////////////////////////////////////////////
// PROTOTYPE    : int TranEndMyDB(MYSQL *mysql)
// DESCRIPTION  :
// RETURN VALUE :
// NOTES        :
//───────────────────────────────────────
// USAGE        :
////////////////////////////////////////////////////////////////////////////////
int TranEndMyDB(MYSQL *mysql)
{
    if(mysql_autocommit(mysql, (my_bool)1)==(my_bool)0) // set autocommit to true
            return 1;                                   // end transaction
    else    return -1;
}

////////////////////////////////////////////////////////////////////////////////
// PROTOTYPE    : int ExecSqlMyDB(MYSQL *mysql, const char *query)
// DESCRIPTION  :
// RETURN VALUE : Returns the number of rows by UPDATE,DELETE,INSERT query
// NOTES        : UPDATE,DELETE,INSERT처럼 결과SET이 없는 Query에 사용
//───────────────────────────────────────
// USAGE        :
////////////////////////////////////////////////////////////////////////////////
int ExecSqlMyDB(MYSQL *mysql, const char *query)
{
    if(mysql_query(mysql, query) != 0) // the statement failed
    {
            Log("[Err] : (%s) Could not execute statement : Error %u (%s): %s\n",
                    __func__, mysql_errno(mysql),mysql_sqlstate(mysql),mysql_error(mysql));

            return -1001;
    }

    return (int)mysql_affected_rows(mysql);
}

////////////////////////////////////////////////////////////////////////////////
// PROTOTYPE    : int CursorUseMyDB(MYSQL *mysql, MYSQL_RES **recset, const char *query)
// DESCRIPTION  :
// RETURN VALUE :
// NOTES        :
//───────────────────────────────────────
// USAGE        :
////////////////////////////////////////////////////////////////////////////////
int CursorUseMyDB(MYSQL *mysql, MYSQL_RES **recset, const char *query)
{
    if(mysql_query(mysql, query) != 0) // the statement failed
    {
            Log("[Err] : (%s) Could not execute statement : Error %u (%s): %s\n",
                    __func__, mysql_errno(mysql),mysql_sqlstate(mysql),mysql_error(mysql));
            return -1001;
    }

    // the statement succeeded; determine whether it returned data
    if((*recset = mysql_use_result(mysql)) == NULL) // no result set was returned
    {
            Log("[Err] : (%s) Could not retrieve result set : Error %u (%s): %s\n",
                    __func__, mysql_errno(mysql),mysql_sqlstate(mysql),mysql_error(mysql));

            return -1002;
    }

    return 1;
}

////////////////////////////////////////////////////////////////////////////////
// PROTOTYPE    : int CursorStoreMyDB(MYSQL *mysql, MYSQL_RES **recset, const char *query)
// DESCRIPTION  :
// RETURN VALUE :
// NOTES        :
//───────────────────────────────────────
// USAGE        :
////////////////////////////////////////////////////////////////////////////////
int CursorStoreMyDB(MYSQL *mysql, MYSQL_RES **recset, const char *query)
{
    if(mysql_query(mysql, query) != 0) // the statement failed
    {
            Log("[Err] : (%s) Could not execute statement : Error %u (%s): %s\n",
                    __func__, mysql_errno(mysql),mysql_sqlstate(mysql),mysql_error(mysql));

            /////////////////////////////////////
            Log("[Err] : (%s) Force Termination!\n", __func__);
            exit(0); // Error 2006 (HY000): MySQL server has gone away
            /////////////////////////////////////

            return -1001;
    }

    // the statement succeeded; determine whether it returned data
    if((*recset = mysql_store_result(mysql)) == NULL) // no result set was returned
    {
            Log("[Err] : (%s) Could not retrieve result set : Error %u (%s): %s\n",
                    __func__, mysql_errno(mysql),mysql_sqlstate(mysql),mysql_error(mysql));

            return -1002;
    }

    return (int)mysql_num_rows(*recset);
}

////////////////////////////////////////////////////////////////////////////////
// PROTOTYPE    : void CursorFreeMyDB(MYSQL_RES **recset)
// DESCRIPTION  :
// RETURN VALUE :
// NOTES        :
//───────────────────────────────────────
// USAGE        :
////////////////////////////////////////////////////////////////////////////////
void CursorFreeMyDB(MYSQL_RES **recset)
{
    if(*recset != NULL)
        mysql_free_result(*recset);
}

////////////////////////////////////////////////////////////////////////////////
// PROTOTYPE    : bool CursorFetchMyDB(MYSQL_RES **recset, MYSQL_ROW *row)
// DESCRIPTION  :
// RETURN VALUE :
// NOTES        :
//───────────────────────────────────────
// USAGE        :
////////////////////////////////////////////////////////////////////////////////
int CursorFetchMyDB(MYSQL_RES **recset, MYSQL_ROW *row)
{
    if((*row = mysql_fetch_row(*recset)) == NULL)
            return 0;
    else    return 1;
}

////////////////////////////////////////////////////////////////////////////////
// PROTOTYPE    : void ErrorMsgMyDB(MYSQL *mysql)
// DESCRIPTION  :
// RETURN VALUE :
// NOTES        :
//───────────────────────────────────────
// USAGE        :
////////////////////////////////////////////////////////////////////////////////
void ErrorMsgMyDB(MYSQL *mysql)
{
    if(mysql != NULL)
    {
            Log("[Err] : (%s) Error %u (%s): %s\n",
                    __func__, mysql_errno(mysql),mysql_sqlstate(mysql),mysql_error(mysql));
    }
}

////////////////////////////////////////////////////////////////////////////////
// PROTOTYPE    : int PingMyDB(MYSQL *mysql)
// DESCRIPTION  :
// RETURN VALUE :
// NOTES        :
//───────────────────────────────────────
// USAGE        :
////////////////////////////////////////////////////////////////////////////////
int PingMyDB(MYSQL *mysql)
{
    // MySQL 5.0 이후로는 자동 접속 되지 않는다.
    if(mysql_ping(mysql) != 0)
    {
            Log("[Err] : (%s) Connection Not valid! : Error %u (%s): %s\n",
                    __func__, mysql_errno(mysql),mysql_sqlstate(mysql),mysql_error(mysql));
            return -1001;
    }

    Log("[Err] : (%s) Connection alive.\n", __func__);

    return 1;
}
////////////////////////////////////////////////////////////////////////////////
// Program End
////////////////////////////////////////////////////////////////////////////////
