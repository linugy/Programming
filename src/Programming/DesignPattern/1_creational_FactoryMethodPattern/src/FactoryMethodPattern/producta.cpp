#include "producta.h"
#include <QDebug>

ProductA::ProductA(QObject *parent) : Product(parent)
{

}

void ProductA::run()
{
    qDebug() << "ProductA is run";
}
