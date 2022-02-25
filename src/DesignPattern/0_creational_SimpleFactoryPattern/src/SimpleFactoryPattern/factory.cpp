#include "factory.h"
#include "producta.h"
#include "productb.h"

Factory::Factory(QObject *parent) : QObject(parent)
{

}

Product *Factory::create(const QString &iName)
{
    Product *res = nullptr;

    if (iName == "A") {
        res = new ProductA();
    } else if (iName == "B") {
        res = new ProductB();
    }

    return res;
}
