#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
#include "User.h"

void Menu()
{
    cout << "***********************" << endl;
    cout << "*****  1???????  *****" << endl;
    cout << "*****  2????????  *****" << endl;
    cout << "*****  3?????е???  *****" << endl;
    cout << "*****  4????????  *****" << endl;
    cout << "*****  5????????  *****" << endl;
    cout << "*****  6?????  *****" << endl;
    cout << "***********************" << endl;
}

int main() {
    std::cout << "Welcome to BDC\n";
    Menu();
    const char *test = "abcd";
    User *u = new User();
    u->setUserName(test);
    cout << u->getUserName();
    return 0;
}