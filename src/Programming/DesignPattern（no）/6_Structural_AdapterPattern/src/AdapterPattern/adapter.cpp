#include "adapter.h"
#include <QDebug>

Adapter::Adapter(QObject *parent) : Target(parent)
{

}

Adapter::Adapter(Adaptee *adaptee)
{
    mAdaptee = adaptee;
}

void Adapter::needRun()
{
    qDebug() << "Adapter::needRun";

    if (mAdaptee) {
        mAdaptee->run();
    }
}
