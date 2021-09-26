//
// Created by zhouzhm1 on 2021/9/26.
//

#include "User.h"
#include <cstring>
using namespace std;

User::User(void)
{
}

void User::addUser(User x)
{
}

void User::delUser(User x)
{
}

unsigned int User::getUserId()
{
    return UserId;
}

void User::setUserId(unsigned int userid)
{
    this->UserId = userid;
}

void User::setUserName(const char * x)
{
    this->UserName.assign(x);
}

const char * User::getUserName()
{
    return UserName.c_str();
}

const char * User::getUserPwd()
{
    return UserPwd.c_str();
}

unsigned int User::getLevel()
{
    return level;
}

void User::setLevel(unsigned int x)
{
    this->level = x;
}

User::~User()
{
}
