#ifndef LEAF_H
#define LEAF_H

#include <QObject>
#include "component.h"

class Leaf : public Component
{
    Q_OBJECT
public:
    explicit Leaf(QObject *parent = 0);

signals:

public slots:
    void addChild(Component *iComponent);
    void removeChild(Component *iComponent);
    Component* getChild(int i);
    int getCount();
};

#endif // LEAF_H
