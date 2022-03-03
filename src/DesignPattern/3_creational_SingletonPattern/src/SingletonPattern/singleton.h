#ifndef SINGLETON_H
#define SINGLETON_H

#include <QObject>

class Singleton : public QObject
{
    Q_OBJECT
public:
    static Singleton &instance();
signals:

public slots:
    void run();

private:
    explicit Singleton(QObject *parent = 0);
};

#endif // SINGLETON_H
