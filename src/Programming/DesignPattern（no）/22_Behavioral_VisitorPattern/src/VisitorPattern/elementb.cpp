#include "elementb.h"

ElementB::ElementB(QObject *parent) : Element(parent)
{

}

void ElementB::accept(Visitor *iVisitor)
{
    iVisitor->visitElementeB(this);
}
