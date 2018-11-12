#include "spider.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Spider w;
    w.show();

    return a.exec();
}
