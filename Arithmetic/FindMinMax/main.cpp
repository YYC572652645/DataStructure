#include <iostream>
using namespace std;
/*****************************************
 * 作者：YYC
 * 日期：2018-06-05
 * 功能：编写一个函数，同时得到一个长度为n的整型
 * 数组数组a的最大值和最小值，并通过交换元素将最
 * 小值放到a[0]，将最大值放入a[n-1]
 * ***************************************/

void findMinMax(int a[], int n)
{
    int maxCount = 0;
    int minCount = 0;

    for(int i = 1; i < n; i ++)
    {
        if(a[maxCount] < a[i]) maxCount = i;
        if(a[minCount] > a[i]) minCount = i;
    }

    int temp = a[maxCount];
    a[maxCount] = a[n - 1];
    a[n - 1] = temp;

    temp = a[minCount];
    a[minCount] = a[0];
    a[0] = temp;

    cout << a[0] << ends;
    cout << a[n - 1];

}

int main()
{
    int a[] = {1,3,8,20,5,0,5,7,9,10, 12} ;

    findMinMax(a, 11);

    return 0;
}
