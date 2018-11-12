#include "spider.h"
#include <QApplication>
#include <QDebug>
#include <QTranslator>
#include <QObject>
#include <QIcon>
#include <QPixmap>
#include <QBrush>
#include <QDesktopWidget>
#include <QBitmap>
#include <QColorDialog>
#include <QFileDialog>


typedef unsigned int uint;

struct TypeFlag {
    uint Flag;
    QString Name;
};
TypeFlag flags[] = {
    TypeFlag{ 0x00000000, "Widget"},
    TypeFlag{ 0x00000001, "Window"},
    TypeFlag{ 0x00000002, "Dialog"},
    TypeFlag{ 0x00000004, "Sheet"},
    TypeFlag{ 0x00000006, "Drawer"},
    TypeFlag{ 0x00000008, "Popup"},
    TypeFlag{ 0x0000000a, "Tool"},
    TypeFlag{ 0x0000000c, "ToolTip"},
    TypeFlag{ 0x0000000e, "SplashScreen"},
    TypeFlag{ 0x00000010, "Desktop"},
    TypeFlag{ 0x00000012, "SubWindow"},
    TypeFlag{ 0x000000ff, "WindowType_Mask"},
    TypeFlag{ 0x00000100, "MSWindowsFixedSizeDialogHint"},
    TypeFlag{ 0x00000200, "MSWindowsOwnDC"},
    TypeFlag{ 0x00000400, "X11BypassWindowManagerHint"},
    TypeFlag{ 0x00000800, "FramelessWindowHint"},
    TypeFlag{ 0x00001000, "WindowTitleHint"},
    TypeFlag{ 0x00002000, "WindowSystemMenuHint"},
    TypeFlag{ 0x00004000, "WindowMinimizeButtonHint"},
    TypeFlag{ 0x00008000, "WindowMaximizeButtonHint"},
    TypeFlag{ 0x00010000, "WindowContextHelpButtonHint"},
    TypeFlag{ 0x00020000, "WindowShadeButtonHint"},
    TypeFlag{ 0x00040000, "WindowStaysOnTopHint"},
    TypeFlag{ 0x02000000, "CustomizeWindowHint"},
    TypeFlag{ 0x04000000, "WindowStaysOnBottomHint"},
    TypeFlag{ 0x08000000, "WindowCloseButtonHint"},
    TypeFlag{ 0x10000000, "MacWindowToolBarButtonHint"},
    TypeFlag{ 0x20000000, "BypassGraphicsProxyWidget"},
    TypeFlag{ 0x00080000, "WindowOkButtonHint"},
    TypeFlag{ 0x00100000, "WindowCancelButtonHint"},
    TypeFlag{ 0x40000000, "WindowSoftkeysVisibleHint"},
    TypeFlag{ 0x80000000, "WindowSoftkeysRespondHint"}
};

void task1(QWidget* w) {
    qDebug() << "Task 1";
    Qt::WindowType type1 = w->windowType();
    qDebug() << "Default Qt::WindowType: " << type1;
    Qt::WindowFlags flag1 = w->windowFlags();
    qDebug() << "Default Qt::WindowFlags: " << flag1;
    for(TypeFlag item : flags) {
        if((flag1 & item.Flag) > 0 ) {
            qDebug() << "Enabled flag: "  << item.Name << " => " << (flag1 & item.Flag);
        }
    }

    Qt::WindowFlags flag2 = Qt::Dialog; // Qt::Dialog;  Qt::Window;
    flag2 |= Qt::WindowTitleHint |
            Qt::WindowSystemMenuHint |
            Qt::WindowMinimizeButtonHint  |
            Qt::WindowMaximizeButtonHint | Qt::WindowCloseButtonHint;
    w->setWindowFlags(flag2);
    w->show();

    // set default
    w->setWindowFlags(Qt::Window | Qt::WindowTitleHint  | Qt::WindowCloseButtonHint);
    w->show();
}

void task2(QWidget* w) {
   // w->showFullScreen();
    w->showMaximized();
    w->showMinimized();
    w->showNormal();
}

void task3(QWidget* w) {
    QString title = QObject::tr("Hello world!");
    w->setWindowTitle(title);

    qDebug() << QObject::tr("red") << QLocale::system().name();
}

void task4(QWidget* w) {
    QIcon icon(":/icon.ico");
    w->setWindowIcon(icon);
    w->show();
}



void task5(QWidget* w) {
  //  w->setStyleSheet("background-color: red");

    QPalette sample_palette;
    sample_palette.setColor(QPalette::Active, QPalette::Background,  Qt::blue);
    sample_palette.setColor(QPalette::Inactive, QPalette::Background,  Qt::yellow);


    QPixmap pix(":icon.ico");
    QBrush brush(pix);
    sample_palette.setBrush(QPalette::Active, QPalette::Background, brush);

    w->setAutoFillBackground(true);
    w->setPalette(sample_palette);

   // w->setWindowOpacity(.5);
   // w->show();
}

void task6(QWidget* w) {
    w->move(100,100);
    w->resize(320, 240);

    QDesktopWidget* d = QApplication::desktop();
    QRect r = d->screenGeometry();

    w->move(r.right()-w->width(),r.bottom() - w->height());

    w->setMinimumSize(100,100);
    w->setMaximumSize(800,600);

    w->setFixedSize(640, 480);
}

void task7(QWidget* w) {
    QCursor cr = Qt::CrossCursor;
    w->setCursor(cr);
    w->unsetCursor();

    QPixmap pix(":cursor.jpeg");
    pix.setMask(QBitmap(":cursor.jpeg"));
    QCursor cr1(pix.scaled(28,28));
    w->setCursor(cr1);
}

void task11(QWidget* w) {
    QPalette sample_palette;
     QColor color = QColorDialog::getColor();
     if(color.isValid()) {

       sample_palette.setColor(QPalette::Inactive, QPalette::Background,  color);
       w->setPalette(sample_palette);
     }
      QString str=QFileDialog::getOpenFileName(0,QString::fromUtf8("Выбор файла"), ".", "*.bmp *.jpg *.png" );
      if(!str.isEmpty()) {
          QPixmap pix(str);
          QBrush brush(pix);
          sample_palette.setBrush(QPalette::Active, QPalette::Background, brush);
      }
      w->setPalette(sample_palette);
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // lupdate main.cpp -ts dict_ru.ts
    // cp dict_ru.qm ../build-qt_lab-Desktop-Debug/dict_ru.qm
    // lrelease dict_ru.ts
    QTranslator translator;
    if (translator.load("dict_ru.qm", ".")) {
            a.installTranslator(&translator);
     }
    if (translator.load("qtbase_ru.qm", "/usr/share/qt5/translations/")) {
            a.installTranslator(&translator);
     }



    Spider w;    
    w.show();

    task1(&w);
    task2(&w);
    task3(&w);
    task4(&w);
    task5(&w);
    task6(&w);
    task7(&w);
    task11(&w);

    return a.exec();
}
