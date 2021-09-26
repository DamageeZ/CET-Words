#include<string>
#include "Word.h"
#include<string>
class Woedlist : public Word
{
    public:
        int listNumber;// the number of list
        bool showParaphrase; //switch show or not
        string get();
};