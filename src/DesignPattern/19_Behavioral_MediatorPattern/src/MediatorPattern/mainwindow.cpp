#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "concretemediator.h"
#include "concretecolleague1.h"
#include "concretecolleague2.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ConcreteMediator *concreteMediator = new ConcreteMediator();

    ConcreteColleague1 *concreteColleague1 = new ConcreteColleague1();
    concreteColleague1->setMediator(concreteMediator);
    ConcreteColleague2 *concreteColleague2 = new ConcreteColleague2();
    concreteColleague2->setMediator(concreteMediator);

    concreteMediator->setConcreteColleague1(concreteColleague1);
    concreteMediator->setConcreteColleague2(concreteColleague2);

    concreteColleague1->sendMessage("test");
}

MainWindow::~MainWindow()
{
    delete ui;
}
