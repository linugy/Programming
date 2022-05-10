#include "subsystema.h"
#include <QDebug>

SubSystemA::SubSystemA(QObject *parent) : QObject(parent)
{

}

void SubSystemA::runA()
{
    qDebug() << "==runA===";
}
