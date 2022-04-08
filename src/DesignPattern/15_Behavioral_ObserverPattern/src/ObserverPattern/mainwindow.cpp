#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "subject.h"
#include "concretesubject.h"
#include "observe.h"
#include "concreteobserve.h"
#include "concreteobserve2.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Subject *mSubject = new ConcreteSubject();

    Observe *mObserve1 = new ConcreteObserve();
    Observe *mObserve2 = new ConcreteObserve2();

    mSubject->addObserve(mObserve1);
    mSubject->addObserve(mObserve2);

    mSubject->setState("状态A");
    mSubject->notify();

    qDebug() << "===================";

    mSubject->removeObserve(mObserve1);
    mSubject->setState("状态B");
    mSubject->notify();
}

MainWindow::~MainWindow()
{
    delete ui;
}
