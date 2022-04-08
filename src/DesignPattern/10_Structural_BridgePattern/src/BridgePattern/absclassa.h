#ifndef ABSCLASSA_H
#define ABSCLASSA_H

#include <QObject>
#include "absclassb.h"

class AbsClassA : public QObject
{
    Q_OBJECT
public:
    explicit AbsClassA(QObject *parent = 0);

signals:

public slots:
    void setClass(AbsClassB *iPClass);
    AbsClassB* getClass();

    virtual void run() = 0;

private:
    AbsClassB *mAbsClassB = nullptr;
};

#endif // ABSCLASSA_H
