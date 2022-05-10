#ifndef SUBJECT_H
#define SUBJECT_H

#include <QObject>
#include "observe.h"

class Subject : public QObject
{
    Q_OBJECT
public:
    explicit Subject(QObject *parent = 0);

signals:

public slots:
    virtual void addObserve(Observe *iObserve) = 0;
    virtual void removeObserve(Observe *iObserve) = 0;
    virtual void notify() = 0;

    void setState(const QString &iStr);
    QString getState();

private:
    QString mState;
};

#endif // SUBJECT_H
