#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    csvModel = new QStandardItemModel(this);    //Створюємо модель даних для відображення таблиці з файлу CSV
    csvModel->setColumnCount(12);               //вказуємо кількість колонок у наборі даних (в прикладі 12 колонок)
    csvModel->setHorizontalHeaderLabels(QStringList() << "name" << "mpg" << "cyl" << "disp" << "hp" << "drat" << "wt" << "qsec" << "vs" << "am" << "gear" << "carb");                   // задаємо назви всіх колонок, вказуємо які підписи будуть відображатися на формі (можна задавати будь-які)
    ui->tableView->setModel(csvModel);          // передаємо нашу створену модель до елементу таблиці на формі (зверніть увагу, попередньо додайте у конструкторі елемент tableView на форму


    // звертаємося до файлу з ресурсів проєкту (звернуть увагу, попередньо потрібно додати файл ресурсів до проєкту, задати префікс та додати csv файл
    // або, можна передати абсолютний шлях до файлу
    QFile file(":/exampleTable.csv");

    // відкриваємо файл для зчитування (якщо не вдалося, то видаємо повідомлення про помилку)
    if ( !file.open(QFile::ReadOnly | QFile::Text) ) {
        qDebug() << "File not exists";
    }

    // якщо файл є і все доступно
    else {
        QTextStream in(&file);      // То створюємо поток для вилучання даних з файлу
        while (!in.atEnd())         // Зчитуємо дані до кінця файлу (до останнього рядка)
        {
            QString line = in.readLine();               // зчитуємо поточний рядок з файлу
            QList<QStandardItem *> standardItemsList;   // створюємо змінну List для зберігання колонок
            for (QString item : line.split(",")) {
                // розбиваємо зчитаний рядок на колонки (в файлі csv в прикладі колонки розділені комою, тому у якості параметру передано саме цей символ. Звернуть увагу, що у csv файлі може бути вказано розділення і ";"
                standardItemsList.append(new QStandardItem(item));
            }
            csvModel->insertRow(csvModel->rowCount(), standardItemsList);   // вставляємо у модель в останній рядок поточний набір колонок
        }
        file.close(); // після зчитування всіх рядків закриваємо поток відкритого файлу
    }
}

MainWindow::~MainWindow()
{
    delete ui;
    delete csvModel;    // додаємо очищення у дескриптор
}
