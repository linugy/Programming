#ifndef ELEMENTB_H
#define ELEMENTB_H

#include <QObject>
#include "element.h"
#include "visitor.h"

class ElementB : public Element
{
    Q_OBJECT
public:
    explicit ElementB(QObject *parent = 0);

signals:

public slots:
    void accept(Visitor *iVisitor);
};

#endif // ELEMENTB_H
