#include "singleton.h"
#include <QDebug>

Singleton::Singleton(QObject *parent) : QObject(parent)
{

}

Singleton &Singleton::instance()
{
    static Singleton i;
    return i;
}

void Singleton::run()
{
    qDebug() << "=====run====";
}
