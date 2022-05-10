#ifndef AGGREGATE_H
#define AGGREGATE_H

#include <QObject>
#include <QVariantList>
#include "iterator.h"

class Aggregate : public QObject
{
    Q_OBJECT
public:
    explicit Aggregate(QObject *parent = 0);

signals:

public slots:
    void append(const QString &iStr);
    QString getValue(int iIndex);
    int count();
    Iterator *createIterator();

private:
    QVariantList mLst;
    Iterator *mIterator = nullptr;
};

#endif // AGGREGATE_H
