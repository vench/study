#include "figurenew.h"

FigureNew::FigureNew(QWidget *parent) : QWidget(parent)
{
    //figure = nullptr;

}

//
void FigureNew::slotUpdateFigure(Figure f) {
    figure = f;
    repaint();
}

//
void FigureNew::paintEvent(QPaintEvent*) {
    QPainter painter(this);

    figure.drawFigure(&painter, 0, 0);
}
