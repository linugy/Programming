#include "absclass.h"
#include <QDebug>

AbsClass::AbsClass(QObject *parent) : QObject(parent)
{

}

void AbsClass::printInfo()
{
    qDebug() << getName();
}
