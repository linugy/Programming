#ifndef COMPONENT_H
#define COMPONENT_H

#include <QObject>

class Component : public QObject
{
    Q_OBJECT
public:
    explicit Component(QObject *parent = 0);

signals:

public slots:
    void setName(const QString &iStr);
    QString getName();
    void printName();

    virtual void addChild(Component *iComponent) = 0;
    virtual void removeChild(Component *iComponent) = 0;
    virtual Component* getChild(int i) = 0;
    virtual int getCount() = 0;

private:
    QString mName;
};

#endif // COMPONENT_H
