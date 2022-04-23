#ifndef MEMENTO_H
#define MEMENTO_H

#include <QObject>

class Memento : public QObject
{
    Q_OBJECT
public:
    explicit Memento(QObject *parent = 0);

signals:

public slots:
    void setName(const QString &iName);
    void setAttack(int iValue);
    void setDefend(int iDefend);

    QString getName();
    int getAttack();
    int getDefend();

private:
    QString mName;
    int mAttack;
    int mDefend;
};

#endif // MEMENTO_H
