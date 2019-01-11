#ifndef GLASS_H
#define GLASS_H

#include <QWidget>
#include <QColor>
#include <QVector>
#include <QDebug>
#include <QPainter>
#include <QKeyEvent>
#include <QThread>
#include "figure.h"
#include "snake.h"



class Glass : public QWidget
{
    Q_OBJECT

    Q_PROPERTY(uint rows READ rows WRITE setRows)
    Q_PROPERTY(uint cols READ cols WRITE setCols)


    static const int W = 30;

    uint timerInterval;
    uint v_cols;
    uint v_rows;
    bool gameOn;
    uint score;
    QVector<QColor> *glassArray;
    int timerId;

    Figure *cur;
    Figure *next;
    Snake *snake;

public:
    explicit Glass(QWidget *parent = 0);
    ~Glass();


    void setRows(uint rows);
    uint rows() const;
    void setCols(uint cols);
    uint cols() const;

    void clearGlass();
    inline int indexOf(uint i, uint j);
    uint minRow(uint i);
    uint minLeft(uint i, uint j);
    uint maxRight(uint i, uint j);
    void gameOver();
    bool isGameOver();
    void scoreCount();

signals:
    void signalGlassInit();
    void signalUpdateScore(int);
    void signalNewFigure(Figure);
    void signalGameOver();

public slots:
    void slotGlassInit();
    void slotNewGame();

protected:
    void paintEvent(QPaintEvent*);
    void keyPressEvent(QKeyEvent*);
    void timerEvent(QTimerEvent *);
};

#endif // GLASS_H
