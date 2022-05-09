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

void deleteNode(Node *iNode)
{
    Node *next = iNode->pNext;
    if (next != nullptr) {
        iNode->data = next->data;
        iNode->pNext = next->pNext;
    }
    delete next;
    next = nullptr;
}

LinkedList *reverseList(LinkedList *iLst)
{
    Node *cur = iLst->pHead;
    Node *head = iLst->pHead;
    Node *pre = nullptr;
    while (cur != nullptr) {
        head = cur;
        cur = cur->pNext;
        head->pNext = pre;
        pre = head;
    }


    LinkedList *newLst = new LinkedList;
    newLst->pHead = head;
    return newLst;
}

//Node *findCommonNode(LinkedList *iLst1, LinkedList *iLst2)
//{

//}

//bool hasRing(LinkedList *iLst)
//{

//}

//Node *findKNode(LinkedList *iLst)
//{

//}

//bool isTntersect(LinkedList *iLst1, LinkedList *iLst2)
//{

//}

//Node *findCentreNode(LinkedList *iLst)
//{

//}

LinkedList *mergeLst(LinkedList *iLst1, LinkedList *iLst2)
{
    // 确定头结点
    Node *resHead = nullptr;
    if (iLst1->pHead == nullptr) {
        resHead = iLst2->pHead;
    }
    if (iLst2->pHead == nullptr) {
        resHead = iLst1->pHead;
    }

    if (iLst1->pHead->data < iLst2->pHead->data) {
        resHead = iLst1->pHead;
    } else {
        resHead = iLst2->pHead;
    }

    // 比较结点
    Node *cur1 = iLst1->pHead;
    Node *cur2 = iLst2->pHead;
    Node *pre = nullptr;

    while (cur1 != nullptr && cur2 != nullptr) {
        if (cur1->data < cur2->data) {
            if (pre == nullptr) {
                pre = cur1;
            } else {
                pre->pNext = cur1;
                pre = cur1;
            }
            cur1 = cur1->pNext;
        } else {
            if (pre == nullptr) {
                pre = cur2;
            } else {
                pre->pNext = cur2;
                pre = cur2;
            }
            cur2 = cur2->pNext;
        }
    }

    // 添加剩余结点
    if (cur1 != nullptr) {
        pre->pNext = cur1;
        pre = cur1;
        cur1 = cur1->pNext;
    }
    if (cur2 != nullptr) {
        pre->pNext = cur2;
        pre = cur2;
        cur2 = cur2->pNext;
    }

    // 返回结果
    LinkedList *resLst = new LinkedList;
    resLst->pHead = resHead;
    return resLst;
}
