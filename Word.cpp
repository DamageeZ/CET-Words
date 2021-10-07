/**
*   Created by zhouzhm1 on 2021/9/27.
*/

#include "Word.h"
#include <iostream>
#include <string>
#include "cstring"
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
        cout << "***** 9、返回主页   *****" << endl;
        cin >> select;
    } else
        select = status;
    
    switch (select) {
        case 1:
            Path = "../src/lib/L_" + to_string(current->Id) + ".dat";
            break;
        case 2:
            Path = "../src/lib/R_" + to_string(current->Id) + ".dat";     //R 代表重新学习的词库
            break;
        case 3:
            Path = "../src/lib/defaultWordLib.dat";
            break;
        case 9:
            Path = "returnHome";
            break;
        default:
            cout << "未正确选择题库，载入系统默认词库" << endl;
            Path = "../src/lib/defaultWordLib.dat";
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

/* 加载单词功能实现 导入一整个单词本 */
NodeWd *loadLib(const string &filePath, int *total) {
    NodeWd *hd = nullptr;
    ifstream file;
    file.open(filePath, ios::in);       //以读方式打开文件
    
    if (!file.is_open()) {
//        ofstream ofile(filePath, ios::ate);
//        ofile.close();
//        createFile(filePath);
//        cerr << "file don't exist" << endl;
        file.open(filePath, ios::in);       //尝试重新打开文件
    }
    
    *total = 0;
    std::string strLine;
    
    for (Wd temp; getline(file, strLine, ';');)     //以 “；" 作为分隔符
    {
        temp.EN = strLine;                                  //获取英语
        getline(file, temp.Attr, ';');        //获取词性
        getline(file, temp.CN, ';');          //获取中文
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
        cout << "\t\t" << tp->info.EN << endl;      //显示英语
        cout << "\t" << tp->info.Attr;              //显示词性
        cout << " " << tp->info.CN << endl;         //显示中文
        cout << "----------------" << endl;
    }
}

/* 删除单词节点 */
void delNodeList(NodeWd *hd) {
    NodeWd *t;
    while (hd != nullptr) {
        t = hd;
        hd = hd->next;
        delete t;
    }
}

/* 查找单词 */
Wd seekWd(NodeWd *head, unsigned int index) {
    for (int i = 0; i < index - 1 && head != nullptr; i++)      //节点偏移
    {
        head = head->next;
    }
    return head->info;
}

//void createFile(const string &filePath)
//{
//    ofstream outfile(filePath, ios::out | ios::ate);
//    outfile.close();
//}

/*读取词库单词，并显示10个*/
//void showWordList(string filePath, int count, int start)
//{
//
//    for (int start; start < count + 1; start++) {
//        cout << start << "、" << loadWord(start, 0, filePath) << endl;
//    }
//    cout << "11、next page" << endl;
//}


/* 将回答错误的单词加入wrongWord.dat
 * 添加单词功能 */
void addWord(const Wd &word, const string &filePath) {
    NodeWd *head = nullptr;
    int total;
    head = loadLib(filePath, &total);
    NodeWd *tp = head;
    
    while (head != nullptr) {
        if (word.EN == head->info.EN && word.Attr == head->info.Attr)       //单词已经添加
        {
            return;
        }
        head = head->next;      //遍历文件
    }
    tp = new NodeWd(word, tp);      //为新的单词节点分配内存
    saveLib(tp, filePath);
}

/* 保存词库 */
void saveLib(NodeWd *head, const string &filePath) {
    ofstream outfile;
    outfile.open(filePath, ios::out);       //用于写入文件
    NodeWd *tp;
    
    while (head != nullptr) {
        string Word = head->info.EN + ";" + head->info.Attr + ";" + head->info.CN + ";";        //将词条整理为存储标准格式
        outfile << Word;
        tp = head;
        head = head->next;
        delete tp;
    }
    outfile.close();
}

/* 添加单词 */
void addWord(const string &filePath) {
    if (!(strcmp(filePath.c_str(), "returnHome"))) {
        return;
    } else {
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
}

/* 词库管理 */
void libManage(currentDTO *current) {
    if (current->Id == 0) {
        cout << "请先登录" << endl;
        return;
    }
    
    int a;
    while (true) {
        cout << "***选择你想要进行的管理方式***" << endl;
        cout << "******************************" << endl;
        cout << "*****\t\t1、增加单词      *****" << endl;
        cout << "*****\t\t2、删除单词      *****" << endl;
        cout << "*****\t\t3、查询单词      *****" << endl;
        cout << "*****\t\t4、修改单词      *****" << endl;
        cout << "*****\t\t0、返回上级菜单   *****" << endl;
        cout << "******************************" << endl;
        cout << "输入对应的数字进行管理:" << endl;
        cin >> a;
        
        switch (a) {
            case 1:
                addWord(libChoose(current));
                break;
            case 2:
                delWord(libChoose(current));
                break;
            case 3:
                learnWord(libChoose(current));
                break;
            case 4:
                modifyWord(libChoose(current));
                break;
            case 0:
                return;
            default :
                cout << "非法输入" << endl;
                break;
        }
    }
}

/* 删除单词 */
void delWord(const string &filePath) {
    if (!(strcmp(filePath.c_str(), "returnHome"))) {
        return;
    } else {
        Wd wd;
        int total;
        cout << "请输入要删除的单词的英文：\t";
        cin >> wd.EN;
        NodeWd *head = loadLib(filePath, &total);
        NodeWd *tp = head;
        NodeWd *tp1 = nullptr;
        NodeWd *del = nullptr;
        bool isFirst = true;        //判断要删除的单词是否是头指针指向的节点
        
        while (tp != nullptr) {
            if (tp->info.EN == wd.EN) {
                del = tp;
                if (isFirst) {
                    head = tp->next;        //将要删除的节点的尾指针赋值给头指针
                    del->next = nullptr;
                    delete tp;
                    break;
                } else {
                    tp1->next = tp->next;       //将尾指针赋值给第三变量
                    del->next = nullptr;
                    delete del;
                    break;
                }
            }
            isFirst = false;
            tp1 = tp;
            tp = tp->next;      //下移，实现遍历
        }
        saveLib(head, filePath);
        cout << "删除完成" << endl;
    }
}

/* 系统删除单词 */
void delWord(const Wd &wd, const string &filePath) {
    int total;
    NodeWd *head = loadLib(filePath, &total);
    NodeWd *tp = head;
    NodeWd *tp1 = nullptr;
    NodeWd *del = nullptr;
    bool isFirst = true;
    
    while (tp != nullptr) {
        if (tp->info.EN == wd.EN) {
            del = tp;
            if (isFirst) {
                head = tp->next;
                del->next = nullptr;
                delete tp;
                break;
            } else {
                tp1->next = tp->next;
                del->next = nullptr;
                delete del;
                break;
            }
        }
        isFirst = false;
        tp1 = tp;
        tp = tp->next;
    }
    saveLib(head, filePath);
}

/* 修改单词 */
void modifyWord(const string &filePath) {
    if (!(strcmp(filePath.c_str(), "returnHome"))) {
        return;
    } else {
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
            tp = tp->next;      //遍历词库
        }
        saveLib(head, filePath);
        cout << "修改完成" << endl;
    }
}