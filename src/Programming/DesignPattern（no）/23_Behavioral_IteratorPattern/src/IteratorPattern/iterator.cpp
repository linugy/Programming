#include "iterator.h"
#include "aggregate.h"

Iterator::Iterator(QObject *parent, Aggregate *iAggregate) : QObject(parent)
{
    mAggregate = iAggregate;
}

bool Iterator::isEnd()
{
    if (mCurrentIndex >= mAggregate->count()) {
        return true;
    }
    return false;
}

QString Iterator::next()
{
    mCurrentIndex++;
    if (mCurrentIndex < mAggregate->count()) {
        return mAggregate->getValue(mCurrentIndex);
    }
    return QString();
}

QString Iterator::getValue()
{
    return mAggregate->getValue(mCurrentIndex);
}
