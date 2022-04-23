#ifndef CONCRETECOLLEAGUE2_H
#define CONCRETECOLLEAGUE2_H

#include <QObject>
#include "colleague.h"

class ConcreteColleague2 : public Colleague
{
    Q_OBJECT
public:
    explicit ConcreteColleague2(QObject *parent = 0);

signals:

public slots:
    void sendMessage(const QString &iStr);
    void reciveMessage(const QString &iStr);
};

#endif // CONCRETECOLLEAGUE2_H
