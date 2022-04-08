#ifndef SUBCLASS2_H
#define SUBCLASS2_H

#include <QObject>
#include "absclass.h"

class SubClass2 : public AbsClass
{
    Q_OBJECT
public:
    explicit SubClass2(QObject *parent = 0);

signals:

public slots:
};

#endif // SUBCLASS2_H
