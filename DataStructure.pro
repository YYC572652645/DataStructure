#*******************************************
#
# 作者：YYC
# 日期：2018-03-29
# 说明：
# 使用C++构建数据结构，所有数据结构源码均放在此项目中
#
# 01.线性结构之顺序存储结构
# 02.线性结构之单链
# 03.线性结构之双向链表
# 04.线性结构之循环链表
# 05.线性结构之静态链表
# 06.线性结构之顺序栈
# 07.线性结构之链栈
# 08.线性结构之链队
# 09.线性结构之循环队列
# 10.线性结构之串的顺序存储之截串
# 11.线性结构之串的堆分配存储
# 12.非线性结构之二叉树
# 13.非线性结构之线索二叉树
# 14.算法
#
# ...................持续更新中！
# ...................最后更新时间：2018-04-17
#
#*******************************************



TEMPLATE = subdirs

SUBDIRS += $$PWD/CDataStructure/BidirectionalList/BidirectionalList.pro
SUBDIRS += $$PWD/CDataStructure/BiThrNode/BiThrNode.pro
SUBDIRS += $$PWD/CDataStructure/BitTree/BitTree.pro
SUBDIRS += $$PWD/CDataStructure/LoopQueue/LoopQueue.pro
SUBDIRS += $$PWD/CDataStructure/CircularList/CircularList.pro
SUBDIRS += $$PWD/CDataStructure/LinkedList/LinkedList.pro
SUBDIRS += $$PWD/CDataStructure/OrderMenmory/OrderMenmory.pro
SUBDIRS += $$PWD/CDataStructure/QueueList/QueueList.pro
SUBDIRS += $$PWD/CDataStructure/StackList/StackList.pro
SUBDIRS += $$PWD/CDataStructure/StaticList/StaticList.pro
SUBDIRS += $$PWD/CDataStructure/StaticStackList/StaticStackList.pro
SUBDIRS += $$PWD/CDataStructure/OrderString/OrderString.pro
SUBDIRS += $$PWD/CDataStructure/HeapString/HeapString.pro
SUBDIRS += $$PWD/Arithmetic/Arithmetic.pro
CONFIG += ordered
