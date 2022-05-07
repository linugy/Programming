#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <QObject>
#include "context.h"

class Expression : public QObject
{
    Q_OBJECT
public:
    explicit Expression(QObject *parent = 0);

signals:

public slots:
    void setLeft(Expression *iLeft);
    void setRight(Expression *iRight);

    virtual int interpreter(Context *iContext) = 0;

protected:
    Expression *mLeft;
    Expression *mRight;
};

#endif // EXPRESSION_H
