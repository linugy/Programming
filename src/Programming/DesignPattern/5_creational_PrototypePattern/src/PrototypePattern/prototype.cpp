#include "prototype.h"

Prototype::Prototype(QObject *parent) : QObject(parent)
{

}

Prototype *Prototype::clone()
{
    Prototype *tmp = new Prototype();
    tmp->setName(this->getName());
    tmp->setId(this->getId());

    return tmp;
}

void Prototype::setName(const QString &name)
{
    mName = name;
}

void Prototype::setId(const QString &id)
{
    mId = id;
}

QString Prototype::getName()
{
    return mName;
}

QString Prototype::getId()
{
    return mId;
}
