#include "observer.h"
#include <QDebug>


void ObjectA::addObserver(Observer *iObserver)
{
    mObserverLst.append(iObserver);
}

void ObjectA::deleteObserver(Observer *iObserver)
{
    mObserverLst.removeOne(iObserver);
}

void ObjectA::notify()
{
    for (Observer *obs : mObserverLst) {
        obs->update();
    }
}

void ObjectA::setState(int state)
{
    mState = state;
    notify();
}

void ObserverA::update()
{
    qDebug() << "--observerA---";
}

void ObserverB::update()
{
    qDebug() << "--observerB---";
}
