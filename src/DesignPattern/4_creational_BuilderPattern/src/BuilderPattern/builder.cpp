#include "builder.h"

Builder::Builder(QWidget *parent) : QWidget(parent)
{

}

void Builder::buildPartA()
{
    mProduct->setPartA();
}

void Builder::buildPartB()
{
    mProduct->setPartB();
}

void Builder::buildPartC()
{
    mProduct->setPartC();
}

void Builder::setProduct(Product *product)
{
    mProduct = product;
}

Product *Builder::getProduct()
{
    return mProduct;
}
