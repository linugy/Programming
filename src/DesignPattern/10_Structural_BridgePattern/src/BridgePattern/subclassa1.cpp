#include "subclassa1.h"
#include <QDebug>

SubClassA1::SubClassA1(QObject *parent) : AbsClassA(parent)
{

}

void SubClassA1::run()
{
    qDebug() << "SubClassA1 run";
    getClass()->exe();
}
