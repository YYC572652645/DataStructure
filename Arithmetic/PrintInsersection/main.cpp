#include <iostream>
using namespace std;
/*****************************************
 * 作者：YYC
 * 日期：2018-06-04
 * 功能：编写一个函数，打印两个长度为n的按升序排列
 * 数组的交集
 * ***************************************/

void printInterSection(int a[], int b[], int n)
{
    int aCount = 0;
    int bCount = 0;
    while(aCount < n && bCount < n)
    {
        if(a[aCount] < b[bCount])
        {
            aCount ++;
        }
        else if(a[aCount] > b[bCount])
        {
            bCount ++;
        }
        else
        {
            cout << a[aCount] << ends;
            aCount ++;
            bCount ++;
        }
    }
}

int main()
{
    int a[] = {1,3,5,7,9,10, 12} ;
    int b[] = {2,3,4,6,8,9, 10};

     printInterSection(a, b, 7);

    return 0;
}
