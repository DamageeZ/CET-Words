//
// Created by zhouzhm1 on 2021/9/26.
//

#ifndef CET_USER_H
#define CET_USER_H


#include<string>
#include <utility>

class User {
private:
    unsigned int UserId;
    std::string UserName;
    std::string UserPwd;
    unsigned int Level;
public:
    User();

    User(unsigned int userId, std::string userPwd, std::string userName, unsigned int level) :
            UserId(userId),
            UserName(std::move(userName)),
            UserPwd(std::move(userPwd)),
            Level(level) {};

    void addUser(User x);

    void delUser(User x);

    unsigned int getUserId() const;

    void setUserId(unsigned int x);

    void setUserName(const char *x);

    const char *getUserName() const;

    const char *getUserPwd() const;

    unsigned int getLevel() const;

    void setLevel(unsigned int x);

    ~User();

    void setUserPwd(const char *x);
};

#endif //CET_USER_H