/**
    Created by zhouzhm1 on 2021/9/26.
    Update by HCl on 2021/9/27.
*/

#ifndef CET_WORD_H
#define CET_WORD_H

#include "string.h"
#include <iostream>
#include <fstream>
#include <string>

#define WORDENLEN 20  //单词长度
#define WORDATTRLEN 10  //词性长度
#define WORDCNLEN 100  //汉译长度

using namespace std;

/* 函数声明 */
int loadWord(unsigned int ID, bool state);
int wordCount(FILE *fp);
int showWrongword();
void addWord(FILE *fp);

/* 结构体声明 */
struct word
{
    string wordEN;
    string wordAttr;
    string wordCN;
};

struct addWord
{
    char wordEN[WORDENLEN];
    char wordAttr[WORDATTRLEN];
    char wordCN[WORDCNLEN];
};

#endif //CET_WORD_H

class Word {
private:
    char eng[46];
    enum PoS {
        n, adj, pron, adv, v, num, art, prep, conj, interj
    } pos;  //Pos Stands for Part of Speech 词性
};

