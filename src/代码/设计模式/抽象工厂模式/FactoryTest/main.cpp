#include "mainwindow.h"
#include <QApplication>
#include "factory.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    Factory *FA = new FactoryA();
    FA->createObj()->show();
    FA->createObjOther()->showOther();

    Factory *FB = new FactoryB();
    FB->createObj()->show();
    FB->createObjOther()->showOther();

    return a.exec();
}
