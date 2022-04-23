#include "manager.h"

Manager::Manager(QObject *parent) : QObject(parent)
{

}

void Manager::save(Memento *iMemento)
{
    mLst.append(iMemento);
}

Memento* Manager::load()
{
    return mLst.first();
}
