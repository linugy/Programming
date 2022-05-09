#include "mainwindow.h"
#include <QApplication>
#include "factory.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    Factory *f = new Factory();

    Product *PA = f->createObj(1);
    PA->show();

    Product *PB = f->createObj(2);
    PB->show();

    return a.exec();
}
