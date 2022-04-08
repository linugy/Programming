#include "decoratorsubclass2.h"

DecoratorSubClass2::DecoratorSubClass2(QObject *parent) : DecoratorAbsClass(parent)
{

}

QString DecoratorSubClass2::getName()
{
    return getClass()->getName() + "+2";
}
