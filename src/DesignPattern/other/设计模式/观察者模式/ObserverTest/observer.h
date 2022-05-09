#ifndef OBSERVER_H
#define OBSERVER_H

#include <QObject>

class Observer;

// 被观察者基类
class Object
{
public:
    virtual void addObserver(Observer *) = 0;
    virtual void deleteObserver(Observer *) = 0;
    virtual void notify() = 0;
    virtual void setState(int) = 0;
};

// 被观察者子类
class ObjectA : public Object
{
public:
    void addObserver(Observer *iObserver);
    void deleteObserver(Observer *iObserver);
    void notify();
    void setState(int state);

private:
    int mState;
    QList<Observer *> mObserverLst;

};

//---------------------------------

// 观察者基类
class Observer
{
public:
    virtual void update() = 0;
};

// 观察者子类
class ObserverA : public Observer
{
public:
    void update();
};

class ObserverB : public Observer
{
public:
    void update();
};


#endif // OBSERVER_H
