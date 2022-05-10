#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct Node
{
    int data;
    Node *pNext;
};

struct LinkedList
{
    Node *pHead;
};

// 创建结点
void initList(LinkedList *iLst);

// 头部插入
void pushFront(LinkedList *iLst, int iData);

// 头部删除
void popFront(LinkedList *iLst);

// 尾部插入
void pushBack(LinkedList *iLst, int iData);

// 尾部删除
void popBack(LinkedList *iLst);

// 任意位置插入
void insert(LinkedList *iLst, int iPos, int iData);

// 任意位置删除
void erase(LinkedList *iLst, int iPos);

// 打印链表数据
void printList(LinkedList *iLst);

// 创建一个结点
Node *createNode(int iData);

// 获取链表的长度
int length(LinkedList *iLst);

#endif // LINKEDLIST_H
