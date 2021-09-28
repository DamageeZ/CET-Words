//
// Created by zhouzhm1 on 2021/9/26.
//

#ifndef CET_USER_H
#define CET_USER_H


#include<string>
#include <utility>
#include "currentDTO.h"

class User {
private:
    std::string userName;
    std::string password;
    unsigned int userId;
    unsigned int level;
    unsigned int score;
    short lastSignTime;
public:
    User() {};

    static void Registers();

    static void Login(currentDTO *current);

    static void save();

    static void read();

    static void update(currentDTO *current);
};

struct Node {
    User info;
    Node *next;

    explicit Node(User user, Node *nextN = nullptr) {  //不允许使用隐式转换
        info = std::move(user);
        next = nextN;
    }
};

#endif //CET_USER_H