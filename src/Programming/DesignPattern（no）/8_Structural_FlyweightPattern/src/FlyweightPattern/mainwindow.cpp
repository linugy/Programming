#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    board = new PieceBoard();
    piecefactory = new PieceFactory();

    Piece *piece1 = piecefactory->getOnePiece(Piece::Color::Black);
    Piece::Position tmp1;
    tmp1.x = 1;
    tmp1.y = 2;
    piece1->setPosition(tmp1);
    board->drawOnePiece(piece1);

    Piece *piece2 = piecefactory->getOnePiece(Piece::Color::Black);
    Piece::Position tmp2;
    tmp2.x = 11;
    tmp2.y = 22;
    piece2->setPosition(tmp2);
    board->drawOnePiece(piece2);

    Piece *piece3 = piecefactory->getOnePiece(Piece::Color::White);
    Piece::Position tmp3;
    tmp3.x = 111;
    tmp3.y = 222;
    piece3->setPosition(tmp3);
    board->drawOnePiece(piece3);

    Piece *piece4 = piecefactory->getOnePiece(Piece::Color::White);
    Piece::Position tmp4;
    tmp4.x = 1111;
    tmp4.y = 2222;
    piece4->setPosition(tmp4);
    board->drawOnePiece(piece4);

    board->showAllPiece();
}

MainWindow::~MainWindow()
{
    delete ui;
}
