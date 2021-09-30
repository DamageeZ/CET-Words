/**
*   Created by zhouzhm1 on 2021/9/26.
*/

#ifndef CET_REC_H
#define CET_REC_H

#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

void wordSpellingModel(const string &filePath, currentDTO *current);

//unsigned int randomNum(int edge);

void choiceQuestionModel(const string &filePath, currentDTO *current);

void learnWord(const string &filePath);

int wordRecite(currentDTO *current);

void R_choiceQuestionModel(currentDTO *current);

#endif