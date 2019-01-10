#ifndef SNAKE_H
#define SNAKE_H

#include <QPainter>
#include <QColor>

class Snake
{
    uint pos_i;
    uint pos_j;
    QColor color;
    Qt::Key _direction;

public:
    Snake();

    Snake(uint i, uint j);

    void newPos(uint i, uint j);
    uint posi();
    uint posj();
    void drawFigure(QPainter*);

    Qt::Key direction() const;
    void setDirection(Qt::Key);

    void updatePosition();

};

#endif // SNAKE_H
