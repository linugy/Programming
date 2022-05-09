#include "aggregate.h"

Aggregate::Aggregate(QObject *parent) : QObject(parent)
{

}

void Aggregate::append(const QString &iStr)
{
    mLst.append(iStr);
}

QString Aggregate::getValue(int iIndex)
{
    return mLst.at(iIndex).toString();
}

int Aggregate::count()
{
    return mLst.length();
}

Iterator *Aggregate::createIterator()
{
    if (mIterator == nullptr) {
        mIterator = new Iterator(new QObject(), this);
    }
    return mIterator;
}
