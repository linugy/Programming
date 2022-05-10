#ifndef CONCRETECOLLEAGUE1_H
#define CONCRETECOLLEAGUE1_H

#include <QObject>
#include "colleague.h"

class ConcreteColleague1 : public Colleague
{
    Q_OBJECT
public:
    explicit ConcreteColleague1(QObject *parent = 0);

signals:

public slots:
    void sendMessage(const QString &iStr);
    void reciveMessage(const QString &iStr);
};

#endif // CONCRETECOLLEAGUE1_H
