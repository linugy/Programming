#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "absclassa.h"
#include "absclassb.h"
#include "subclassa1.h"
#include "subclassb1.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    AbsClassA *mClassA = new SubClassA1();

    AbsClassB *mClassB = new SubClassB1();

    mClassA->setClass(mClassB);
    mClassA->run();
}

MainWindow::~MainWindow()
{
    delete ui;
}
