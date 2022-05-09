#ifndef MANAGER_H
#define MANAGER_H

#include <QObject>
#include <QList>
#include "memento.h"

class Manager : public QObject
{
    Q_OBJECT
public:
    explicit Manager(QObject *parent = 0);

signals:

public slots:
    void save(Memento *iMemento);
    Memento *load();

private:
    QList<Memento *> mLst;
};

#endif // MANAGER_H
