#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "prototype.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Prototype *tmp1 = new Prototype();
    tmp1->setName("1");
    tmp1->setId("11");

    Prototype *tmp2 = tmp1->clone();
    tmp2->setId("22");

    qDebug() << tmp1->getName() << tmp1->getId();
    qDebug() << tmp2->getName() << tmp2->getId();
}

MainWindow::~MainWindow()
{
    delete ui;
}
