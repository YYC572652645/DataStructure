#ifndef MYQUEUE_H
#define MYQUEUE_H
#include <iostream>
#include <vector>
using namespace std;

template <class T>
class MyQueue
{
public:
     int size();
     void enQueue(const T &elementData);
     T deQueue();
     bool isEmpty();
private:
    vector<T> queueElements;
};

#endif // MYQUEUE_H
