#ifndef PRODUCT2A_H
#define PRODUCT2A_H

#include <QObject>
#include "product2.h"

class Product2A : public Product2
{
    Q_OBJECT
public:
    explicit Product2A(QObject *parent = 0);

signals:

public slots:
    void run();
};

#endif // PRODUCT2A_H
