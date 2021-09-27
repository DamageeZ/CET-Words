/**
 Created by zhouzhm1 on 2021/9/26.
 Update by HCl on 2021/9/27.
*/

#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "Word.h"

#define LEN 20
#define STDLIB "./Word-store/sysLib.dat" //系统词库

/* 词库选择 */
int selLib(unsigned int ID, bool state)
{
    FILE *fp;
    char openName[LEN];
    
    itoa(ID,openName,10);    //将ID转化为字符串存储在openName中
    strcat(openName, ".dat");

    if(state)
    {
        fp = fopen(STDLIB,"r+");
    }
    else
    {
        fp = fopen("./Word-store/openName","a+");
    }
}



