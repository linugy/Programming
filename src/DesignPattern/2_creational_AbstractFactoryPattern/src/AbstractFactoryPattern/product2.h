#ifndef PRODUCT2_H
#define PRODUCT2_H

#include <QObject>

class Product2 : public QObject
{
    Q_OBJECT
public:
    explicit Product2(QObject *parent = 0);

signals:

public slots:
    virtual void run() = 0;
};
#endif // PRODUCT2_H
