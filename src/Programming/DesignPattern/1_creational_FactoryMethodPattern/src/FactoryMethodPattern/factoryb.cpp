#include "factoryb.h"
#include "productb.h"

FactoryB::FactoryB(QObject *parent) : Factory(parent)
{

}

Product *FactoryB::create()
{
    return new ProductB();
}
