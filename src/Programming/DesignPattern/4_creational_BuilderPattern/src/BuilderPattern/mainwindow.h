#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "product.h"
#include "builder.h"
#include "director.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private:
    Product *mProduct = nullptr;
    Builder *mBuilder = nullptr;
    Director *mDirector = nullptr;
};

#endif // MAINWINDOW_H
