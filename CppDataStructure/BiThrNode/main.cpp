/****************************
 * 作者：YYC
 * 日期：2018-04-13
 * 功能：非线性结构之线索二叉树
 *
 * 知识点：
 * 1.只有空指针才能加线索
 * 2.二叉树n个节点有n+1个空指针
 * **************************/

#include <iostream>

#define PRIENDL(arg) std::cout << arg <<std::endl;
#define PRIENDS(arg) std::cout << arg <<std::ends;
#define CINARG(arg)  std::cin >> arg;

typedef enum {LINK, THREAD} POINTTAG;  //link表示指向左右孩子，thread表示指向节点前驱

typedef struct BiThrNode
{
    int data;                //数据域
    int leftTag;             //左标识，0：指向节点的左孩子， 1：指向节点前驱
    int rightTag;            //右标识，0：指向节点的右孩子， 1：指向节点前驱
    BiThrNode *leftChild;    //左孩子
    BiThrNode *rightChild;   //右孩子
}BiThrNode;

BiThrNode *preBitNode = NULL;                    //上一个节点
BiThrNode *createBiThrNode();                    //创建二叉树
void preOrderTraverse(BiThrNode *bitThrNode);    //前序遍历线索化
void midOrderTraverse(BiThrNode *bitThrNode);    //中序遍历线索化
void lastOrderTraverse(BiThrNode *bitThrNode);   //后序遍历线索化

/*****************   主函数        *****************/
int main()
{
    BiThrNode *bitThrNode = createBiThrNode();

    return 0;
}

/*****************   创建二叉树     *****************/
BiThrNode *createBiThrNode()
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

    BiThrNode *bitHead = NULL;

    int data;

    PRIENDL("please input data:");
    CINARG(data);

    if(data == 0)
    {
        bitHead = NULL;
    }
    else
    {
        bitHead = new BiThrNode();

        bitHead->data = data;
        bitHead->leftTag = LINK;
        bitHead->leftChild = createBiThrNode();

        bitHead->rightTag = LINK;
        bitHead->rightChild = createBiThrNode();
    }
}

/*****************   前序遍历线索化     *****************/
void preOrderTraverse(BiThrNode *bitThrNode)
{
    /*************************************************
     * 思路：
     *
     * 假如输入一个二叉树：
     *       a
     *      / \
     *     b   c
     *
     * 则其先序遍历结果为abc，则进入函数进行第一次递归
     *
     * 第一次：遍历左子树
     * 递归得出b的左子树的前驱节点为a，b的右子树后继节点待定
     * 左子树下次递归，因为b无子节点，所以遍历左子树结束
     * 此时preBitNode = b
     *
     * 第二次：遍历右子树
     * 递归得出c节点的左子树前驱节点为b，
     * 此时因为b的右子树为空，所以进入第二个if判断条件
     * 即b的右子树的后继节点由待定变为c
     *
     * 结果：
     *              a
     *            /   \
     *           /     \
     *          b       c
     *         / \     / \
     *       ~a  ~c  ~b  NULL
     *
     * 结论：当后继节点还未遍历到时，先将当前节点的后继节点待定
     * 等遍历到当前节点的后继节点时，再将该待定节点的后继节点置为
     * 当前遍历到的节点。中序遍历线索化和后续遍历线索化同上。
     * 如上述，为abc的二叉树，当b的后继节点为c，但c此时还未遍历到
     * 将b待定，当遍历到c时，此时可将b的后继节点置为。
     *
     * **********************************************/

    if(bitThrNode)
    {
        //设置左线索
        if(NULL == bitThrNode->leftChild)
        {
            bitThrNode->leftTag = THREAD;
            bitThrNode->leftChild = preBitNode;
        }

        //设置右线索
        if(preBitNode != NULL && NULL == preBitNode->rightChild)
        {
            preBitNode->rightTag = THREAD;
            preBitNode->rightChild = bitThrNode;
        }

        //在递归前赋值
        preBitNode = bitThrNode;

        preOrderTraverse(bitThrNode->leftChild);   //遍历左子树
        preOrderTraverse(bitThrNode->rightChild);  //遍历右子树
    }
}

/*****************   中序遍历线索化     *****************/
void midOrderTraverse(BiThrNode *bitThrNode)
{
    if(bitThrNode)
    {
        preOrderTraverse(bitThrNode->leftChild);   //遍历左子树

        //设置左线索
        if(NULL == bitThrNode->leftChild)
        {
            bitThrNode->leftTag = THREAD;
            bitThrNode->leftChild = preBitNode;
        }

        //设置右线索
        if(preBitNode != NULL && NULL == preBitNode->rightChild)
        {
            preBitNode->rightTag = THREAD;
            preBitNode->rightChild = bitThrNode;
        }

        //在递归前赋值
        preBitNode = bitThrNode;

        preOrderTraverse(bitThrNode->rightChild);  //遍历右子树
    }
}

/*****************   后序遍历线索化     *****************/
void lastOrderTraverse(BiThrNode *bitThrNode)
{
    if(bitThrNode)
    {
        preOrderTraverse(bitThrNode->leftChild);   //遍历左子树
        preOrderTraverse(bitThrNode->rightChild);  //遍历右子树

        //设置左线索
        if(NULL == bitThrNode->leftChild)
        {
            bitThrNode->leftTag = THREAD;
            bitThrNode->leftChild = preBitNode;
        }

        //设置右线索
        if(preBitNode != NULL && NULL == preBitNode->rightChild)
        {
            preBitNode->rightTag = THREAD;
            preBitNode->rightChild = bitThrNode;
        }

        //在递归前赋值
        preBitNode = bitThrNode;
    }
}
