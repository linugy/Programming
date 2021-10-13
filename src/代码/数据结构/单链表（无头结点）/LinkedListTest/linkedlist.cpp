#include "linkedlist.h"
#include <QDebug>

void initList(LinkedList *iLst)
{
    if (iLst != nullptr) {
        iLst->pHead = nullptr;
    }
}

void pushFront(LinkedList *iLst, int iData)
{
    if (iLst != nullptr) {
        Node *newNode = createNode(iData);
        if (iLst->pHead == nullptr) {
            iLst->pHead = newNode;
        } else {
            Node *tmpHead = iLst->pHead;
            iLst->pHead = newNode;
            newNode->pNext = tmpHead;
        }
    }
}

void popFront(LinkedList *iLst)
{
    if (iLst != nullptr) {
        if (iLst->pHead != nullptr) {
            if (iLst->pHead->pNext == nullptr) {
                delete iLst->pHead;
                iLst->pHead = nullptr;
            } else {
                Node *tmpNext = iLst->pHead->pNext;
                delete iLst->pHead;
                iLst->pHead = tmpNext;
            }
        }
    }
}

void pushBack(LinkedList *iLst, int iData)
{
    if (iLst != nullptr) {
        Node *newNode = createNode(iData);
        if (iLst->pHead == nullptr) {
            iLst->pHead = newNode;
        } else {
            Node *cur = iLst->pHead;
            while (cur->pNext != nullptr) {
                cur = cur->pNext;
            }
            cur->pNext = newNode;
        }
    }
}

void popBack(LinkedList *iLst)
{
    if (iLst != nullptr) {
        if (iLst->pHead != nullptr) {
            if (iLst->pHead->pNext == nullptr) {
                delete iLst->pHead;
                iLst->pHead = nullptr;
            } else {
                Node *cur = iLst->pHead;
                Node *pre = nullptr;
                while (cur->pNext != nullptr) {
                    pre = cur;
                    cur = cur->pNext;
                }
                delete cur;
                pre->pNext = nullptr;
            }
        }
    }
}

void insert(LinkedList *iLst, int iPos, int iData)
{
    if (iPos <= 0) {
        pushFront(iLst, iData);
    } else if (iPos >= length(iLst)) {
        qDebug() << "---length---" << length(iLst);
        pushBack(iLst, iData);
    } else {
        Node *newNode = createNode(iData);
        Node *cur = iLst->pHead;
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

void erase(LinkedList *iLst, int iPos)
{
    if (iPos <= 0) {
        popFront(iLst);
    } else if (iPos >= length(iLst)) {
        popBack(iLst);
    } else {
        Node *cur = iLst->pHead;
        Node *pre = nullptr;
        int i = 0;
        while(i < iPos) {
            pre = cur;
            cur = cur->pNext;
            i++;
        }
        pre->pNext = cur->pNext;
        delete cur;
        cur = nullptr;
    }
}

void printList(LinkedList *iLst)
{
    Node *node = iLst->pHead;
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


int length(LinkedList *iLst)
{
    Node *cur = iLst->pHead;
    int count = 0;
    while (cur != nullptr) {
        cur = cur->pNext;
        count++;
    }
    return count;
}
