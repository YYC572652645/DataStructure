#include <iostream>
using namespace std;
/*****************************************
 * 作者：YYC
 * 日期：2018-06-05
 * 功能：在一个数据中如果i<j， 并且A[i]>A[j],则
 * 称为i和j为一对逆序对，请设计算法计算数组A[n]中
 * 的逆序对数
 * ***************************************/

void sortCount(int A[], int n)
{
    int count = 0;
    for(int i = 0; i < n; i ++)
    {
        for(int j = i + 1; j < n; j ++)
        {
            if(A[i] > A[j]) count ++;
        }
    }

    cout <<count;
}

int main()
{
    int a[] = {1,3,5,2,9} ;

     sortCount(a, 5);

    return 0;
}
