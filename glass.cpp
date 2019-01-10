#include "glass.h"

Glass::Glass(QWidget *parent) : QWidget(parent)
{
    glassArray = nullptr;
    cur = nullptr;
    next = nullptr;
    snake = nullptr;
    this->timerInterval = 550;

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

    if (tickScore) {
        scoreCount();
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
    return false;
}

//
void Glass::paintEvent(QPaintEvent*) {



    QPainter painter(this);


    for(uint i = 0; i < v_rows; i ++) {
        for(uint j = 0; j < v_cols; j ++) {
            int index = indexOf(i, j);
            QColor c = glassArray->at(index);
            painter.fillRect(j * W+1, i * W+1, W-2, W-2, QBrush(c));
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

    tickScore = false;
    for(int y = v_rows - 1; y >= 0; y --) {
        for(uint x = 0; x < v_cols; x ++) {
            int index = indexOf(y, x);
            QColor a = glassArray->at(index);
            if(a == emptyCell) {
                continue;
            }

            // to left
            uint j = x+1;
            for(; j < v_cols; j ++) {
                index = indexOf(y, j);
                if(a != glassArray->at(index)) {
                    break;
                }
            }

            if(j - x > 2) {
                // shift
                this->score += j - x - 2;
                emit signalUpdateScore(this->score);

               // qDebug() << "New score " << this->score;
               //  qDebug() << "New score " << j << x;

                for(uint x2 = x; x2 < j; x2 ++) {
                    for(int y2 = y-1; y2 >= 0; y2 --) {
                        index = indexOf(y2, x2);
                        QColor b =glassArray->at(index);
                        if(b == emptyCell) {
                            //continue;
                        }
                        glassArray->replace(index, emptyCell);
                        if(index+v_cols < v_cols * v_rows) {
                            glassArray->replace(index+v_cols, b);
                        }
                    }
                }

                tickScore = true;
                repaint();
                return;
            }

            // to top
            uint i = y-1;
            for(; i > 0; i --) {
                index = indexOf(i, x);
                if(a != glassArray->at(index)) {
                    break;
                }
            }

            if(y - i > 2) {
                // shift
                //qDebug() << "shift " << y - i;
                int diff = y - i;
                this->score += y - i - 2;
                emit signalUpdateScore(this->score);

                for(int y2 = y-diff; y2 >= 0; y2 --) {
                    index = indexOf(y2, x);
                    QColor b =glassArray->at(index);

                    glassArray->replace(index, emptyCell);
                    if(index+v_cols < v_cols * v_rows) {
                        glassArray->replace(index+v_cols*diff, b);
                    }
                }

                tickScore = true;
                repaint();
                return;
            }
        }
    }
}


//
void Glass::gameOver() {
    qDebug() << "Glass::gameOver";
    gameOn = false;
    this->killTimer(timerId);

    if(cur){
        delete cur;
        cur = nullptr;
    }
    if(next) {
        delete next;
        next = nullptr;
    }

    emit signalGameOver();
}
