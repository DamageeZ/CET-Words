#include <iostream>
#include <string>
#include "cstring"
#include <cstdlib>
#include "Word.h"
#include "Recitation.h"
#include <random>

using namespace std;

/*单词背诵拼写模式*/
void wordSpellingModel(const string &filePath, currentDTO *current) {
//    string userAnswer;
    int score = 0, total, done[10];
    NodeWd *head = loadLib(filePath, &total);
    Wd tp;
    default_random_engine e;
    uniform_int_distribution<int> d(1, total);
    for (int i = 0; i < 12; i++) {
        bool ok = false;
        while (!ok) {
            done[i] = d(e);
            ok = true;
            for (int j = 0; j < i; j++)
                if (done[i] == done[j]) {
                    ok = false;
                    break;
                }
        }

    }
    char getAns[20], StandAns[20];
    for (int i = 0; i < 10; i++) {
        tp = seekWd(head, done[i + 2]); //第一个总是1没意思
        strcpy(StandAns, tp.EN.c_str());
        cout << "\t" << tp.CN << "\t" << strlen(StandAns) << "个字母\t" << done[i + 2] << endl;//show chinese
        for (int k = 0; k < 3; k++) {
            cout << "请输入你的答案" << endl;
            cin >> getAns;
            if (strcmp(StandAns, getAns) == 0) {
                cout << "回答正确，下一个!" << endl;
                score += 10;
                break;
            } else {
                cout << "回答错误！" << endl;
                if (strlen(StandAns) == strlen(getAns)) {
                    for (int j = 0; j < strlen((StandAns)); j++) {
                        if (StandAns[j] == getAns[j]) {
                            cout << getAns[j];
                        } else {
                            cout << "_";
                        }
                    }
                    cout << endl;
                } else {
                    cout << "长度不正确" << endl;
                }
            }
            if (k == 2)score -= 10;
        }
        cout << "正确答案：" << tp.EN << endl;
        addWord(seekWd(head, done[i + 2]), libChoose(current, 2));

    }
    current->score += score;
    delNodeList(head);
}


/*选择题背诵模式*/
void choiceQuestionModel(const string &filePath, currentDTO *current) {
    int total, score = 0, defTotal;
    char userChoice;
    string defPath = "./src/lib/defaultWordLib.dat";
    NodeWd *head = loadLib(filePath, &total);
    NodeWd *defHead = loadLib(defPath, &defTotal);
    cout << "本词库共计" << total << "词" << endl;
    int done[12], ans[12];
    default_random_engine e;
    uniform_int_distribution<int> a(0, 3);
    uniform_int_distribution<int> d(1, total);
    uniform_int_distribution<int> def(1, defTotal);
    for (int i = 0; i < 12; i++) {
        done[i] = d(e);
        ans[i] = a(e);
    }
    for (int i = 0; i < 10; i++) {
        cout << seekWd(head, done[i + 2]).EN << endl;
        char sc = 'A';
        for (int j = 0; j < 4; j++, sc++) {
            if (ans[i + 2] == j)
                cout << sc << "\t" << seekWd(head, done[i + 2]).CN << "\t" << seekWd(head, done[i + 2]).Attr << endl;
            else {
                int Err = 0;
                do {
                    Err = def(e);
                } while (Err == done[i]);
                cout << sc << "\t" << seekWd(defHead, Err).CN << "\t" << seekWd(defHead, Err).Attr << endl;
            }
        }

        cin >> userChoice;
        if ((userChoice - 65) == ans[i + 2] || (userChoice - 97) == ans[i + 2]) {
            cout << "回答正确，下一个!" << endl;
            score += 10;
        } else {
            addWord(seekWd(head, done[i + 2]), libChoose(current, 2));
            cout << "回答错误！" << endl;
            score -= 10;
        }
    }
    cout << "本次背诵，您的分数为 " << score << " 分" << endl;
    current->score += score;
    delNodeList(head);
}

