//
// Created by zhouzhm1 on 2021/9/26.
//

#ifndef CET_USER_H
#define CET_USER_H


#include<string>

class User {
private:
    std::string userName;
    std::string password;
    unsigned int userId;
    unsigned int level;
    unsigned int score;
public:
    User() {};

    void Registers();

    void Login();

    void save();

    void read();
} us;

#endif //CET_USER_H