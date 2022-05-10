#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "context.h"
#include "concretestate1.h"
#include "concretestate2.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Context *context = new Context();

    ConcreteState1 *concreteState1 = new ConcreteState1();
    ConcreteState2 *concreteState2 = new ConcreteState2();

    context->setState(concreteState1);
    context->run();

    context->setState(concreteState2);
    context->run();
}

MainWindow::~MainWindow()
{
    delete ui;
}
