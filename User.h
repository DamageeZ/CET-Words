//
// Created by zhouzhm1 on 2021/9/26.
//

#ifndef CET_USER_H
#define CET_USER_H


#include<string>

class User
{
private:
    unsigned int UserId;
    std::string UserName;
    std::string UserPwd;
    unsigned int level;
public:
    User();

    void addUser(User x);

    void delUser(User x);

    unsigned int getUserId();

    void setUserId(unsigned int x);

    void setUserName(const char *x);

    const char *getUserName();

    const char *getUserPwd();

    unsigned int getLevel();

    void setLevel(unsigned int x);

    ~User();

    void setUserPwd(const char *x);
};

#endif //CET_USER_H