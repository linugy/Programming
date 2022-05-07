#include "expression.h"

Expression::Expression(QObject *parent) : QObject(parent)
{

}

void Expression::setLeft(Expression *iLeft)
{
    mLeft = iLeft;
}

void Expression::setRight(Expression *iRight)
{
    mRight = iRight;
}
