#include "doublelinkedlist.h"
#include <QDebug>

void initList(DoubleLinkedList *iLst)
{
    if (iLst != nullptr) {
        iLst->pHead = nullptr;
        iLst->pTail = nullptr;
        iLst->length = 0;
    }
}

void pushFront(DoubleLinkedList *iLst, int iData)
{
    if (iLst != nullptr) {
        Node *newNode = createNode(iData);
        if (iLst->pHead == nullptr) {
            iLst->pHead = newNode;
            iLst->pTail = newNode;
        } else {
            Node *cur = iLst->pHead;
            newNode->pNext = cur;
            cur->pPre = newNode;
            iLst->pHead = newNode;
        }
        iLst->length++;
    }
}

void popFront(DoubleLinkedList *iLst)
{
    if (iLst != nullptr) {
        if (iLst->pHead != nullptr) {
            if (iLst->pHead->pNext == nullptr) {
                Node *cur = iLst->pHead;
                iLst->pHead = nullptr;
                iLst->pTail = nullptr;
                delete cur;
                cur = nullptr;
            } else {
                Node *cur = iLst->pHead;
                cur->pPre = nullptr;
                iLst->pHead = cur->pNext;
                delete cur;
                cur = nullptr;
            }
            iLst->length--;
        }
    }
}

void pushBack(DoubleLinkedList *iLst, int iData)
{
    if (iLst != nullptr) {
        Node *newNode = createNode(iData);
        if (iLst->pHead == nullptr) {
            iLst->pHead = newNode;
            iLst->pTail = newNode;
        } else {
            Node *cur = iLst->pTail;
            newNode->pPre = cur;
            cur->pNext = newNode;
            iLst->pTail = newNode;
        }
        iLst->length++;
    }
}

void popBack(DoubleLinkedList *iLst)
{
    if (iLst != nullptr) {
        if (iLst->pHead != nullptr) {
            if (iLst->pHead->pNext == nullptr) {
                Node *cur = iLst->pHead;
                iLst->pHead = nullptr;
                iLst->pTail = nullptr;
                delete cur;
                cur = nullptr;
            } else {
                Node *cur = iLst->pTail;
                cur->pPre->pNext = nullptr;
                iLst->pTail = cur->pPre;
                delete cur;
                cur = nullptr;
            }
            iLst->length--;
        }
    }
}

void insert(DoubleLinkedList *iLst, int iPos, int iData)
{
    if (iPos <= 0) {
        pushFront(iLst, iData);
    } else if (iPos >= iLst->length) {
        pushBack(iLst, iData);
    } else {
        Node *newNode = createNode(iData);
        Node *cur = iLst->pHead;
        int i = 0;
        // 找到插入位置前一个结点
        while (i < iPos - 1) {
            cur = cur->pNext;
            i++;
        }
        cur->pNext->pPre = newNode;
        newNode->pNext = cur->pNext;
        cur->pNext = newNode;
        newNode->pPre = cur;

        iLst->length++;
    }
}

void erase(DoubleLinkedList *iLst, int iPos)
{
    if (iPos <= 0) {
        popFront(iLst);
    } else if (iPos >= iLst->length) {
        popBack(iLst);
    } else {
        int i = 0;
        Node *cur = iLst->pHead;
        // 找到删除的结点
        while (i < iPos) {
            cur = cur->pNext;
            i++;
        }
        cur->pPre->pNext = cur->pNext;
        cur->pNext->pPre = cur->pPre;

        delete cur;
        cur = nullptr;

        iLst->length--;
    }
}

void printList(DoubleLinkedList *iLst)
{
    if (iLst != nullptr) {
        Node *cur = iLst->pHead;
        while (cur != nullptr) {
            qDebug() << cur->data;
            cur = cur->pNext;
        }
    }
}

Node *createNode(int iData)
{
    Node *newNode = new Node;
    newNode->data = iData;
    newNode->pPre = nullptr;
    newNode->pNext = nullptr;
    return newNode;
}
