#ifndef SUBCLASSB1_H
#define SUBCLASSB1_H

#include <QObject>
#include "absclassb.h"

class SubClassB1 : public AbsClassB
{
    Q_OBJECT
public:
    explicit SubClassB1(QObject *parent = 0);

signals:

public slots:
    void exe();
};

#endif // SUBCLASSB1_H
