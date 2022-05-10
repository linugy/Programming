#include "command.h"

Command::Command(QObject *parent) : QObject(parent)
{

}

void Command::setReceive(Receive *iReceive)
{
    mReceive = iReceive;
}

Receive *Command::getReceive()
{
    return mReceive;
}
