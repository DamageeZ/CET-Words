#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
#include "UserService.h"

void Menu()
{
    cout << "***********************" << endl;
    cout << "*****  1�����մ�  *****" << endl;
    cout << "*****  2���û�ע��  *****" << endl;
    cout << "*****  3�����е���  *****" << endl;
    cout << "*****  4���ʿ����  *****" << endl;
    cout << "*****  5������ʿ�  *****" << endl;
    cout << "*****  6���˳�  *****" << endl;
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