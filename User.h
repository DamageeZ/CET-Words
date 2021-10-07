/**
*   Created by zhouzhm1 on 2021/9/26.
*/

#ifndef CET_USER_H
#define CET_USER_H

#include<string>
#include <utility>
#include "currentDTO.h"


struct User     //定义用户类
{
    std::string userName;       //
    std::string password;
    unsigned int userId;
    unsigned int level;
    unsigned int score;
    short lastSignTime;
    
    User() {};
};

struct Node     //定义用于链表节点的结构体
{
    User info;
    Node *next;
    
    explicit Node(User user, Node *nextN = nullptr)     //不允许使用隐式转换
    {
        info = std::move(user);
        next = nextN;
    }
};

/* 函数声明 */
void Registers();

void Login(currentDTO *current);

void save(Node *head);

Node *read(int *userCount);

void update(currentDTO *current);

#endif //CET_USER_H