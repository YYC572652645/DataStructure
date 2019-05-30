#include "mystack.h"
#include "mystack.cpp"
#include <iostream>
using namespace std;

int main()
{
    MyStack<int> myStack;

    myStack.push(100);
    myStack.push(200);
    myStack.push(300);
    myStack.push(400);
    myStack.push(500);

    cout << "top value:" << myStack.top() << endl;
    cout << "stack size:" << myStack.size() << endl;

    cout << "stack value:";
    while(!myStack.isEmpty())
    {
        cout << myStack.pop() << ends;
    }

    return 0;
}
