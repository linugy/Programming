#ifndef DIRECTOR_H
#define DIRECTOR_H

#include <QWidget>
#include "builder.h"

class Director : public QWidget
{
    Q_OBJECT
public:
    explicit Director(QWidget *parent = 0);

signals:

public slots:
    void build();
    void setBuilder(Builder *builder);

private:
    Builder *mBuilder = nullptr;
};

#endif // DIRECTOR_H
