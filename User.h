//
// Created by zhouzhm1 on 2021/9/26.
//

#ifndef CET_USER_H
#define CET_USER_H


#include<string>
#include "currentDTO.h"
class User {
private:
    std::string userName;
    std::string password;
    unsigned int userId;
    unsigned int level;
    unsigned int score;
public:
    User() {};

    static void Registers();

    static void Login(DTO *current);

    static void save();

    static void read();
};

#endif //CET_USER_H