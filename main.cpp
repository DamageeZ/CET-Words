#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ctime>

#define SYSCLEAR cls
//#define  SYSCLEAR clear
using namespace std;

#include "User.h"
#include "Recitation.h"
#include "Word.h"

void Signup(currentDTO *current) {
    current->level += 12;
    current->lastSignTime = current->dateOfToday;
    User::update(current);
}

void Menu(currentDTO *current) {
    if (current->Id == 0) {
        cout << "\n\t\t未登录" << endl;
    } else {
        cout << "\t\t" << current->UserName << endl;
        cout << "\t\t经验：" << current->level << endl;
        cout << "\t\t打卡\t" << current->level / 12 << "\t天" << endl;
        cout << "\t\t分数：" << current->score << endl;
    }

    cout << "***********************" << endl;
    if (current->Id != 0 && current->lastSignTime == current->dateOfToday) {
        cout << "*****     已打卡   *****" << endl;
    } else cout << "*****  1、每日打卡  *****" << endl;
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

    struct tm *si;
    time_t t = time(nullptr);
    si = localtime(&t);
    current->dateOfToday = si->tm_mday;
    int status = 0; //0 means normal
    unsigned long control = 0;
    while (true) {
        cin >> control;
        switch (control) {
            case 1:
                Signup(current);
                User::update(current);
                break;
            case 2:
                User::Login(current);
                break;
            case 3:
                User::Registers();
                break;
            case 4:
                do { status = wordRecite(current); }
                while (status == 1);
                User::update(current);
                break;
            case 5:
                libManage(current);
                break;
            case 6:
                User::update(current);  //实现退出登录前保存个人信息
                memset(current, 0, sizeof(currentDTO));
                break;
            case 7:
                User::update(current); //实现退出程序前保存个人信息
                return 0;
            default :
                cout << "error input" << endl;
        }
        Menu(current);
    }
}