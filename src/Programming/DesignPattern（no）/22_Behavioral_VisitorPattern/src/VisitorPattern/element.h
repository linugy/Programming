#ifndef ELEMENT_H
#define ELEMENT_H

#include <QObject>
#include "visitor.h"

class Element : public QObject
{
    Q_OBJECT
public:
    explicit Element(QObject *parent = 0);

signals:

public slots:
   virtual void accept(Visitor *iVisitor) = 0;
};

#endif // ELEMENT_H
