#ifndef OBJECTSTRUCTURE_H
#define OBJECTSTRUCTURE_H

#include <QObject>
#include "element.h"
#include "visitor.h"

class ObjectStructure : public QObject
{
    Q_OBJECT
public:
    explicit ObjectStructure(QObject *parent = 0);

signals:

public slots:
    void add(Element *iElement);
    void accept(Visitor *iVisitor);

private:
    QList<Element *> mElementLst;
};

#endif // OBJECTSTRUCTURE_H
