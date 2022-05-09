#ifndef SUBCLASS1_H
#define SUBCLASS1_H

#include <QObject>
#include "absclass.h"

class SubClass1 : public AbsClass
{
    Q_OBJECT
public:
    explicit SubClass1(QObject *parent = 0);

signals:

public slots:
};

#endif // SUBCLASS1_H
