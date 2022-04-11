#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "invoke.h"
#include "concretecommand.h"
#include "receive.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Receive *mReceive = new Receive();

    Command *mCommand = new ConcreteCommand();
    mCommand->setReceive(mReceive);

    Invoke *mInvoke = new Invoke();
    mInvoke->setConcreteCommand(mCommand);

    mInvoke->invoke();
}

MainWindow::~MainWindow()
{
    delete ui;
}
