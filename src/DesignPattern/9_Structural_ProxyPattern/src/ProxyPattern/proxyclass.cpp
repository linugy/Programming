#include "proxyclass.h"
#include <QDebug>

ProxyClass::ProxyClass(QObject *parent) : AbsClass(parent)
{

}

void ProxyClass::run()
{
    qDebug() << "ProxyClass is run";
    if (mSubClass != nullptr) {
        mSubClass->run();
    }
}

void ProxyClass::setSubClass(AbsClass *iPClass)
{
    mSubClass = iPClass;
}
