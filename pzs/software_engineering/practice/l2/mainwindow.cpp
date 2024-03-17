#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_plusBtn_clicked()
{
    int a = ui->lineEdit->text().toInt();
    int b = ui->lineEdit_2->text().toInt();
    ui->forResult->setText(QString::number(a+b));
}


void MainWindow::on_minusBtn_clicked()
{
    int a = ui->lineEdit->text().toInt();
    int b = ui->lineEdit_2->text().toInt();
    ui->forResult->setText(QString::number(a-b));
}


void MainWindow::on_multBtn_clicked()
{
    int a = ui->lineEdit->text().toInt();
    int b = ui->lineEdit_2->text().toInt();
    ui->forResult->setText(QString::number(a*b));
}


void MainWindow::on_divideBtn_clicked()
{
    double a = ui->lineEdit->text().toDouble();
    double b = ui->lineEdit_2->text().toDouble();
    if(b==0) ui->forResult->setText("Error");
    else ui->forResult->setText(QString::number(a/b));
}

