#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QtMath>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButtonCalculate_released();

    void on_pushButtonReset_released();

private:
    Ui::MainWindow *ui;
    double fraction_input;
    double error;
    int    bits;

    void  convertFractionToBinary(void);
};

#endif // MAINWINDOW_H
