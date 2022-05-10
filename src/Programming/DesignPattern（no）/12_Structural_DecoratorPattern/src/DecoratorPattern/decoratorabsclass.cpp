#include "decoratorabsclass.h"
#include <QDebug>

DecoratorAbsClass::DecoratorAbsClass(QObject *parent) : AbsClass(parent)
{

}

void DecoratorAbsClass::setClass(AbsClass *iClass)
{
    mAbsClass = iClass;
}

AbsClass *DecoratorAbsClass::getClass()
{
    return mAbsClass;
}
