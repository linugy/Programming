#include "termimalexpression.h"

TermimalExpression::TermimalExpression(QObject *parent) : Expression(parent)
{

}

int TermimalExpression::interpreter(Context *iContext)
{
    return mValue;
}

void TermimalExpression::setValue(int iValue)
{
    mValue = iValue;
}
