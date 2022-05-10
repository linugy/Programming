#include "objectstructure.h"

ObjectStructure::ObjectStructure(QObject *parent) : QObject(parent)
{

}

void ObjectStructure::add(Element *iElement)
{
    mElementLst.append(iElement);
}

void ObjectStructure::accept(Visitor *iVisitor)
{
    for (int i = 0; i < mElementLst.length(); i++) {
        mElementLst.at(i)->accept(iVisitor);
    }
}
