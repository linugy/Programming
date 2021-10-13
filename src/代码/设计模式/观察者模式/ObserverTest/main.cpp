#include "mainwindow.h"
#include <QApplication>
#include "observer.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    Object *obj = new ObjectA();

    Observer *A = new ObserverA();
    Observer *B = new ObserverB();

    obj->addObserver(A);
    obj->addObserver(B);
    obj->setState(1);

    qDebug() << "---------------";

    obj->deleteObserver(A);
    obj->setState(2);

    return a.exec();
}
