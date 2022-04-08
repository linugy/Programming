#ifndef FUNCLASS1_H
#define FUNCLASS1_H

#include <QObject>
#include "absfunclass.h"

class FunClass1 : public AbsFunClass
{
    Q_OBJECT
public:
    explicit FunClass1(QObject *parent = 0);

signals:

public slots:
    void doFun();
};

#endif // FUNCLASS1_H
