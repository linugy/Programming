#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "template.h"
#include "subclass1.h"
#include "subclass2.h"

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
    Template *mTemplate = nullptr;
};

#endif // MAINWINDOW_H
