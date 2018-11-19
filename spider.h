#ifndef SPIDER_H
#define SPIDER_H

#include <QWidget>
#include <QDebug>
#include <QMouseEvent>
#include <QToolTip>
#include <QPainter>
#include <QBitmap>
#include <math.h>

class Spider : public QWidget
{
    Q_OBJECT

    bool mouseDown;
    bool mouseRightDown;
    QPoint firstPos;
    QPoint lastPos;
    QList<QRect> listRects;


    void mathCPoint(int *, int *);
    void changeCursor(QString s);
    void changeCursor(Qt::CursorShape s);
    void changeCursorDefault();
    void updateTitleInfo();
    void drawWeb(QPainter*);
    void drawRect(QPainter*);
    void drawRects(QPainter*);
    void fillRect(QRect&);

public:
    Spider(QWidget *parent = 0);
    ~Spider();


protected:
    void mousePressEvent( QMouseEvent * event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent * event );
    void paintEvent ( QPaintEvent * event );
    void resizeEvent(QResizeEvent *);
};

#endif // SPIDER_H
