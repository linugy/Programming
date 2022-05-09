#include "concreteobserve2.h"
#include <QDebug>

ConcreteObserve2::ConcreteObserve2(QObject *parent) : Observe(parent)
{

}

void ConcreteObserve2::update()
{
    qDebug() << "ConcreteObserve2" << getState();
}
