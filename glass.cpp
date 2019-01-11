#include "glass.h"

Glass::Glass(QWidget *parent) : QWidget(parent)
{
    glassArray = nullptr;
    cur = nullptr;
    next = nullptr;
    snake = nullptr;
    this->timerInterval = 250;

    connect(this, SIGNAL(signalGlassInit()), this, SLOT(slotGlassInit()), Qt::QueuedConnection);
    emit signalGlassInit();
}

Glass::~Glass() {
    qDebug() << "Glass::~Glass";
    if(glassArray) {
        delete glassArray;
    }
    glassArray = nullptr;
    if(snake) {
        delete snake;
        snake = nullptr;
    }
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
   // qDebug() << v_cols;
   // qDebug() << v_rows;
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
    this->score = 0;
    snake = new Snake();
    timerId = this->startTimer(this->timerInterval);

    qDebug() << "slotNewGame";
}

//
void Glass::keyPressEvent(QKeyEvent*event) {
    if(!gameOn || !snake) {
        return;
    }

    switch(event->key()) {
        case Qt::Key_Left:
        case Qt::Key_Right:
        case Qt::Key_Up:
        case Qt::Key_Down:
            snake->setDirection((Qt::Key)event->key());
        break;
        case Qt::Key_Space:


        break;
        default:
            QWidget::keyPressEvent(event);
        break;
    }

    repaint();
}

//
uint Glass::minLeft(uint i, uint j) {
    if(j == 0) {
        return 0;
    }
    int x = j;
    for(; x > 0; x --) {
        int index =  indexOf(i, x-1);
        if(glassArray->at(index) != emptyCell) {
            break;
        }
    }
    return x;
}

//
uint Glass::maxRight(uint i, uint j) {
    if(j + 1 == v_cols) {
        return j;
    }
    for(; j < v_cols; j ++) {
        int index =  indexOf(i, j+1);
        if(glassArray->at(index) != emptyCell) {
            break;
        }
    }
    return j;
}

//
void Glass::timerEvent(QTimerEvent *) {

    if(!gameOn) {
        return;
    }

    if(isGameOver()) {

            gameOver();

     } else {
            this->scoreCount();
            snake->updatePosition();
    }


    repaint();
}

//
bool Glass::isGameOver() {
    if(this->v_cols < snake->posj() || this->v_rows < snake->posi()) {
        return true;
    }
    // TODO
    return false;
}

//
void Glass::paintEvent(QPaintEvent*) {
    QPainter painter(this);

    for(uint i = 0; i < v_rows; i ++) {
        for(uint j = 0; j < v_cols; j ++) {
            painter.fillRect(j * W+1, i * W+1, W-2, W-2, QBrush(emptyCell));
            painter.drawRect(j * W, i * W, W, W);
        }
    }

    if(gameOn) {
        if(snake) {
            snake->drawFigure(&painter);
        }
    }

}

//
int Glass::indexOf(uint i, uint j) {
    return  i * v_cols + j;
}

//
uint Glass::minRow(uint j) {
    for(uint i = 0; i < v_rows; i ++) {
        int index = indexOf(i, j);
        if(glassArray->at(index) != emptyCell) {
            return i;
        }
    }
    return v_rows;
}

//
void Glass::scoreCount() {

   this->score = snake->size() - 1;
   emit signalUpdateScore(this->score);
}


//
void Glass::gameOver() {
    qDebug() << "Glass::gameOver";
    gameOn = false;
    this->killTimer(timerId);

    emit signalGameOver();
}
