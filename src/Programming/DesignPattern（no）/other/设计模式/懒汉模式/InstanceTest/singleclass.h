#ifndef SINGLECLASS_H
#define SINGLECLASS_H

#include <QObject>

class SingleClass : public QObject
{
    Q_OBJECT
public:
    static SingleClass *instance();
    ~SingleClass();

public slots:
    void test();

private:
    explicit SingleClass(QObject *parent = 0);
};

#endif // SINGLECLASS_H
