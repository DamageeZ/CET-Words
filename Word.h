//
// Created by zhouzhm1 on 2021/9/26.
//

#ifndef CET_WORD_H
#define CET_WORD_H

/* 函数声明 */
int selLib(unsigned int ID, bool state);

#endif //CET_WORD_H
class Word {
private:
    char eng[46];
    enum PoS {
        n, adj, pron, adv, v, num, art, prep, conj, interj
    } pos;  //Pos Stands for Part of Speech 词性
};

