#ifndef PRODUCTA_H
#define PRODUCTA_H

#include <QObject>
#include "product.h"

class ProductA : public Product
{
    Q_OBJECT
public:
    explicit ProductA(QObject *parent = 0);

signals:

public slots:
    void run();
};

#endif // PRODUCTA_H
