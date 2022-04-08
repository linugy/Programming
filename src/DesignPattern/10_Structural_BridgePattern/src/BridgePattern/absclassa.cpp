#include "absclassa.h"

AbsClassA::AbsClassA(QObject *parent) : QObject(parent)
{

}

void AbsClassA::setClass(AbsClassB *iPClass)
{
    mAbsClassB = iPClass;
}

AbsClassB *AbsClassA::getClass()
{
    return mAbsClassB;
}
