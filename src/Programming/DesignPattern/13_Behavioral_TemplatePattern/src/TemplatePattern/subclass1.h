#ifndef SUBCLASS1_H
#define SUBCLASS1_H

#include <QObject>
#include "template.h"

class SubClass1 : public Template
{
    Q_OBJECT
public:
    explicit SubClass1(QObject *parent = 0);

signals:

public slots:
    void do1();
    void do2();
    void do3();
};

#endif // SUBCLASS1_H
