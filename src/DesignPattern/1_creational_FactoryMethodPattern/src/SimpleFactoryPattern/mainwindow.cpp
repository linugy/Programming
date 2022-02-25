#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "factorya.h"
#include "factoryb.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    FactoryA factoryA;
    mProductA = factoryA.create();
    if (mProductA != nullptr) {
        mProductA->run();
    }

    FactoryB factoryB;
    mProductB = factoryB.create();
    if (mProductB != nullptr) {
        mProductB->run();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
