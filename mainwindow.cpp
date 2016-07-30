#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonCalculate_released()
{
    QString text =  ui->lineEditFraction->text();
    text.replace(QChar( ',' ) , QChar( '.' ) );
    ui->lineEditFraction->setText(text);

    convertFractionToBinary ();
}

void MainWindow::convertFractionToBinary()
{
    bits = ui->spinBoxBits->value();
    fraction_input = ui->lineEditFraction->text().toDouble();
    qDebug() << "Fraction = " << qSetRealNumberPrecision( 24 ) << fraction_input;

    double  substraction = 0;
    double  remain = fraction_input;
    QString bitVektor = "";
    int64_t registerValue = 0;
    double  calculatedValue = 0;

    for (int i= 1;i <= bits;i++)
    {
        substraction = qPow(2,(-1 * i));

        if (remain >= substraction)
        {
            remain = remain - substraction;
            bitVektor.append("1");
            registerValue += qPow(2,i);
            calculatedValue += substraction;
        }
        else
        {
            bitVektor.append("0");
        }
    }

    error = 100 - (calculatedValue * 100) / fraction_input;

    ui->lineEditBitResult->setText(bitVektor);
    ui->lineEditBitRegister->setText(QString::number(registerValue));
    ui->labelError->setText(QString::number(calculatedValue));
    ui->labelErrorPercent->setText(QString::number(error,'f',4));
}

void MainWindow::on_pushButtonReset_released()
{
    ui->lineEditBitRegister->setText("");
    ui->lineEditBitResult->setText("");
    ui->lineEditBitRegister->setText("");
}
