#include "subclass2.h"
#include "funclass2.h"

SubClass2::SubClass2(QObject *parent) : AbsClass(parent)
{
    setFun(new FunClass2());
}
