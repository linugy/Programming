#ifndef OBSERVE_H
#define OBSERVE_H

#include <QObject>

class Observe : public QObject
{
    Q_OBJECT
public:
    explicit Observe(QObject *parent = 0);

signals:

public slots:
    void setState(const QString &iStr);
    QString getState();

    virtual void update() = 0;

private:
    QString mState;
};

#endif // OBSERVE_H
