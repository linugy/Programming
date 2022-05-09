#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "absclass.h"
#include "subclass.h"
#include "proxyclass.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    AbsClass *mClass = new SubClass();

    ProxyClass *mProxyClass = new ProxyClass();
    mProxyClass->setSubClass(mClass);

    mProxyClass->run();
}

MainWindow::~MainWindow()
{
    delete ui;
}
