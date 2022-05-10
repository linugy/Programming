#include "visitorb.h"
#include <QDebug>

VisitorB::VisitorB(QObject *parent) : Visitor(parent)
{

}

void VisitorB::visitElementeA(ElementA *iElementA)
{
    qDebug() << "VisitorB iElementA";
}

void VisitorB::visitElementeB(ElementB *iElementB)
{
    qDebug() << "VisitorB iElementB";
}
