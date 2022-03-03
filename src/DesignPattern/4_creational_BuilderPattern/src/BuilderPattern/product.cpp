#include "product.h"
#include <QDebug>

Product::Product(QObject *parent) : QObject(parent)
{

}

void Product::setPartA()
{
    name.append("A");
}

void Product::setPartB()
{
    name.append("B");
}

void Product::setPartC()
{
    name.append("C");
}

void Product::run()
{
    qDebug() << "===run===" << name;
}
