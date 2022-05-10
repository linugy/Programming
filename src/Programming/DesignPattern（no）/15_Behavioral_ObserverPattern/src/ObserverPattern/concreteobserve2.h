#ifndef CONCRETEOBSERVE2_H
#define CONCRETEOBSERVE2_H

#include <QObject>
#include "observe.h"

class ConcreteObserve2 : public Observe
{
    Q_OBJECT
public:
    explicit ConcreteObserve2(QObject *parent = 0);

signals:

public slots:
    void update();
};

#endif // CONCRETEOBSERVE2_H
