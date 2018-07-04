#include <iostream>
using namespace std;
/*****************************************
 * 作者：YYC
 * 日期：2018-06-04
 * 功能：编写一个函数，将参数a的十进制表示中所有的
 * 位数相加，如果其值为个位数，则返回该值，否则对
 * 该值继续运算，例如a=123456返回3
 * ***************************************/

int sumTodigit(int a)
{
    const int VALUE_TEN = 10;
    int totalSum = 0;
    while(a != 0)
    {
        totalSum += a % VALUE_TEN;

        a /= VALUE_TEN;

        if(a == 0 && totalSum > VALUE_TEN)
        {
            a = totalSum;
            totalSum = 0;
        }
    }

    return totalSum;
}

int main()
{
    int a = 123456;

    cout << sumTodigit(a);
    return 0;
}
