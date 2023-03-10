#include "lr2.h"
#include "ui_lr2.h"

#include <QMessageBox>


lr2::lr2(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::lr2)
{
    ui->setupUi(this);
}

lr2::~lr2()
{
    delete ui;
}


void lr2::on_pushButton_clicked()
{
    QString text = ui->lineEdit->text(); // зчитування значення з текстового елемента форми
    QMessageBox::about(this, "Назва", text); // виклик вікна з повідомленням
}

