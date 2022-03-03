#ifndef PROTOTYPE_H
#define PROTOTYPE_H

#include <QObject>

class Prototype : public QObject
{
    Q_OBJECT
public:
    explicit Prototype(QObject *parent = 0);

signals:

public slots:
    Prototype *clone();

    void setName(const QString &name);
    void setId(const QString &id);

    QString getName();
    QString getId();

private:
    QString mName;
    QString mId;
};

#endif // PROTOTYPE_H
