#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "Word.h"
#include "Word.cpp"

using namespace std;


/*单词背诵拼写模式*/
void wordSpellingModel(string filePath) {
    string userAnswer;
    int score = 0;
    for (int i = 0; i < 10; i++) {
        cout << "请输入你的答案" << endl;
        string show = loadWord(i, 2, filePath);//show chinese
        string temp = loadWord(i, 1, filePath);
        string rightAnswer = loadWord(i, 0, filePath);
        cout << show << endl;
        string userAnswer;
        cin >> userAnswer;
        switch (rightAnswer.compare(userAnswer)) {
            case 0:
                cout << "回答正确，下一个!" << endl;
                score += 10;
                break;

            default:
                cout << "回答错误！" << endl;
                score -= 10;
                break;
        }
    }
}

/*随机数生成*/
int randnumber(string filePath, int i) {
    return rand() % (wordCount(filePath) - i);
}

/*选择题背诵模式*/
void choiceQuestionModel(string filePath) {
    int userChoice;
    int score = 0;
    cout << "本词库共计" << wordCount(filePath) << "词" << endl;
    for (int i = 0; i < wordCount(filePath); i++) {
        cout << loadWord(i, 0, filePath) << endl;
        cout << 1 << loadWord(i, 2, filePath) << endl;
        cout << 2 << loadWord(i + 1, 2, filePath) << endl;
        cout << 3 << loadWord(i + 5, 2, filePath) << endl;
        cout << 4 << loadWord(i + 6, 2, filePath) << endl;
        cin >> userChoice;
        if (userChoice == 1) {
            cout << "回答正确，下一个!" << endl;
            score += 10;
        } else {
            cout << "回答错误！" << endl;
            score -= 10;
        }

    }

}


/*显示单词列表，并提供单个单词详细查看功能*/
//存在bug，无法翻页
void singleWordChoose(string filePath, int pages = 0) {
    int start = 0, count = 10, select;
    int temp;
    showWordList(filePath, count, 10);
    cout << "选择你要查看的单词。" << endl;
    cin >> select;
    switch (select) {
        case 1:
            showAll(0, filePath);
            singleWordChoose(filePath);
            break;
        case 2:
            showAll(1, filePath);
            singleWordChoose(filePath);
            break;
        case 3:
            showAll(2, filePath);
            singleWordChoose(filePath);
            break;
        case 4:
            showAll(3, filePath);
            singleWordChoose(filePath);
            break;
        case 5:
            showAll(4, filePath);
            singleWordChoose(filePath);
            break;
        case 6:
            showAll(5, filePath);
            singleWordChoose(filePath);
            break;
        case 7:
            showAll(6, filePath);
            singleWordChoose(filePath);
            break;
        case 8:
            showAll(7, filePath);
            singleWordChoose(filePath);
            break;
        case 9:
            showAll(8, filePath);
            singleWordChoose(filePath);
            break;
        case 10:
            showAll(9, filePath);
            singleWordChoose(filePath);
            break;
        case 11:
            singleWordChoose(filePath, start + 10);
            break;
        default:
            break;
    }
}

/*生词学习*/
void learnWord(string filePath) {
    singleWordChoose(filePath);
}

/*背诵主界面*/
void wordReciate() {
    int selectModel = 0;
    string filePath;
    cout << "***选择你想要进行的背诵模式***" << endl;
    cout << "******************************" << endl;
    cout << "*****   0、生词学习     *****" << endl;
    cout << "*****   1、选择题背诵    *****" << endl;
    cout << "*****   2、拼写单词背诵  *****" << endl;
    cout << "*****   3、回到上一页    *****" << endl;
    cout << "******************************" << endl;
    cout << "输入对应的数字:" << endl;
    cin >> selectModel;
    switch (selectModel) {
        case 0:
            filePath = libChoose();
            learnWord(filePath);
            break;
        case 1:
            filePath = libChoose();
            choiceQuestionModel(filePath);
            break;
        case 2:
            filePath = libChoose();
            wordSpellingModel(filePath);
            break;
        case 3:
            /**/
            break;
        default:
            break;
    }
}
