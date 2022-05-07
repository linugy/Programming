#ifndef MULTIEXPRESSION_H
#define MULTIEXPRESSION_H

#include <QObject>
#include "expression.h"

class MultiExpression : public Expression
{
    Q_OBJECT
public:
    explicit MultiExpression(QObject *parent = 0);

signals:

public slots:
    int interpreter(Context *iContext);
};

#endif // MULTIEXPRESSION_H
