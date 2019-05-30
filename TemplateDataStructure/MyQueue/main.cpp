#include "myqueue.h"
#include "myqueue.cpp"
#include <iostream>
using namespace std;

int main()
{
    MyQueue<int> myQueue;

    myQueue.enQueue(100);
    myQueue.enQueue(200);
    myQueue.enQueue(300);
    myQueue.enQueue(400);
    myQueue.enQueue(500);

    cout << "Queue size:" << myQueue.size() << endl;

    cout << "Queue value:";
    while(!myQueue.isEmpty())
    {
        cout << myQueue.deQueue() << ends;
    }

    return 0;
}
