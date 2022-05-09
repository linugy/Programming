#include "divexpression.h"

DivExpression::DivExpression(QObject *parent) : Expression(parent)
{

}

int DivExpression::interpreter(Context *iContext)
{
    if (mRight->interpreter(iContext) == 0) {
        return 0;
    }

    return mLeft->interpreter(iContext) / mRight->interpreter(iContext);
}
