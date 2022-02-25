#ifndef FACTORY_H
#define FACTORY_H

#include <QObject>
#include "product.h"

class Factory : public QObject
{
    Q_OBJECT
public:
    explicit Factory(QObject *parent = 0);

signals:

public slots:
    static Product *create(const QString &iName);
};
#endif // FACTORY_H
