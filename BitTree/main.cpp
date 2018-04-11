/****************************
 * 作者：YYC
 * 日期：2018-04-11
 * 功能：非线性结构之二叉树
 * **************************/

#include <iostream>

#define PRIENDL(arg) std::cout<< arg <<std::endl;
#define PRIENDS(arg) std::cout<< arg <<std::ends;
#define CINARG(arg)  std::cin >> arg;

typedef struct BitTree
{
    int data;                //数据域
    BitTree * leftChild;     //左孩子
    BitTree * rightChild;    //右孩子

}BitTree, *PBitTree;

PBitTree createBitTree();                      //创建二叉树
void PreOrderTraverse(PBitTree bitTree);       //先序遍历之递归写法
void MidOrderTraverse(PBitTree bitTree);       //中序遍历之递归写法
void LastOrderTraverse(PBitTree bitTree);      //后序遍历之递归写法
int  sumNode(PBitTree bitTree);                //二叉树节点总数
int  depthNode(PBitTree bitTree);              //二叉树深度
int  leafNode(PBitTree bitTree);               //叶子节点数

/*****************   主函数        *****************/
int main()
{
    PBitTree bitTree = NULL;

    bitTree = createBitTree();

    PreOrderTraverse(bitTree);
    std::cout << std::endl;

    MidOrderTraverse(bitTree);
    std::cout << std::endl;

    LastOrderTraverse(bitTree);
    std::cout << std::endl;

    std::cout << sumNode(bitTree);
    std::cout << std::endl;

    std::cout << depthNode(bitTree);
    std::cout << std::endl;

    std::cout << leafNode(bitTree);

    return 0;
}

/*****************   创建二叉树     *****************/
PBitTree createBitTree()
{
    /*************************************************
     * 思路：输入数据根据递归一直输入
     *
     * 假如输入一个二叉树：
     *       a
     *      / \
     *     b   c
     *
     * 则应输入数据为 a b 0 0 c 0 0， 其中0代表结束
     *
     * 即先输入左子树数据，左子树数据输入结束才输入右子树数据：
     *       a
     *     /   \
     *    b     c
     *   / \   / \
     *  0   0 0   0
     *
     * **********************************************/

    int data;
    PBitTree bitTree = NULL;

    PRIENDL("please input data:");
    CINARG(data);

    if(data == 0)
    {
        bitTree = NULL;
    }
    else
    {
        bitTree = new BitTree();

        bitTree->data = data;

        bitTree->leftChild = createBitTree();
        bitTree->rightChild = createBitTree();
    }

    return bitTree;
}

/*****************   先序遍历之递归写法     *****************/
void PreOrderTraverse(PBitTree bitTree)
{
    if(NULL != bitTree)
    {
        PRIENDS(bitTree->data);

        PreOrderTraverse(bitTree->leftChild);
        PreOrderTraverse(bitTree->rightChild);
    }
}

/*****************   中序遍历之递归写法     *****************/
void MidOrderTraverse(PBitTree bitTree)
{
    if(NULL != bitTree)
    {
        MidOrderTraverse(bitTree->leftChild);
        PRIENDS(bitTree->data);

        MidOrderTraverse(bitTree->rightChild);
    }
}

/*****************   后序遍历之递归写法     *****************/
void LastOrderTraverse(PBitTree bitTree)
{
    if(NULL != bitTree)
    {
        LastOrderTraverse(bitTree->leftChild);
        LastOrderTraverse(bitTree->rightChild);
        PRIENDS(bitTree->data);
    }
}

/*****************     二叉树节点总数       *****************/
int sumNode(PBitTree bitTree)
{
    if(NULL == bitTree)
    {
        return 0;
    }
    else
    {
        return 1 + sumNode(bitTree->leftChild) + sumNode(bitTree->rightChild);
    }
}

/*****************     二叉树深度       *****************/
int depthNode(PBitTree bitTree)
{
    if(NULL == bitTree)
    {
        return 0;
    }
    else
    {
        int leftDepth = depthNode(bitTree->leftChild);
        int rightDepth = depthNode(bitTree->rightChild);

        return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
    }
}

/*****************     叶子节点数       *****************/
int leafNode(PBitTree bitTree)
{
    if(NULL == bitTree)
    {
        return 0;
    }
    else if(NULL == bitTree->leftChild && NULL == bitTree->rightChild)
    {
        return 1;
    }
    else
    {
        return leafNode(bitTree->leftChild) + leafNode(bitTree->rightChild);
    }

}
