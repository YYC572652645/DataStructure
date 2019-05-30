/****************************
 * 作者：YYC
 * 日期：2018-02-27
 * 功能：线性结构之静态链表
 * **************************/

#include <iostream>

#define MAXSIZE 100

typedef struct StaticListData
{
    int data;        //数据域
    int cursor;      //游标
}StaticListData, StaticListArray[MAXSIZE];

void createStaticList(StaticListArray &array);                        //创建链表
void appendData(StaticListArray &array, int data);                    //追加数据
int mallocData(StaticListArray &array);                               //申请空间
int freeData(StaticListArray &array, int index);                      //释放空间
void insertStaticList(StaticListArray &array, int index, int data);   //插入数据
void deleteStaticList(StaticListArray &array, int index);             //删除数据
int getStaticListLength(StaticListArray &array);                      //获取长度
void showStaticList(StaticListArray &array);                          //显示链表

/********************     主函数     ******************/
int main()
{
    StaticListArray staticListArray;
    createStaticList(staticListArray);

    appendData(staticListArray, 5);
    appendData(staticListArray, 6);
    appendData(staticListArray, 7);
    appendData(staticListArray, 8);
    appendData(staticListArray, 9);
    appendData(staticListArray, 10);
    appendData(staticListArray, 11);

    insertStaticList(staticListArray, 7, 100);
    deleteStaticList(staticListArray, 5);

    showStaticList(staticListArray);
    return 0;
}


/********************     创建链表    ******************/
void createStaticList(StaticListArray &array)
{
    for(int i = 0; i < MAXSIZE - 1; i ++)
    {
        array[i].cursor = i + 1;
    }

    array[MAXSIZE - 1].cursor = 0;
}

/********************     追加数据    ******************/
void appendData(StaticListArray &array, int data)
{
    /*************************************************
     * 理解：
     * 先将为0的游标即也就是链表的最后一个数据，将其游标赋值为下一个
     * 数据的下标，避免断链，在追加数据时需要将当前数据的游标置为0
     * ***********************************************/

    for(int i = 0; i < MAXSIZE - 1; i ++)
    {
        if(array[i].cursor == 0)
        {
            array[i].cursor = array[0].cursor;
        }
    }

    int addIndex = mallocData(array);

    array[addIndex].data = data;
    array[addIndex].cursor = 0;

    if(array[0].cursor != 1)
    {
        array[MAXSIZE - 1].cursor = 1;
    }
}

/********************     申请空间       ******************/
int mallocData(StaticListArray &array)
{
    int i = array[0].cursor;

    if(array[0].cursor)
    {
        array[0].cursor = array[i].cursor;
    }

    return i;
}

/********************     释放空间       ******************/
int freeData(StaticListArray &array, int index)
{
    /*************************************************
     * 理解：
     * 将下标为index的数组元素释放掉，也就是将其游标置为该链表
     * 的最后一个可用元素的下一个游标，将头元素的游标置为该释放
     * 掉的游标，为了优先利用这个空间
     * ***********************************************/

    array[index].cursor = array[0].cursor;
    array[0].cursor = index;
}

/********************     插入数据       ******************/
void insertStaticList(StaticListArray &array, int index, int data)
{
    if(index < 1 || index > getStaticListLength(array)) return;

    int searchIndex = MAXSIZE - 1;
    int inserIndex = mallocData(array);

    if(inserIndex != 0)
    {
        for(int i = 1; i < index; i++)
        {
            searchIndex = array[searchIndex].cursor;
        }

        array[inserIndex].cursor = array[searchIndex].cursor;
        array[searchIndex].cursor = inserIndex;

        array[inserIndex].data = data;
    }
}

/********************     删除数据       ******************/
void deleteStaticList(StaticListArray &array, int index)
{
    int length = getStaticListLength(array);
    if(index < 1 || index > length) return;

    int searchIndex = MAXSIZE - 1;
    for(int i = 1; i < index; i++)
    {
        searchIndex = array[searchIndex].cursor;
    }

    int midIndex = array[searchIndex].cursor;

    if(midIndex > 0 &&  midIndex < length)
    {
        array[searchIndex].cursor = array[midIndex].cursor;
    }
    else
    {
        array[searchIndex].cursor = 0;
    }

    freeData(array, index);
}

/********************     获取长度       ******************/
int getStaticListLength(StaticListArray &array)
{
    int count = 0;
    int startIndex = array[MAXSIZE - 1].cursor;

    while(startIndex != 0)
    {
        startIndex = array[startIndex].cursor;
        count ++;
    }

    return count;
}

/********************     显示链表       ******************/
void showStaticList(StaticListArray &array)
{
    int startIndex = array[MAXSIZE - 1].cursor;

    while(startIndex)
    {
        std::cout << array[startIndex].data << std::endl;

        startIndex = array[startIndex].cursor;
    }
}
