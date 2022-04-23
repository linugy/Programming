#include "concretestate2.h"
#include <QDebug>

ConcreteState2::ConcreteState2(QObject *parent) : State(parent)
{

}

void ConcreteState2::run()
{
    qDebug() << "===ConcreteState2::run===";
}
