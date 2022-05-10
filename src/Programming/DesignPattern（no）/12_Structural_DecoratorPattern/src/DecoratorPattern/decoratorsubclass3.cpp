#include "decoratorsubclass3.h"

DecoratorSubClass3::DecoratorSubClass3(QObject *parent) : DecoratorAbsClass(parent)
{

}

QString DecoratorSubClass3::getName()
{
    return getClass()->getName() + "+3";
}
