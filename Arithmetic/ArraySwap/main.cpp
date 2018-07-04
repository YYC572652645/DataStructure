#include <iostream>
using namespace std;
/*****************************************
 * 作者：YYC
 * 日期：2018-06-02
 * 功能：一个长度为n数组，由负数，0，正数组成。
 * 编写函数，将其重新排序为前段都是负数，中间均为0
 * 后段均为正数的结构，要求时间复杂度为O(n)
 * ***************************************/

void swapValue(int &preValue, int &lastValue)
{
    int temp =  preValue;
    preValue = lastValue;
    lastValue = temp;
}

void sortArray(int array[], int length)
{
    int preCount = 0;             //前段计数器
    int lastCount = length - 1;   //后段计数器
    int count = 0;                //比较的元素个数

    for(int i = 0; count < length; )
    {
        if(array[i] > 0)
        {
            swapValue (array[i], array[lastCount]);
            lastCount --;
            count ++;
        }

        if(array[i] == 0)
        {
            i++;
            count ++;
        }

        if(array[i] < 0)
        {
            swapValue (array[i], array[preCount]);
            preCount ++;
            i ++;
            count ++;
        }
    }
}

int main()
{
    int testArray[] = {-1, 2, 0, -5, 6, 0, -1, -5, 10, 100, 0};

    sortArray(testArray, 11);

    for(int i = 0; i < 11; i ++)
    {
        cout<<testArray[i]<<endl;
    }

    return 0;
}


