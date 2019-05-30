#ifndef MYSTACK_H
#define MYSTACK_H
#include <vector>
#include <iostream>
using namespace std;

template<class T>
class MyStack
{
public:
    T pop();
    T top() const;
    bool isEmpty();
    int size();
    void push(const T &stackValue);
private:
    vector<T> stackElements;
};


#endif // MYSTACK_H
