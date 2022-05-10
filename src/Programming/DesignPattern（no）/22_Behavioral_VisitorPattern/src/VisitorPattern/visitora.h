#ifndef VISITORA_H
#define VISITORA_H

#include <QObject>
#include "visitor.h"

class VisitorA : public Visitor
{
    Q_OBJECT
public:
    explicit VisitorA(QObject *parent = 0);

signals:

public slots:
    void visitElementeA(ElementA *iElementA);
    void visitElementeB(ElementB *iElementB);
};

#endif // VISITORA_H
