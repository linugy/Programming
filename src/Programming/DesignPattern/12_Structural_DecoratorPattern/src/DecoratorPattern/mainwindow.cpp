#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "absclass.h"
#include "subclass.h"
#include "decoratorabsclass.h"
#include "decoratorsubclass.h"
#include "decoratorsubclass2.h"
#include "decoratorsubclass3.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    AbsClass *mClass = new SubClass();

    DecoratorAbsClass *mDecorator = new DecoratorSubClass();
    mDecorator->setClass(mClass);

    DecoratorAbsClass *mDecorator2 = new DecoratorSubClass2();
    mDecorator2->setClass(mDecorator);

    DecoratorAbsClass *mDecorator3 = new DecoratorSubClass3();
    mDecorator3->setClass(mDecorator2);

    mDecorator3->printInfo();
}

MainWindow::~MainWindow()
{
    delete ui;
}
