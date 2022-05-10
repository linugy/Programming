#ifndef DECORATORABSCLASS_H
#define DECORATORABSCLASS_H

#include <QObject>
#include "absclass.h"

class DecoratorAbsClass : public AbsClass
{
    Q_OBJECT
public:
    explicit DecoratorAbsClass(QObject *parent = 0);

signals:

public slots:
    void setClass(AbsClass *iClass);
    AbsClass *getClass();

    virtual QString getName() = 0;

private:
    AbsClass *mAbsClass = nullptr;
};

#endif // DECORATORABSCLASS_H
