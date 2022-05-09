#ifndef CONCRETESTATE1_H
#define CONCRETESTATE1_H

#include <QObject>
#include "state.h"

class ConcreteState1 : public State
{
    Q_OBJECT
public:
    explicit ConcreteState1(QObject *parent = 0);

signals:

public slots:
    void run();
};

#endif // CONCRETESTATE1_H
