#ifndef POINTEAT_H
#define POINTEAT_H

#include <QPainter>
#include <QColor>

class Pointeat
{
    uint pos_i;
    uint pos_j;
    QColor color;
    bool active;
public:
    Pointeat();

    void newPos(uint i, uint j);
    uint posi();
    uint posj();
    void drawFigure(QPainter*);
    bool isActive() const;
};

#endif // POINTEAT_H
