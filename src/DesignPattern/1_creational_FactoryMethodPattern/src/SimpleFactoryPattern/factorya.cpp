#include "factorya.h"
#include "producta.h"

FactoryA::FactoryA(QObject *parent) : Factory(parent)
{

}

Product *FactoryA::create()
{
    return new ProductA();
}
