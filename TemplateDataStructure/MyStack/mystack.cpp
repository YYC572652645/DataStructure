#include "mystack.h"

template<class T>
T MyStack<T>::pop()
{
    T elementData = T();
    if(!stackElements.empty())
    {
        elementData = stackElements.back();
        stackElements.pop_back();
    }
    return elementData;
}

template<class T>
T MyStack<T>::top() const
{
    T elementData = T();
    if(!stackElements.empty())
    {
        elementData = stackElements.back();
    }
    return elementData;
}

template<class T>
bool MyStack<T>::isEmpty()
{
    return stackElements.empty();
}

template<class T>
int MyStack<T>::size()
{
    return static_cast<int>(stackElements.size());
}


template<class T>
void MyStack<T>::push(T stackValue)
{
    stackElements.push_back(stackValue);
}
