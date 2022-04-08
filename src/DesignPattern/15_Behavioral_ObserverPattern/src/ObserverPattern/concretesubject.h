#ifndef CONCRETESUBJECT_H
#define CONCRETESUBJECT_H

#include <QObject>
#include "subject.h"
#include "observe.h"

class ConcreteSubject : public Subject
{
    Q_OBJECT
public:
    explicit ConcreteSubject(QObject *parent = 0);

signals:

public slots:
    void addObserve(Observe *iObserve);
    void removeObserve(Observe *iObserve);
    void notify();

private:
    QList<Observe *> mSubjectLst;
};

#endif // CONCRETESUBJECT_H
