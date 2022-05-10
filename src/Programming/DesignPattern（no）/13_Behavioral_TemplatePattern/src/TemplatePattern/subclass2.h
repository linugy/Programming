#ifndef SUBCLASS2_H
#define SUBCLASS2_H

#include <QObject>
#include "template.h"

class SubClass2 : public Template
{
    Q_OBJECT
public:
    explicit SubClass2(QObject *parent = 0);

signals:

public slots:
    void do1();
    void do2();
    void do3();
};

#endif // SUBCLASS2_H
