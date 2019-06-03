#ifndef MYLIST_H
#define MYLIST_H
#include<iostream>
#include <vector>
using namespace std;

template<class T>
class MyList
{
private:
    vector<T> listElement;
public:
    void append(const T &elementData);
    T at(const int &index) const;
    int size() const;
    void clear();
    bool isEmpty() const;
    void removeAt(const int &index);

};

#endif // MYLIST_H
