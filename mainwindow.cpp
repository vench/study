#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{

    setWindowTitle("Signal and slot");
    resize(480, 120);


    mapper = new QSignalMapper(this);


    buttonExit=new QPushButton(QObject::tr("Exit"),this);
    connect(buttonExit, SIGNAL(clicked()), this, SLOT(clickBtnExit()));

    buttonDisabled=new QPushButton(QObject::tr("Disabled"),this);
    connect(buttonDisabled, SIGNAL(clicked()), this, SLOT(clickBtnDisabled()));
    buttonStyle =new QPushButton(QObject::tr(BTN_STYLE_TWO),this);
    connect(buttonStyle, SIGNAL(clicked()), this, SLOT(clickBtnStyle()));

    labelTest = new QLabel(intToStringValue(DEFAULT_VALUE), this);
    labelTest->setFrameStyle(1);
    labelTest->setMinimumWidth(10);
    labelTest->setAlignment(Qt::AlignCenter);
    labelTest->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    lineEdit = new QLineEdit(this);
    lineEdit->setValidator(new QIntValidator(MIN_VALUE,MAX_VALUE));
    lineEdit->setText(intToStringValue(DEFAULT_VALUE));
    connect(lineEdit, SIGNAL(textChanged(QString)), this, SLOT(lineEdit_textChanged(QString)));

    spinBox = new QSpinBox(this);
    spinBox->setRange(MIN_VALUE,MAX_VALUE);
    spinBox->setValue(DEFAULT_VALUE);
   // spinBox->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    spinBox->setFixedSize(spinBox->sizeHint());
    connect(spinBox, SIGNAL(valueChanged(int)), this, SLOT(spinBox_valueChanged(int)));

    slider = new QSlider(Qt::Horizontal ,this);
    slider->setRange(MIN_VALUE,MAX_VALUE);
    slider->setSliderPosition(DEFAULT_VALUE);
    slider->setTickInterval(10);
    //slider->setTracking(false);
    slider->setSingleStep(5);
    connect(slider, SIGNAL(valueChanged(int)), this, SLOT(slider_valueChanged(int)));

    combo = new QComboBox(this);
    combo->addItem("QSpinBox");
    combo->addItem("QSlider");
    combo->addItem("QLineEdit");
    combo->hide();

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

    gLayout = new QGridLayout();
    gLayout->addWidget(spinBox, 0,0);
    gLayout->addWidget(slider, 0,1);
    gLayout->addWidget(lineEdit, 1,0);
    gLayout->addWidget(labelTest,1,1);

    sLayout = new QStackedLayout();
    sLayout->addWidget(spinBox);
    sLayout->addWidget(slider);
    sLayout->addWidget(lineEdit);

    demoStackLayout = new QVBoxLayout();
    demoStackLayout->addWidget(combo);
    demoStackLayout->addWidget(labelTest);
    demoStackLayout->addLayout(sLayout);


    buttonsLayout = new QVBoxLayout();
    buttonVertival=new QPushButton(QObject::tr("Vertical"),this);
    buttonsLayout->addWidget(buttonVertival);
    connect(buttonVertival, SIGNAL(clicked(bool)), mapper, SLOT(map()));

    buttonHorizontal=new QPushButton(QObject::tr("Horizontal"),this);
    buttonsLayout->addWidget(buttonHorizontal);
    connect(buttonHorizontal, SIGNAL(clicked(bool)), mapper, SLOT(map()));

    buttonGrid=new QPushButton(QObject::tr("Table"),this);
    buttonsLayout->addWidget(buttonGrid);
    connect(buttonGrid, SIGNAL(clicked(bool)), mapper, SLOT(map()));

    buttonStacked=new QPushButton(QObject::tr("Stack"),this);
    buttonsLayout->addWidget(buttonStacked);
    connect(buttonStacked, SIGNAL(clicked(bool)), mapper, SLOT(map()));

    mapper->setMapping(buttonHorizontal, hLayout);
    mapper->setMapping(buttonVertival, vLayout);
    mapper->setMapping(buttonGrid, gLayout);
    mapper->setMapping(buttonStacked, demoStackLayout);

    connect(mapper, SIGNAL(mapped(QObject*)), this, SLOT(changeLayout(QObject*)));
    connect(combo, SIGNAL(activated(int)), sLayout, SLOT(setCurrentIndex(int)));


    panelControll = new QFrame(this);
    layoutPanelControll = new QHBoxLayout(panelControll);
    layoutPanelControll->addLayout(hLayout);
    layoutPanelControll->addLayout(buttonsLayout);

    menuBtm = new QVBoxLayout();
    menuBtm->addWidget(buttonExit);
    menuBtm->addWidget(buttonStyle);
    menuBtm->addWidget(buttonDisabled);

    mainLayout=new QHBoxLayout(this);
    mainLayout->addWidget(panelControll);
    mainLayout->addLayout(menuBtm);


    changeLayout(hLayout);

    // synch
    spinBox->setValue(10);

}

//
MainWindow::~MainWindow()
{
    delete hLayout;
    delete vLayout;
    delete gLayout;
    delete sLayout;
    delete buttonsLayout;
    delete demoStackLayout;
    delete menuBtm;
}

//
void MainWindow::clickBtnExit() {
    qDebug() << "clickBtn";
    close();
}


//
void MainWindow::changeLayout(QObject*pNewLayout) {

    if(pNewLayout==demoStackLayout)  {
        combo->setVisible(true);
        spinBox->hide();
        lineEdit->hide();
        slider->hide();
        sLayout->currentWidget()->show();
        sLayout->setStackingMode(QStackedLayout::StackOne);
    } else  {
        combo->setVisible(false);
        sLayout->setStackingMode(QStackedLayout::StackAll);
    }

    QLayoutItem * pItem= layoutPanelControll->itemAt(0);
    layoutPanelControll->removeItem(pItem);
    layoutPanelControll->insertLayout(0,static_cast<QLayout *>(pNewLayout));
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
void MainWindow::clickBtnDisabled() {
    qDebug() << "panelControll";
    panelControll->setDisabled(!!panelControll->isEnabled());
}

//
void MainWindow::clickBtnStyle() {
    qDebug() << QStyleFactory::keys();
    if(buttonStyle->text() == BTN_STYLE_ONE) {
        QApplication::setStyle(QStyleFactory::create("Windows"));
        buttonStyle->setText(BTN_STYLE_TWO);
    } else {
        buttonStyle->setText(BTN_STYLE_ONE);
        QApplication::setStyle(QStyleFactory::create("Motif"));
    }

}

