#ifndef FACTORY_H
#define FACTORY_H

#include <QObject>
#include "product.h"
#include "product2.h"

class Factory : public QObject
{
    Q_OBJECT
public:
    explicit Factory(QObject *parent = 0);

signals:

public slots:
    virtual Product *create() = 0;
    virtual Product2 *create2() = 0;
};
#endif // FACTORY_H
