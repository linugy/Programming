#ifndef INVOKE_H
#define INVOKE_H

#include <QObject>
#include "command.h"
#include "concretecommand.h"

class Invoke : public QObject
{
    Q_OBJECT
public:
    explicit Invoke(QObject *parent = 0);

signals:

public slots:
    void setConcreteCommand(Command *iConcreteCommand);
    void invoke();

private:
    Command *mConcreteCommand = nullptr;
};

#endif // INVOKE_H
