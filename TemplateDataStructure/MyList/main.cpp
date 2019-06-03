/****************************
 * 作者：YYC
 * 日期：2019-06-03
 * 功能：用模板实现链表
 * **************************/

#include "mylist.h"
#include "mylist.cpp"
#include <iostream>
using namespace std;

int main()
{
    MyList<int> myList;

    myList.append(100);
    myList.append(200);
    myList.append(300);
    myList.append(400);
    myList.append(500);

    cout << "list size:" << myList.size() << endl;

    cout << "list value:";
    while(!myList.isEmpty())
    {
        cout << myList.at(0) << ends;
        myList.removeAt(0);
    }

    return 0;
}
