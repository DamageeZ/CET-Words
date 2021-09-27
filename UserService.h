//
// Created by zhouzhm1 on 2021/9/26.
//

#ifndef CET_USERSERVICE_H
#define CET_USERSERVICE_H

#include "User.h"

class UserService {
public:
    User *login(unsigned int userName, const char *userPwd);

    void createUser(const User &x);

    void delUser(unsigned int userId);

    void findByUserId(unsigned int userId);

    void writeUser(std::ofstream &out, User data);

    void readUser(std::ifstream &in, User &dest);

private:
    Cryption encryption;
};


#endif //CET_USERSERVICE_H
