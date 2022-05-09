#include "invoke.h"

Invoke::Invoke(QObject *parent) : QObject(parent)
{

}

void Invoke::setConcreteCommand(Command *iConcreteCommand)
{
    mConcreteCommand = iConcreteCommand;
}

void Invoke::invoke()
{
    if (mConcreteCommand) {
        mConcreteCommand->exe();
    }
}
