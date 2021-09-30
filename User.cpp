/**
*   Created by zhouzhm1 on 2021/9/26.
*/

#include "User.h"
#include <cstring>
#include <fstream>
#include <iostream>
#include <conio.h>

using namespace std;
//#define MAXUSER 100
//int UserCount = 0;

//User user[MAXUSER];
//Node *head = nullptr;   //链表头指针

/* 保存到文件 */
void save(Node *head)       //传入链表指针
{
    ofstream outfile("./src/user.dat", ios::out);      //以写入模式打开文件

//    for (int i = 0; i < UserCount; i++)
//    {
//        outfile << user[i].userId << endl;
//        outfile << user[i].userName << endl;
//        outfile << user[i].password << endl;
//        outfile << user[i].level << endl;
//        outfile << user[i].score << endl;
//        outfile << user[i].lastSignTime << endl;
//    }

    Node *tp;       //创建零时指针，用于指针轮换
    while (head != nullptr)     //将用户信息存入文件
    {
        outfile << head->info.userId << endl;
        outfile << head->info.userName << endl;
        outfile << head->info.password << endl;
        outfile << head->info.level << endl;
        outfile << head->info.score << endl;
        outfile << head->info.lastSignTime << endl;
        tp = head;
        head = head->next;      //指针指向下一个节点
        delete tp;      //释放指针
    }
    outfile.close();
}

/* 读取用户数据 */
Node *read(int *userCount) {
    Node *head = nullptr;
    ifstream infile("./src/user.dat", ios::in);        //以读方式打开文件
    *userCount = 0;

    if (!infile.is_open()) {
        cerr << "file can't open" << endl;
        return nullptr;
    }

//    unsigned int help;
//    for (int i = 0; infile >> help; i++) {
//        user[i].userId = help;
//        infile >> user[i].userName;
//        infile >> user[i].password;
//        infile >> user[i].level;
//        infile >> user[i].score;
//        infile >> user[i].lastSignTime;
//        UserCount++;
//    }

    unsigned int help;
    for (User tuser; infile >> help;)       //如果文件读取到 help 则进行读取操作
    {
        tuser.userId = help;        //将文件中的用户信息读取到类的对象
        infile >> tuser.userName;
        infile >> tuser.password;
        infile >> tuser.level;
        infile >> tuser.score;
        infile >> tuser.lastSignTime;
        head = new Node(tuser, head);       //分配动态内存
        (*userCount)++;     //计数器自增
    }
    infile.close();
    return head;        //返回链表指针
}

/* 用户注册 */
void Registers()
{
    int UserCount;
    Node *head = read(&UserCount);      //为新用户分配链表节点
    string userN;       //用户名字符串
    bool auth = false;      //用于后期判断是否再次循环
    
    while (!auth)
    {
        auth = true;
        cout << "请输入用户名" << endl;
        cin >> userN;
        
//        for (int i = 0; i < UserCount; i++) {  //判断用户名是否存在
//            if (userN == user[i].userName) {
//                cout << "当前用户名已经注册,ID为\t" << user[i].userId << endl;
//                auth = false;
//                break;
//            }
//        }
//        user[UserCount].userName = userN;

        Node *tp = head;
        while (tp != nullptr)
        {
            if (tp->info.userName == userN)     //首先判断用户是否已经注册
            {
                cout << "当前用户名已经注册,ID为\t" << tp->info.userId << endl;
                auth = false;
                save(head);
                return;
            }
            tp = tp->next;      //遍历用户列表
        }
    }
    
    auth = false;
    while (!auth)
    {
        User tuser;
        
        cout << "请输入密码；";
        cin >> tuser.password;
        
//        char ch, passwd[22], passwd2[22];
//        int x = 0;
//        while ((ch = getch()) != '\r' && x <= 20) {
//            if (ch == '\b') {
//                if (x > 0) {
//                    x--;
//                    cout << "\b \b";//密码支持退格的实现
//                }
//            } else {
//                passwd[x++] = ch;
//                printf("*");
//            }
//        }
//        passwd[x] = '\0';
//        cout << endl;
//        user[UserCount].password = passwd;

        cout << "请再次输入密码：";
//        x = 0;
//        while ((ch = getch()) != '\r' && x <= 20) {
//            if (ch == '\b') {
//                if (x > 0) {
//                    x--;
//                    cout << "\b \b";//密码支持退格的实现
//                }
//            } else {
//                passwd[x++] = ch;
//                printf("*");
//            }
//        }
//        passwd2[x] = '\0';
//        cout << endl;

        string passwd2;
        cin >> passwd2;
        auth = true;
        
        if (tuser.password != passwd2)
        {
            cout << "两次输入的密码不同" << endl;
            auth = false;       //再次进入循环
        }
        else
        {
//            user[UserCount].userId = 190000 + UserCount;
//            user[UserCount].level = 0;
//            user[UserCount].score = 0;

            tuser.userId = 190000 + UserCount;
            tuser.userName = userN;
            tuser.level = 0;
            tuser.score = 0;
            tuser.lastSignTime = 0;
            head = new Node(tuser, head);
            cout << "注册完成，请记住你的Id:\t" << tuser.userId << endl;
            save(head);     //保存节点信息
        }
    }
}

