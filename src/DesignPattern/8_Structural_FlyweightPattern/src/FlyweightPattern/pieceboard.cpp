#include "pieceboard.h"
#include <QDebug>

PieceBoard::PieceBoard(QObject *parent) : QObject(parent)
{

}

void PieceBoard::drawOnePiece(Piece *piece)
{
    mPieceMap.insert(piece->getPosition(), piece->getColor());
}

void PieceBoard::showAllPiece()
{
    for (Piece::Position key : mPieceMap.keys()) {
        qDebug() << key.x << key.y << mPieceMap.value(key);
    }
}
