#include "multiexpression.h"

MultiExpression::MultiExpression(QObject *parent) : Expression(parent)
{

}

int MultiExpression::interpreter(Context *iContext)
{
    return mLeft->interpreter(iContext) * mRight->interpreter(iContext);
}
