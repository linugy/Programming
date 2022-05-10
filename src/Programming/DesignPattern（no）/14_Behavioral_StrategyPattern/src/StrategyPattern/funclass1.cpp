#include "funclass1.h"
#include <QDebug>

FunClass1::FunClass1(QObject *parent) : AbsFunClass(parent)
{

}

void FunClass1::doFun()
{
    qDebug() << "do fun 1";
}
