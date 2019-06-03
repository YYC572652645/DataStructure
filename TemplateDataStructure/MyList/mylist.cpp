#include "mylist.h"

template<class T>
void MyList<T>::append(const T &elementData)
{
    listElement.push_back(elementData);
}

template<class T>
T MyList<T>::at(const int &index) const
{
    if(listElement.empty() || index >= listElement.size()) return T();

    return listElement.at(index);
}

template<class T>
int MyList<T>::size() const
{
    return static_cast<int>(listElement.size());
}

template<class T>
void MyList<T>::clear()
{
    listElement.clear();
}


template<class T>
bool MyList<T>::isEmpty() const
{
    return listElement.empty();
}

template<class T>
void MyList<T>::removeAt(const int &index)
{
    if(listElement.empty() || index >= listElement.size()) return;

    auto iter = listElement.begin();
    for(int i = 0; i < index; i++)
    {
        iter++;
    }
    listElement.erase(iter);
}

