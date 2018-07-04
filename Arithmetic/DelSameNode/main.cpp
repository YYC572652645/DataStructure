#include <iostream>
using namespace std;
/*****************************************
 * 作者：YYC
 * 日期：2018-06-03
 * 功能：从有序表A中删除所有和有序表B中元素相同的节点
 * ***************************************/

typedef struct ListNode
{
    int listData;
    ListNode * next;
}ListNode, *LinkList;

void deleteSameNode(LinkList A, LinkList B)
{
    LinkList curNodeA = A;
    LinkList curNodeB = B;

    while(curNodeA->next != NULL && curNodeB->next != NULL)
    {
        if(curNodeA->next->listData > curNodeB->next->listData)
        {
            curNodeB = curNodeB->next;
        }
        else if(curNodeA->next->listData < curNodeB->next->listData)
        {
            curNodeA = curNodeA->next;
        }
        else
        {

            LinkList delNode = curNodeA->next;

            if(delNode->next != NULL)
            {
                curNodeA->next = delNode->next;
            }
            else
            {
                curNodeA->next = NULL;
            }

            delete(delNode);
            curNodeB = curNodeB->next;
        }
    }

}

int main()
{
    LinkList A = new ListNode();

    LinkList pCurrent = A;
    pCurrent->next = NULL;

    for(int i = 0; i < 10; i ++)
    {
        LinkList newData = new ListNode();
        newData->listData = i;
        newData->next = NULL;

        pCurrent->next = newData;
        pCurrent = newData;
    }

    LinkList B = new ListNode();

    LinkList pBCurrent = B;
    pBCurrent->next = NULL;


    for(int i = 5; i < 10; i ++)
    {
        LinkList newData = new ListNode();
        newData->listData = i;
        newData->next = NULL;

        pBCurrent->next = newData;

        pBCurrent = newData;
    }


    deleteSameNode(A, B);


    while(A->next != NULL)
    {
        A = A->next;
        cout<<A->listData;
    }

    return 0;
}
