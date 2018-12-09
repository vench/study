#include "figure.h"

Figure::Figure()
{

    colors.resize(3);
    colors.insert(0, redCell);
    colors.insert(1, blueCell);
    colors.insert(2, greenCell);
}

Figure::Figure(uint i, uint j) : Figure(){
    pos_i = i;
    pos_j = j;
}

//
void Figure::newPos(uint i, uint j) {
    pos_i = i;
    pos_j = j;
}

//
uint Figure::posi() {
    return pos_i;
}

//
uint Figure::posj() {
    return pos_j;
}

//
void Figure::drawFigure(QPainter* p) {
    p->fillRect(pos_j * 30+1, pos_i * 30+1, 30-2, 30-2, QBrush(colors.at(0)));
    p->fillRect(pos_j * 30+1, (pos_i+1) * 30+1, 30-2, 30-2, QBrush(colors.at(1)));
    p->fillRect(pos_j * 30+1, (pos_i+2) * 30+1, 30-2, 30-2, QBrush(colors.at(2)));
    qDebug() << "drawFigure" << pos_j << pos_i;
}
