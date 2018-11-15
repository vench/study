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
    if(event->button() == Qt::MouseButton::RightButton ) {
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
   // qDebug() << event->pos();
}


//
void Spider::repaint() {
    qDebug() << "event->pos()";
}
