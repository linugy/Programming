#include "concretecolleague1.h"
#include <QDebug>

ConcreteColleague1::ConcreteColleague1(QObject *parent) : Colleague(parent)
{

}

void ConcreteColleague1::sendMessage(const QString &iStr)
{
    qDebug() << "===ConcreteColleague1::sendMessage==" << iStr;
    mMediator->send(this, iStr);
}

void ConcreteColleague1::reciveMessage(const QString &iStr)
{
    qDebug() << "===ConcreteColleague1::reciveMessage==" << iStr;
}
