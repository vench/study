#ifndef SPIDER_H
#define SPIDER_H

#include <QWidget>
#include <QDebug>
#include <QMouseEvent>
#include <QToolTip>
#include <QPainter>
#include <math.h>

class Spider : public QWidget
{
    Q_OBJECT

    bool mouseDown;
    QPoint lastPos;


    void mathCPoint(int *, int *);

public:
    Spider(QWidget *parent = 0);
    ~Spider();


protected:
    void mousePressEvent( QMouseEvent * event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent * event );
    void paintEvent ( QPaintEvent * event );
};

#endif // SPIDER_H
