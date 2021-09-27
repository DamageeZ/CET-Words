#include<string>
#include "Word.h"
#include<string>
using namespace std;

class Woedlist : public Word
{
    public:
        int listNumber;// the number of list
        bool showParaphrase; //switch show or not
};