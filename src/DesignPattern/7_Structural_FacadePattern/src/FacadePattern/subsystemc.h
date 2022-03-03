#ifndef SUBSYSTEMC_H
#define SUBSYSTEMC_H

#include <QObject>

class SubSystemC : public QObject
{
    Q_OBJECT
public:
    explicit SubSystemC(QObject *parent = 0);

signals:

public slots:
    void runC();
};

#endif // SUBSYSTEMC_H
