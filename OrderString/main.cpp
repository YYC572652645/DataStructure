/****************************
 * 作者：YYC
 * 日期：2018-04-02
 * 功能：线性结构之串的顺序存储之截串
 * **************************/

#include <iostream>
#include <stdlib.h>

#define MAXSTRLEN 255

typedef unsigned char String[MAXSTRLEN];

void concatStr(String &resultString, String strFirst, String strSecond);        //连接字符串
int getStrLength(String string);                                                //获取字符串长度
void leftStr(String &resultString, String string, int length);                  //截取左长度为length字符串
void rightStr(String &resultString, String string, int length);                 //截取右长度为length
void midStr(String &resultString, String string, int startIndex, int length);   //截取中间字符串
int compareStr(String strFirst, String strSecond);                              //比较字符串，大于0为大，等于0为相等，小于0为小

/******************  主函数               *****************/
int main()
{
    String stringFirst = "12345aa";
    String stringSecond = "12345b2";

    String tempStr;

    rightStr(tempStr, stringFirst, 2);

    concatStr(tempStr, stringFirst, stringSecond);

    std::cout << compareStr(tempStr, stringSecond) << std::endl;

    midStr(tempStr, stringFirst, 1, 10);

    std::cout << tempStr;

    return 0;
}

/******************  连接字符串            *****************/
void concatStr(String &resultString, String strFirst, String strSecond)
{
    int firstLength = getStrLength(strFirst);
    int secondLength = getStrLength(strSecond);

    for(int i = 0; i < firstLength; i ++)
    {
        resultString[i] = strFirst[i];
    }

    int count = 0;
    for(int i = 0; i < secondLength; i ++)
    {
        if(i + firstLength >= MAXSTRLEN) break;
        resultString[i + firstLength] = strSecond[i];
        count ++;
    }

    resultString[count] = '\0';
}

/******************  获取字符串长度         *****************/
int getStrLength(String string)
{
    int count = 0;

    while(string[count ++] != '\0');

    return --count;
}

/******************  截取左侧字符串         *****************/
void leftStr(String &resultString, String string, int length)
{
    int strLength = getStrLength(string);

    int maxIndex = length > strLength ? strLength : length;

    for(int i = 0; i < maxIndex; i ++)
    {
        resultString[i] = string[i];
    }

    maxIndex = maxIndex >= strLength ? maxIndex - 1 : maxIndex;
    resultString[maxIndex] = '\0';
}

/******************  截取右侧字符串         *****************/
void rightStr(String &resultString, String string, int length)
{
    int strLength = getStrLength(string) + 1;

    int minIndex = length >= strLength ? 0 : strLength - length - 1;

    for(int i = minIndex; i < strLength; i ++)
    {
        int index = i - minIndex;
        resultString[index] = string[i];
    }
}

/******************  截取中间字符串         *****************/
void midStr(String &resultString, String string, int startIndex, int length)
{
    int strLength = getStrLength(string);
    if(startIndex >= length || startIndex >= strLength || startIndex < 0) return;

    int maxIndex = startIndex + length >= strLength ? strLength : startIndex + length;

    for(int i = startIndex; i < maxIndex; i ++)
    {
        resultString[i - startIndex] = string[i];
    }

    resultString[maxIndex - startIndex] =  '\0';
}

/******************  比较字符串            *****************/
int compareStr(String strFirst, String strSecond)
{
    int firstLength = getStrLength(strFirst);
    int secondLength = getStrLength(strSecond);

    for(int i = 0; i < firstLength && i < secondLength; i ++)
    {
        if(strFirst[i] != strSecond[i]) return strFirst[i] - strSecond[i];
    }

    return firstLength - secondLength;
}
