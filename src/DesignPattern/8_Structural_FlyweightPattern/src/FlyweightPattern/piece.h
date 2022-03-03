#ifndef PIECE_H
#define PIECE_H

#include <QObject>

class Piece : public QObject
{
    Q_OBJECT

public:
    enum Color{
        White,
        Black
    };

    struct Position{
        int x;
        int y;

        // 没有会报错
        bool operator <(const Position& other) const
        {
            if (x < other.x)
            {
                return true;
            }
            else if (x == other.x)
            {
                return y < other.y;
            }

            return false;
        }
    };

public:
    explicit Piece(QObject *parent = 0);

signals:

public slots:
    void setColor(Color color);
    Color getColor();

    void setPosition(Position position);
    Position getPosition();

private:
    Color mColor;
    Position mPosition;
};

#endif // PIECE_H
