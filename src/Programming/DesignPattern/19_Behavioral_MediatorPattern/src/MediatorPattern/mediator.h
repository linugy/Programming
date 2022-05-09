#ifndef MEDIATOR_H
#define MEDIATOR_H

#include <QObject>
#include "colleague.h"

class Colleague;
class Mediator : public QObject
{
    Q_OBJECT
public:
    explicit Mediator(QObject *parent = 0);

signals:

public slots:
    virtual void send(Colleague *iColleague, const QString &iStr)  = 0;
};

#endif // MEDIATOR_H
