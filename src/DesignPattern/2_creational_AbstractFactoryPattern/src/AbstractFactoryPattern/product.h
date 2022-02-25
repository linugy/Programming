#ifndef PRODUCT_H
#define PRODUCT_H

#include <QObject>

class Product : public QObject
{
    Q_OBJECT
public:
    explicit Product(QObject *parent = 0);

signals:

public slots:
    virtual void run() = 0;
};

#endif // PRODUCT_H
