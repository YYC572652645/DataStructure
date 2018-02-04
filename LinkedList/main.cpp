/****************************
 * 作者：YYC
 * 日期：2018-02-04
 * 功能：线性表的链式存储结构
 * **************************/

#include <stdio.h>
#include <memory.h>
#include <malloc.h>

#define PRINT(str) printf("%s\n", str);

typedef struct LinkListData
{
    int data;             //数据域
    LinkListData *pNext;  //指针域
}LinkListData, *PLinkListData;

PLinkListData createList();                              //创建单链表
void showLinkList(PLinkListData pHead);                  //遍历链表
void removeLinkListAt(PLinkListData pHead, int index);   //移除链表元素

/*****************    主函数       **************/
int main()
{
    PLinkListData pHead = NULL;

    pHead = createList();

    showLinkList(pHead);

    removeLinkListAt(pHead, 0);

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
    if(NULL == pHead)
    {
        PRINT("show link list error");
        return;
    }

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
    printf("%d   ", pHead->pNext->data);
    if(NULL == pHead)
    {
        PRINT("link list error");
        return;
    }

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
