#ifndef COMMAND_H
#define COMMAND_H

#include <QObject>
#include "receive.h"

class Command : public QObject
{
    Q_OBJECT
public:
    explicit Command(QObject *parent = 0);

signals:

public slots:
    virtual void exe() = 0;
    void setReceive(Receive *iReceive);
    Receive *getReceive();

private:
    Receive *mReceive = nullptr;
};

#endif // COMMAND_H
