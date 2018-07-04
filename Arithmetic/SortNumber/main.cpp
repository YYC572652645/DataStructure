/****************************
 * 作者：YYC
 * 日期：2018-07-04
 * 功能：排序大综合
 * **************************/

#include <iostream>

#define PRIENDL(arg)      std::cout << arg <<std::endl;
#define PRIENDS(arg)      std::cout << arg <<std::ends;
#define CINARG(arg)       std::cin >> arg;
#define ARRAYCOUNT(array) (static_cast<int>(sizeof(array) / sizeof(*array)))

void bubbleSort(int *arrayData, int length);      //冒泡排序
void selectionSort(int *arrayData, int length);   //选择排序
void insertSort(int *arrayData, int length);      //插入排序
void quickSort(int *arrayData, int length);       //快速排序
void heapSort(int *arrayData, int length);        //堆排序
void mergeSort(int *arrayData, int length);       //归并排序
void radixSort(int *arrayData, int length);       //基数排序
void shellSort(int *arrayData, int length);       //希尔排序
void printArray(int *arrayData, int length);      //打印输出

/*****************   主函数        *****************/
int main()
{
    int arrayData[] = {3, 1, 20, 5, 8, 10, 4, 11, 2};

    //bubbleSort(arrayData, ARRAYCOUNT(arrayData));
    //selectionSort(arrayData, ARRAYCOUNT(arrayData));
    //insertSort(arrayData, ARRAYCOUNT(arrayData));

    shellSort(arrayData, ARRAYCOUNT(arrayData));
    printArray(arrayData, ARRAYCOUNT(arrayData));

    return 0;
}

/*****************   冒泡排序        *****************/
void bubbleSort(int *arrayData, int length)
{
    for(int i = 0; i < length; i ++)
    {
        for(int j = i + 1; j < length; j ++)
        {
            if(arrayData[i] > arrayData[j])
            {
                int temp = arrayData[i];
                arrayData[i] = arrayData[j];
                arrayData[j] = temp;
            }
        }
    }
}

/*****************   选择排序        *****************/
void selectionSort(int *arrayData, int length)
{
    for(int i = 0; i < length; i ++)
    {
        int minIndex = i;
        for(int j = i + 1; j < length; j ++)
        {
            if(arrayData[minIndex] > arrayData[j])
            {
                minIndex = j;
            }
        }

        if(minIndex != i)
        {
            int tempData = arrayData[i];
            arrayData[i] = arrayData[minIndex];
            arrayData[minIndex] = tempData;
        }
    }
}

/*****************   插入排序        *****************/
void insertSort(int *arrayData, int length)
{
    int tempData, j;
    for(int i = 1; i < length; i ++)
    {
        tempData = arrayData[i];
        j = i - 1;
        while(j >= 0 && arrayData[j] > tempData)
        {
            arrayData[j + 1] = arrayData[j];

            j --;
        }

        arrayData[j + 1] = tempData;
    }
}

/*****************   快速排序        *****************/
void quickSort(int *arrayData, int length)
{

}

/*****************   堆排序        *****************/
void heapSort(int *arrayData, int length)
{

}

/*****************   归并排序        *****************/
void mergeSort(int *arrayData, int length)
{

}

/*****************   基数排序        *****************/
void radixSort(int *arrayData, int length)
{

}

/*****************   希尔排序        *****************/
void shellSort(int *arrayData, int length)
{
    int i, j;
    int tempData = 0;
    int increment = length;

    while(increment > 1)
    {
        increment = increment / 3 + 1;

        for(i = increment; i < length; i ++)
        {
            if(arrayData[i] < arrayData[i - increment])
            {
                tempData = arrayData[i];

                for(j = i - increment; j >= 0 && tempData < arrayData[j]; j -= increment)
                {
                    arrayData[j + increment] = arrayData[j];
                }

                arrayData[j + increment] = tempData;
            }
        }
    }

}

/*****************   打印输出        *****************/
void printArray(int *arrayData, int length)
{
    PRIENDL("");
    for(int i = 0; i < length; i ++)
    {
        PRIENDS(arrayData[i]);
    }
    PRIENDL("");
}

