#include <QApplication>
#include <QTranslator>
#include "mainwindow.h"



typedef unsigned int uint;

//
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // lupdate main.cpp -ts dict_ru.ts
    // lrelease dict_ru.ts
    // cp dict_ru.qm ../build-qt_lab-Desktop-Debug/dict_ru.qm

    QTranslator translator;
    if (translator.load("dict_ru.qm", ".")) {
            a.installTranslator(&translator);
     }
    QTranslator translator1;
    if (translator1.load("qtbase_ru.qm", "/usr/share/qt5/translations/")) {
            a.installTranslator(&translator1);
     }

    MainWindow w;
    w.show();

    return a.exec();
}
