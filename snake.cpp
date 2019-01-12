#include "snake.h"

//
Snake::Snake()
{
    newPos(0, 0);
    _size = 1;

    setDirection( Qt::Key_Right);
    color = QColor(255,0,0);
}


//
Snake::Snake(uint i, uint j) : Snake(){
    newPos(i, j);
}

//
void Snake::addSize() {
    _size ++;
}

//
bool Snake::inPos(uint i, uint j) {
    for(int n = 0; n<states.count(); n ++) {
        s_state s = states.at(n);
        if(s.pos_i == i && s.pos_j == j) {
            return true;
        }
    }
    return false;
}

//
void Snake::newPos(uint i, uint j) {
    if(pos_j != j || pos_i != i) {
        pos_i = i;
        pos_j = j;

        s_state s(pos_i, pos_j);
        states.insert(0, s);
        states.resize(_size);

    }
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
   for(int i = 0; i<states.count(); i ++) {
       s_state s = states.at(i);
       p->fillRect(s.pos_j * 30+1, s.pos_i * 30+1, 30-2, 30-2, color);
   }
}

//
Qt::Key Snake::direction() const {
    return _direction;
}

//
void Snake::setDirection(Qt::Key d) {
    if(d != _direction) {
        if(d == Qt::Key_Right && _direction == Qt::Key_Left) {
            return;
        }
        if(d == Qt::Key_Left && _direction == Qt::Key_Right) {
            return;
        }
        if(d == Qt::Key_Up && _direction == Qt::Key_Down) {
            return;
        }
        if(d == Qt::Key_Down && _direction == Qt::Key_Up) {
            return;
        }
        _direction = d;
    }
}

//
uint Snake::size() const {
    return _size;
}


