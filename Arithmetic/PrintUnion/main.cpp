#include <iostream>
using namespace std;
/*****************************************
 * 作者：YYC
 * 日期：2018-06-03
 * 功能：打印出非递减数组a与b的升序并集
 * ***************************************/

const static int MAX_ARRAY_INDEX = 255;

typedef struct MyArray
{
    int array[MAX_ARRAY_INDEX];
    int length;
}MyArray;

void printUnion(MyArray &a, MyArray &b)
{
    if(a.length > MAX_ARRAY_INDEX || b.length > MAX_ARRAY_INDEX) return;

    int lastData = 0;   //记录上一次的比较数据
    int aCount = 0;     //指向a数组计时器
    int bCount = 0;     //指向b数组计时器

    while(aCount < a.length && bCount < b.length)
    {
        int tempData = 0;

        if(a.array[aCount] < b.array[bCount])
        {
            tempData = a.array[aCount];
            aCount ++;
        }
        else if(a.array[aCount] == b.array[bCount])
        {
            tempData = a.array[aCount];
            aCount ++;
            bCount ++;
        }
        else
        {
            tempData = b.array[bCount];
            bCount ++;
        }

        if(tempData != lastData) cout << tempData <<ends;

        lastData = tempData;
    }

    for(int i = aCount; i < a.length; i ++) cout << a.array[i];
    for(int i = bCount; i < b.length; i ++) cout << b.array[i];
}

int main()
{

    MyArray arrayA = {{1,3,5,8,10}, 5};
    MyArray arrayB = {{1,4,5,8,15}, 5};

    printUnion(arrayA, arrayB);
    return 0;
}
