#include "spider.h"


Spider::Spider(QWidget *parent)
    : QWidget(parent)
{
    this->timerId = -1;
    this->mouseDown = false;
    this->mouseRightDown = false;
    this->updateTitleInfo();
    this->changeCursorDefault();
}

Spider::~Spider()
{

}

//
void Spider::timerEvent(QTimerEvent*) {
    repaint();
}

//
void Spider::keyPressEvent( QKeyEvent * event) {
    if(event->key() == 32) {
        if(this->timerId >= 0) {
            this->killTimer(this->timerId);
            this->timerId = -1;
        } else {
            timerId = this->startTimer(100);
        }
    }
}

//
void Spider::mousePressEvent(QMouseEvent * event) {

    if(event->button() == Qt::MouseButton::RightButton) {

        if((event->modifiers() & Qt::KeyboardModifier::ControlModifier) > 0) {
            QString s = QString("X:%1,Y:%2")
                    .arg(QString::number(event->pos().x()),
                         QString::number(event->pos().y()));

            QToolTip::showText(event->globalPos(), s);
        } else {
            this->firstPos = event->pos();
            this->mouseRightDown = true;
        }

    } else if(event->button() == Qt::MouseButton::LeftButton ) {
        this->mouseDown = true;
        changeCursor(":spider.png");
    } else {
        this->mouseDown = false;
        this->mouseRightDown = false;
    }
}


//
void Spider::changeCursor(Qt::CursorShape s) {
    this->setCursor(  QCursor(s));
}


//
void Spider::changeCursor(QString s) {
    QPixmap pix(s);
    pix.setMask(QBitmap(s));
    QCursor cr1(pix.scaled(28,28));
    this->setCursor(cr1);
}

//
void Spider::changeCursorDefault() {
     this->changeCursor(Qt::BusyCursor);
}

//
void Spider::mouseReleaseEvent(QMouseEvent*) {
    this->mouseDown = false;
    if(this->mouseRightDown) {
        QRect r;
        this->fillRect(r);
        listRects.append(r);
    }
    this->mouseRightDown = false;
    this->changeCursorDefault();
}

//
void Spider::mouseMoveEvent(QMouseEvent * event) {
    if(!this->rect().contains(event->pos())) {
        this->mouseReleaseEvent(event);
        return;
    }
    if(this->mouseRightDown) {
        lastPos = event->pos();
        repaint();
    }
    if(this->mouseDown) {
        lastPos = event->pos();
        repaint();
    }
}


//
void Spider::paintEvent ( QPaintEvent *  ) {
    QPainter p(this);
    if(this->mouseDown) {
        this->drawWeb(&p);
    }
    if(this->mouseRightDown){
        this->drawRect(&p);
    }

    //spdr
    spdr.p.setX( spdr.p.x() + spdr.speedX * spdr.directionX );
    if(!this->rect().contains(spdr.p)) {
        spdr.directionX *=-1;
        spdr.p.setX( spdr.p.x() + spdr.speedX * spdr.directionX );
    }

    spdr.p.setY( spdr.p.y() + spdr.speedY * spdr.directionY);
    if(!this->rect().contains(spdr.p)) {
        spdr.directionY *=-1;
         spdr.p.setY( spdr.p.y() + spdr.speedY * spdr.directionY);
    }
    QString s = ":spider.png";
    QPixmap pix(s);
    p.drawPixmap(spdr.p.x(), spdr.p.y(), 28, 28, pix.scaled(28,28));


    this->drawRects(&p);
}

//
void Spider::drawRects(QPainter*p) {
    p->setPen(QPen(Qt::blue,1,Qt::SolidLine));
    for(auto i : listRects) {
        p->drawRect(i);
    }
}

//
void Spider::drawRect(QPainter*p) {
    p->setPen(QPen(Qt::green,1,Qt::SolidLine));
    QRect r;
    this->fillRect(r);
    p->drawRect(r);
}

//
 void Spider::fillRect(QRect&r) {
     int x = std::min(this->firstPos.x(), this->lastPos.x()),
         y = std::min(this->firstPos.y(), this->lastPos.y()),
         w = fabs(this->firstPos.x() - this->lastPos.x()),
         h = fabs(this->firstPos.y() - this->lastPos.y());
     r.setX(x);
     r.setY(y);
     r.setWidth(w);
     r.setHeight(h);
 }

//
void Spider::drawWeb(QPainter*p) {
    if(lastPos.x() <= 0 || lastPos.y() <= 0) {
        return;
    }
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

    p->setPen(QPen(Qt::red,1,Qt::SolidLine));

    int a[2],b[2];
    mathCPoint(lb[7], a);

    for(int i = 0; i < 8; i ++) {
        p->drawLine(lb[i][0], lb[i][1], lb[i][2], lb[i][3]);

        mathCPoint(lb[i], b);
        p->drawLine(a[0], a[1], b[0], b[1]);
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


//
void Spider::resizeEvent(QResizeEvent *) {
    this->updateTitleInfo();
}

//
void Spider::updateTitleInfo() {
    QString s = tr("Spider window, width: %1, height: %2").arg(this->width()).arg(this->height());
    this->setWindowTitle(s);
}
