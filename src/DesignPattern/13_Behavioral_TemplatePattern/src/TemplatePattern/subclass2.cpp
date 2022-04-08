#include "subclass2.h"
#include <QDebug>

SubClass2::SubClass2(QObject *parent) : Template(parent)
{

}

void SubClass2::do1()
{
    qDebug() << "2 do1";
}

void SubClass2::do2()
{
    qDebug() << "2 do2";
}

void SubClass2::do3()
{
    qDebug() << "2 do3";
}
