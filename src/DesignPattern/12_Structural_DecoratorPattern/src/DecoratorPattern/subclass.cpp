#include "subclass.h"
#include <QDebug>

SubClass::SubClass(QObject *parent) : AbsClass(parent)
{

}

QString SubClass::getName()
{
    return "0";
}
