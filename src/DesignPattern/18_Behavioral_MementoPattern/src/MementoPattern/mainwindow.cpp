#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "role.h"
#include "memento.h"
#include "manager.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Role *role = new Role();
    role->setAttack(1);
    role->setDefend(2);
    role->setName("33");

    qDebug() << "====111===" << role->getAttack() << role->getDefend() << role->getName();

    Manager *manager = new Manager();
    manager->save(role->save());

    role->setAttack(11);
    role->setDefend(22);
    role->setName("3333");

    qDebug() << "====222===" << role->getAttack() << role->getDefend() << role->getName();

    role->load(manager->load());

    qDebug() << "====333===" << role->getAttack() << role->getDefend() << role->getName();
}

MainWindow::~MainWindow()
{
    delete ui;
}
