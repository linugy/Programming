#include "product2a.h"
#include <QDebug>

Product2A::Product2A(QObject *parent) : Product2(parent)
{

}

void Product2A::run()
{
    qDebug() << "Product2A is run";
}
