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
    virtual void run() = 0;
};

#endif // ABSCLASS_H
