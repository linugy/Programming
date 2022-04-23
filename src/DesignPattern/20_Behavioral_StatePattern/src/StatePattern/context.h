#ifndef CONTEXT_H
#define CONTEXT_H

#include <QObject>
#include "state.h"

class Context : public QObject
{
    Q_OBJECT
public:
    explicit Context(QObject *parent = 0);

signals:

public slots:
    void setState(State *iState);
    void run();

private:
    State *mState;
};

#endif // CONTEXT_H
