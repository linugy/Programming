#ifndef TARGET_H
#define TARGET_H

#include <QObject>

class Target : public QObject
{
    Q_OBJECT
public:
    explicit Target(QObject *parent = 0);

    virtual void needRun() = 0;
signals:

public slots:
};

#endif // TARGET_H
