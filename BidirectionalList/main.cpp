/****************************
 * 作者：YYC
 * 日期：2018-02-29
 * 功能：线性结构之双向链表
 * **************************/

#include <stdio.h>
#include <memory.h>
#include <malloc.h>

#define PRINT(str) printf("\n%s\n", str);


typedef struct BidiList
{
    int data;          //数据域
    BidiList *pLast;   //指针域
    BidiList *pNext;   //指针域
}BidiListData, *PBidiListData;

PBidiListData createList();                                                    //创建双向链表
void showBidiList(PBidiListData pHead);                                        //遍历链表
void removeBidiListAt(PBidiListData pHead, int index);                         //移除链表元素
void appendBidiList(PBidiListData pHead, PBidiListData appendData);            //追加链表元素
void insertBidiList(PBidiListData pHead, int index, PBidiListData insertData); //插入链表元素
int getBidiListLength(PBidiListData pHead);                                    //获取链表长度

/*********************    主函数         ********************/
int main()
{
    PBidiListData pHead = createList();

    removeBidiListAt(pHead, 3);

    PBidiListData pNew = (PBidiListData)malloc(sizeof(BidiListData));
    pNew->data = 100;

    appendBidiList(pHead, pNew);

    PBidiListData pInsert = (PBidiListData)malloc(sizeof(BidiListData));
    pInsert->data = 200;

    insertBidiList(pHead, 2, pInsert);

    showBidiList(pHead);

    return 0;
}

/*********************    创建双向链表    ********************/
PBidiListData createList()
{
    PBidiListData pHead = (PBidiListData)malloc(sizeof(BidiListData));

    PRINT("please input node number");

    int length = 0;
    int value = 0;
    scanf("%d", &length);

    PBidiListData pCurrent = pHead;
    pCurrent->pNext = NULL;
    pCurrent->pLast = NULL;

    for(int i = 0; i < length; i ++)
    {
        printf("please input %d data\n", i);

        scanf("%d", &value);

        PBidiListData pNew = (PBidiListData)malloc(sizeof(BidiListData));
        pNew->pNext = NULL;

        pNew->data = value;

        pCurrent->pNext = pNew;
        pNew->pLast = pCurrent;

        pCurrent = pNew;
    }

    return pHead;
}

/*********************    遍历链表       ********************/
void showBidiList(PBidiListData pHead)
{
    if(NULL == pHead) return;

    PRINT("print result:");
    PBidiListData pData = pHead->pNext;
    while(NULL != pData)
    {
        printf("%d  ", pData->data);
        pData = pData->pNext;
    }
}

/*********************    移除链表元素    ********************/
void removeBidiListAt(PBidiListData pHead, int index)
{
    if(NULL == pHead) return;
    if(index <= 0 || index > getBidiListLength(pHead)) return;

    PBidiListData pCurrent = pHead;
    for(int i = 0; i < index; i ++)
    {
        pCurrent = pCurrent->pNext;
    }

    PBidiListData pLast = pCurrent->pLast;
    PBidiListData pNext = pCurrent->pNext;

    if(NULL != pNext) pNext->pLast = pLast;

    pLast->pNext = pCurrent->pNext;

    free(pCurrent);
}

/*********************    获取链表长度    ********************/
int getBidiListLength(PBidiListData pHead)
{
    int countData = 0;
    while(pHead->pNext != NULL)
    {
        pHead = pHead->pNext;
        countData ++;
    }

    return countData;
}

/*********************    追加链表元素    ********************/
void appendBidiList(PBidiListData pHead, PBidiListData appendData)
{
    if(NULL == pHead) return;

    PBidiListData pCurrent = pHead;
    while(NULL != pCurrent->pNext) pCurrent = pCurrent->pNext;

    pCurrent->pNext = appendData;
    appendData->pLast = pCurrent;

    appendData->pNext = NULL;
}

/*********************    插入链表元素    ********************/
void insertBidiList(PBidiListData pHead, int index, PBidiListData insertData)
{
    if(NULL == pHead) return;
    if(index <= 0 || index > getBidiListLength(pHead)) return;

    PBidiListData pCurrent = pHead;
    for(int i = 0; i < index; i ++)
    {
        pCurrent = pCurrent->pNext;
    }

    PBidiListData pLast = pCurrent->pLast;

    insertData->pNext = pCurrent;
    insertData->pLast = pLast;

    pLast->pNext = insertData;
    pCurrent->pLast = insertData;
}
