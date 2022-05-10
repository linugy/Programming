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
    mProduct2A = factoryA.create2();
    if (mProduct2A != nullptr) {
        mProduct2A->run();
    }

    FactoryB factoryB;
    mProductB = factoryB.create();
    if (mProductB != nullptr) {
        mProductB->run();
    }
    mProduct2B = factoryB.create2();
    if (mProduct2B != nullptr) {
        mProduct2B->run();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
