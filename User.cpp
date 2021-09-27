//
// Created by zhouzhm1 on 2021/9/26.
//

#include "User.h"
#include <cstring>
#include <fstream>
#include <iostream>

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
    }
    outfile.close();
}

//read to ram
void User::read() {
    ifstream infile("./src/user.dat", ios::in);

    UserCount = 0;

    if (!infile.is_open()) {
        cerr << "file can't open" << endl;
    }

    for (int i = 0; !infile.eof(), i++) {
        infile >> user[i].userId;
        infile >> user[i].userName;
        infile >> user[i].password;
        infile >> user[i].level;
        infile >> user[i].score;
        UserCount++;
    }
    infile.close();
}

void User::Registers() {
    us.read();
    string userN, userP, userP2;
    for (int i = UserCount - 1; i < MAXUSER; i++) {
        cout << ""
    }
}