/****************************
 * 作者：YYC
 * 日期：2018-03-13
 * 功能：线性结构之动态链表
 * **************************/

#include <stdio.h>
#include <malloc.h>
#include <memory.h>

#define PRINT(str) printf("\n%s\n", str);

typedef struct NodeListData
{
    int data;         //数据域
    NodeListData *pNext;  //指针域
}NodeListData, *PNodeList;

typedef struct StackListData
{
    PNodeList pTop;     //栈顶
    PNodeList pBottom;  //栈底
}StackListData, *PStackList;

void initStackList(PStackList pStackList);
void pushStack(PStackList pStackList,int data);
bool popStack(PStackList pStackList, int *data);
void traverseStackList(PStackList pStackList);
bool isEmpty(PStackList pStackList);
void clearStackList(PStackList pStackList);


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
    printf("%d ", popValue);

    popStack(&stackListData, &popValue);
    printf("%d ", popValue);

    popStack(&stackListData, &popValue);
    printf("%d ", popValue);

    clearStackList(&stackListData);
    traverseStackList(&stackListData);

    return 0;
}

/*****************    初始化栈       **************/
void initStackList(PStackList pStackList)
{
    pStackList->pTop = (PNodeList)malloc(sizeof(NodeListData));
    pStackList->pBottom = pStackList->pTop;

    pStackList->pTop->pNext = NULL;
}
/*****************    入栈       **************/
void pushStack(PStackList pStackList, int data)
{
    PNodeList pNew = (PNodeList)malloc(sizeof(NodeListData));

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
    free(pTop);
    pTop = NULL;

    return true;
}

/*****************    遍历输出       **************/
void traverseStackList(PStackList pStackList)
{
    PNodeList pTop = pStackList->pTop;

    PRINT("output:");
    while(pTop != pStackList->pBottom)
    {
        printf("%d ", pTop->data);
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

        free(pTop);
        pTop = NULL;
    }
}
