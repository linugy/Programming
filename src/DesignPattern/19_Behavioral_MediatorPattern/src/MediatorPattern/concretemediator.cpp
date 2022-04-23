#include "concretemediator.h"

ConcreteMediator::ConcreteMediator(QObject *parent) : Mediator(parent)
{

}

void ConcreteMediator::send(Colleague *iColleague, const QString &iStr)
{
    if (ConcreteColleague1 *tmp = qobject_cast<ConcreteColleague1 *>(iColleague)) {
        if (mConcreteColleague2) {
            mConcreteColleague2->reciveMessage(iStr);
        }
    } else if (ConcreteColleague2 *tmp = qobject_cast<ConcreteColleague2 *>(iColleague)) {
        if (mConcreteColleague1) {
            mConcreteColleague1->reciveMessage(iStr);
        }
    }
}

void ConcreteMediator::setConcreteColleague1(ConcreteColleague1 *iConcreteColleague1)
{
    mConcreteColleague1 = iConcreteColleague1;
}

void ConcreteMediator::setConcreteColleague2(ConcreteColleague2 *iConcreteColleague2)
{
    mConcreteColleague2 = iConcreteColleague2;
}
