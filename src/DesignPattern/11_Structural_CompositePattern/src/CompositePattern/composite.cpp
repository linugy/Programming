#include "composite.h"

Composite::Composite(QObject *parent) : Component(parent)
{

}

void Composite::addChild(Component *iComponent)
{
    mChildren.append(iComponent);
}

void Composite::removeChild(Component *iComponent)
{
    mChildren.removeAt(mChildren.indexOf(iComponent));
}

Component *Composite::getChild(int i)
{
    return mChildren.at(i);
}

int Composite::getCount()
{
    return mChildren.length();
}
