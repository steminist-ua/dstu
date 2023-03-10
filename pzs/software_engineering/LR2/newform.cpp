#include "newform.h"
#include "ui_newform.h"
#include "dialog.h"

#include <QMessageBox>

newForm::newForm(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::newForm)
{
    ui->setupUi(this);
}

newForm::~newForm()
{
    delete ui;
}

void newForm::on_radioButton_clicked(bool checked)
{
    //if(checked == true) - це перевірка умови, що змінна checked дорівнює значенню true.
    //if(checked) - це скорочений запис тієї ж умови

    if(checked)
    {
        ui->label->setStyleSheet("image: url(:/img/img/Asset 1.png);");
        //якщо було обрано перший radioButton на формі, то змінюється стиль елементу label, йому задається відповідне зображення. Звернення до стилів відбувається за допомогою методу setStyleSheet, де в якості параметру у лапках вказується назва  властивості, яку потрібно змінити (в цьому випадку це image), далі двокрапка і далі значення властивості (в цьому випадку це шлях до зображення з доданого ресурсу - url(:/img/img/Asset 1.png))
    }
}


void newForm::on_radioButton_2_clicked(bool checked)
{
    if(checked)
    {
        ui->label->setStyleSheet("image: url(:/img/img/Asset 4.png);");
    }
}


void newForm::on_radioButton_3_clicked(bool checked)
{
    if(checked)
    {
        ui->label->setStyleSheet("image: url(:/img/img/Asset 3.png);");
    }
}


void newForm::on_radioButton_4_clicked(bool checked)
{
    if(checked)
    {
        ui->label->setStyleSheet("image: url(:/img/img/Asset 2.png);");
    }
}


void newForm::on_radioButton_5_clicked(bool checked)
{
    if (checked)
        {
            ui->label_2->setStyleSheet("background-color: rgb(219, 245, 214);");
            //тут у стилях змінюється не зображення, а колір фону. За це відповідає властивість background-color і далі, через двокрапку, вказується колір (rgb або, наприклад, у шістнадцятковій системі, тобто через # )
        }
}


void newForm::on_radioButton_6_clicked(bool checked)
{
    if (checked)
        {
            ui->label_2->setStyleSheet(" ");
        }
}


void newForm::on_actionForm_2_changed()
{

}


void newForm::on_actionForm_1_triggered()
{
    /*
     * для того, щоб при обранні певного пункту меню відкривати іншу форму:
     * 1. створити у проєкті новий елемент - правою кнопкою миші на назву проєкту, далі "Добавить новый...". У вікні, яке з'явилося обрати розділ Qt, а справа обрати "Класс формы Qt Designer". Далі у новому вікну обрати шаблон. Зверніть увагу! Необхідно обрати будь-який варіант саме діалогового вінка, наприклад, якщо потрібне порожнє, то "Dialog without Buttons".
     * 2. підключити у cpp файлі головної форми (де меню) заголовочний файл створенної форми #include "dialog.h"
     * 3. створити обробку події кліку на пункт меню (у режимі дизайну обрати пункт меню, правою кнопкою миші, "Перейти к слоту...". Обрати подію triggered
     * 4. створити екземпляр класу створеної форми
     * 5. вказати влкастивість модального вікна setModal(true)
     * 6. вказати метод відображення цього вікна, цієї форми exec()
    */
    Dialog w;
    w.setModal(true);
    w.exec();
}

