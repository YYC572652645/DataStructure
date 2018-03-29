/****************************
 * 作者：YYC
 * 日期：2018-03-29
 * 功能：线性结构之链队列
 * **************************/

#include <iostream>

typedef struct QNode
{
    int data;       //数据域
    QNode *pNext;   //指针域

}QNode, *PQNode;

typedef struct LinkQueue
{
    PQNode pFront;  //队头指针
    PQNode pRear;   //队尾指针
}LinkQueue;


void initQueue(LinkQueue &linkQueue);               //初始化队列
void clearQueue(LinkQueue &linkQueue);              //清空队列
bool isQueueEmpty(LinkQueue &linkQueue);            //判断是否为空
void appendQueue(LinkQueue &linkQueue, int data);   //添加数据
void deleteQueue(LinkQueue &linkQueue, int &data);  //删除数据
void showQueue(LinkQueue &linkQueue);               //显示输出

/*******************       主函数     ********************/
int main()
{
    LinkQueue linkQueue;

    initQueue(linkQueue);

    appendQueue(linkQueue, 1);
    appendQueue(linkQueue, 2);
    appendQueue(linkQueue, 3);
    appendQueue(linkQueue, 4);

    int data;
    deleteQueue(linkQueue, data);
    std::cout<<data<<std::endl;

    showQueue(linkQueue);

    clearQueue(linkQueue);
    showQueue(linkQueue);

    return 0;
}

/*******************       初始化队列     ********************/
void initQueue(LinkQueue &linkQueue)
{
    linkQueue.pFront = linkQueue.pRear = new QNode();

    linkQueue.pFront->pNext = NULL;
}

/*******************       清空队列      ********************/
void clearQueue(LinkQueue &linkQueue)
{
    if(isQueueEmpty(linkQueue)) return;

    while(NULL != linkQueue.pFront)
    {
        PQNode pNode = linkQueue.pFront->pNext;

        delete linkQueue.pFront;

        linkQueue.pFront = pNode;
    }

    linkQueue.pFront = linkQueue.pRear;
    linkQueue.pFront->pNext = NULL;
}

/*******************       判断是否为空   ********************/
bool isQueueEmpty(LinkQueue &linkQueue)
{
    if(linkQueue.pFront == linkQueue.pRear) return true;

    return false;
}

/*******************       添加数据      ********************/
void appendQueue(LinkQueue &linkQueue, int data)
{
    PQNode pNode = new QNode();

    pNode->data = data;
    pNode->pNext = NULL;

    linkQueue.pRear->pNext = pNode;

    linkQueue.pRear = pNode;
}

/*******************       删除数据      ********************/
void deleteQueue(LinkQueue &linkQueue, int &data)
{
    if(isQueueEmpty(linkQueue)) return;

    PQNode pFront = linkQueue.pFront;

    data = pFront->pNext->data;

    linkQueue.pFront = pFront->pNext;

    delete pFront;
}

/*******************       显示输出      ********************/
void showQueue(LinkQueue &linkQueue)
{
    if(isQueueEmpty(linkQueue)) return;

    PQNode pFront = linkQueue.pFront->pNext;

    std::cout<< "output results:" <<std::endl;

    while(pFront != linkQueue.pRear)
    {
        std::cout<<pFront->data;

        pFront = pFront->pNext;
    }

    std::cout<<pFront->data;
}
