#ifndef VISITORB_H
#define VISITORB_H

#include <QObject>
#include "visitor.h"

class VisitorB : public Visitor
{
    Q_OBJECT
public:
    explicit VisitorB(QObject *parent = 0);

signals:

public slots:
    void visitElementeA(ElementA *iElementA);
    void visitElementeB(ElementB *iElementB);
};

#endif // VISITORB_H
