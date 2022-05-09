#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mProduct = new Product();
    mBuilder = new Builder();
    mDirector = new Director();

    mBuilder->setProduct(mProduct);
    mDirector->setBuilder(mBuilder);

    mDirector->build();
}

MainWindow::~MainWindow()
{
    delete ui;
}
