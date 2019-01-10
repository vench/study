#ifndef FIGURENEW_H
#define FIGURENEW_H

#include <QWidget>
#include <QDebug>
#include <QPainter>
#include "figure.h"

class FigureNew : public QWidget
{
    Q_OBJECT

    Figure figure;

public:
    explicit FigureNew(QWidget *parent = 0);

signals:

public slots:
    void slotUpdateFigure(Figure);

protected:
    void paintEvent(QPaintEvent*);
};

#endif // FIGURENEW_H
