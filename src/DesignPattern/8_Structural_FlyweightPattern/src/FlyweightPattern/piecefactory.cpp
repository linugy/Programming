#include "piecefactory.h"
#include <QDebug>

PieceFactory::PieceFactory(QObject *parent) : QObject(parent)
{

}

Piece *PieceFactory::getOnePiece(Piece::Color color)
{
    if (mPieceLst.length() == 0) {
        Piece *piece = new Piece();
        piece->setColor(color);

        mPieceLst.append(piece);
        qDebug() << "==不存在==" << color;
        return piece;
    } else {
        bool isExsit = false;
        for (Piece *tmp : mPieceLst) {
            if (tmp->getColor() == color) {
                isExsit = true;
                qDebug() << "==已存在==" << color;
                return tmp;
            }
        }

        if (!isExsit) {
            Piece *piece = new Piece();
            piece->setColor(color);

            mPieceLst.append(piece);
            qDebug() << "==不存在==" << color;
            return piece;
        }
    }
    return nullptr;
}
