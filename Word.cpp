/**
 Created by zhouzhm1 on 2021/9/26.
 Update by HCl on 2021/9/27.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "Word.h"

#define LEN 20
#define WORDLEN 256  //词条最大值
#define STDLIB "../Word-store/sysLib.dat" //系统词库

using namespace std;

/* 显示单词全部信息（背诵单词） */
int loadWord(unsigned int ID, bool state)
{
    FILE *fp;
    string target;
    char openName[20];
    char shoWord[WORDLEN];  //词条显示数组
    char userlib[50] = "../Word-store/";

    itoa(ID,openName,10);    //将ID转化为字符串存储在openName中
    strcat(openName, ".dat");
    
    target.assign(userlib);
    target.append(openName);
    strcat(userlib,openName);

    if(state)
    {
        fp = fopen(STDLIB,"r+");
        if(fp == NULL)      //文件开启不成功
        {
            printf("打开 %s 错误，请刷新",STDLIB);
            return 0;
        }
        
        while( fgets(shoWord,WORDLEN,fp) != NULL)
        {
            do
            {
                printf(shoWord);
            }while(getchar() == '\n');
        }
    }
    else
    {
        fp = fopen(target.c_str(),"a+");
        if(fp == NULL)        //文件开启不成功
        {
            printf("打开 %s 错误，请刷新",openName);
            return 0;
        }
    
        while( fgets(shoWord,WORDLEN,fp) != NULL)
        {
            do
            {
                printf(shoWord);
            }while(getchar() == '\n');
        }
    }
    
    return 1;
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
    return wordNum;
}

int showWrongword()
{
    int count;
    count = 10;//wordNumber();
    word word[count];
    char filePath[] = {STDLIB};
    ifstream file;
    file.open(filePath,ios::in);
    
    if(!file.is_open())
        return 0;
    else{
        for (int i = 0; i < count; i++)
        {
            std::string strLine;
            getline(file,strLine,';');
            word[i].wordEN = strLine;
            getline(file,strLine,';');
            word[i].wordAttr = strLine;
            getline(file,strLine,';');
            word[i].wordCN = strLine;
        }
    }
}