#ifndef STATE_H
#define STATE_H

#include <QObject>

class State : public QObject
{
    Q_OBJECT
public:
    explicit State(QObject *parent = 0);

signals:

public slots:
    virtual void run() = 0;
};

#endif // STATE_H
