#ifndef ROLE_H
#define ROLE_H

#include <QObject>
#include "memento.h"

class Role : public QObject
{
    Q_OBJECT
public:
    explicit Role(QObject *parent = 0);

signals:

public slots:
    void setName(const QString &iName);
    void setAttack(int iValue);
    void setDefend(int iDefend);

    QString getName();
    int getAttack();
    int getDefend();

    Memento *save();
    void load(Memento *iMemento);

private:
    QString mName;
    int mAttack;
    int mDefend;
    Memento *mMemento;
};

#endif // ROLE_H
