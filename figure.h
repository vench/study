#ifndef FIGURE_H
#define FIGURE_H

#include <QVector>
#include <QColor>
#include <QPainter>
#include <QDebug>
#include "random"

#define emptyCell QColor(150,150,150)//серыйцвет
#define redCell QColor(255,0,0)//red
#define blueCell QColor(0,0,255)//blue
#define greenCell QColor(0,255,0)//green
#define yellowCell QColor(255,255,0)//yellow
#define purpCell QColor(0,255,255)//purp

const QColor M_COLORS[] = {redCell, blueCell, greenCell, yellowCell, purpCell};

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
    void changeUp();
    void changeDown();
    QColor colorAt(int);
};

#endif // FIGURE_H
