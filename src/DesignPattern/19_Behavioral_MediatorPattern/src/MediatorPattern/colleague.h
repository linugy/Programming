#ifndef COLLEAGUE_H
#define COLLEAGUE_H

#include <QObject>
#include "mediator.h"

class Mediator;
class Colleague : public QObject
{
    Q_OBJECT
public:
    explicit Colleague(QObject *parent = 0);

signals:

public slots:
    void setMediator(Mediator *iMediator);
    virtual void sendMessage(const QString &iStr) = 0;
    virtual void reciveMessage(const QString &iStr) = 0;

protected:
    Mediator *mMediator;
};

#endif // COLLEAGUE_H
