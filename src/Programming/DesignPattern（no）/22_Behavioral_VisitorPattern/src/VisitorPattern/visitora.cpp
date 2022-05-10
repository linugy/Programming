#include "visitora.h"
#include <QDebug>

VisitorA::VisitorA(QObject *parent) : Visitor(parent)
{

}

void VisitorA::visitElementeA(ElementA *iElementA)
{
    qDebug() << "VisitorA iElementA";
}

void VisitorA::visitElementeB(ElementB *iElementB)
{
    qDebug() << "VisitorA iElementB";
}
