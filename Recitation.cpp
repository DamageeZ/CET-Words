#include <iostream>
#include <cstdlib>
#include <string>
#include "Recitation.h"
#include "Word.h"
#include "User.h"

using namespace std;

/*单词复习实现*/
void wordsReview()
{
    int wrongWordNum;
    wrongWordNum = wordNumber();//call the func that return a list word number
    if(wrongWordNum == 0){
        cout << "没有错题继续努力" << endl;
    }
    else{
        wordLearn(0);
    }
}

/*单词预览学习实现*/
void wordLearn(int learnModel)      // 传入学习单词的模式，区分是从错误单词还是默认单词中取出数据。
{
        int pages = wordNumber(learnModel) / 10 + 1;//根据learnModel，获取对应单词本含有的单词数
        showWordList(learnModel);//show 10 wrongwords,default is 0;
        for (int i = 0; i < pages; i++)
        {
            cout << i;
        }
        int inputNumber;
        cout << "输入数字以翻页" << endl;
        cin >> inputNumber;
        switch (inputNumber)//choose word list
        {
        case 2:
            showWordList(1);//show 10 wrongwords,default is 0;
            break;
        case 3:
            showWordList(2);//show 10 wrongwords,default is 0;
            break;
        case 4:
            showWordList(3);//show 10 wrongwords,default is 0;
            break;
        case 5:
            showWordList(4);//show 10 wrongwords,default is 0;
            break;
        case 6:
            cout << "dd" << endl;
            break;
        default:
            break;
        }
        singleWordChoose(inputNumber);
}

/*单词背诵实现*/
void wordReciate()
{
    int selectModel = 0;
    cout << "choose an model you want" << endl;
    cout << "***************************" << endl;
	cout << "*****  1、选择题背诵  *****" << endl;
	cout << "*****  2、拼写单词背诵 *****" << endl;
	cout << "*****  3、回到上一页 *****" << endl;
	cout << "***************************" << endl;
    cout << "input the number ):" << endl;
    cin >> selectModel;
    switch (selectModel)
    {
    case 1:
        choiceQuestionModel();
        break;
    case 2:
        wordSpellingModel();
        break;
    case 3:
        /* code */
        break;
    default:
        break;
    }
}

/*单词复习实现*/
void wordsReview()
{
    int wrongWordNum;
    wrongWordNum = wordNumber();//call the func that return a list word number
    if(wrongWordNum == 0){
        cout << "没有错题继续努力" << endl;
    }
    else{
        wordLearn(0);
    }
}

/*单个单词显示实现*/
void singleWordChoose(int listNumber)
{
    int select;
    cout << "选择你要查看的单词。";
    cin >> select;
    switch (select)
    {
    case 1:
        loadWord(3);//show all contents
        break;
    
    case 2:
        loadWord(3);//show all contents
        break;
    
    case 3:
        loadWord(3);//show all contents
        break;
    
    case 4:
        loadWord(3);//show all contents
        break;
    
    case 5:
        loadWord(3);//show all contents
        break;
    
    case 6:
        loadWord(3);//show all contents
        break;
    
    case 7:
        loadWord(3);//show all contents
        break;
    
    case 8:
        loadWord(3);//show all contents
        break;
    
    case 9:
        loadWord(3);//show all contents
        break;
    
    case 10:
        loadWord(3);//show all contents
        break;
    
    default:
        break;
    }
}

/*显示单个单词*/
void showContent(int countNumber, int type)
{
    int count = 10;//wordNumber(); 
    string wordarry[count][3];
    string filePath = "/Users/qiy/Desktop/Developments/C_Projects/learn_env/word.txt";
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
    cout << wordarry[countNumber][type];
}