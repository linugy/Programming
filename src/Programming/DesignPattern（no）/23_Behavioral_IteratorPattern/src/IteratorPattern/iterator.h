#ifndef ITERATOR_H
#define ITERATOR_H

#include <QObject>

class Aggregate;
class Iterator : public QObject
{
    Q_OBJECT
public:
    explicit Iterator(QObject *parent = 0, Aggregate *iAggregate = 0);

signals:

public slots:
    bool isEnd();
    QString next();
    QString getValue();

private:
    Aggregate *mAggregate;
    int mCurrentIndex = 0;
};

#endif // ITERATOR_H
