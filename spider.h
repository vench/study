#ifndef SPIDER_H
#define SPIDER_H

#include <QWidget>
#include <QDebug>
#include <QMouseEvent>
#include <QToolTip>

class Spider : public QWidget
{
    Q_OBJECT

    bool mouseDown;

public:
    Spider(QWidget *parent = 0);
    ~Spider();


protected:
    void mousePressEvent( QMouseEvent * event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent * event );
    void repaint();
};

#endif // SPIDER_H
