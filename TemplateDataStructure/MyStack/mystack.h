#ifndef MYSTACK_H
#define MYSTACK_H
#include <vector>

template<typename T>
class MyStack
{
private:
    std::vector<T> stackElements;
public:
    void push(const T &stackValue);

};

#endif // MYSTACK_H
