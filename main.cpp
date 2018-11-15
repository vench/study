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

//
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
    QTranslator translator1;
    if (translator1.load("qtbase_ru.qm", "/usr/share/qt5/translations/")) {
            a.installTranslator(&translator1);
     }



    Spider w;    
    w.show();


    return a.exec();
}
