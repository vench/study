#include "pointeat.h"

Pointeat::Pointeat()
{
    newPos(0,0);
    color = QColor(0,255,0);
}

//
void Pointeat::newPos(uint i, uint j) {
    pos_i = i;
    pos_j = j;
}

//
uint Pointeat::posi() {
    return pos_i;
}

//
uint Pointeat::posj() {
    return pos_j;
}

//
void Pointeat::drawFigure(QPainter* p) {
    p->fillRect(pos_j * 30+1, pos_i * 30+1, 30-2, 30-2, color);
}

 bool Pointeat::isActive() const {
     return active;
 }
