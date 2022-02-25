#ifndef PRODUCTB_H
#define PRODUCTB_H

#include <QObject>
#include "product.h"

class ProductB : public Product
{
    Q_OBJECT
public:
    explicit ProductB(QObject *parent = 0);

signals:

public slots:
    void run();
};

#endif // PRODUCTB_H
