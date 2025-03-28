////////////////////////////////////////////////////////////////////////////////
// Description  : Config Common Library
// File Name    : config.c
// Author       :
// Notes        : first release
//收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收
// Date         : 2015-07-25 螃�� 6:19:21
////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>

#include "zconf.h"

#define  CONFIG_FILE "zconfig.cfg"


////////////////////////////////////////////////////////////////////////////////
// PROTOTYPE    : int ReadConfig(char *pathname, char *category, char *keyword, char *val)
// DESCRIPTION  :
// RETURN VALUE :
// NOTES        :
//式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式
// USAGE        :
////////////////////////////////////////////////////////////////////////////////
int ReadConfig(char *pathname, char *category, char *keyword, char *val)
{
    FILE *fp = NULL;
    char lbuf[256], kbuf[256], filename[96];
    int  i, j, pathlen;
    int  clen = strlen(category);
    int  klen = strlen(keyword);
    bool findok = false;

    /////////////////////////////////////////////
    pathlen = strlen(pathname);

    if(pathname[pathlen-1] == '/') {
            pathname[pathlen-1] = 0x00;
            pathlen--;
    }

    if(pathname[0] == '/')
            sprintf(filename, "%s%s/%s" , getenv("HOME"), pathname, CONFIG_FILE);
    else    sprintf(filename, "%s/%s/%s", getenv("HOME"), pathname, CONFIG_FILE);
    /////////////////////////////////////////////

    if((fp = fopen(filename,"rt")) == NULL)
            return -1000;

    rewind(fp);

    while ( fgets(lbuf,sizeof(lbuf),fp) )
    {
            // clear space
            memset(kbuf, 0x00, sizeof(kbuf));
            for(i=0,j=0;i<strlen(lbuf);i++) {
                    if(lbuf[i] == '#') break;
                    if(isgraph(lbuf[i])) {
                            kbuf[j] = lbuf[i];
                            j++;
                    }
            }
            if(j < 3) continue; // insufficiency size

            if(findok == false) { // category find
                    if (kbuf[0]=='[' && kbuf[clen+1]==']' && strncmp(kbuf+1, category, clen) == 0)
                            findok = true;
            } else { // keyword check & copy
                    if (kbuf[0]=='[') {  // next category reached
                            fclose(fp);
                            return -1001;
                    }
                    if (strncmp(kbuf,keyword,klen) == 0 && kbuf[klen]=='=') {
                            strcpy(val,&kbuf[klen+1]);
                            fclose(fp);
                            return 1;
                    }
            }
    }

    fclose(fp);
    return -1002;
}

////////////////////////////////////////////////////////////////////////////////
// Program End
////////////////////////////////////////////////////////////////////////////////