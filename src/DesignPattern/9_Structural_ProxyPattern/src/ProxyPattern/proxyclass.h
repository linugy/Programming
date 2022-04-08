#ifndef PROXYCLASS_H
#define PROXYCLASS_H

#include <QObject>
#include "absclass.h"
#include "subclass.h"

class ProxyClass : public AbsClass
{
    Q_OBJECT
public:
    explicit ProxyClass(QObject *parent = 0);

signals:

public slots:
    void run();

    void setSubClass(AbsClass *iPClass);

private:
    AbsClass *mSubClass = nullptr;
};

#endif // PROXYCLASS_H
