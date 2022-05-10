#include "concretecolleague2.h"
#include <QDebug>

ConcreteColleague2::ConcreteColleague2(QObject *parent) : Colleague(parent)
{

}

void ConcreteColleague2::sendMessage(const QString &iStr)
{
    qDebug() << "===ConcreteColleague2::sendMessage==" << iStr;
    mMediator->send(this, iStr);
}

void ConcreteColleague2::reciveMessage(const QString &iStr)
{
    qDebug() << "===ConcreteColleague2::reciveMessage==" << iStr;
}
