#ifndef MYPICTURE_H
#define MYPICTURE_H

#include <QWidget>
#include <QPixmap>
#include <QPainter>
#include <QDebug>

class MyPicture : public QWidget
{
    Q_OBJECT


    QPixmap* picture;
    double scale;

public:
    explicit MyPicture(QWidget *parent = 0);
    ~MyPicture();

signals:

public Q_SLOTS:
    void scaleChanged(int);

protected:
    void paintEvent ( QPaintEvent *  );
};

#endif // MYPICTURE_H
