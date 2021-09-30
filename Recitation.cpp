/**
*   Created by zhouzhm1 on 2021/9/26.
*/

#include <iostream>
#include <string>
#include "cstring"
#include <cstdlib>
#include "Word.h"
#include "Recitation.h"
#include <random>

using namespace std;

/* 单词背诵拼写模式 */
void wordSpellingModel(const string &filePath, currentDTO *current)
{
//    string userAnswer;
    int score = 0, total, done[10];
    NodeWd *head = loadLib(filePath, &total);       //加载词库
    Wd tp;
    default_random_engine e;        //创建随机数引擎
    uniform_int_distribution<int> d(1, total);      //限定随机数边界
    
    for (int i = 0; i < 12; i++)
    {
        bool ok = false;
        while (!ok)     //随机出题，防止每次一样
        {
            done[i] = d(e);     //随机取值
            ok = true;
            for (int j = 0; j < i; j++)
            {
                if (done[i] == done[j])
                {
                    ok = false;
                    break;
                }
            }
        }
    }
    
    char getAns[20], StandAns[20];
    
    for (int i = 0; i < 10; i++)
    {
        tp = seekWd(head, done[i + 2]);         //每次都不从第一个选取单词
        strcpy(StandAns, tp.EN.c_str());        //获取标准答案
        cout << "\t" << tp.CN << "\t" << strlen(StandAns) << "个字母\t" << done[i + 2] << endl;    //显示汉语意思
        
        for (int k = 0; k < 3; k++)     //给用户三次答题机会
        {
            cout << "请输入你的答案" << endl;
            cin >> getAns;
            if (strcmp(StandAns, getAns) == 0)
            {
                cout << "回答正确，下一个!" << endl;
                score += 10;
                break;
            }
            else
            {
                cout << "回答错误！" << endl;
                if (strlen(StandAns) == strlen(getAns))     //回答单词长度与答案单词长度相等
                {
                    for (int j = 0; j < strlen((StandAns)); j++)        //判断用户的哪一个字母有误
                    {
                        if (StandAns[j] == getAns[j])
                        {
                            cout << getAns[j];
                        }
                        else
                        {
                            cout << "_";
                        }
                    }
                    cout << endl;
                }
                else
                {
                    cout << "长度不正确" << endl;
                }
            }
            if (k == 2)     //进行第二次循环，单词错误，扣10分
                score -= 10;
        }
        cout << "正确答案：" << tp.EN << endl;
        addWord(seekWd(head, done[i + 2]), libChoose(current, 2));  //将错词添加到错题本
    }
    current->score += score;
    delNodeList(head);
}

/* 选择题背诵模式 */
void choiceQuestionModel(const string &filePath, currentDTO *current)
{
    int total, score = 0, defTotal;
    char userChoice;
    string defPath = "./src/lib/defaultWordLib.dat";        //系统词库
    NodeWd *head = loadLib(filePath, &total);       //用户词库链表
    NodeWd *defHead = loadLib(defPath, &defTotal);      //系统词库链表
    cout << "本词库共计" << total << "词" << endl;
    int done[12], ans[12];
    default_random_engine e;        //创建随机数引擎
    uniform_int_distribution<int> a(0, 3);      //随机三个错误答案
    uniform_int_distribution<int> d(1, total);      //在全部用户单词里随机选择
    uniform_int_distribution<int> def(1, defTotal);     //在系统里随机选择
    
    for (int i = 0; i < 12; i++)
    {
        done[i] = d(e);     //题目题号
        ans[i] = a(e);      //对应的答案
    }
    for (int i = 0; i < 10; i++)
    {
        cout << seekWd(head, done[i + 2]).EN << endl;       //随机输出英语单词
        char sc = 'A';
        for (int j = 0; j < 4; j++, sc++)       //生成选项
        {
            if (ans[i + 2] == j)        //在四个选项中随机生成正确答案对应的中文
            {
                cout << sc << "\t" << seekWd(head, done[i + 2]).CN << "\t" << seekWd(head, done[i + 2]).Attr << endl;
            }
            else
            {
                int Err = 0;
                do
                {
                    Err = def(e);
                } while (Err == done[i]);
                cout << sc << "\t" << seekWd(defHead, Err).CN << "\t" << seekWd(defHead, Err).Attr << endl;
            }
        }

        cin >> userChoice;
        if ((userChoice - 65) == ans[i + 2] || (userChoice - 97) == ans[i + 2])     //用户输入大小写选项均可识别
        {
            cout << "回答正确，下一个!" << endl;
            score += 10;
        }
        else
        {
            addWord(seekWd(head, done[i + 2]), libChoose(current, 2));      //将单词添加到错词库
            cout << "回答错误！" << endl;
            score -= 10;
        }
    }
    cout << "本次背诵，您的分数为 " << score << " 分" << endl;
    current->score += score;
    delNodeList(head);
}

/* 上一函数功能补充 可以删除错词库中用户答对的单词 */
void R_choiceQuestionModel(currentDTO *current)
{
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
    
    for (int i = 0; i < 12; i++)
    {
        done[i] = d(e);
        ans[i] = a(e);
    }
    for (int i = 0; i < 10; i++)
    {
        cout << seekWd(head, done[i + 2]).EN << endl;
        char sc = 'A';
        for (int j = 0; j < 4; j++, sc++)
        {
            if (ans[i + 2] == j)
                cout << sc << "\t" << seekWd(head, done[i + 2]).CN << "\t" << seekWd(head, done[i + 2]).Attr << endl;
            else
            {
                int Err = 0;
                do
                {
                    Err = def(e);
                } while (Err == done[i]);
                cout << sc << "\t" << seekWd(defHead, Err).CN << "\t" << seekWd(defHead, Err).Attr << endl;
            }
        }
        cin >> userChoice;
        if ((userChoice - 65) == ans[i + 2] || (userChoice - 97) == ans[i + 2]) {
            cout << "回答正确，下一个!" << endl;
            delWord(seekWd(head, done[i + 2]), libChoose(current, 2));      //从用户选择测库删除正确单词
            score += 10;
        }
        else
        {
            addWord(seekWd(head, done[i + 2]), libChoose(current, 2));
            cout << "回答错误！" << endl;
            score -= 10;
        }
    }
    cout << "本次背诵，您的分数为 " << score << " 分" << endl;
    current->score += score;
    delNodeList(head);
}

/* 生词学习 */
void learnWord(const string &filePath)
{
    int select, total, nowPage = 1;
    NodeWd *head = loadLib(filePath, &total);       //加载词库
    if (head == nullptr)
    {
        cout << "词本里没有单词，即将返回主菜单" << endl;
        return;
    }
    NodeWd *tp = head, *pg = head;
    int page = total / 10;
    if (total % 10 != 0) page++;        //每页显示10个单词
    
    while (true)
    {
        tp = pg;
        for (int i = 1; i <= 10 && tp != nullptr; i++)
        {
            cout << "----------------" << endl;
            cout << i + 10 * (nowPage - 1) << "、" << tp->info.EN << endl;   //标出单词的排序
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
        if (select == 11)
        {
            if (nowPage < page)
            {
                pg = tp;
                nowPage++;
            }
            else
            {
                cout << "没有更多了,输入0返回主菜单吧" << endl;
            }
            continue;
        }
        else
        {
            showAll(head, nowPage * select);
//            system("cls");
        }
    }
    delNodeList(head);
}

/* 背诵主界面 */
int wordRecite(currentDTO *current)
{
    int selectModel = 0;
    if (current->Id == 0)
    {
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
    
    switch (selectModel)
    {
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