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

Product *Factory::createObj(int type)
{
    if (type == 1) {
        return new ProductA();
    } else if (type == 2) {
        return new ProductB();
    } else {
        return nullptr;
    }
}
