#ifndef FACTORYB_H
#define FACTORYB_H

#include <QObject>
#include "factory.h"

class FactoryB : public Factory
{
    Q_OBJECT
public:
    explicit FactoryB(QObject *parent = 0);

signals:

public slots:
    Product *create();
};

#endif // FACTORYB_H
