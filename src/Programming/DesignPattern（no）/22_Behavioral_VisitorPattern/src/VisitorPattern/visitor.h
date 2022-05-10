#ifndef VISITOR_H
#define VISITOR_H

#include <QObject>
// 注意：这里放开会导致编译错误，只能使用类的前置声明
//#include "elementa.h"
//#include "elementb.h"

class ElementA;
class ElementB;
class Visitor : public QObject
{
    Q_OBJECT
public:
    explicit Visitor(QObject *parent = 0);

signals:

public slots:
    virtual void visitElementeA(ElementA *iElementA) = 0;
    virtual void visitElementeB(ElementB *iElementB) = 0;
};

#endif // VISITOR_H
