#include "component.h"
#include <QDebug>
#include <iostream>
using namespace std;

Component::Component(QObject *parent) : QObject(parent)
{

}

void Component::setName(const QString &iStr)
{
    mName = iStr;
}

QString Component::getName()
{
    return mName;
}

void Component::printName()
{
    cout << mName.toStdString() << endl;
}
