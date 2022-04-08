#include "subclassb1.h"
#include <QDebug>

SubClassB1::SubClassB1(QObject *parent) : AbsClassB(parent)
{

}

void SubClassB1::exe()
{
    qDebug() << "SubClassB1 exe";
}
