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
void getNext(String strSource, int *next);                                      //获取KMP算法的next数组
int indexKmp(String strFirst, String strSecond, int pos);                       //KMP算法
int indexNormal(String strFirst, String strSecond, int pos);                    //常规字符串比较算法

/******************  主函数               *****************/
int main()
{
    String stringFirst = "12345aa";
    String stringSecond = "aa";


    String tempStr;

    rightStr(tempStr, stringFirst, 2);

    concatStr(tempStr, stringFirst, stringSecond);

    std::cout << compareStr(tempStr, stringSecond) << std::endl;

    midStr(tempStr, stringFirst, 1, 10);

    std::cout << indexKmp(stringFirst, stringSecond, 0);
    std::cout << indexNormal(stringFirst, stringSecond, 0);

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

/******************  获取KMP算法的next数组            *****************/
void getNext(String strSource, int *next)
{
    /********************************************
    * 思路：
    * 假如模式串为     a b c a b x
    * 其求得next数组为 0 1 1 1 2 3
    *
    * 当j=1时 next[j] = 0
    * 当j=2时 j由1~j-1只有a自己，故next[j] = 1
    * 当j=3时 j由1~j-1为ab，故next[j] = 1
    * 当j=4时 j由1~j-1为abc，故next[j] = 1
    * 当j=5时 j由1~j-1为abca，前后a=a，此时相等字符为1个
    * next[j] = 1 + 1， 故next[j] = 2
    * 当j=6时 j由1~j-1为abcab，前后ab=ab，此时相等字符为2个
    * next[j] = 2 + 1， 故next[j] = 3
    *
    * 其中next[1]为0，为特殊标记，表示应从模式串第一个字符
    * 与主串当前不匹配字符的下一个字符开始比较。
    ************************************************/

    int i = 1;
    int j = 0;

    next[i] = 0;

    while(i < getStrLength(strSource))
    {
        if(j == 0 || strSource[i] == strSource[j])  //strSource[i]表示串的前缀，strSource[j]表示串的后缀
        {
            i ++;
            j ++;

            next[i] = j;
        }
        else
        {
            j = next[j];                             //如果匹配不到，j回溯，一直匹配不到，一直回溯到j=0
        }
    }

}

/******************  KMP算法            *****************/
int indexKmp(String strFirst, String strSecond, int pos)
{
    /********************************************
     * 思路：
     * 模式串中第j个位置和第i个位置发生不匹配时，
     * 应从模式串中的第next[j]个位置开始，
     * 从主串的第i个位置开始
     *
     ********************************************/

    int i = pos + 1;

    int j = 1;

    int next[255];

    getNext(strSecond, next);

    int firstLength = getStrLength(strFirst);
    int secondLength = getStrLength(strSecond);

    while(i < firstLength && j < secondLength)
    {
        if(j == 0 || strFirst[i - 1] == strSecond[j - 1])  //因为数组的数据从0开始，所以都减1
        {
            i ++;
            j ++;
        }
        else
        {
            j = next[j];
        }
    }

    if(j >= secondLength) return i - secondLength;

    return 0;
}

/******************  常规字符串比较算法            *****************/
int indexNormal(String strFirst, String strSecond, int pos)
{
    int i = pos;
    int j = 0;
    int k = i;

    int firstLength = getStrLength(strFirst);
    int secondLength = getStrLength(strSecond);

    while(i < firstLength && j < secondLength)
    {
        if(strFirst[i] == strSecond[j])
        {
            i ++;
            j ++;
        }
        else
        {
            j = 0;
            i = ++k;
        }
    }

    if(j >= secondLength) return k;

    return 0;
}
