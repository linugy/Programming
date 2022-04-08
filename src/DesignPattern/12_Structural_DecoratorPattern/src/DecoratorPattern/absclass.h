#ifndef ABSCLASS_H
#define ABSCLASS_H

#include <QObject>

class AbsClass : public QObject
{
    Q_OBJECT
public:
    explicit AbsClass(QObject *parent = 0);

signals:

public slots:
    virtual QString getName() = 0;
    void printInfo();
};

#endif // ABSCLASS_H
