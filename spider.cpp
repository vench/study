#include "spider.h"


Spider::Spider(QWidget *parent)
    : QWidget(parent)
{
    this->mouseDown = false;
    this->setWindowTitle(tr("Spider window"));
}

Spider::~Spider()
{

}

//
void Spider::mousePressEvent(QMouseEvent * event) {

    if(event->button() == Qt::MouseButton::RightButton &&
       (event->modifiers() & Qt::KeyboardModifier::ControlModifier) > 0) {
        QString s = QString("X:%1,Y:%2")
                .arg(QString::number(event->pos().x()),
                     QString::number(event->pos().y()));

        QToolTip::showText(event->globalPos(), s);
    }
    if(event->button() == Qt::MouseButton::LeftButton ) {
        this->mouseDown = true;
    } else {
        this->mouseDown = false;
    }
}

//
void Spider::mouseReleaseEvent(QMouseEvent*) {
    this->mouseDown = false;
}

//
void Spider::mouseMoveEvent(QMouseEvent * event) {
    if(this->mouseDown) {
        lastPos = event->pos();
        repaint();
    }
}


//
void Spider::paintEvent ( QPaintEvent *  ) {
    if(lastPos.x() <= 0 || lastPos.y() <= 0) {
        return;
    }
    QPainter p(this);

    int lb[8][4] = {
        {lastPos.x(), lastPos.y(),0,0},
        {lastPos.x(), lastPos.y(),width()>>1,0},
        {lastPos.x(), lastPos.y(),width(),0},
        {lastPos.x(), lastPos.y(),width(),height() >> 1},
        {lastPos.x(), lastPos.y(),width(),height()},
        {lastPos.x(), lastPos.y(),width()>>1,height()},
        {lastPos.x(), lastPos.y(),0,height()},
        {lastPos.x(), lastPos.y(),0,height() >> 1}
    };

    p.setPen(QPen(Qt::red,1,Qt::SolidLine));

    int a[2],b[2];
    mathCPoint(lb[7], a);


    for(int i = 0; i < 8; i ++) {
        p.drawLine(lb[i][0], lb[i][1], lb[i][2], lb[i][3]);

        mathCPoint(lb[i], b);
        p.drawLine(a[0], a[1], b[0], b[1]);
        a[0] = b[0];
        a[1] = b[1];
    }

}

//
void Spider::mathCPoint(int *line, int *pc) {
    double len = sqrt(pow(line[3]  - line[1],2) + pow(line[0] * 1. - line[2], 2));
    int llen = width() >> 2;
    double k = llen / len;
    pc[0] = line[0] + (line[2]-line[0])*k;
    pc[1] = line[1] + (line[3]-line[1])*k;
}
