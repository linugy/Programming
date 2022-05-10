#include "factoryb.h"
#include "productb.h"
#include "product2b.h"

FactoryB::FactoryB(QObject *parent) : Factory(parent)
{

}

Product *FactoryB::create()
{
    return new ProductB();
}

Product2 *FactoryB::create2()
{
    return new Product2B();
}
