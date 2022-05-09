#include "mainwindow.h"
#include <QApplication>
#include "linkedlist.h"
#include <QDebug>

// 从无头单链表中删除节点
void testDeleteNode()
{
    qDebug() << "====start_1=======";
    LinkedList *lst = new LinkedList;
    initList(lst);
    pushBack(lst, 1);
    pushBack(lst, 2);
    pushBack(lst, 3);
    printList(lst);
    qDebug() << "===========";
    deleteNode(lst->pHead->pNext);// 删掉第二个结点
    printList(lst);
    qDebug() << "====end_1=======";
}

// 反转链表
void testReverseList()
{
    qDebug() << "====start_2=======";
    LinkedList *lst = new LinkedList;
    initList(lst);
    pushBack(lst, 1);
    pushBack(lst, 2);
    pushBack(lst, 3);
    printList(lst);
    qDebug() << "===========";
    LinkedList *resLst = reverseList(lst);// 删掉第二个结点
    printList(resLst);
    qDebug() << "====end_2=======";
}

// 两个链表的第一个公共节点
void testCommonNode()
{}

// 判断给定链表是否存在环
void testExsitRing()
{}

// 查找倒数第K个结点
void testKNode()
{}

// 判断两个链表是否相交
void testIsIntersect()
{}

// 查找中间结点
void testFindCentreNode()
{}

// 合并两个排序的链表
void testmergeTwoList()
{
    qDebug() << "====start_3=======";
    LinkedList *lst1 = new LinkedList;
    initList(lst1);
    pushBack(lst1, 1);
    pushBack(lst1, 3);
    pushBack(lst1, 5);
    pushBack(lst1, 6);
    pushBack(lst1, 8);
    pushBack(lst1, 11);

    LinkedList *lst2 = new LinkedList;
    initList(lst2);
    pushBack(lst2, 2);
    pushBack(lst2, 4);
    pushBack(lst2, 7);
    pushBack(lst2, 9);
    pushBack(lst2, 10);

    printList(lst1);
    qDebug() << "-------1------";
    printList(lst2);
    qDebug() << "-------2------";

    LinkedList *resLst = mergeLst(lst1, lst2);
    printList(resLst);
    qDebug() << "====end_3=======";
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    testDeleteNode();
    testReverseList();
    testCommonNode();
    testExsitRing();
    testKNode();
    testIsIntersect();
    testFindCentreNode();
    testmergeTwoList();

    return a.exec();
}

