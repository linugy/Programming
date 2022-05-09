#ifndef SUBCLASSA1_H
#define SUBCLASSA1_H

#include <QObject>
#include "absclassa.h"

class SubClassA1 : public AbsClassA
{
    Q_OBJECT
public:
    explicit SubClassA1(QObject *parent = 0);

signals:

public slots:
    void run();
};

#endif // SUBCLASSA1_H
