#include "director.h"
#include "product.h"

Director::Director(QWidget *parent) : QWidget(parent)
{

}

void Director::build()
{
    if (mBuilder == nullptr) {
        return;
    }

    mBuilder->buildPartA();
    mBuilder->buildPartB();
    mBuilder->buildPartC();

    Product *product = mBuilder->getProduct();
    product->run();

}

void Director::setBuilder(Builder *builder)
{
    mBuilder = builder;
}
