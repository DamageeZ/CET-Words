#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
#include "User.h"
#include "Word.h"

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

int main()
{
    unsigned int ID;
    int num;
    ID = 20011025;
    
    loadWord(ID,0);

    return 0;
}