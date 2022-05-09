#ifndef ABSCLASS_H
#define ABSCLASS_H

#include <QObject>
#include "absfunclass.h"

class AbsClass : public QObject
{
    Q_OBJECT
public:
    explicit AbsClass(QObject *parent = 0);

signals:

public slots:
    void run();
    void setFun(AbsFunClass *iFun);

private:
    AbsFunClass *mAbsFunClass = nullptr;
};

#endif // ABSCLASS_H
