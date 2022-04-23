#include "colleague.h"
#include <QDebug>

Colleague::Colleague(QObject *parent) : QObject(parent)
{

}

void Colleague::setMediator(Mediator *iMediator)
{
    mMediator = iMediator;
}
