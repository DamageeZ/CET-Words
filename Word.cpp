/**
 Created by zhouzhm1 on 2021/9/26.
 Update by HCl on 2021/9/27.
*/

#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "Word.h"

#define LEN 20
#define WORDLEN 256  //词条最大值
#define STDLIB "./Word-store/sysLib.dat" //系统词库

/* 显示单词全部信息（背诵单词） */
int loadWord(unsigned int ID, bool state)
{
    FILE *fp;
    char openName[LEN];
    char shoWord[WORDLEN];  //词条显示数组
    
    itoa(ID,openName,10);    //将ID转化为字符串存储在openName中
    strcat(openName, ".dat");

    if(state)
    {
        fp = fopen(STDLIB,"r+");
        if(fp == NULL)
        {
            printf("打开 %s 错误，请刷新",STDLIB);
            return -1;
        }
        
        while( fgets(shoWord,WORDLEN,fp) != NULL)
        {
            printf(shoWord);
        }
    }
    else
    {
        fp = fopen("./Word-store/openName","a+");
        if(fp == NULL)
        {
            printf("打开 %s 错误，请刷新",openName);
            return -1;
        }
    }
}

/* 记录单词总数 */
int wordCount(FILE *fp)
{
    int wordNum = 0;  //初始单词初始化
    char ch;
    while((ch = fgetc(fp)) != EOF)
    {
        if(ch == ';')   //单词记录标准：每个单词以“；”结尾
            wordNum++;
    }
    fclose(fp);
    return wordNum;
}