#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "component.h"
#include "composite.h"
#include "leaf.h"
#include <QDebug>
#include <iostream>
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Component *mClassA = new Composite();
    mClassA->setName("A");

    Component *mClassB = new Composite();
    mClassB->setName("B");

    Component *mClassC = new Composite();
    mClassC->setName("C");

    mClassA->addChild(mClassB);
    mClassA->addChild(mClassC);

    Component *mLeafD = new Leaf();
    mLeafD->setName("D");

    Component *mLeafE = new Leaf();
    mLeafE->setName("E");

    mClassB->addChild(mLeafD);
    mClassB->addChild(mLeafE);

    Component *mLeafF = new Leaf();
    mLeafF->setName("F");

    mClassC->addChild(mLeafF);

    // 打印
    cout << "=";
    mClassA->printName();
    printTree(mClassA, 1);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::printTree(Component *iNode, int level)
{
    for (int i = 0; i < iNode->getCount(); i++) {
        if (level == 1) {
            cout << "===";
        } else if (level == 2) {
            cout << "=====";
        }
        iNode->getChild(i)->printName();
        printTree(iNode->getChild(i), level+1);
    }
}
