#ifndef SUBCLASS_H
#define SUBCLASS_H

#include <QObject>
#include "absclass.h"

class SubClass : public AbsClass
{
    Q_OBJECT
public:
    explicit SubClass(QObject *parent = 0);

signals:

public slots:
    void run();
};

#endif // SUBCLASS_H
