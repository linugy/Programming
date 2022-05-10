#include "context.h"

Context::Context(QObject *parent) : QObject(parent)
{
    init();
}

int Context::getValue(const QString &iStr)
{
    if (mValueMap.contains(iStr)) {
        return mValueMap.value(iStr);
    }
    return 0;
}

void Context::init()
{
    mValueMap.insert("value_1", 1);
    mValueMap.insert("value_2", 2);
    mValueMap.insert("value_3", 3);
    mValueMap.insert("value_4", 4);
}
