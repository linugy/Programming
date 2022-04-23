#ifndef CONCRETEMEDIATOR_H
#define CONCRETEMEDIATOR_H

#include <QObject>
#include "mediator.h"
#include "concretecolleague1.h"
#include "concretecolleague2.h"

class ConcreteMediator : public Mediator
{
    Q_OBJECT
public:
    explicit ConcreteMediator(QObject *parent = 0);

signals:

public slots:
    void send(Colleague *iColleague, const QString &iStr);
    void setConcreteColleague1(ConcreteColleague1 *iConcreteColleague1);
    void setConcreteColleague2(ConcreteColleague2 *iConcreteColleague2);

private:
    ConcreteColleague1 *mConcreteColleague1;
    ConcreteColleague2 *mConcreteColleague2;
};

#endif // CONCRETEMEDIATOR_H
