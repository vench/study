#ifndef SNAKE_H
#define SNAKE_H

#include <QPainter>
#include <QColor>
#include <QVector>
#include <QDebug>



class Snake
{
    uint pos_i;
    uint pos_j;
    QColor color;
    Qt::Key _direction;
    uint _size;

    class s_state{
       uint pos_i;
       uint pos_j;

    public:
       s_state() {}

       s_state(uint i, uint j ) {
           this->pos_i = i;
           this->pos_j = j;
       }

       friend class Snake;
    };

    QVector<Snake::s_state> states;

public:
    Snake();

    Snake(uint i, uint j);

    void newPos(uint i, uint j);
    uint posi();
    uint posj();
    uint size() const;
    void drawFigure(QPainter*);

    Qt::Key direction() const;
    void setDirection(Qt::Key);

    void updatePosition();

};



#endif // SNAKE_H
