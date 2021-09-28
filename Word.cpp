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
string libChoose(currentDTO *current) {
    int select;
    string Path;
    cout << "***** 1、个人词库 *****" << endl;
    cout << "***** 2、背诵错词 *****" << endl;
    cout << "***** 3、系统词库 *****" << endl;
    cout << "*****  选择词库: *****" << endl;
    cin >> select;
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
    while (!file.is_open()) {
//        createFile(filePath);
        cerr << "file don't exist" << endl;
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

void createFile(const string &filePath) {
    ofstream outfile(filePath, ios::out | ios::ate);
    outfile.close();
}

/*读取词库单词，并显示10个*/
//void showWordList(string filePath, int count, int start) {
//
//    for (int start; start < count + 1; start++) {
//        cout << start << "、" << loadWord(start, 0, filePath) << endl;
//    }
//    cout << "11、next page" << endl;
//}

/*将回答错误的单词加入wrongWord.dat*/
void addWrongWord(const Wd &word, currentDTO *current) {
    string wrongWord = word.EN + ";" + word.Attr + ";" + word.CN + ";";
    ofstream outfile;
    outfile.open("./src/lib/R_" + to_string(current->Id) + ".dat", ios::out | ios::app);
    outfile << wrongWord;
    outfile.close();
}
