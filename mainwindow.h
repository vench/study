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
#include <QSignalMapper>
#include <QGridLayout>
#include <QStackedLayout>
#include <QComboBox>
#include <QStyleFactory>
#include <QApplication>
#include <QFrame>

class MainWindow : public QWidget
{
    Q_OBJECT


    const int MIN_VALUE = 0;
    const int MAX_VALUE = 100;
    const int DEFAULT_VALUE = 10;
    const char* BTN_STYLE_ONE = "Windows style";
    const char* BTN_STYLE_TWO = "Motif style";


    QHBoxLayout* hLayout;
    QVBoxLayout* vLayout;
    QGridLayout* gLayout;
    QStackedLayout* sLayout;
    QVBoxLayout* demoStackLayout;
    QVBoxLayout* menuBtm;
    QPushButton* buttonExit;
    QPushButton* buttonDisabled;
    QPushButton* buttonStyle;
    QHBoxLayout* layoutPanelControll;
    QFrame* panelControll;

    QLabel* labelTest;
    QLineEdit* lineEdit;
    QSpinBox* spinBox;
    QSlider* slider;
    QHBoxLayout* mainLayout;
    QVBoxLayout* buttonsLayout;
    QPushButton*    buttonVertival;
    QPushButton*    buttonHorizontal;
    QPushButton*    buttonGrid;
    QPushButton*    buttonStacked;
    QSignalMapper* mapper;
    QComboBox* combo;




public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();


protected:
    QString intToStringValue(int);


protected Q_SLOTS:
    void clickBtnExit();
    void clickBtnDisabled();
    void clickBtnStyle();
    void spinBox_valueChanged(int);
    void slider_valueChanged(int);
    void lineEdit_textChanged(QString);
    void changeLayout(QObject*pNewLayout);
};

#endif // SPIDER_H
