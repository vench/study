#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->lineEdit->setValidator(new QIntValidator(0, 100));
    ui->spinBox->setValue(100);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//
void MainWindow::setTextEditLine(const QString & val) {
    emit changeTextEditLine(val.toInt());
}

//
void MainWindow::showAboutDialog() {
    qDebug() << "MainWindowMainWindowMainWindowMainWindow";
    QMessageBox::about(this, tr("About window"), tr("Text about my programme.\nCopyright 2018"));
}

