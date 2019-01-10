#include "snake.h"

//
Snake::Snake()
{
    pos_j = 0;
    pos_i = 0;

    _direction = Qt::Key_Right;
    color = QColor(255,0,0);
}


//
Snake::Snake(uint i, uint j) : Snake(){
    pos_j = j;
    pos_i = i;
}

//

//
void Snake::newPos(uint i, uint j) {
    pos_i = i;
    pos_j = j;
}

//
uint Snake::posi() {
    return pos_i;
}

//
uint Snake::posj() {
    return pos_j;
}

//
void Snake::drawFigure(QPainter*p) {
    p->fillRect(pos_j * 30+1, pos_i * 30+1, 30-2, 30-2, color);
}

//
Qt::Key Snake::direction() const {
    return _direction;
}

//
void Snake::setDirection(Qt::Key d) {
    _direction = d;
}

//
void Snake::updatePosition() {
    switch(_direction) {
    case Qt::Key_Left:
        pos_j --;
        break;
    case Qt::Key_Right:
        pos_j ++;
        break;
    case Qt::Key_Up:
        pos_i --;
        break;
    case Qt::Key_Down:
        pos_i ++;
        break;
    }
}
