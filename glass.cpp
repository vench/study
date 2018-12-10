#include "glass.h"

Glass::Glass(QWidget *parent) : QWidget(parent)
{
    glassArray = nullptr;
    cur = nullptr;
    next = nullptr;
    this->timerInterval = 550;

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
    this->score = 0;
    timerId = this->startTimer(this->timerInterval);

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
        case Qt::Key_Up:
            cur->changeUp();
        break;
        case Qt::Key_Down:
            cur->changeDown();
        break;
        case Qt::Key_Space:
            cur->newPos(minRow(cur->posj())-3, cur->posj());
        break;
        default:
            QWidget::keyPressEvent(event);
        break;
    }

    repaint();
}

//
void Glass::timerEvent(QTimerEvent *) {

    if(!gameOn) {
        return;
    }

    if(!next) {
        next = new Figure(0, v_cols / 2);

    }

    if (tickScore) {
        scoreCount();
        return;
    }

    if(!cur) {
        cur = new Figure(0, v_cols / 2);
    } else {

        if(cur->posi() + 3 >= minRow(cur->posj())) {

            if(cur->posi() == 0) {
                 gameOver();
                 return;
            }

            // copy
            for(int i = 0; i < 3; i ++) {
                int index = indexOf(cur->posi()+i, cur->posj());
                glassArray->replace(index, cur->colorAt(i));
            }

            // check score
            this->scoreCount();

            //
            delete cur;
            cur = next;
            next = nullptr;
        } else {
            cur->newPos(cur->posi()+1, cur->posj());
        }
    }




    repaint();
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
        if(cur) {
            cur->drawFigure(&painter);
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
                //scoreCount();
                return;
            }
        }
    }
}


//
void Glass::gameOver() {
    this->killTimer(timerId);
}
