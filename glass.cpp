#include "glass.h"

Glass::Glass(QWidget *parent) : QWidget(parent)
{
    glassArray = nullptr;
    cur = nullptr;
    next = nullptr;
    snake = nullptr;
    pointEat = nullptr;
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
    if(pointEat) {
        delete pointEat;
        pointEat = nullptr;
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
    pointEat = new Pointeat();
    updatePosPointEat();
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
uint Glass::minLeft(uint, uint) {
    return 0;
}

//
uint Glass::maxRight(uint, uint) {
    return 0;
}

//
void Glass::timerEvent(QTimerEvent *) {

    if(!gameOn) {
        return;
    }

    uint pj = snake->posj();
    uint pi = snake->posi();
    switch(snake->direction()) {
    case Qt::Key_Left:
        pj --;
        break;
    case Qt::Key_Right:
        pj ++;
        break;
    case Qt::Key_Up:
        pi --;
        break;
    case Qt::Key_Down:
        pi ++;
        break;
    default:
        break;
    }

    if(isGameOver(pi, pj)) {
            gameOver();
     } else {            
            snake->newPos(pi, pj);
            this->scoreCount();
    }

    repaint();
}

//
bool Glass::isGameOver(uint pi, uint pj) {
    if(this->v_cols <= pj || this->v_rows <= pi) {
        return true;
    }

    return snake->inPos(pi,pj);
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

    if(pointEat) {
        pointEat->drawFigure(&painter);
    }

    if(snake) {
        snake->drawFigure(&painter);
    }
}

//
int Glass::indexOf(uint i, uint j) {
    return  i * v_cols + j;
}

//
uint Glass::minRow(uint ) {
    return 0;
}

//
void Glass::scoreCount() {

   if(pointEat->posi() == snake->posi() && pointEat->posj() == snake->posj()) {
       updatePosPointEat();
       snake->addSize();
   }
   this->score = snake->size() - 1;
   emit signalUpdateScore(this->score);
}

//
void Glass::updatePosPointEat() {


    while(true) {
        uint i = rand() % v_rows;
        uint j = rand() % v_cols;

        if(snake->inPos(i,j)) {
            continue;
        }

        pointEat->newPos(i,j);
        break;
    }
}


//
void Glass::gameOver() {
    qDebug() << "Glass::gameOver";
    gameOn = false;
    this->killTimer(timerId);

    emit signalGameOver();
}
