#include "observe.h"

Observe::Observe(QObject *parent) : QObject(parent)
{

}

void Observe::setState(const QString &iStr)
{
    mState = iStr;
}

QString Observe::getState()
{
    return mState;
}
