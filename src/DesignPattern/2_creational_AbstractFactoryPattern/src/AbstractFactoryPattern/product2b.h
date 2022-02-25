#ifndef PRODUCT2B_H
#define PRODUCT2B_H

#include <QObject>
#include "product2.h"

class Product2B : public Product2
{
    Q_OBJECT
public:
    explicit Product2B(QObject *parent = 0);

signals:

public slots:
    void run();
};

#endif // PRODUCT2B_H
