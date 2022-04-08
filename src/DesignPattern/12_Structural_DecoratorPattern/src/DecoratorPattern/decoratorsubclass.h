#ifndef DECORATORSUBCLASS_H
#define DECORATORSUBCLASS_H

#include <QObject>
#include "decoratorabsclass.h"

class DecoratorSubClass : public DecoratorAbsClass
{
    Q_OBJECT
public:
    explicit DecoratorSubClass(QObject *parent = 0);

signals:

public slots:
    QString getName();
};

#endif // DECORATORSUBCLASS_H
