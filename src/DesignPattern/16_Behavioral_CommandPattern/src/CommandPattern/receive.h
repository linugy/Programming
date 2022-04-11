#ifndef RECEIVE_H
#define RECEIVE_H

#include <QObject>

class Receive : public QObject
{
    Q_OBJECT
public:
    explicit Receive(QObject *parent = 0);

signals:

public slots:
    void run();
};

#endif // RECEIVE_H
