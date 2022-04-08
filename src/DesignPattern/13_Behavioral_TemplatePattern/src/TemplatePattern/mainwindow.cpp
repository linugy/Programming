#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mTemplate = new SubClass1();
    mTemplate->run();

    delete mTemplate;

    qDebug() << "================";

    mTemplate = new SubClass2();
    mTemplate->run();

    delete mTemplate;
}

MainWindow::~MainWindow()
{
    delete ui;
}
