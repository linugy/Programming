#ifndef DIVEXPRESSION_H
#define DIVEXPRESSION_H

#include <QObject>
#include "expression.h"

class DivExpression : public Expression
{
    Q_OBJECT
public:
    explicit DivExpression(QObject *parent = 0);

signals:

public slots:
    int interpreter(Context *iContext);
};

#endif // DIVEXPRESSION_H
