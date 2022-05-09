#include "absclass.h"

AbsClass::AbsClass(QObject *parent) : QObject(parent)
{

}

void AbsClass::run()
{
    if (mAbsFunClass != nullptr) {
        mAbsFunClass->doFun();
    }
}

void AbsClass::setFun(AbsFunClass *iFun)
{
    mAbsFunClass = iFun;
}