/* 用户登录 */
void Login(currentDTO *current)
{
    int userCount;
    Node *head = read(&userCount);      //找到用户所在的节点

    unsigned int Id;
    char pass[20];
    cout << "请输入Id:";
    cin >> Id;
    bool found = false;
    
//    int i;
//    for (i = 0; i < UserCount; i++) {
//        if (user[i].userId == Id) {
//            found = true;
//            break;
//        }
//    }

    Node *tp = head;
    while (tp != nullptr)
    {
        if (tp->info.userId == Id)
        {
            found = true;       //判断已经注册，进行后续操作
            break;
        }
        tp = tp->next;
    }
    
    if (!found)
    {
        cout << "Id" << Id << "未被注册，请注册后重试。" << endl;
        save(head);
        return;
    }
    
    for (int j = 0; j < 3; j++)         //给用户三次输入密码的机会
    {
        cout << "请输入密码" << flush;
        
//        int x = 0;
//        while ((ch = getch()) != '\r' && x <= 20) {
//            if (ch == '\b') {
//                if (x > 0) {
//                    x--;
//                    cout << "\b \b";//密码支持退格的实现
//                }
//            } else {
//                pass[x++] = ch;
//                printf("*");
//            }
//        }

        cin >> pass;
        
//        if (user[i].password == pass)
//        {
//            cout << "登录成功" << endl;
//            current->Id = user[i].userId;
//            current->score = user[i].score;
//            current->level = user[i].level;
//            current->lastSignTime = user[i].lastSignTime;
//            strcpy(current->UserName, user[i].userName.c_str());
//            break;
//        }
//        else
//        {
//            cout << "密码错误" << endl;
//        }

        if (tp->info.password == pass)
        {
            cout << "登录成功" << endl;
            current->Id = tp->info.userId;
            current->score = tp->info.score;
            current->level = tp->info.level;
            current->lastSignTime = tp->info.lastSignTime;
            strcpy(current->UserName, tp->info.userName.c_str());
            break;
        }
        else
        {
            cout << "密码错误" << "\n请再次输入密码" << "\n您还有" << 2 - j << "次机会" << endl;
        }
    }
    save(head);
}

/* 用户信息更新 */
void update(currentDTO *current)
{
    int userCount;
    Node *head = read(&userCount);
    
//    for (int i = 0; i < UserCount; i++) {
//        if (current->Id == user[i].userId) {
//            user[i].score = current->score;
//            user[i].level = current->level;
//            user[i].lastSignTime = current->lastSignTime;
//            break;
//        }
//    }

    Node *tp = head;
    while (tp != nullptr)
    {
        if (current->Id == tp->info.userId)     //判断用户相同
        {
            tp->info.score = current->score;
            tp->info.level = current->level;
            tp->info.lastSignTime = current->lastSignTime;
            break;
        }
        tp = tp->next;
    }
    save(head);
}