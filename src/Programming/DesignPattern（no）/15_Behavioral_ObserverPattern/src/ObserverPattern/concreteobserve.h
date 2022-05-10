#ifndef CONCRETEOBSERVE_H
#define CONCRETEOBSERVE_H

#include <QObject>
#include "observe.h"

class ConcreteObserve : public Observe
{
    Q_OBJECT
public:
    explicit ConcreteObserve(QObject *parent = 0);

signals:

public slots:
    void update();
};

#endif // CONCRETEOBSERVE_H
