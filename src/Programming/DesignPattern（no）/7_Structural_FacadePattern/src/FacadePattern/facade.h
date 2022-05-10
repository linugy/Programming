#ifndef FACADE_H
#define FACADE_H

#include <QObject>
#include "subsystema.h"
#include "subsystemb.h"
#include "subsystemc.h"

class Facade : public QObject
{
    Q_OBJECT
public:
    explicit Facade(QObject *parent = 0);

signals:

public slots:
    void run();

private:
    SubSystemA *mA;
    SubSystemB *mB;
    SubSystemC *mC;
};

#endif // FACADE_H
