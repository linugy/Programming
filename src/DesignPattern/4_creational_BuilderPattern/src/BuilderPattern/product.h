#ifndef PRODUCT_H
#define PRODUCT_H

#include <QObject>

class Product : public QObject
{
    Q_OBJECT
public:
    explicit Product(QObject *parent = 0);

signals:

public slots:
    void setPartA();
    void setPartB();
    void setPartC();

    void run();

private:
    QString name;
};

#endif // PRODUCT_H
