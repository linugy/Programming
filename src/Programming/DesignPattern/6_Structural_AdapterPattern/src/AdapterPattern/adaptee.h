#ifndef ADAPTEE_H
#define ADAPTEE_H

#include <QObject>

class Adaptee : public QObject
{
    Q_OBJECT
public:
    explicit Adaptee(QObject *parent = 0);

signals:

public slots:
    void run();
};

#endif // ADAPTEE_H
