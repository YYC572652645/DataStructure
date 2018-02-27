/****************************
 * 作者：YYC
 * 日期：2018-02-04
 * 功能：线性结构之单链表
 * **************************/

#include <stdio.h>
#include <memory.h>
#include <malloc.h>

#define PRINT(str) printf("\n%s\n", str);

typedef struct LinkListData
{
    int data;             //数据域
    LinkListData *pNext;  //指针域
}LinkListData, *PLinkListData;

PLinkListData createList();                                                    //创建单链表
void showLinkList(PLinkListData pHead);                                        //遍历链表
void removeLinkListAt(PLinkListData pHead, int index);                         //移除链表元素
void appendLinkList(PLinkListData pHead, PLinkListData appendData);            //追加链表元素
PLinkListData reverseLinkList(PLinkListData pHead);                            //反转链表元素
void insertLinkList(PLinkListData pHead, int index, PLinkListData insertData); //插入链表元素

/*****************    主函数       **************/
int main()
{
    PLinkListData pHead = NULL;

    pHead = createList();

    showLinkList(pHead);

    removeLinkListAt(pHead, 0);

    showLinkList(pHead);

    pHead = reverseLinkList(pHead);

    showLinkList(pHead);

    PLinkListData pNew = (PLinkListData)malloc(sizeof(LinkListData));

    pNew->data = 1000;

    insertLinkList(pHead, 0, pNew);

    showLinkList(pHead);

    return 0;
}

/*****************    创建单链表    **************/
PLinkListData createList()
{
    PLinkListData pHead = (PLinkListData)malloc(sizeof(LinkListData));

    PRINT("please input node number");

    int length = 0;
    int value = 0;
    scanf("%d", &length);

    PLinkListData pCuurrent = pHead;
    pCuurrent->pNext = NULL;

    for(int i = 0; i < length; i ++)
    {
        printf("please input %d data\n", i);

        scanf("%d", &value);

        PLinkListData pNew = (PLinkListData)malloc(sizeof(LinkListData));

        pNew->data = value;
        pNew->pNext = NULL;
        pCuurrent->pNext = pNew;
        pCuurrent = pNew;
    }

    return pHead;
}

/*****************    遍历链表    **************/
void showLinkList(PLinkListData pHead)
{
    if(NULL == pHead) return;

    PRINT("print result:");
    PLinkListData pData = pHead->pNext;
    while(NULL != pData)
    {
        printf("%d  ", pData->data);
        pData = pData->pNext;
    }
}

/*****************    移除链表元素    **************/
void removeLinkListAt(PLinkListData pHead, int index)
{
    if(NULL == pHead) return;

    int tempCount = 0;
    while(NULL != pHead->pNext)
    {
        PLinkListData pRemove = pHead->pNext;

        if(tempCount == index)
        {
            pHead->pNext = pRemove->pNext;
            free(pRemove);
            break;
        }

        pHead = pHead->pNext;
        tempCount ++;
    }
}

/*****************    追加链表元素    **************/
void appendLinkList(PLinkListData pHead, PLinkListData appendData)
{
    if(NULL == pHead) return;

    while(NULL != pHead->pNext) pHead = pHead->pNext;

    appendData->pNext = NULL;
    pHead->pNext = appendData;
}

/*****************    反转链表元素    **************/
PLinkListData reverseLinkList(PLinkListData pHead)
{
    /**************************************************
     * 注解：假设一条链表 头 -> 1 -> 2 -> 3
     *
     * NULL  <- 头   <-  1      2     3 (第一次循环)
     * last  current   next
     *
     * NULL <-  头   <-  1  <-  2     3 (第二次循环)
     *         last  current   next
     *
     * NULL <-  头   <-  1  <-  2  <- 3 (第三次循环)
     *                 last  current next
     *
     * 此时3是头，头变为尾节点
     * *************************************************/
    if(NULL == pHead) return NULL;

    PLinkListData reverseList = NULL;
    PLinkListData currentNode = pHead;
    PLinkListData lastNode = NULL;

    while(NULL != currentNode)
    {
        PLinkListData nextNode = currentNode->pNext;

        if(NULL == nextNode) reverseList = currentNode;

        currentNode->pNext = lastNode;

        lastNode = currentNode;

        currentNode = nextNode;
    }

    return reverseList;
}

/*****************    插入链表元素    **************/
void insertLinkList(PLinkListData pHead, int index, PLinkListData insertData)
{
    if(NULL == pHead) return;

    int countData = 0;
    while(NULL != pHead)
    {
        if(countData >= index)
        {
            insertData->pNext = pHead->pNext;
            pHead->pNext = insertData;

            break;
        }
        pHead = pHead->pNext;
    }
}
