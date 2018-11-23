#ifndef SPIDER_H
#define SPIDER_H

#include <QWidget>
#include <QDebug>
#include <QPushButton>
#include <QHBoxLayout>
#include <QSpinBox>
#include <QLineEdit>
#include <QLabel>
#include <QSlider>
#include <QVBoxLayout>

class MainWindow : public QWidget
{
    Q_OBJECT


    const int MIN_VALUE = 0;
    const int MAX_VALUE = 100;
    const int DEFAULT_VALUE = 10;


    QHBoxLayout* hLayout;
    QPushButton*buttonExit;
    QLabel*labelTest;
    QLineEdit *lineEdit;
    QSpinBox*spinBox;
    QSlider*slider;
    QHBoxLayout* mainLayout;
    QVBoxLayout* buttonsLayout;
    QPushButton*    buttonVertival;
    QPushButton*    buttonHorizontal;


public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();


protected:
    QString intToStringValue(int);

protected Q_SLOTS:
    void clickBtnExit();
    void click_buttonVertival();
    void click_buttonHorizontal();
    void spinBox_valueChanged(int);
    void slider_valueChanged(int);
    void lineEdit_textChanged(QString);
};

#endif // SPIDER_H
