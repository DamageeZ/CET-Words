/**
 Created by zhouzhm1 on 2021/9/26.
 Update by HCl on 2021/9/27.
 Update by HCl on 2021/9/28.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stdbool.h"
#include <iostream>
#include <fstream>
#include "Word.h"


#define LEN 20  //ID最大长度
#define WORDLEN 256  //词条最大值
#define STDLIB "../src/sysLib.dat" //系统词库

using namespace std;

/* 显示单词全部信息（背诵单词） */
int loadWord(unsigned int ID, _Bool state)
{
    FILE *fp;
    string target;
    char openName[LEN];
    char shoWord[WORDLEN];  //词条显示数组
    char userlib[50] = "../src/";

    itoa(ID,openName,10);    //将ID转化为字符串存储在openName中
    strcat(openName, ".dat");
    
    target.assign(userlib);
    target.append(openName);
    strcat(userlib,openName);

    if(state)
    {
        fp = fopen(STDLIB,"r+");    //打开系统词库
        if(fp == NULL)      //文件开启不成功
        {
            printf("打开 %s 错误，请刷新",STDLIB);
            return 0;
        }
        
        while(fgets(shoWord,WORDLEN,fp) != NULL)
        {
            fputs(shoWord,stdout);
            if(getchar() == '\n')
                continue;
        }
    }
    else
    {
        fp = fopen(target.c_str(),"a+");
        if(fp == NULL)        //文件开启不成功
        {
            printf("打开 %s 错误，请刷新",target.c_str());
            return 0;
        }
        
        while(fgets(shoWord,WORDLEN,fp) != NULL)
        {
            fputs(shoWord,stdout);
            if(getchar() == '\n')
                continue;
        }
    }

    if(fclose(fp) == 0)
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

/* 显示单词 */
int showWrongword(void)
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

/* 用户添加词条 */
void addWord(FILE *fp)
{
    struct addWord list;
    list = {0};
    
    gets(list.wordEN);    //从键盘输入英语单词
    gets(list.wordAttr);  //从键盘输入词性
    gets(list.wordCN);    //从键盘输入汉语翻译
    
    fputs(list.wordEN,fp);      //显示英语单词
    fputs(",",fp);         //用“，”分隔
    fputs(list.wordAttr,fp);    //显示词性
    fputs(",",fp);         //用“，”分隔
    fputs(list.wordCN,fp);      //显示汉语翻译
    fputs(";",fp);         //用“；”表示词条结束
    fputs("\n",fp);
}