#include "mainwindow.h"
#include <QApplication>
#include "headlinkedlist.h"
#include <QDebug>

void testHeadLinkedList()
{
    qDebug() << "======testHedadLinkedList=======";
    HeadLinkedList *lst = new HeadLinkedList;
    initList(lst);

    // 测试头插
    pushFront(lst, 1);
    pushFront(lst, 2);
    pushFront(lst, 3);
    printList(lst);// 3 2 1
    qDebug() << "--------1----------";

    // 测试头删
    popFront(lst);
    printList(lst);// 2 1
    qDebug() << "---------2---------";
    popFront(lst);
    printList(lst);// 1
    qDebug() << "----------3--------";
    popFront(lst);
    printList(lst);//
    qDebug() << "---------4---------";

    // 测试尾插
    pushBack(lst, 1);
    pushBack(lst, 2);
    pushBack(lst, 3);
    printList(lst);// 1 2 3
    qDebug() << "----------5--------";

    // 测试尾删
    popBack(lst);
    printList(lst);// 1 2
    qDebug() << "----------6--------";
    popBack(lst);
    printList(lst);// 1
    qDebug() << "----------7--------";

    // 测试任意插入
    insert(lst, 0, 4);// 0相当于头插
    printList(lst);// 4 1
    qDebug() << "----------8--------";
    insert(lst, 2, 5);// 大于等于长度，相当于尾插
    printList(lst);// 4 1 5
    qDebug() << "----------9--------";
    insert(lst, 2, 6);
    printList(lst);// 4 1 6 5
    qDebug() << "----------1--------";
    insert(lst, 1, 7);
    printList(lst);// 4 7 1 6 5
    qDebug() << "----------2--------";

    // 测试任意删除
    erase(lst, 0);// 0相当于头删
    printList(lst);// 7 1 6 5
    qDebug() << "----------3--------";
    erase(lst, 4);// 大于等于长度等于尾删
    printList(lst);// 7 1 6
    qDebug() << "----------4--------";
    erase(lst, 1);
    printList(lst);// 7 6
    qDebug() << "----------5--------";

    qDebug() << "======endTestHeadLinkedList=======";

}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    testHeadLinkedList();

    return a.exec();
}
