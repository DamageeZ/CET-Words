//
// Created by zhouzhm1 on 2021/9/26.
// Used to encrypt and decrypt pwd
//

#ifndef CET_CRYPTION_H
#define CET_CRYPTION_H

class Cryption {
private:
    char cryptChar(char ch);

    char deCryptChar(char ch);

public:
    char *encrypt(const char *ch);

    char *decrypt(const char *ch);
};


#endif //CET_CRYPTION_H
