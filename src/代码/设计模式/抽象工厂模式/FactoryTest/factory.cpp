#include "factory.h"
#include <QDebug>

void ProductA::show()
{
    qDebug() << "A----show";
}

void ProductB::show()
{
    qDebug() << "B----show";
}


void ProductOtherA::showOther()
{
    qDebug() << "A----showOther";
}

void ProductOtherB::showOther()
{
    qDebug() << "B----showOther";
}

Product *FactoryA::createObj()
{
    return new ProductA();
}

ProductOther *FactoryA::createObjOther()
{
    return new ProductOtherA();
}

Product *FactoryB::createObj()
{
    return new ProductB();
}

ProductOther *FactoryB::createObjOther()
{
    return new ProductOtherB();
}
