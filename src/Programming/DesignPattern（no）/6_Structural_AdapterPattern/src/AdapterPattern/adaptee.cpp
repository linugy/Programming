#include "adaptee.h"
#include <QDebug>

Adaptee::Adaptee(QObject *parent) : QObject(parent)
{

}

void Adaptee::run()
{
    qDebug() << "Adaptee::run";
}
