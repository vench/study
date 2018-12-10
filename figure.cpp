#include "figure.h"

Figure::Figure()
{

    int size = 3;
    colors.resize(size);

    int s =  sizeof(M_COLORS) / sizeof(QColor);
    int start = rand() % s + 1;
    for(int i = 0; i < size; i ++) {
        int n = (i + start) % s;
        colors.insert(i, M_COLORS[n]);
    }
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
    drawFigure(p, pos_j, pos_i);
}

//
void Figure::drawFigure(QPainter* p, uint j, uint i) {
    p->fillRect(j * 30+1, i * 30+1, 30-2, 30-2, QBrush(colors.at(0)));
    p->fillRect(j * 30+1, (i+1) * 30+1, 30-2, 30-2, QBrush(colors.at(1)));
    p->fillRect(j * 30+1, (i+2) * 30+1, 30-2, 30-2, QBrush(colors.at(2)));
}

//
void Figure::changeUp() {
    QColor tmp = colors.at(0);
    colors.replace(0, colors.at(1));
    colors.replace(1, colors.at(2));
    colors.replace(2, tmp);
}

//
void Figure::changeDown() {
    QColor tmp = colors.at(2);
    colors.replace(2, colors.at(1));
    colors.replace(1, colors.at(0));
    colors.replace(0, tmp);
}

//
QColor Figure::colorAt(int i) {
    return colors.at(i);
}
