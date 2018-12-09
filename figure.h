#ifndef FIGURE_H
#define FIGURE_H

#include <QVector>
#include <QColor>
#include <QPainter>
#include <QDebug>

#define emptyCell QColor(150,150,150)//серыйцвет
#define redCell QColor(150,0,0)//red
#define blueCell QColor(0,0,150)//blue
#define greenCell QColor(0,150,0)//green

class Figure
{
    uint pos_i;
    uint pos_j;
    QVector<QColor> colors;
public:
    Figure();
    Figure(uint i, uint j);

    void drawFigure(QPainter*);
    void newPos(uint i, uint j);
    uint posi();
    uint posj();
};

#endif // FIGURE_H
