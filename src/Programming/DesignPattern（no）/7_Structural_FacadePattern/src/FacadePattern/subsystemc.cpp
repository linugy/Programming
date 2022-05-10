#include "subsystemc.h"
#include <QDebug>

SubSystemC::SubSystemC(QObject *parent) : QObject(parent)
{

}

void SubSystemC::runC()
{
    qDebug() << "==runC===";
}
