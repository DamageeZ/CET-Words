#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include "User.h"
#include "Recitation.h"
#include "Word.h"

using namespace std;

/* 打卡操作 */
void Signup(currentDTO *current) {
    current->level += 12;
    current->lastSignTime = current->dateOfToday;
    update(current);
}

/* 菜单显示 */
void Menu(currentDTO *current) {
    if (current->Id == 0) {
        cout << "\n\t\t未登录" << endl;
    } else        //显示用户信息
    {
        cout << "\t\t" << current->UserName << endl;
        cout << "\t\t经验：" << current->level << endl;
        cout << "\t\t打卡\t" << current->level / 12 << "\t天" << endl;
        cout << "\t\t分数：" << current->score << endl;
    }
    
    cout << "***********************" << endl;
    
    if (current->Id != 0 && current->lastSignTime == current->dateOfToday) {
        cout << "*****     已打卡   *****" << endl;
    } else {
        cout << "*****  1、每日打卡  *****" << endl;
        cout << "*****  2、用户登录  *****" << endl;
        cout << "*****  3、用户注册  *****" << endl;
        cout << "*****  4、单词学习  *****" << endl;
        cout << "*****  5、词库管理  *****" << endl;
        cout << "*****  6、退出登录  *****" << endl;
        cout << "*****  7、退出软件  *****" << endl;
        cout << "***********************" << endl;
    }
}

int main() {
    currentDTO *current = (currentDTO *) malloc(sizeof(currentDTO));
    memset(current, 0, sizeof(currentDTO));     //初始化内存
    std::cout << "Welcome to BDC\n";
    Menu(current);
    
    struct tm *si;
    time_t t = time(nullptr);
    si = localtime(&t);
    current->dateOfToday = si->tm_mday + (si->tm_mon + 1) * 100;
    int status = 0;                         //0 代表正常
    unsigned long control = 0;
    
    while (true) {
        cin >> control;
        switch (control) {
            case 1:
                Signup(current);
                update(current);
                break;
            case 2:
                Login(current);
                break;
            case 3:
                Registers();
                break;
            case 4:
                do { status = wordRecite(current); }
                while (status == 1);
                update(current);
                break;
            case 5:
                libManage(current);
                break;
            case 6:
                update(current);        //实现退出登录前保存个人信息
                current->Id = 0;
                break;
            case 7:
                update(current);        //实现退出程序前保存个人信息
                return 0;
            default :
                cout << "error input" << endl;
        }
        Menu(current);
    }
}