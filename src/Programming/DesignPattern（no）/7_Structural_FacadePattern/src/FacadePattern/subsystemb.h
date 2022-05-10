#ifndef SUBSYSTEMB_H
#define SUBSYSTEMB_H

#include <QObject>

class SubSystemB : public QObject
{
    Q_OBJECT
public:
    explicit SubSystemB(QObject *parent = 0);

signals:

public slots:
    void runB();
};

#endif // SUBSYSTEMB_H
