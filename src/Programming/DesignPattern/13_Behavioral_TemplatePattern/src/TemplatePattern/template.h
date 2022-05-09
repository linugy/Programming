#ifndef TEMPLATE_H
#define TEMPLATE_H

#include <QObject>

class Template : public QObject
{
    Q_OBJECT
public:
    explicit Template(QObject *parent = 0);

signals:

public slots:
    virtual void do1() = 0;
    virtual void do2() = 0;
    virtual void do3() = 0;

    void run();
};

#endif // TEMPLATE_H
