#include "decoratorsubclass.h"

DecoratorSubClass::DecoratorSubClass(QObject *parent) : DecoratorAbsClass(parent)
{

}

QString DecoratorSubClass::getName()
{
    return getClass()->getName() + "+1";
}