void R_choiceQuestionModel(currentDTO *current) {
    int total, score = 0, defTotal;
    char userChoice;
    string defPath = "./src/lib/defaultWordLib.dat";
    NodeWd *head = loadLib(libChoose(current, 2), &total);
    NodeWd *defHead = loadLib(defPath, &defTotal);
    cout << "本词库共计" << total << "词" << endl;
    int done[12], ans[12];
    default_random_engine e;
    uniform_int_distribution<int> a(0, 3);
    uniform_int_distribution<int> d(1, total);
    uniform_int_distribution<int> def(1, defTotal);
    for (int i = 0; i < 12; i++) {
        done[i] = d(e);
        ans[i] = a(e);
    }
    for (int i = 0; i < 10; i++) {
        cout << seekWd(head, done[i + 2]).EN << endl;
        char sc = 'A';
        for (int j = 0; j < 4; j++, sc++) {
            if (ans[i + 2] == j)
                cout << sc << "\t" << seekWd(head, done[i + 2]).CN << "\t" << seekWd(head, done[i + 2]).Attr << endl;
            else {
                int Err = 0;
                do {
                    Err = def(e);
                } while (Err == done[i]);
                cout << sc << "\t" << seekWd(defHead, Err).CN << "\t" << seekWd(defHead, Err).Attr << endl;
            }
        }
        cin >> userChoice;
        if ((userChoice - 65) == ans[i + 2] || (userChoice - 97) == ans[i + 2]) {
            cout << "回答正确，下一个!" << endl;
            delWord(seekWd(head, done[i + 2]), libChoose(current, 2));
            score += 10;
        } else {
            addWord(seekWd(head, done[i + 2]), libChoose(current, 2));
            cout << "回答错误！" << endl;
            score -= 10;
        }
    }
    cout << "本次背诵，您的分数为 " << score << " 分" << endl;
    current->score += score;
    delNodeList(head);
}

/*生词学习*/
void learnWord(const string &filePath) {
    int select, total, nowPage = 1;
    NodeWd *head = loadLib(filePath, &total);
    if (head == nullptr) {
        cout << "词本里没有单词，即将返回主菜单" << endl;
        return;
    }
    NodeWd *tp = head, *pg = head;
    int page = total / 10;
    if (total % 10 != 0) page++;
    while (true) {
        tp = pg;
        for (int i = 1; i <= 10 && tp != nullptr; i++) {
            cout << "----------------" << endl;
            cout << i + 10 * (nowPage - 1) << "、" << tp->info.EN << endl;
            cout << "\t" << tp->info.Attr;
            cout << " " << tp->info.CN << endl;
//            cout << "----------------" << endl;
            tp = tp->next;
        }
        cout << "第\t" << nowPage << "\t页";
        //选择部分
        cout << "选择你要查看的单词,输入0返回主菜单,输入11下一页" << endl;
        cin >> select;
        if (select <= 0) break;
        if (select == 11) {
            if (nowPage < page) {
                pg = tp;
                nowPage++;
            } else {
                cout << "没有更多了,输入0返回主菜单吧" << endl;
            }
            continue;
        } else {
            showAll(head, nowPage * select);
//            system("cls");
        }
    }
    delNodeList(head);
}

/*背诵主界面*/
int wordRecite(currentDTO *current) {
    int selectModel = 0;
    if (current->Id == 0) {
        cout << "请先登录" << endl;
        return 0;
    }
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
            filePath = libChoose(current);
            if (filePath == "returnHome") break;
            else learnWord(filePath);
            break;
        case 1:
            filePath = libChoose(current);
            if (filePath == "./src/lib/R_" + to_string(current->Id) + ".dat") R_choiceQuestionModel(current);
            else if (filePath == "returnHome") break;
            else choiceQuestionModel(filePath, current);
            break;
        case 2:
            filePath = libChoose(current);
            if (filePath == "returnHome") break;
            else wordSpellingModel(filePath, current);
            break;
        case 3:
            break;
        default:
            return 1;
    }
    return 0;
}