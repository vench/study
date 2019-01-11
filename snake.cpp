#include "snake.h"

//
Snake::Snake()
{
    newPos(0, 0);
    _size = 5;

    setDirection( Qt::Key_Right);
    color = QColor(255,0,0);
}


//
Snake::Snake(uint i, uint j) : Snake(){
    newPos(i, j);
}

//

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
        _direction = d;
    }
}

//
uint Snake::size() const {
    return _size;
}

//
void Snake::updatePosition() {
    uint pj = pos_j;
    uint pi = pos_i;
    switch(_direction) {
    case Qt::Key_Left:
        pj --;
        break;
    case Qt::Key_Right:
        pj ++;
        break;
    case Qt::Key_Up:
        pi --;
        break;
    case Qt::Key_Down:
        pi ++;
        break;
    default:
        break;
    }

    //qDebug() << "Add to state";
    newPos(pi, pj);
}
