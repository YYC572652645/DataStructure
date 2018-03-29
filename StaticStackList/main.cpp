/****************************
 * 作者：YYC
 * 日期：2018-03-13
 * 功能：线性结构之顺序栈
 * **************************/

#include <iostream>

#define INIT_STACK_SIZE  100   //初始长度
#define RELOC_STACK_SIZE 10    //追加长度

typedef struct StaticStack
{
    int *pTop;      //栈顶元素
    int *pBottom;   //栈底元素
    int stackSize;  //栈长度
}StaticStack;

void initStack(StaticStack &staticStack);            //初始化栈
void pushStack(StaticStack &staticStack,int data);   //入栈
bool popStack(StaticStack &staticStack, int *data);  //出栈
void traverseStack(StaticStack &staticStack);        //遍历输出
bool isEmpty(StaticStack &staticStack);              //判断是否为空
void clearStack(StaticStack &staticStack);           //清空栈

/*****************    主函数         **************/
int main()
{
    StaticStack newStack;

    initStack(newStack);

    pushStack(newStack, 1);
    pushStack(newStack, 2);
    pushStack(newStack, 3);
    pushStack(newStack, 4);
    pushStack(newStack, 5);

    int popValue;
    popStack(newStack, &popValue);
    std::cout<<popValue<<std::endl;

    traverseStack(newStack);

    clearStack(newStack);
    traverseStack(newStack);
    return 0;
}

/*****************    初始化栈       **************/
void initStack(StaticStack &staticStack)
{
    staticStack.pTop = new int[INIT_STACK_SIZE];

    staticStack.pBottom =  staticStack.pTop;

    staticStack.stackSize = INIT_STACK_SIZE;
}

/*****************    入栈          **************/
void pushStack(StaticStack &staticStack, int data)
{
    if(staticStack.pTop - staticStack.pBottom >= staticStack.stackSize) return;

    *staticStack.pTop ++ = data;
}

/*****************    出栈          **************/
bool popStack(StaticStack &staticStack, int *data)
{
    if(isEmpty(staticStack)) return false;

    int *pTop = staticStack.pTop;

    *data = * -- staticStack.pTop ;

    free(pTop);
    pTop = NULL;

    return true;
}

/*****************    遍历输出       **************/
void traverseStack(StaticStack &staticStack)
{
    std::cout << "output:";
    while(staticStack.pTop != staticStack.pBottom)
    {
        std::cout<< * --staticStack.pTop << std::endl;
    }
}

/*****************    判断是否为空    **************/
bool isEmpty(StaticStack &staticStack)
{
    if(staticStack.pTop == staticStack.pBottom) return true;

    return false;
}

/*****************    清空栈         **************/
void clearStack(StaticStack &staticStack)
{
    if(isEmpty(staticStack)) return;

    while(staticStack.pTop != staticStack.pBottom)
    {
         int *pTop = staticStack.pTop;

         staticStack.pTop --;

         delete pTop;
         pTop = NULL;
    }
}
