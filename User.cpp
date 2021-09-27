//
// Created by zhouzhm1 on 2021/9/26.
//

#include "User.h"
#include <cstring>
#include <fstream>
#include <iostream>
#include <conio.h>

using namespace std;
#define MAXUSER 100
int UserCount = 0;

User user[MAXUSER];

//save to disk
void User::save() {
    ofstream outfile("./src/user.dat", ios::out);

    for (int i = 0; i < UserCount; i++) {
        outfile << user[i].userId << endl;
        outfile << user[i].userName << endl;
        outfile << user[i].password << endl;
        outfile << user[i].level << endl;
        outfile << user[i].score << endl;
        outfile << user[i].lastSignTiem << endl;
    }
    outfile.close();
}

//read to ram
void User::read() {
    ifstream infile("./src/user.dat", ios::in);

    UserCount = 0;

    if (!infile.is_open()) {
        cerr << "file can't open" << endl;
        save();
    }

    unsigned int help;
    for (int i = 0; infile >> help; i++) {
        user[i].userId = help;
        infile >> user[i].userName;
        infile >> user[i].password;
        infile >> user[i].level;
        infile >> user[i].score;
        infile >> user[i].lastSignTiem;
        UserCount++;
    }
    infile.close();
}

void User::Registers() {
    read();

    string userN;
    bool auth = false;
    while (!auth) {
        auth = true;
        cout << "请输入用户名" << endl;
        cin >> userN;
        for (int i = 0; i < UserCount; i++) {  //判断用户名是否存在
            if (userN == user[i].userName) {
                cout << "当前用户名已经注册,ID为" << user[i].userId << endl;
                auth = false;
                break;
            }
        }
        user[UserCount].userName = userN;
    }
    auth = false;
    while (!auth) {
        cout << "请输入密码；";
        string passwd;
        cin >> passwd;

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
        cout << endl;
        user[UserCount].password = passwd;

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
        if (passwd != passwd2) {
            cout << "两次输入的密码不同" << endl;
            auth = false;
        } else {
            user[UserCount].userId = 190000 + UserCount;
            user[UserCount].level = 0;
            user[UserCount].score = 0;
            cout << "注册完成，请记住你的Id" << user[UserCount++].userId << endl;
            save();
        }
    }
}

void User::Login(currentDTO *current) {
    read();

    unsigned int Id;
    int i;
    char ch, pass[20];
    cout << "请输入Id:";
    cin >> Id;
    bool found = false;
    for (i = 0; i < UserCount; i++) {
        if (user[i].userId == Id) {
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Id" << Id << "未被注册，请注册后重试。" << endl;
        return;
    }

    for (int j = 0; j < 3; j++) {
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
        if (user[i].password == pass) {
            cout << "登录成功" << endl;
            current->Id = user[i].userId;
            current->score = user[i].score;
            current->level = user[i].level;
            current->lastSignTime = user[i].lastSignTiem;
            strcpy(current->UserName, user[i].userName.c_str());
            break;
        } else {
            cout << "密码错误" << endl;
        }
    }
}

void User::update(currentDTO *current) {
    read();
    for (int i = 0; i < UserCount; i++) {
        if (current->Id == user[i].userId) {
            user[i].score = current->score;
            user[i].level = current->level;
            user[i].lastSignTiem = current->lastSignTime;
            break;
        }
    }
    save();
}
