#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
#include "User.h"

int main()
{
    std::cout << "Welcome to BDC\n";
    const char* test = "abcd";
    User * u = new User();
    u->setUserName(test);
    cout << u->getUserName();
    return 0;
}