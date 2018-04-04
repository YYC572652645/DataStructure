/****************************
 * 作者：YYC
 * 日期：2018-02-29
 * 功能：线性结构之串的堆分配存储
 * **************************/

#include <iostream>

typedef struct String
{
    char *stringData;  //串数据区域
    int length;        //串长度
}String;


int getStrLength(String string);                                              //获取串长度
void strAssign(String &resultStr, char *str);                                 //生成一个与str相等的串
int strCompare(String firstStr, String secondStr);                            //比较字符串，大于0为大，等于0为相等，小于0为小
void strCleare(String &resultStr);                                            //串的清空
void strConcat(String &resultStr, String firstStr, String secondStr);         //串的连接
void subString(String &resultStr, String string, int startIndex, int length); //返回子串
void printString(String string);                                              //输出字符串

/*********************    主函数                ********************/
int main()
{
    String firstStr;
    String secondStr;
    String thirdStr;

    char *str = "abceefg";
    strAssign(firstStr, str);
    strAssign(secondStr, str);

    strConcat(thirdStr, firstStr, secondStr);

    printString(firstStr);
    printString(secondStr);
    printString(thirdStr);

    strCompare(firstStr, secondStr);
    subString(thirdStr, firstStr, 0, 3);
    printString(thirdStr);

    return 0;
}

/*********************    获取串长度             ********************/
int getStrLength(String string)
{
    return string.length;
}

/*********************    生成一个与str相等的串    ********************/
void strAssign(String &resultStr, char *str)
{
    if(resultStr.stringData) delete resultStr.stringData;

    int length = 0;

    char *c = str;
    for(length = 0, c = str; *c; length ++, c++);

    if(length <= 0)
    {
        resultStr.length = 0;
        resultStr.stringData = NULL;
    }
    else
    {
        resultStr.stringData = new char[length + 1];
        for(int i = 0; i < length; i ++)
        {
            resultStr.stringData[i] = str[i];
        }

        resultStr.stringData[length] = '\0';
        resultStr.length = length;
    }
}

/*********************    串的比较               ********************/
int strCompare(String firstStr, String secondStr)
{
    for(int i = 0; i < firstStr.length && i < secondStr.length; i ++)
    {
        if(firstStr.stringData[i] != secondStr.stringData[i])
        {
            return firstStr.stringData[i] - secondStr.stringData[i];
        }
    }

    return firstStr.length - secondStr.length;
}

/*********************    串的清空               ********************/
void strCleare(String &resultStr)
{
    if(resultStr.stringData)
    {
        delete resultStr.stringData;

        resultStr.stringData = NULL;
    }

    resultStr.length = 0;
}

/*********************    串的连接               ********************/
void strConcat(String &resultStr, String firstStr, String secondStr)
{
    if(resultStr.stringData) delete resultStr.stringData;

    int maxLength = firstStr.length + secondStr.length;

    resultStr.stringData = new char[maxLength + 1];

    for(int i = 0; i < firstStr.length; i ++)
    {
        resultStr.stringData[i] = firstStr.stringData[i];
    }

    for(int i = 0; i < secondStr.length; i ++)
    {
        resultStr.stringData[i + firstStr.length] = secondStr.stringData[i];
    }

    resultStr.stringData[maxLength] = '\0';
    resultStr.length = maxLength;
}

/*********************    返回子串               ********************/
void subString(String &resultStr, String string, int startIndex, int length)
{
    if(resultStr.stringData) delete resultStr.stringData;

    if(startIndex + length >= string.length || startIndex < 0)
    {
        resultStr.stringData = NULL;
        resultStr.length = 0;
        return;
    }

    int maxIndex = startIndex + length >= string.length ? string.length - 1 : startIndex + length;

    resultStr.stringData =  new char[maxIndex - startIndex + 1];

    for(int i = startIndex; i < maxIndex; i ++)
    {
        resultStr.stringData[i - startIndex] = string.stringData[i];
    }

    resultStr.stringData[maxIndex - startIndex] = '\0';

    resultStr.length = maxIndex - startIndex;
}

/*********************    输出字符串               ********************/
void printString(String string)
{
    if(string.stringData)
    {
        std::cout << "string: " << string.stringData << " length:" <<string.length << std::endl;
    }
}
