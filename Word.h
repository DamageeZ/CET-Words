//
// Created by zhouzhm1 on 2021/9/26.
//

#ifndef CET_WORD_H
#define CET_WORD_H

#include "string.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/* 函数声明 */
int loadWord(unsigned int ID, bool state);
int wordCount(FILE *fp);

/* 结构体声明 */
struct word
{
    string wordEN;
    string wordAttr;
    string wordCN;
};

#endif //CET_WORD_H

class Word {
private:
    char eng[46];
    enum PoS {
        n, adj, pron, adv, v, num, art, prep, conj, interj
    } pos;  //Pos Stands for Part of Speech 词性
};

