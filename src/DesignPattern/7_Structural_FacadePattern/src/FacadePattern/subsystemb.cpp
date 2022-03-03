#include "subsystemb.h"
#include <QDebug>

SubSystemB::SubSystemB(QObject *parent) : QObject(parent)
{

}

void SubSystemB::runB()
{
    qDebug() << "==runB===";
}
