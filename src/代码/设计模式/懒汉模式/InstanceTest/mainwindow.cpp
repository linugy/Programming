#include "mainwindow.h"
#include "singleclass.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    SingleClass::instance()->test();
}

MainWindow::~MainWindow()
{

}
