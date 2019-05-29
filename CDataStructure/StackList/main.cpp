/****************************
 * 作者：YYC
 * 日期：2018-03-13
 * 功能：线性结构之链栈
 * **************************/

#include <iostream>

typedef struct NodeListData
{
    int data;             //数据域
    NodeListData *pNext;  //指针域
}NodeListData, *PNodeList;

typedef struct StackListData
{
    PNodeList pTop;     //栈顶
    PNodeList pBottom;  //栈底
}StackListData, *PStackList;

void initStackList(PStackList pStackList);         //初始化栈
void pushStack(PStackList pStackList,int data);    //入栈
bool popStack(PStackList pStackList, int *data);   //出栈
void traverseStackList(PStackList pStackList);     //遍历输出
bool isEmpty(PStackList pStackList);               //判断是否为空
void clearStackList(PStackList pStackList);        //清空栈

/*****************    主函数       **************/
int main()
{
    StackListData stackListData;

    initStackList(&stackListData);

    pushStack(&stackListData, 1);
    pushStack(&stackListData, 2);
    pushStack(&stackListData, 3);
    pushStack(&stackListData, 4);
    pushStack(&stackListData, 5);
    pushStack(&stackListData, 6);
    pushStack(&stackListData, 7);

    int popValue;
    popStack(&stackListData, &popValue);
    std::cout<<popValue<<std::endl;

    popStack(&stackListData, &popValue);
    std::cout<<popValue<<std::endl;

    popStack(&stackListData, &popValue);
    std::cout<<popValue<<std::endl;

    clearStackList(&stackListData);
    traverseStackList(&stackListData);

    return 0;
}

/*****************    初始化栈       **************/
void initStackList(PStackList pStackList)
{
    pStackList->pTop = new NodeListData();
    pStackList->pBottom = pStackList->pTop;

    pStackList->pTop->pNext = NULL;
}

/*****************    入栈       **************/
void pushStack(PStackList pStackList, int data)
{
    PNodeList pNew = new NodeListData();

    pNew->data = data;
    pNew->pNext = pStackList->pTop;

    //栈顶上移
    pStackList->pTop = pNew;
}

/*****************    出栈       **************/
bool popStack(PStackList pStackList, int *data)
{
    if(isEmpty(pStackList)) return false;

    *data = pStackList->pTop->data;

    //记住栈顶元素
    PNodeList pTop = pStackList->pTop;

    pStackList->pTop =  pTop->pNext;

    //释放记住的栈顶元素
    delete pTop;
    pTop = NULL;

    return true;
}

/*****************    遍历输出       **************/
void traverseStackList(PStackList pStackList)
{
    PNodeList pTop = pStackList->pTop;

    std::cout<< "output:" << std::endl;
    while(pTop != pStackList->pBottom)
    {
        std::cout<<pTop->data<<std::endl;
        pTop = pTop->pNext;
    }
}

/*****************    判断是否为空       **************/
bool isEmpty(PStackList pStackList)
{
    if(pStackList->pTop == pStackList->pBottom) return true;

    return false;
}

/*****************    清空栈       **************/
void clearStackList(PStackList pStackList)
{
    if(isEmpty(pStackList)) return;

    while(pStackList->pTop != pStackList->pBottom)
    {
        PNodeList pTop = pStackList->pTop;
        pStackList->pTop = pTop->pNext;

        delete pTop;
        pTop = NULL;
    }
}
