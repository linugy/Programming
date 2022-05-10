#include "elementa.h"

ElementA::ElementA(QObject *parent) : Element(parent)
{

}

void ElementA::accept(Visitor *iVisitor)
{
    iVisitor->visitElementeA(this);
}
