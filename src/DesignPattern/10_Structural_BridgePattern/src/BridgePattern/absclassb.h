#ifndef ABSCLASSB_H
#define ABSCLASSB_H

#include <QObject>

class AbsClassB : public QObject
{
    Q_OBJECT
public:
    explicit AbsClassB(QObject *parent = 0);

signals:

public slots:
    virtual void exe() = 0;
};

#endif // ABSCLASSB_H
