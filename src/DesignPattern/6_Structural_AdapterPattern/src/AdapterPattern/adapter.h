#ifndef ADAPTER_H
#define ADAPTER_H

#include <QObject>
#include "target.h"
#include "adaptee.h"

class Adapter : public Target
{
    Q_OBJECT
public:
    explicit Adapter(QObject *parent = 0);
    Adapter(Adaptee *adaptee);

    void needRun();
signals:

public slots:

private:
    Adaptee *mAdaptee = nullptr;
};

#endif // ADAPTER_H
