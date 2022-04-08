#include "subject.h"

Subject::Subject(QObject *parent) : QObject(parent)
{

}

void Subject::setState(const QString &iStr)
{
    mState = iStr;
}

QString Subject::getState()
{
    return mState;
}
