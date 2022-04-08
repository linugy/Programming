#include "concreteobserve.h"
#include <QDebug>

ConcreteObserve::ConcreteObserve(QObject *parent) : Observe(parent)
{

}

void ConcreteObserve::update()
{
    qDebug() << "ConcreteObserve1" << getState();
}
