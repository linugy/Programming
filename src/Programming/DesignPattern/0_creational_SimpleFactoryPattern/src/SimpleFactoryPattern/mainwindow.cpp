#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "factory.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mProduct = Factory::create("A");
    if (mProduct != nullptr) {
        mProduct->run();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
