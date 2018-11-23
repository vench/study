#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{

    setWindowTitle("Signal and slot");
    resize(480, 120);


    mapper = new QSignalMapper(this);


    buttonExit=new QPushButton(QObject::tr("Exit"),this);
    connect(buttonExit, SIGNAL(clicked()), this, SLOT(clickBtnExit()));

    labelTest = new QLabel(intToStringValue(DEFAULT_VALUE), this);
    labelTest->setFrameStyle(1);
    labelTest->setMinimumWidth(10);
    labelTest->setAlignment(Qt::AlignCenter);

    lineEdit = new QLineEdit(this);
    lineEdit->setValidator(new QIntValidator(MIN_VALUE,MAX_VALUE));
    lineEdit->setText(intToStringValue(DEFAULT_VALUE));
    connect(lineEdit, SIGNAL(textChanged(QString)), this, SLOT(lineEdit_textChanged(QString)));

    spinBox = new QSpinBox(this);
    spinBox->setRange(MIN_VALUE,MAX_VALUE);
    spinBox->setValue(DEFAULT_VALUE);
    connect(spinBox, SIGNAL(valueChanged(int)), this, SLOT(spinBox_valueChanged(int)));

    slider = new QSlider(Qt::Horizontal ,this);
    slider->setRange(MIN_VALUE,MAX_VALUE);
    slider->setSliderPosition(DEFAULT_VALUE);
    slider->setTickInterval(10);
    //slider->setTracking(false);
    slider->setSingleStep(5);
    connect(slider, SIGNAL(valueChanged(int)), this, SLOT(slider_valueChanged(int)));

    hLayout = new QHBoxLayout();
    hLayout->addWidget(spinBox, 0);
    hLayout->addWidget(slider, 3);
    hLayout->addWidget(lineEdit, 2);
    hLayout->addWidget(labelTest,0);

    vLayout = new QVBoxLayout();
    vLayout->addWidget(spinBox, 0);
    vLayout->addWidget(slider, 3);
    vLayout->addWidget(lineEdit, 2);
    vLayout->addWidget(labelTest,0);



    buttonsLayout = new QVBoxLayout();
    buttonVertival=new QPushButton(QObject::tr("Vertical"),this);
    buttonsLayout->addWidget(buttonVertival);
    connect(buttonVertival, SIGNAL(clicked(bool)), mapper, SLOT(map()));
    buttonHorizontal=new QPushButton(QObject::tr("Horizontal"),this);
    buttonsLayout->addWidget(buttonHorizontal);
    connect(buttonHorizontal, SIGNAL(clicked(bool)), mapper, SLOT(map()));

    mainLayout=new QHBoxLayout(this);
    mainLayout->addLayout(hLayout);
    mainLayout->addLayout(vLayout);
    mainLayout->addLayout(buttonsLayout);
    mainLayout->addWidget(buttonExit);

    mapper->setMapping(buttonHorizontal, hLayout);
    mapper->setMapping(buttonVertival, vLayout);

    connect(mapper, SIGNAL(mapped(QObject*)), this, SLOT(changeLayout(QObject*)));
}

//
MainWindow::~MainWindow()
{
    delete hLayout;
}

//
void MainWindow::clickBtnExit() {
    qDebug() << "clickBtn";
    close();
}


//
void MainWindow::changeLayout(QObject*pNewLayout) {
    QLayoutItem * pItem= mainLayout->itemAt(0);
    mainLayout->removeItem(pItem);
    mainLayout->insertLayout(0,static_cast<QLayout *>(pNewLayout));
    qDebug() << "chnage ";
}


//
void MainWindow::spinBox_valueChanged(int value) {
    labelTest->setText( intToStringValue(value) );
    lineEdit->setText( intToStringValue(value)  );
    slider->setSliderPosition(value);
}

//
void MainWindow::slider_valueChanged(int value) {
    labelTest->setText( intToStringValue(value) );
    lineEdit->setText( intToStringValue(value)  );
    spinBox->setValue(value);
}

//
void MainWindow::lineEdit_textChanged(QString value) {
    labelTest->setText( value );
    spinBox->setValue( value.toInt() );
    slider->setSliderPosition( value.toInt() );
}

//
QString MainWindow::intToStringValue(int value) {
    return QString("%1").arg(value) ;
}

//
void MainWindow::click_buttonVertival() {
    qDebug() << "click_buttonVertival";
}

//
void MainWindow::click_buttonHorizontal() {
    qDebug() << "click_buttonHorizontal";
}
