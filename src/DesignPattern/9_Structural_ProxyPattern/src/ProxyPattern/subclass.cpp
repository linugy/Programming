#include "subclass.h"
#include <QDebug>

SubClass::SubClass(QObject *parent) : AbsClass(parent)
{

}

void SubClass::run()
{
    qDebug() << "SubClass is run";
}
