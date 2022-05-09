#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "product.h"
#include "product2.h"

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
    Product *mProductA = nullptr;
    Product2 *mProduct2A = nullptr;
    Product *mProductB = nullptr;
    Product2 *mProduct2B = nullptr;
};

#endif // MAINWINDOW_H
