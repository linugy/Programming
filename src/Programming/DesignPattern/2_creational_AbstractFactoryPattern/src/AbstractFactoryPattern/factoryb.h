#ifndef FACTORYB_H
#define FACTORYB_H

#include <QObject>
#include "factory.h"
#include "product.h"
#include "product2.h"

class FactoryB : public Factory
{
    Q_OBJECT
public:
    explicit FactoryB(QObject *parent = 0);

signals:

public slots:
    Product *create();
    Product2 *create2();
};

#endif // FACTORYB_H
