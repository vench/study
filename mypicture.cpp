#include "mypicture.h"

MyPicture::MyPicture(QWidget *parent) : QWidget(parent)
{
    scale = 1;
    picture = new QPixmap(":/uz.jpg");
}

MyPicture::~MyPicture() {
    delete picture;
    picture = nullptr;
}


//
void MyPicture::paintEvent ( QPaintEvent *  ) {
    QPainter p(this);
    // qDebug() << "paintEvent";
    QPixmap px = picture->scaled(this->width()*scale, this->height()*scale);
    p.drawPixmap(this->rect(), px);
}

//
void MyPicture::scaleChanged(int val) {
    scale = val / 100.;
    if(val == 0) {
        scale = .01;
    }
    this->repaint();
}
