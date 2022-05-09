#ifndef ELEMENTA_H
#define ELEMENTA_H

#include <QObject>
#include "element.h"
#include "visitor.h"

class ElementA : public Element
{
    Q_OBJECT
public:
    explicit ElementA(QObject *parent = 0);

signals:

public slots:
    void accept(Visitor *iVisitor);
};

#endif // ELEMENTA_H
