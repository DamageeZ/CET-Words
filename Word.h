//
// Created by zhouzhm1 on 2021/9/26.
//

#ifndef CET_WORD_H
#define CET_WORD_H

/* 函数声明 */
string libChoose();
int wordCount(string filePath);
string loadWord(int countNumber, int type, string filePath);
void showAll(int select, string filePath);
void showWordList(string filePath, int count, int start);

#endif //CET_WORD_H
class Word {
private:
    char eng[46];
    enum PoS {
        n, adj, pron, adv, v, num, art, prep, conj, interj
    } pos;  //Pos Stands for Part of Speech 词性
};

