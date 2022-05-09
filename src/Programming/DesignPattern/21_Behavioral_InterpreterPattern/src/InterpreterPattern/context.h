#ifndef CONTEXT_H
#define CONTEXT_H

#include <QObject>
#include <QMap>

class Context : public QObject
{
    Q_OBJECT
public:
    explicit Context(QObject *parent = 0);

signals:

public slots:
    int getValue(const QString &iStr);

private:
    void init();

private:
    QMap<QString, int> mValueMap;
};

#endif // CONTEXT_H
