#include "subclass1.h"
#include <QDebug>

SubClass1::SubClass1(QObject *parent) : Template(parent)
{

}

void SubClass1::do1()
{
    qDebug() << "1 do1";
}

void SubClass1::do2()
{
    qDebug() << "1 do2";
}

void SubClass1::do3()
{
    qDebug() << "1 do3";
}
