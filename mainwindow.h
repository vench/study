#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QIntValidator>
#include <QDebug>
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public Q_SLOTS:
    void setTextEditLine(const QString &);
    void showAboutDialog();

Q_SIGNALS:
    void changeTextEditLine( int );

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
