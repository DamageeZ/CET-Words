#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

void wordSpellingModel(const string &filePath, currentDTO *current);

//unsigned int randomNum(int edge);

void choiceQuestionModel(const string &filePath, currentDTO *current);

void learnWord(const string &filePath);

int wordRecite(currentDTO *current);
