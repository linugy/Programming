#include "piece.h"

Piece::Piece(QObject *parent) : QObject(parent)
{

}

void Piece::setColor(Piece::Color color)
{
    mColor = color;
}

Piece::Color Piece::getColor()
{
    return mColor;
}

void Piece::setPosition(Piece::Position position)
{
    mPosition = position;
}

Piece::Position Piece::getPosition()
{
    return mPosition;
}
