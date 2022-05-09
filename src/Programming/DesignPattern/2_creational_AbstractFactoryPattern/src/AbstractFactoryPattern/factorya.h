#ifndef FACTORYA_H
#define FACTORYA_H

#include <QObject>
#include "factory.h"
#include "product.h"
#include "product2.h"

class FactoryA : public Factory
{
    Q_OBJECT
public:
    explicit FactoryA(QObject *parent = 0);

signals:

public slots:
    Product *create();
    Product2 *create2();
};

#endif // FACTORYA_H
