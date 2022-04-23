#include "concretestate1.h"
#include <QDebug>

ConcreteState1::ConcreteState1(QObject *parent) : State(parent)
{

}

void ConcreteState1::run()
{
    qDebug() << "===ConcreteState1::run===";
}
