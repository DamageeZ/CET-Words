#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <utility>
#include "currentDTO.h"

struct Wd {
    std::string EN;
    std::string Attr;
    std::string CN;

    Wd() {};

    Wd(std::string &E, std::string &A, std::string &C) {
        EN = E;
        Attr = A;
        CN = C;
    }
};

struct NodeWd {
    Wd info;
    NodeWd *next;

    NodeWd(Wd word, NodeWd *n = nullptr) { //不允许使用隐式转换
        info = std::move(word);
        next = n;
    }
};

std::string libChoose(currentDTO *current);

int wordCount(std::string filePath);

NodeWd *loadLib(const std::string &filePath, int *total);

void showAll(NodeWd *ptr, int index);

//void showWordList(std::string filePath, int count, int start);

void delNodeList(NodeWd *head);

Wd seekWd(NodeWd *head, unsigned int index);

void createFile(const std::string &filePath);

void addWrongWord(const Wd &word, currentDTO *current);