#include "productb.h"
#include <QDebug>

ProductB::ProductB(QObject *parent) : Product(parent)
{

}

void ProductB::run()
{
    qDebug() << "ProductB is run";
}
