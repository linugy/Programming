#ifndef PIECEBOARD_H
#define PIECEBOARD_H

#include <QObject>
#include "piecefactory.h"
#include "piece.h"
#include <QMap>

class PieceBoard : public QObject
{
    Q_OBJECT
public:
    explicit PieceBoard(QObject *parent = 0);

signals:

public slots:
    void drawOnePiece(Piece *piece);
    void showAllPiece();

private:
    QMap<Piece::Position, Piece::Color> mPieceMap;
};

#endif // PIECEBOARD_H
