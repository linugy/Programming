#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

struct Node
{
    int data;
    Node *pPre;
    Node *pNext;
};

struct DoubleLinkedList
{
    Node *pHead;
    Node *pTail;
    int length;
};

// 初始化链表
void initList(DoubleLinkedList *iLst);

// 头部插入
void pushFront(DoubleLinkedList *iLst, int iData);

// 头部删除
void popFront(DoubleLinkedList *iLst);

// 尾部插入
void pushBack(DoubleLinkedList *iLst, int iData);

// 尾部删除
void popBack(DoubleLinkedList *iLst);

// 任意位置插入
void insert(DoubleLinkedList *iLst, int iPos, int iData);

// 任意位置删除
void erase(DoubleLinkedList *iLst, int iPos);

// 打印链表数据
void printList(DoubleLinkedList *iLst);

// 创建一个结点
Node *createNode(int iData);

#endif // DOUBLELINKEDLIST_H
