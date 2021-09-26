//
// Created by zhouzhm1 on 2021/9/26.
//

#include "User.h"
#include <cstring>

using namespace std;

User::User() {
}

void User::addUser(User x) {
}

void User::delUser(User x) {
}

unsigned int User::getUserId() const {
    return UserId;
}

void User::setUserId(unsigned int userid) {
    this->UserId = userid;
}

void User::setUserName(const char *x) {
    this->UserName.assign(x);
}

void User::setUserPwd(const char *x) {
    this->UserPwd.assign(x);
}

const char *User::getUserName() const {
    return UserName.c_str();
}

const char *User::getUserPwd() const {
    return UserPwd.c_str();
}

unsigned int User::getLevel() const {
    return Level;
}

void User::setLevel(unsigned int x) {
    this->Level = x;
}

User::~User() {
}
