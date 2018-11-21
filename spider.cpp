#include "spider.h"


Spider::Spider(QWidget *parent)
    : QWidget(parent)
{
    this->setFixedSize(320, 240);
    this->updateTitleInfo();



    label = new QLabel(tr("Are you suit your salary?"), this);
    label->setGeometry(QRect(QPoint(20, 20),QSize(200, 50)));

    btnNo = new QPushButton(tr("No"), this);
    btnNo->setGeometry(QRect(QPoint(20, 100),QSize(100, 30)));

    btnYes = new QPushButton(tr("Yes"), this);
    btnYes->setGeometry(QRect(QPoint(200, 100),QSize(100, 30)));

    connect(btnNo, SIGNAL (released()), this, SLOT (handleButtonNo()));
    connect(btnYes, SIGNAL (released()), this, SLOT (handleButtonYes()));

    btnNo->installEventFilter(this);

}

Spider::~Spider()
{
    delete btnNo;
    delete btnYes;
    delete label;
}

//
bool Spider::eventFilter(QObject* target,QEvent* event) {
    if((target == btnNo)) {
        if(event->type() == QEvent::MouseMove ||
           event->type() == QEvent::HoverEnter ||
           event->type() == QEvent::HoverMove
                ) {

            int mx=(btnNo->x()>this->width()/2) ? -1 : 1,
                my=(btnNo->y()>this->height()/2) ? -1 : 1;
            while(true) {

                QRect r(
                            btnNo->x()+ (rand()%width()-btnNo->width())*mx,
                            btnNo->y()+(rand()%height()-btnNo->height())*my,
                            btnNo->width(), btnNo->height());

                if(!this->rect().contains(r)) {
                    mx = -mx;
                    my = -my;
                    continue;
                }
                if(this->btnYes->rect().contains(r)) {
                    continue;
                }
                if(r.contains(QCursor::pos())) {
                    continue;
                }
                btnNo->setGeometry(r);

                break;
            }

            return true;
        }

    }

    return QWidget::eventFilter(target, event);
}

//
void Spider::handleButtonNo() {
    QMessageBox msgBox;
    msgBox.setText("Oh!");
    msgBox.exec();
}

//
void Spider::handleButtonYes() {
    QMessageBox msgBox;
    msgBox.setText(tr("We think as you."));
    msgBox.exec();
}

//
void Spider::timerEvent(QTimerEvent*) {
    repaint();
}

//
void Spider::keyPressEvent( QKeyEvent * ) {

}

//
void Spider::mousePressEvent(QMouseEvent * ) {


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

}

//
void Spider::mouseMoveEvent(QMouseEvent * ) {

}


//
void Spider::paintEvent ( QPaintEvent *  ) {


}

//
void Spider::drawRects(QPainter*) {

}

//
void Spider::drawRect(QPainter*) {

}

//
 void Spider::fillRect(QRect&) {

 }

//
void Spider::drawWeb(QPainter*) {

}

//
void Spider::mathCPoint(int *, int *) {

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
