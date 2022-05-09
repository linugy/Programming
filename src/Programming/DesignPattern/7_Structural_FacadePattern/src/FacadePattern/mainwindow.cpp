#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "facade.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Facade *facade = new Facade();
    facade->run();
}

MainWindow::~MainWindow()
{
    delete ui;
}
