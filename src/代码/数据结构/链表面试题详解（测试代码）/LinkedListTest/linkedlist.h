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

// 初始化链表
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

//=============以下为面试题===================

// 从无头单链表中删除节点
void deleteNode(Node *iNode);

// 反转链表
LinkedList *reverseList(LinkedList *iLst);

// 两个链表的第一个公共节点
//Node *findCommonNode(LinkedList *iLst1, LinkedList *iLst2);

// 判断给定链表是否存在环
//bool hasRing(LinkedList *iLst);

// 查找倒数第K个结点
//Node *findKNode(LinkedList *iLst);

// 判断两个链表是否相交
//bool isTntersect(LinkedList *iLst1, LinkedList *iLst2);

// 查找中间结点
//Node *findCentreNode(LinkedList *iLst);

// 合并两个排序的链表
LinkedList *mergeLst(LinkedList *iLst1, LinkedList *iLst2);

#endif // LINKEDLIST_H
