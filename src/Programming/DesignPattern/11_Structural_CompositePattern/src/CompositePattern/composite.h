#ifndef COMPOSITE_H
#define COMPOSITE_H

#include <QObject>
#include "component.h"

class Composite : public Component
{
    Q_OBJECT
public:
    explicit Composite(QObject *parent = 0);

signals:

public slots:
    void addChild(Component *iComponent);
    void removeChild(Component *iComponent);
    Component* getChild(int i);
    int getCount();

private:
    QList<Component *> mChildren;
};

#endif // COMPOSITE_H
