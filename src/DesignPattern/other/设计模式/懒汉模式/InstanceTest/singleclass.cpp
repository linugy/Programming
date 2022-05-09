#include "singleclass.h"
#include <QDebug>

SingleClass *SingleClass::instance()
{
    static SingleClass instance;
    return &instance;
}

SingleClass::~SingleClass()
{
    qDebug() << "-----destory-------";
}

void SingleClass::test()
{
    qDebug() << "---test-----";
}

SingleClass::SingleClass(QObject *parent) : QObject(parent)
{
    qDebug() << "-----constuct-------";
}
