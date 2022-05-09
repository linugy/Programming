#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "aggregate.h"
#include "iterator"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Aggregate *aggregate = new Aggregate();
    aggregate->append("1");
    aggregate->append("2");
    aggregate->append("3");
    aggregate->append("4");

    Iterator *iterator = aggregate->createIterator();

    while (!iterator->isEnd()) {
        qDebug() << iterator->getValue();
        iterator->next();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
