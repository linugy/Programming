#include "template.h"

Template::Template(QObject *parent) : QObject(parent)
{

}

void Template::run()
{
    do1();
    do2();
    do3();
}
