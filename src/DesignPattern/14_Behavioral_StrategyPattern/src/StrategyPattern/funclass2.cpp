#include "funclass2.h"
#include <QDebug>

FunClass2::FunClass2(QObject *parent) : AbsFunClass(parent)
{

}

void FunClass2::doFun()
{
    qDebug() << "do fun 2";
}
