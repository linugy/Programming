#include "factorya.h"
#include "producta.h"
#include "product2a.h"

FactoryA::FactoryA(QObject *parent) : Factory(parent)
{

}

Product *FactoryA::create()
{
    return new ProductA();
}

Product2 *FactoryA::create2()
{
    return new Product2A();
}
