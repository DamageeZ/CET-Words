//
// Created by zhouzhm1 on 2021/9/26.
//

#include <cstring>
#include "Cryption.h"

const int key = 24;

char Cryption::cryptChar(char ch) { //char encryption
    return ch ^ key;
}

char Cryption::deCryptChar(char ch) { //char decryption
    return ch ^ key;
}

char *Cryption::encrypt(const char *ch) {
    char *chd;
    strcpy(chd, ch);
    int len = strlen(chd);
    for (int i = 0; i < len; i++)
        *(chd + i) = cryptChar(*(chd + i));
    return chd;
}

char *Cryption::decrypt(const char *ch) {
    char *chd;
    strcpy(chd, ch);
    int len = strlen(chd);
    for (int i = 0; i < len; i++)
        *(chd + i) = deCryptChar(*(chd + i));
    return chd;
}
