#include "myqueue.h"

template<class T>
T MyQueue<T>::deQueue()
{
    T elementData = T();
    if(!queueElements.empty())
    {
        auto iter = queueElements.begin();
        elementData = *iter;
        queueElements.erase(iter);
    }
    return elementData;
}

template<class T>
bool MyQueue<T>::isEmpty()
{
    return queueElements.empty();
}

template<class T>
int MyQueue<T>::size()
{
    return static_cast<int>(queueElements.size());
}


template<class T>
void MyQueue<T>::enQueue(const T &elementData)
{
    queueElements.push_back(elementData);
}
