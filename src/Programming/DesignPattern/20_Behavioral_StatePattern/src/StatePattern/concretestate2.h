#ifndef CONCRETESTATE2_H
#define CONCRETESTATE2_H

#include <QObject>
#include "state.h"

class ConcreteState2 : public State
{
    Q_OBJECT
public:
    explicit ConcreteState2(QObject *parent = 0);

signals:

public slots:
    void run();
};

#endif // CONCRETESTATE2_H
