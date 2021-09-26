//
// Created by zhouzhm1 on 2021/9/26.
//

#include "UserService.h"
#include <iostream>
#include <fstream>
#include <dirent.h>

using namespace std;

User *UserService::login(unsigned int userId, const char *userPwd) {
    ifstream infile;
    User *correctUser = new User();
    unsigned int tempUserInt;
    char tempUserChar[20], encryptedPwd[20];
    strcpy(encryptedPwd, encryption.encrypt(userPwd));
    infile.open("\\src\\user.dat", ios::in);
    if (!infile)  //no such file
    {
        ofstream outfile;
        outfile.open("\\src\\user.dat", ios::out);
        outfile.close();
        return nullptr; //emtpy pointer
    }
    while (!infile.eof()) {
        infile >> tempUserInt >> tempUserChar;
        if (strcmp(tempUserChar, userPwd) == 0 && tempUserInt == userId) {
            correctUser->setUserId(tempUserInt);
            infile >> tempUserChar;
            correctUser->setUserName(tempUserChar);
            infile >> tempUserInt;
            correctUser->setLevel(tempUserInt);
            infile.close();
            break;
        }
    }
    return correctUser;
}

void UserService::createUser(const User &x) {
    ifstream userfile;
    userfile.open("\\src\\user.dat", ios::out | ios::in);
    cout << x.getUserId() << x.getUserPwd() << x.getUserName() << x.getLevel();
//    cout << "You are the "  << "User" << endl;
}

void UserService::delUser(unsigned int userId) {

}

void UserService::findByUserId(unsigned int userId) {
    ifstream infile;
    unsigned int id = 190000;
    infile.open("\\src\\user.dat", ios::in);
}

void UserService::readUser(ifstream &in, User &dest) {
    in.read(reinterpret_cast<char *>(&dest), sizeof(User));
}

void UserService::writeUser(ofstream &out, User data) {
    out.write(reinterpret_cast<char *>(&data), sizeof(User));
}
