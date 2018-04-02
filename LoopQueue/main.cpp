/****************************
 * 作者：YYC
 * 日期：2018-01-28
 * 功能：线性结构之循环队列
 * **************************/

#include <iostream>

#define MAXQSIZE 100

typedef struct LoopQueue
{
    int *base;  //数据
    int front;  //头指针
    int rear;   //尾指针
}LoopQueue;

void initQueue(LoopQueue &linkQueue);               //初始化队列
void clearQueue(LoopQueue &linkQueue);              //清空队列
bool isQueueEmpty(LoopQueue &linkQueue);            //判断是否为空
void appendQueue(LoopQueue &linkQueue, int data);   //添加数据
void deleteQueue(LoopQueue &linkQueue, int &data);  //删除数据
void showQueue(LoopQueue &linkQueue);               //显示输出
int getQueueLength(LoopQueue &linkQueue);           //获取长度

/*******************       主函数     ********************/
int main()
{
    LoopQueue loopData;

    initQueue(loopData);

    appendQueue(loopData, 1);
    appendQueue(loopData, 2);
    appendQueue(loopData, 3);

    clearQueue(loopData);

    appendQueue(loopData, 4);
    appendQueue(loopData, 5);
    appendQueue(loopData, 6);

    int data;
    deleteQueue(loopData, data);

    showQueue(loopData);

    return 0;
}

/*******************       初始化队列    ********************/
void initQueue(LoopQueue &linkQueue)
{
    linkQueue.base = new int[MAXQSIZE];

    linkQueue.front = linkQueue.rear = 0;
}

/*******************       清空队列     ********************/
void clearQueue(LoopQueue &linkQueue)
{
    int count = linkQueue.front;
    for(int i = 0; i < getQueueLength(linkQueue); i ++)
    {
        linkQueue.base[count % MAXQSIZE] = 0;

        count ++;
    }

    linkQueue.front = linkQueue.rear = 0;
}

/*******************       判断是否为空  ********************/
bool isQueueEmpty(LoopQueue &linkQueue)
{
    if(linkQueue.rear == linkQueue.front) return true;

    return false;
}

/*******************       添加数据     ********************/
void appendQueue(LoopQueue &linkQueue, int data)
{
    /*************************************************
     * 理解：
     * 如果头指针与尾指针相邻时，此时队列为满
     * 在添加数据时，如果尾部指针大于元素长度时，往前进行添加数据
     * 如果全面没用可用空间，则rear = 1， front为0为满
     * ***********************************************/
    if((linkQueue.rear + 1) % MAXQSIZE == linkQueue.front) return;

    linkQueue.base[linkQueue.rear] = data;

    linkQueue.rear = (linkQueue.rear + 1) % MAXQSIZE;
}

/*******************       删除数据     ********************/
void deleteQueue(LoopQueue &linkQueue, int &data)
{
    if(isQueueEmpty(linkQueue)) return;

    data = linkQueue.base[linkQueue.front];

    linkQueue.base[linkQueue.front] = 0;

    linkQueue.front = (linkQueue.front + 1) % MAXQSIZE;
}

/*******************       显示输出     ********************/
void showQueue(LoopQueue &linkQueue)
{
    std::cout <<"output:" << std::endl;

    int count = linkQueue.front;
    for(int i = 0; i < getQueueLength(linkQueue); i ++)
    {
        std::cout << linkQueue.base[count % MAXQSIZE] << std::endl;

        count ++;
    }
}

/*******************       获取长度     ********************/
int getQueueLength(LoopQueue &linkQueue)
{
    return (linkQueue.rear - linkQueue.front + MAXQSIZE) % MAXQSIZE;
}
