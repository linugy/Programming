#include "role.h"

Role::Role(QObject *parent) : QObject(parent)
{
    mMemento = new Memento();
}

void Role::setName(const QString &iName)
{
    mName = iName;
}

void Role::setAttack(int iValue)
{
    mAttack = iValue;
}

void Role::setDefend(int iDefend)
{
    mDefend = iDefend;
}

QString Role::getName()
{
    return mName;
}

int Role::getAttack()
{
    return mAttack;
}

int Role::getDefend()
{
    return mDefend;
}

Memento* Role::save()
{
    mMemento->setAttack(getAttack());
    mMemento->setDefend(getDefend());
    mMemento->setName(getName());
    return mMemento;
}

void Role::load(Memento *iMemento)
{
    mMemento = iMemento;
    setAttack(mMemento->getAttack());
    setDefend(mMemento->getDefend());
    setName(mMemento->getName());
}
