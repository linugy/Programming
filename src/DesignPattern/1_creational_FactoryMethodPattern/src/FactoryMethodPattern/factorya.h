#ifndef FACTORYA_H
#define FACTORYA_H

#include <QObject>
#include "factory.h"

class FactoryA : public Factory
{
    Q_OBJECT
public:
    explicit FactoryA(QObject *parent = 0);

signals:

public slots:
    Product *create();
};

#endif // FACTORYA_H
