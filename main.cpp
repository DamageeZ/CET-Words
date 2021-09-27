#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
#include "User.h"
#include "Word.h"

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
    unsigned int ID;
    int num;
    ID = 20011025;
    
    loadWord(ID,0);

    return 0;
}