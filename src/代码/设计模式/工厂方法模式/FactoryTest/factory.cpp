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

Product *FactoryA::createObj()
{
    return new ProductA();
}

Product *FactoryB::createObj()
{
    return new ProductB();
}
