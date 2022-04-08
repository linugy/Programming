#include "subclass1.h"
#include "funclass1.h"

SubClass1::SubClass1(QObject *parent) : AbsClass(parent)
{
    setFun(new FunClass1());
}

