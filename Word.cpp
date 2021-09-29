//
// 2021/9/26.
//

#include "Word.h"
#include <iostream>
#include <string>
#include "Recitation.h"

using namespace std;

/*词库选择*/
string libChoose(currentDTO *current, int status) {
    int select;
    string Path;
    if (status == 0) {
        cout << "***** 1、个人词库   *****" << endl;
        cout << "***** 2、个人错词库 *****" << endl;
        cout << "***** 3、系统词库   *****" << endl;
        cout << "*****  选择词库:   *****" << endl;
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
    outfile.close();
}


void addWord(const string &filePath) {
    Wd wd;
    cout << "请输入要添加的单词的英文：";
    cin >> wd.EN;
    cout << endl << "请输入要添加的单词的词性：";
    cin >> wd.Attr;
    cout << endl << "请输入要添加的单词的意思";
    cin >> wd.CN;
    addWord(wd, filePath);
    cout << "添加成功" << endl;
}

void libManage(currentDTO *current) {
    if (current->Id == 0) {
        cout << "请先登录" << endl;
        return;
    }
    cout << "***选择你想要进行的管理方式***" << endl;
    cout << "******************************" << endl;
    cout << "*****\t\t1、增加单词      *****" << endl;
    cout << "*****\t\t2、删除单词      *****" << endl;
    cout << "*****\t\t3、查询单词      *****" << endl;
    cout << "*****\t\t4、修改单词      *****" << endl;
    cout << "*****\t\t0、返回上级菜单   *****" << endl;
    cout << "******************************" << endl;
    int a;
    bool b;
    while (true) {
        cout << "输入对应的数字进行管理:" << endl;
        cin >> a;
        switch (a) {
            case 1:

                addWord(libChoose(current, &b));
                break;
            case 2:
                delWord(libChoose(current, &b));
                break;
            case 3:
                learnWord(libChoose(current, &b));
                break;
            case 4:
                modifyWord(libChoose(current, &b));
                break;
            case 0:
                return;
            default :
                cout << "非法输入" << endl;
                break;
        }
    }

}

void delWord(const string &filePath) {
    Wd wd;
    int total;
    cout << "请输入要删除的单词的英文：\t";
    cin >> wd.EN;
    NodeWd *head = loadLib(filePath, &total);
    NodeWd *tp = head;
    NodeWd *del = nullptr;
    while (tp != nullptr && tp->next != nullptr) {
        if (tp->next->info.EN == wd.EN) {
            del = tp->next;
            tp->next = del->next;
            delete del;
        }
        tp = tp->next;
    }
    if (tp != nullptr && tp->next == nullptr) {
        delete tp;
        head = nullptr;
    }
    saveLib(head, filePath);
    cout << "删除完成" << endl;
}

void modifyWord(const string &filePath) {
    Wd wd;
    int total;
    cout << "请输入要修改的单词的英文：\t";
    cin >> wd.EN;
    NodeWd *head = loadLib(filePath, &total);
    NodeWd *tp = head;
    while (tp != nullptr) {
        if (tp->info.EN == wd.EN) {
            cout << "请输入新的词汇信息\t" << endl << "词性:\t";
            cin >> wd.Attr;
            cout << endl << "中文:\t";
            cin >> wd.CN;
        }
        tp = tp->next;
    }
    saveLib(head, filePath);
    cout << "修改完成" << endl;
}
