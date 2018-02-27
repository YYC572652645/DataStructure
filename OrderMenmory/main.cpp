/****************************
 * 作者：YYC
 * 日期：2018-01-28
 * 功能：线性结构之顺序存储结构
 * **************************/

#include <stdio.h>
#include <malloc.h>
#include <memory.h>

#define PRINT(str) printf("%s\n", str);

typedef struct OrderData
{
    int *pHead;         //存储数组的首地址
    int length;         //数组长度
    int validLength;    //有效长度
}OrderData;

void initArray(OrderData *orderData, int length);                 //初始化数据
bool appendArray(OrderData *orderData, int value);                //追加数据
bool insertArray(OrderData *orderData, int index, int value);     //插入数据
bool isEmpty(OrderData *orderData);                               //判断是否为空
bool isFull(OrderData *orderData);                                //是否满
void sortArray(OrderData *orderData);                             //排序
void inversionArray(OrderData *orderData);                        //倒置
void showArray(OrderData *orderData);                             //显示数组
bool removeArrayAt(OrderData *orderData, int index);              //移除数据
void clearArray(OrderData *orderData);                            //清空数据

/******************  主函数   *****************/
int main()
{
    OrderData orederData;

    initArray(&orederData, 10);

    appendArray(&orederData, 1);
    appendArray(&orederData, 2);
    appendArray(&orederData, 3);
    appendArray(&orederData, 4);
    appendArray(&orederData, 5);
    appendArray(&orederData, 6);
    appendArray(&orederData, 7);
    appendArray(&orederData, 8);
    appendArray(&orederData, 9);
    appendArray(&orederData, 10);
    appendArray(&orederData, 11);
    appendArray(&orederData, 12);
    appendArray(&orederData, 13);
    insertArray(&orederData, 1, 1000);
    insertArray(&orederData, 1, 2000);
    removeArrayAt(&orederData, 1);
    sortArray(&orederData);
    inversionArray(&orederData);
    showArray(&orederData);

    clearArray(&orederData);
    showArray(&orederData);

    return 0;
}

/******************  初始化数据   *****************/
void initArray(OrderData *orderData, int length)
{
    if(NULL == orderData)
    {
        PRINT("init error");

        return;
    }
    else
    {
        orderData->pHead = (int *)malloc(sizeof(int) * length);

        orderData->length = length;
        orderData->validLength = 0;
    }
}

/******************  判断是否为空   *****************/
bool isEmpty(OrderData *orderData)
{
    if(NULL == orderData)
    {
        PRINT("Array is NULL");
        return true;
    }
    if(orderData->validLength == 0)
    {
        PRINT("Array is Empty");

        return true;
    }

    return false;
}

/******************  显示数据   *****************/
void showArray(OrderData *orderData)
{
    if(!isEmpty(orderData))
    {
        for(int i = 0; i < orderData->validLength; i ++)
        {
            printf("%d\n", orderData->pHead[i]);
        }
    }
}

/******************  是否满   *****************/
bool isFull(OrderData *orderData)
{
    if(NULL == orderData)
    {
        PRINT("Array is NULL");
        return true;
    }

    if(orderData->validLength >= orderData->length)
    {
        return true;
    }

    return false;
}

/******************  追加数据   *****************/
bool appendArray(OrderData *orderData, int value)
{
    if(isFull(orderData)) return false;

    orderData->pHead[orderData->validLength] = value;
    orderData->validLength ++;

    return true;
}

/******************  插入数据   *****************/
bool insertArray(OrderData *orderData, int index, int value)
{
    if(index <= 0 || index > orderData->validLength) return false;

    if(index != orderData->length - 1)
    {
        for(int i = orderData->validLength - 2;  i >= index - 1; i --)
        {
            orderData->pHead[i + 1] = orderData->pHead[i];
        }
    }
    orderData->pHead[index - 1] = value;

    if(orderData->validLength < orderData->length)
    {
        orderData->validLength ++;
    }
    return true;
}

/******************  移除数据   *****************/
bool removeArrayAt(OrderData *orderData, int index)
{
    if(NULL == orderData)
    {
        PRINT("Array is NULL");
        return false;
    }

    if(index <= 0 || index > orderData->validLength) return false;

    for(int i = index;  i < orderData->validLength; i ++)
    {
        orderData->pHead[i - 1] = orderData->pHead[i];
    }

    orderData->validLength --;

    return true;
}

/******************  清空数据   *****************/
void clearArray(OrderData *orderData)
{
    if(NULL == orderData) return;

    memset(orderData, 0, sizeof(OrderData));
    orderData->validLength = 0;
}

/******************  排序   *****************/
void sortArray(OrderData *orderData)
{
    if(NULL == orderData) return;

    for(int i = 0; i < orderData->validLength; i ++)
    {
        for(int j = 0; j < orderData->validLength - i - 1; j ++)
        {
            if(orderData->pHead[j + 1] < orderData->pHead[j])
            {
                int temp = orderData->pHead[j + 1];
                orderData->pHead[j + 1] = orderData->pHead[j];
                orderData->pHead[j] = temp;
            }
        }
    }
}

/******************  倒置   *****************/
void inversionArray(OrderData *orderData)
{
    if(NULL == orderData) return;

    OrderData inversionData;

    inversionData.pHead = (int *)malloc(sizeof(int) * orderData->length);

    inversionData.validLength = orderData->validLength;

    for(int i = 0; i < orderData->validLength; i ++)
    {
        inversionData.pHead[i] = orderData->pHead[orderData->validLength - i - 1];
    }
    *orderData = inversionData;

    free(inversionData.pHead);
}
