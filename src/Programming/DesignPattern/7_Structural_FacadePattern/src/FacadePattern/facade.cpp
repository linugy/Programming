#include "facade.h"

Facade::Facade(QObject *parent) : QObject(parent)
{
    mA = new SubSystemA();
    mB = new SubSystemB();
    mC = new SubSystemC();
}

void Facade::run()
{
    mA->runA();
    mB->runB();
    mC->runC();
}
