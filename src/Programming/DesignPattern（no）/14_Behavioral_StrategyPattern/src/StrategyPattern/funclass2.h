#ifndef FUNCLASS2_H
#define FUNCLASS2_H

#include <QObject>
#include "absfunclass.h"

class FunClass2 : public AbsFunClass
{
    Q_OBJECT
public:
    explicit FunClass2(QObject *parent = 0);

signals:

public slots:
    void doFun();
};

#endif // FUNCLASS2_H
