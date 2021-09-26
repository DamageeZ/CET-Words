#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
#include "User.h"

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

int main()
{
    std::cout << "Welcome to BDC\n";
    Menu();
    const char* test = "abcd";
    User * u = new User();
    u->setUserName(test);
    cout << u->getUserName();
    return 0;
}