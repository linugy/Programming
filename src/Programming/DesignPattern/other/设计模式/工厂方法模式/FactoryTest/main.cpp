#include "mainwindow.h"
#include <QApplication>
#include "factory.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    Factory *fA = new FactoryA();
    Product *PA = fA->createObj();
    PA->show();

    Factory *fB = new FactoryB();
    Product *PB = fB->createObj();
    PB->show();

    return a.exec();
}
