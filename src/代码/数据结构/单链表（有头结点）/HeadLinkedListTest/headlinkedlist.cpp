#include "headlinkedlist.h"
#include <QDebug>

void initList(HeadLinkedList *iLst)
{
    if (iLst != nullptr) {
        Node *head = new Node;
        head->pNext = nullptr;
        iLst->pHead = head;
    }
}

void pushFront(HeadLinkedList *iLst, int iData)
{
    if (iLst != nullptr) {
        if (iLst->pHead != nullptr) {
            Node *newNode = createNode(iData);
            Node *next = iLst->pHead->pNext;
            newNode->pNext = next;
            iLst->pHead->pNext = newNode;
        }
    }
}

void popFront(HeadLinkedList *iLst)
{
    if (iLst != nullptr) {
        if (iLst->pHead != nullptr) {
            Node *next = iLst->pHead->pNext;
            iLst->pHead->pNext = next->pNext;
            delete next;
        }
    }
}

void pushBack(HeadLinkedList *iLst, int iData)
{
    if (iLst != nullptr) {
        if (iLst->pHead != nullptr) {
            Node *newNode = createNode(iData);
            Node *cur = iLst->pHead;
            while (cur->pNext != nullptr){
                cur = cur->pNext;
            }
            cur->pNext = newNode;
        }
    }
}

void popBack(HeadLinkedList *iLst)
{
    if (iLst != nullptr) {
        if (iLst->pHead != nullptr) {
            Node *cur = iLst->pHead->pNext;
            Node *pre = nullptr;
            while (cur->pNext != nullptr) {
                pre = cur;
                cur = cur->pNext;
            }
            pre->pNext = nullptr;
            delete cur;
            cur = nullptr;
        }
    }
}

void insert(HeadLinkedList *iLst, int iPos, int iData)
{
    if (iPos <= 0) {
        pushFront(iLst, iData);
    } else if (iPos >= length(iLst)) {
        qDebug() << "---length---" << length(iLst);
        pushBack(iLst, iData);
    } else {
        Node *newNode = createNode(iData);
        Node *cur = iLst->pHead->pNext;
        Node *pre = nullptr;
        int i = 0;
        while (i < iPos) {
            pre = cur;
            cur = cur->pNext;
            i++;
        }
        pre->pNext = newNode;
        newNode->pNext = cur;
    }
}

void erase(HeadLinkedList *iLst, int iPos)
{
    if (iPos <= 0) {
        popFront(iLst);
    } else if (iPos >= length(iLst)) {
        popBack(iLst);
    } else {
        int i = 0;
        Node *cur = iLst->pHead->pNext;
        Node *pre = nullptr;
        while (i < iPos) {
            pre = cur;
            cur = cur->pNext;
            i++;
        }
        pre->pNext = cur->pNext;
        delete cur;
        cur = nullptr;
    }
}

void printList(HeadLinkedList *iLst)
{
    Node *node = iLst->pHead->pNext;
    while(node != nullptr) {
        qDebug() << node->data;
        node = node->pNext;
    }
}

Node *createNode(int iData)
{
    Node *newNode = new Node;
    newNode->data = iData;
    newNode->pNext = nullptr;
    return newNode;
}

int length(HeadLinkedList *iLst)
{
    int length = 0;
    Node *cur = iLst->pHead->pNext;
    while (cur != nullptr) {
        cur = cur->pNext;
        length++;
    }
    return length;
}
