#ifndef HEADLINKEDLIST_H
#define HEADLINKEDLIST_H

struct Node
{
    int data;
    Node *pNext;
};

struct HeadLinkedList
{
    Node *pHead;
};

// 初始化链表
void initList(HeadLinkedList *iLst);

// 头部插入
void pushFront(HeadLinkedList *iLst, int iData);

// 头部删除
void popFront(HeadLinkedList *iLst);

// 尾部插入
void pushBack(HeadLinkedList *iLst, int iData);

// 尾部删除
void popBack(HeadLinkedList *iLst);

// 任意位置插入
void insert(HeadLinkedList *iLst, int iPos, int iData);

// 任意位置删除
void erase(HeadLinkedList *iLst, int iPos);

// 打印链表数据
void printList(HeadLinkedList *iLst);

// 创建一个结点
Node *createNode(int iData);

// 获取链表的长度
int length(HeadLinkedList *iLst);

#endif // HEADLINKEDLIST_H
