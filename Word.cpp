#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <time.h>
using namespace std;
/*词库选择*/
string libChoose(){
    int select;
    string Path;
    cout << "***** 1、个人词库 *****" << endl;
    cout << "***** 2、背诵错词 *****" << endl;
    cout << "***** 3、系统词库 *****" << endl;
    cout << "*****  选择词库: *****" << endl;
    cin >> select;
    switch (select)
    {
    case 1:
        Path = "/Users/qiy/CET/personalWordLib.txt";
        break;
    case 2:
        Path = "/Users/qiy/CET/wrongWrongWord.txt";
        break;
    case 3:
        Path = "/Users/qiy/CET/defaultWordLib.txt";
        break;
    default:
        cout << "未正确选择题库，载入系统默认词库" << endl;
        Path = "/Users/qiy/CET/defaultWordLib.txt";
        break;
    }
    return Path;
}

/*返回词库单词数*/
int wordCount(string filePath){
    string Path = filePath;
    ifstream file;
    file.open(Path,ios::in);
    int i = 1;
    do
    {
        std::string strLine;
        getline(file,strLine,';');
        i++;
    } while (!file.eof());
    return i/3;
}

/*加载单词功能实现*/
string loadWord(int countNumber, int type, string filePath){
    int count = wordCount(filePath);//wordNumber(); 
    string wordarry[count][3];
    ifstream file;
    file.open(filePath,ios::in);
    for (int i = 0; i < count; i++)
    {
    std::string strLine;
    getline(file,strLine,';');
    wordarry[i][0] = strLine;//get EN
    getline(file,strLine,';');
    wordarry[i][1] = strLine;//get Attr
    getline(file,strLine,';');
    wordarry[i][2] = strLine;//get CN
    }
    return wordarry[countNumber][type];
}

/*显示单词全部信息*/
void showAll(int select, string filePath){
    string a, b, c;
    a = loadWord(select,0,filePath);
    b = loadWord(select,1,filePath);
    c = loadWord(select,2,filePath);
    cout <<"----------------"<<endl;
    cout << a << endl << b << endl << c << endl;
    cout <<"----------------"<<endl;
}

/*读取词库单词，并显示10个*/
void showWordList(string filePath, int count, int start){
    
    for (int start; start < count+1; start++)
    {
        cout << start << "、" << loadWord(start, 0,filePath) << endl;
    }
    cout << "11、next page" << endl;
}
