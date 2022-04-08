#ifndef ABSFUNCLASS_H
#define ABSFUNCLASS_H

#include <QObject>

class AbsFunClass : public QObject
{
    Q_OBJECT
public:
    explicit AbsFunClass(QObject *parent = 0);

signals:

public slots:
    virtual void doFun() = 0;
};

#endif // ABSFUNCLASS_H
