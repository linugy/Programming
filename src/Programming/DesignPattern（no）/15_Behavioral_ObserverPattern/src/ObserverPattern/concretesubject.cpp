#include "concretesubject.h"

ConcreteSubject::ConcreteSubject(QObject *parent) : Subject(parent)
{

}

void ConcreteSubject::addObserve(Observe *iObserve)
{
    mSubjectLst.append(iObserve);
}

void ConcreteSubject::removeObserve(Observe *iObserve)
{
    mSubjectLst.removeAt(mSubjectLst.indexOf(iObserve));
}

void ConcreteSubject::notify()
{
    for (Observe *sub : mSubjectLst) {
        sub->setState(getState());
        sub->update();
    }
}
