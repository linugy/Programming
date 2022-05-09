#include "receive.h"
#include <QDebug>

Receive::Receive(QObject *parent) : QObject(parent)
{

}

void Receive::run()
{
    qDebug() << "Receive::run";
}
