/****************************
 * 作者：YYC
 * 日期：2018-02-28
 * 功能：线性结构之循环链表
 * **************************/

#include <iostream>

typedef struct CircularList
{
    int data;               //数据域
    CircularList *pNext;    //指针域
}CircularListData, *PCircularList;

PCircularList createList();                                                        //创建循环链表
void showCircularList(PCircularList pHead);                                        //遍历链表
void removeCircularListAt(PCircularList pHead, int index);                         //移除链表元素
void appendCircularList(PCircularList pHead, PCircularList appendData);            //追加链表元素
PCircularList reverseCircularList(PCircularList pHead);                            //反转链表元素
void insertCircularList(PCircularList pHead, int index, PCircularList insertData); //插入链表元素
int getListLength(PCircularList pHead);                                            //获取链表长度


/*****************   主函数        *****************/
int main()
{
    PCircularList pHead = createList();

    PCircularList appendData = new CircularListData();
    appendData->data = 100;

    appendCircularList(pHead, appendData);

    removeCircularListAt(pHead, 3);

    PCircularList insertData = new CircularListData();
    insertData->data = 200;

    insertCircularList(pHead, 3, insertData);

    pHead = reverseCircularList(pHead);

    showCircularList(pHead);

    return 0;
}

/*****************   创建循环链表   *****************/
PCircularList createList()
{
    PCircularList pHead = (PCircularList)malloc(sizeof(CircularListData));

    int length = 0;
    int value = 0;
    std::cout << "please input list length" << std::endl;

     std::cin >> length;

    PCircularList pCurrentNode = pHead;
    for(int i = 0; i < length; i ++)
    {
        std::cout << "please input " << i << " data";
        std::cin >> value;

        PCircularList dataNode = (PCircularList)malloc(sizeof(CircularListData));

        dataNode->data = value;

        pCurrentNode->pNext = dataNode;

        pCurrentNode = dataNode;

        if(i == length - 1)
        {
            pCurrentNode->pNext = pHead;
        }
    }

    return pHead;
}

/*****************   遍历链表       *****************/
void showCircularList(PCircularList pHead)
{
    PCircularList pCurrentNode = pHead->pNext;

    std::cout << "show list :" << std::endl;

    while(pCurrentNode != pHead)
    {
        std::cout << pCurrentNode->data << std::ends;

        pCurrentNode = pCurrentNode->pNext;
    }
}

/*****************   移除链表元素    *****************/
void removeCircularListAt(PCircularList pHead, int index)
{
    PCircularList pCurrentNode = pHead->pNext;

    if(index == 1) pCurrentNode = pHead;
    for(int i = 0; i < index - 2; i ++)
    {
        if(pCurrentNode == pHead) return;
        pCurrentNode = pCurrentNode->pNext;
    }

    PCircularList pMidNode = pCurrentNode->pNext;

    pCurrentNode->pNext = pMidNode->pNext;

    delete pMidNode;
}

/*****************   追加链表元素    *****************/
void appendCircularList(PCircularList pHead, PCircularList appendData)
{
    PCircularList pCurrentNode = pHead->pNext;

    while(pCurrentNode->pNext != pHead) pCurrentNode = pCurrentNode->pNext;

    pCurrentNode->pNext = appendData;

    appendData->pNext = pHead;
}

/*****************   反转链表元素    *****************/
PCircularList reverseCircularList(PCircularList pHead)
{
    PCircularList pLastNode = pHead;
    PCircularList pCurrentNode = pHead->pNext;
    PCircularList pNextNode = NULL;

    int length = getListLength(pHead);
    for(int i = 0; i < length + 2; i ++)
    {
        pNextNode = pCurrentNode->pNext;

        pCurrentNode->pNext = pLastNode;

        pLastNode = pCurrentNode;
        pCurrentNode = pNextNode;
    }

    return pCurrentNode;
}

/*****************   插入链表元素    *****************/
void insertCircularList(PCircularList pHead, int index, PCircularList insertData)
{
    PCircularList pCurrentNode = pHead->pNext;

    if(index == 1) pCurrentNode = pHead;
    for(int i = 0; i < index - 2; i ++)
    {
        if(pCurrentNode == pHead) return;
        pCurrentNode = pCurrentNode->pNext;
    }

    PCircularList pNextNode = pCurrentNode->pNext;

    insertData->pNext = pNextNode;

    pCurrentNode->pNext = insertData;
}

/*****************   获取链表长度    *****************/
int getListLength(PCircularList pHead)
{
    PCircularList pNextNode = pHead->pNext;

    int countData = 0;
    while(pHead != pNextNode)
    {
        pNextNode = pNextNode->pNext;
        countData ++;
    }

    return countData;
}
