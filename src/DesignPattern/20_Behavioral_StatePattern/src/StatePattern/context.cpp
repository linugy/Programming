#include "context.h"

Context::Context(QObject *parent) : QObject(parent)
{

}

void Context::setState(State *iState)
{
    mState = iState;
}

void Context::run()
{
    mState->run();
}
