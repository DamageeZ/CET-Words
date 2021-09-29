#ifndef CET_WORD_H
#define CET_WORD_H

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <utility>
#include "currentDTO.h"

struct Wd       //定义单词类
{
    std::string EN;
    std::string Attr;
    std::string CN;

    Wd() {};

    Wd(std::string &E, std::string &A, std::string &C)
    {
        EN = E;
        Attr = A;
        CN = C;
    }
};

struct NodeWd       //定义用于单词链表的结构体
{
    Wd info;
    NodeWd *next;

    NodeWd(Wd word, NodeWd *n = nullptr)        //不允许使用隐式转换
    {
        info = std::move(word);
        next = n;
    }
};


/* 函数声明 */
std::string libChoose(currentDTO *current, int status = 0);

//int wordCount(std::string filePath);

NodeWd *loadLib(const std::string &filePath, int *total);

void showAll(NodeWd *ptr, int index);

//void showWordList(std::string filePath, int count, int start);

void delNodeList(NodeWd *head);

Wd seekWd(NodeWd *head, unsigned int index);

//void createFile(const std::string &filePath);

void addWord(const Wd &word, const std::string &filePath);

void addWord(const std::string &filePath);

void delWord(const std::string &filePath);

void delWord(const Wd &word, const std::string &filePath);

void saveLib(NodeWd *head, const std::string &filePath);

void libManage(currentDTO *current);

void modifyWord(const std::string &filePath);

#endif