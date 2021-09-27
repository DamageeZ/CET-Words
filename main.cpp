#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

#include "User.h"

void Menu(currentDTO *current) {
    if (current->Id == 0) {
        cout << "未登录" << endl;
    } else {
        cout << "\t\t" << current->UserName << endl;
        cout << "\t\t经验：" << current->level << endl;
        cout << "\t\t分数：" << current->score << endl;
    }

    cout << "***********************" << endl;
    cout << "*****  1、每日打卡  *****" << endl;
    cout << "*****  2、用户登录  *****" << endl;
    cout << "*****  3、用户注册  *****" << endl;
    cout << "*****  4、单词学习  *****" << endl;
    cout << "*****  5、词库管理  *****" << endl;
    cout << "*****  6、退出登录  *****" << endl;
    cout << "*****  7、退出软件  *****" << endl;
    cout << "***********************" << endl;
}

int main() {
    currentDTO *current = (currentDTO *) malloc(sizeof(currentDTO));
    memset(current, 0, sizeof(currentDTO));
    std::cout << "Welcome to BDC\n";
    Menu(current);
    int control = 0;
    while (true) {
        cin >> control;
        switch (control) {
            case 1:
                break;
            case 2:
                User::Login(current);
                break;
            case 3:
                User::Registers();
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                User::update(current);
                memset(current, 0, sizeof(currentDTO));
            case 7:
                return 0;
            default :
                cout << "error input" << endl;
        }
        Menu(current);
    }
}