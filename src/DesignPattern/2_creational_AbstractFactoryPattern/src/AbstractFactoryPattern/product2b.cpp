#include "product2b.h"
#include <QDebug>

Product2B::Product2B(QObject *parent) : Product2(parent)
{

}

void Product2B::run()
{
    qDebug() << "Product2B is run";
}
