#ifndef SUBSYSTEMA_H
#define SUBSYSTEMA_H

#include <QObject>

class SubSystemA : public QObject
{
    Q_OBJECT
public:
    explicit SubSystemA(QObject *parent = 0);

signals:

public slots:
    void runA();
};

#endif // SUBSYSTEMA_H
