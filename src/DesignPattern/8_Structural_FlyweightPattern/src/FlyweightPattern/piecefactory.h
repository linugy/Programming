#ifndef PIECEFACTORY_H
#define PIECEFACTORY_H

#include <QObject>
#include "piece.h"

class PieceFactory : public QObject
{
    Q_OBJECT
public:
    explicit PieceFactory(QObject *parent = 0);

signals:

public slots:
    Piece *getOnePiece(Piece::Color color);

private:
    QList<Piece *> mPieceLst;
};

#endif // PIECEFACTORY_H
