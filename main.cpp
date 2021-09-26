#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
#include "UserService.h"

void Menu()
{
    cout << "***********************" << endl;
    cout << "*****  1、今日打卡  *****" << endl;
    cout << "*****  2、用户注册  *****" << endl;
    cout << "*****  3、背诵单词  *****" << endl;
    cout << "*****  4、词库管理  *****" << endl;
    cout << "*****  5、导入词库  *****" << endl;
    cout << "*****  6、退出  *****" << endl;
    cout << "***********************" << endl;
}

void creatUserSurface() {
    unsigned int tempUserId;
    char tempUserChar[20];
    cout << "UserId";

}

int main() {
    std::cout << "Welcome to BDC\n";
    Menu();
    getchar();
    UserService userService{};
    return 0;
}