#ifndef CONCRETECOMMAND_H
#define CONCRETECOMMAND_H

#include <QObject>
#include "command.h"

class ConcreteCommand : public Command
{
    Q_OBJECT
public:
    explicit ConcreteCommand(QObject *parent = 0);

signals:

public slots:
    void exe();
};

#endif // CONCRETECOMMAND_H
