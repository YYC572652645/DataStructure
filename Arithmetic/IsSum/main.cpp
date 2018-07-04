#include <iostream>
using namespace std;
/*****************************************
 * 作者：YYC
 * 日期：2018-06-04
 * 功能：给定一个长度为n的且已经按升序排序的整型
 * 数组a，和一个整数x，设计一个函数，判断是否存在
 * 两个元素使它们之和为x，如果存在则返回0，否则
 * 返回-1
 * ***************************************/

int isSum(int array[], int n, int x)
{
    int preCount = 0;        //前段计数器
    int lastCount = n - 1;   //后段计数器

    for(int i = 0; preCount != lastCount; i ++)
    {
        int tempSum = array[preCount] + array[lastCount];
        if(tempSum < x)
        {
            preCount ++;
        }
        else if(tempSum > x)
        {
            lastCount --;
        }
        else
        {
            return 0;
        }
    }

    return -1;
}

int main()
{
    int a[] = {1,3,5,7,9,10};

    cout << isSum(a, 6, 8);
    return 0;
}
