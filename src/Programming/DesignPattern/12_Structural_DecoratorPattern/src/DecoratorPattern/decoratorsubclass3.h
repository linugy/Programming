#ifndef DECORATORSUBCLASS3_H
#define DECORATORSUBCLASS3_H

#include <QObject>
#include "decoratorabsclass.h"

class DecoratorSubClass3 : public DecoratorAbsClass
{
    Q_OBJECT
public:
    explicit DecoratorSubClass3(QObject *parent = 0);

signals:

public slots:
    QString getName();
};

#endif // DECORATORSUBCLASS3_H
