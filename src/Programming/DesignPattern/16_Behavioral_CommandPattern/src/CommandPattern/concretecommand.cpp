#include "concretecommand.h"

ConcreteCommand::ConcreteCommand(QObject *parent) : Command(parent)
{

}

void ConcreteCommand::exe()
{
    if (getReceive()) {
        getReceive()->run();
    }
}
