#ifndef BUILDER_H
#define BUILDER_H

#include <QWidget>
#include "product.h"

class Builder : public QWidget
{
    Q_OBJECT
public:
    explicit Builder(QWidget *parent = 0);

signals:

public slots:
    void buildPartA();
    void buildPartB();
    void buildPartC();

    void setProduct(Product *product);
    Product *getProduct();

private:
    Product *mProduct = nullptr;
};

#endif // BUILDER_H
