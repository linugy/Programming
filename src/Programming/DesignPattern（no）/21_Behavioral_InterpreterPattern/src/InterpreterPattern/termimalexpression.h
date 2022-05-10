#ifndef TERMIMALEXPRESSION_H
#define TERMIMALEXPRESSION_H

#include <QObject>
#include "expression.h"

class TermimalExpression : public Expression
{
    Q_OBJECT
public:
    explicit TermimalExpression(QObject *parent = 0);

signals:

public slots:
    int interpreter(Context *iContext);
    void setValue(int iValue);

private:
    int mValue;
};

#endif // TERMIMALEXPRESSION_H
