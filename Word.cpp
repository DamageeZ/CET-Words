//
// 2021/9/26.
//

#include "Word.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

/*词库选择*/
string libChoose(currentDTO *current, int status) {
    int select;
    string Path;
    if (status == 0) {
        cout << "***** 1、个人词库 *****" << endl;
        cout << "***** 2、背诵错词 *****" << endl;
        cout << "***** 3、系统词库 *****" << endl;
        cout << "*****  选择词库: *****" << endl;
        cin >> select;
    } else select = status;
    switch (select) {
        case 1:
            Path = "./src/lib/L_" + to_string(current->Id) + ".dat";
            break;
        case 2:
            Path = "./src/lib/R_" + to_string(current->Id) + ".dat"; //R means Re-learn
            break;
        case 3:
            Path = "./src/lib/defaultWordLib.dat";
            break;
        default:
            cout << "未正确选择题库，载入系统默认词库" << endl;
            Path = "./src/lib/defaultWordLib.dat";
            break;
    }
    return Path;
}

/*返回词库单词数*/
//int wordCount(string filePath) {
//    ifstream file;
//    file.open(filePath, ios::in);
//    int i = 1;
//    do {
//        string strLine;
//        getline(file, strLine, ';');
//        i++;
//    } while (!file.eof());
//    return i / 3;
//}

/*加载单词功能实现 导入一整个单词本*/
NodeWd *loadLib(const string &filePath, int *total) {
    NodeWd *hd = nullptr;
    ifstream file;
    file.open(filePath, ios::in);
    if (!file.is_open()) {
        ofstream ofile(filePath, ios::ate);
        ofile.close();
//        createFile(filePath);
//        cerr << "file don't exist" << endl;
        file.open(filePath, ios::in);
    }
    *total = 0;
    std::string strLine;
    for (Wd temp; getline(file, strLine, ';');) {
        temp.EN = strLine;//get EN
        getline(file, temp.Attr, ';');//get Attr
        getline(file, temp.CN, ';');//get CN
        hd = new NodeWd(temp, hd);
        (*total)++;
    }
    file.close();
    return hd;
}

/*显示单词全部信息*/
void showAll(NodeWd *tp, int index) {
    for (int i = 0; i < index - 1 && tp != nullptr; i++) {
        tp = tp->next;
    }
    if (tp != nullptr) {
        cout << "----------------" << endl;
        cout << "\t\t" << tp->info.EN << endl;
        cout << "\t" << tp->info.Attr;
        cout << " " << tp->info.CN << endl;
        cout << "----------------" << endl;
    }
}

void delNodeList(NodeWd *hd) {
    NodeWd *t;
    while (hd != nullptr) {
        t = hd;
        hd = hd->next;
        delete t;
    }
}

Wd seekWd(NodeWd *head, unsigned int index) {
    for (int i = 0; i < index - 1 && head != nullptr; i++) {
        head = head->next;
    }
    return head->info;
}

//void createFile(const string &filePath) {
//    ofstream outfile(filePath, ios::out | ios::ate);
//    outfile.close();
//}

/*读取词库单词，并显示10个*/
//void showWordList(string filePath, int count, int start) {
//
//    for (int start; start < count + 1; start++) {
//        cout << start << "、" << loadWord(start, 0, filePath) << endl;
//    }
//    cout << "11、next page" << endl;
//}

/*将回答错误的单词加入wrongWord.dat*/
void addWord(const Wd &word, const string &filePath) {
    NodeWd *head = nullptr;
    int total;
    head = loadLib(filePath, &total);
    NodeWd *tp = head;
    while (head != nullptr) {
        if (word.EN == head->info.EN && word.Attr == head->info.Attr) {
            return;
        }
        head = head->next;
    }
    tp = new NodeWd(word, tp);
    saveLib(tp, filePath);

}

void saveLib(NodeWd *head, const string &filePath) {
    ofstream outfile;
    outfile.open(filePath, ios::out);
    NodeWd *tp;
    while (head != nullptr) {
        string Word = head->info.EN + ";" + head->info.Attr + ";" + head->info.CN + ";";
        outfile << Word;
        tp = head;
        head = head->next;
        delete tp;
    }
}

void addWord(const Wd &word, NodeWd **head) {
    *head = new NodeWd(word, *head);
}
