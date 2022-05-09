#include "memento.h"

Memento::Memento(QObject *parent) : QObject(parent)
{

}

void Memento::setName(const QString &iName)
{
    mName = iName;
}

void Memento::setAttack(int iValue)
{
    mAttack = iValue;
}

void Memento::setDefend(int iDefend)
{
    mDefend = iDefend;
}

QString Memento::getName()
{
    return mName;
}

int Memento::getAttack()
{
    return mAttack;
}

int Memento::getDefend()
{
    return mDefend;
}
