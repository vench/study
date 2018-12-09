#include "glass.h"

Glass::Glass(QWidget *parent) : QWidget(parent)
{
    glassArray = nullptr;
    cur = nullptr;
    this->timerInterval = 500;


    connect(this, SIGNAL(signalGlassInit()), this, SLOT(slotGlassInit()), Qt::QueuedConnection);
    emit signalGlassInit();
}

Glass::~Glass() {
    if(glassArray) {
        delete glassArray;
    }
    glassArray = nullptr;
}

//
void Glass::setRows(uint rows) {
    v_rows = rows;
}

//
uint Glass::rows() const {
    return v_rows;
}

//
void Glass::setCols(uint cols) {
    v_cols = cols;
}

//
uint Glass::cols() const {
    return v_cols;
}

//
void Glass::slotGlassInit() {
    qDebug() << "signalGlassInit";
    qDebug() << v_cols;
    qDebug() << v_rows;
    glassArray = new QVector<QColor>();
    glassArray->resize(v_cols * v_rows);
    glassArray->fill(emptyCell);
    QSize s(v_cols * W + 1, v_rows * W + 1);
    this->setFixedSize(s);
}

//
void Glass::slotNewGame() {

    gameOn = true;
    glassArray->fill(emptyCell);
    this->setFocus();
    this->startTimer(this->timerInterval);

    qDebug() << "slotNewGame";
}

//
void Glass::keyPressEvent(QKeyEvent*event) {
    if(!gameOn) {
        return;
    }

    //
    if(!cur) {
        return;
    }

    switch(event->key()) {
        case Qt::Key_Left:
            if( cur->posj() > 0)
                cur->newPos(cur->posi(), cur->posj()-1);
        break;
        case Qt::Key_Right:
            if(cur->posj()+1 < v_cols)
                cur->newPos(cur->posi(), cur->posj()+1);
        break;
    }
}

//
void Glass::timerEvent(QTimerEvent *) {
     qDebug() << "timerEvent";
    if(!gameOn) {
        return;
    }

    if(!cur) {
        cur = new Figure(0, v_cols / 2);
    } else {
        cur->newPos(cur->posi()+1, cur->posj());
    }

    repaint();
}

//
void Glass::paintEvent(QPaintEvent*) {
    QPainter painter(this);

    for(uint i = 0; i < v_rows; i ++) {
        for(uint j = 0; j < v_cols; j ++) {
            int index = i * v_cols + j;
            QColor c = glassArray->at(index);
            painter.fillRect(j * W+1, i * W+1, W-2, W-2, QBrush(c));
            painter.drawRect(j * W, i * W, W, W);
        }
    }

    if(gameOn) {
        if(cur) {
            cur->drawFigure(&painter);
        }
    }
}

