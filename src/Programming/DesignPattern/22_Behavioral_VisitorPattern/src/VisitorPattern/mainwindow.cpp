#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "objectstructure.h"
#include "elementa.h"
#include "elementb.h"
#include "visitora.h"
#include "visitorb.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ObjectStructure *objectstructure = new ObjectStructure();

    Element *elementA = new ElementA();
    Element *elementB = new ElementB();

    objectstructure->add(elementA);
    objectstructure->add(elementB);

    VisitorA *visitorA = new VisitorA();
    VisitorB *visitorB = new VisitorB();

    objectstructure->accept(visitorB);

    objectstructure->accept(visitorA);
}

MainWindow::~MainWindow()
{
    delete ui;
}
