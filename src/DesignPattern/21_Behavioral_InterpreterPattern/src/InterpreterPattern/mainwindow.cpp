#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "context.h"
#include "multiexpression.h"
#include "divexpression.h"
#include "termimalexpression.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Context context;

    MultiExpression *multiExpression = new MultiExpression();
    TermimalExpression *termimalExpression1 = new TermimalExpression();
    TermimalExpression *termimalExpression2 = new TermimalExpression();

    termimalExpression1->setValue(context.getValue("value_3"));
    termimalExpression2->setValue(context.getValue("value_4"));

    multiExpression->setLeft(termimalExpression1);
    multiExpression->setRight(termimalExpression2);

    DivExpression *divExpression = new DivExpression();
    TermimalExpression *termimalExpression3 = new TermimalExpression();

    termimalExpression3->setValue(context.getValue("value_2"));

    divExpression->setLeft(multiExpression);
    divExpression->setRight(termimalExpression3);

    qDebug() << divExpression->interpreter(&context);
}

MainWindow::~MainWindow()
{
    delete ui;
}
