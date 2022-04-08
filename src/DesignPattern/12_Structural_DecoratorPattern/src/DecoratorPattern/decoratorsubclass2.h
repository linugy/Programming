#ifndef DECORATORSUBCLASS2_H
#define DECORATORSUBCLASS2_H

#include <QObject>
#include "decoratorabsclass.h"

class DecoratorSubClass2 : public DecoratorAbsClass
{
    Q_OBJECT
public:
    explicit DecoratorSubClass2(QObject *parent = 0);

signals:

public slots:
    QString getName();
};

#endif // DECORATORSUBCLASS2_H
