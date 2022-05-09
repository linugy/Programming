#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "absclass.h"
#include "subclass1.h"
#include "subclass2.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    AbsClass *mAbsClass = new SubClass1();
    mAbsClass->run();

    qDebug() <<  "========================";

    AbsClass *mAbsClass2 = new SubClass2();
    mAbsClass2->run();
}

MainWindow::~MainWindow()
{
    delete ui;
}
