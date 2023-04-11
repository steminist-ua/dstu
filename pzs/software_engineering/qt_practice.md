# Qt C++ Form Arrays

## 1. приклад роботи з формами на Qt C++ для початківців за допомогою конструктора

У цьому прикладі ми створимо форму з двома текстовими полями та кнопкою для додавання чисел з цих полів.

Для початку створіть новий проект на Qt Creator та виберіть шаблон "Qt Widgets Application". Після цього додайте нову форму за допомогою контекстного меню проекту "Add New...", виберіть "Qt" > "Qt Designer Form Class" та додайте форму з двома текстовими полями та кнопкою. В нашому прикладі форма буде називатись "AddDialog".

Коли форма буде створена, Qt Creator автоматично згенерує відповідний код у файлах "adddialog.ui" та "adddialog.h". Тепер ми можемо змодифікувати код у файлі "adddialog.h", щоб додати логіку нашого додатку:

```cpp
#ifndef ADDDIALOG_H
#define ADDDIALOG_H

#include <QDialog>namespace Ui {
class AddDialog;
}

class AddDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddDialog(QWidget *parent = nullptr);
    ~AddDialog();

private slots:
    void on_addButton_clicked();

private:
    Ui::AddDialog *ui;
};

#endif // ADDDIALOG_H

```

У цьому коді ми створили клас "AddDialog", який наслідується від класу "QDialog". Ми також створили слот "on_addButton_clicked()", який буде викликатися при натисканні кнопки "Add".

Тепер ми можемо додати логіку до цього слоту у файлі "adddialog.cpp":

```cpp
#include "adddialog.h"#include "ui_adddialog.h"

AddDialog::AddDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddDialog)
{
    ui->setupUi(this);
}

AddDialog::~AddDialog()
{
    delete ui;
}

void AddDialog::on_addButton_clicked()
{
    QString firstValueString = ui->firstValueLineEdit->text();
    QString secondValueString = ui->secondValueLineEdit->text();

    bool firstValueOk, secondValueOk;
    int firstValue = firstValueString.toInt(&firstValueOk);
    int secondValue = secondValueString.toInt(&secondValueOk);

    if (firstValueOk && secondValueOk) {
        int result = firstValue + secondValue;
        ui->resultLabel->setText(QString::number(result));
    } else {
        ui->resultLabel->setText("Помилка: введено неправильні значення");
    }
}

```

## 2. приклад роботи з формами з використанням масивів для початківців Qt C++ за допомогою візуального конструктора

1. Створіть новий проект Qt Application у Qt Creator.
2. Відкрийте головне вікно (mainwindow.ui) у візуальному конструкторі.
3. Додайте три елементи QLineEdit на форму за допомогою панелі інструментів.
4. Виділіть всі три елементи і використовуйте функцію копіювання-вставки, щоб створити три елементи QLabel на формі.
5. Виберіть перший елемент QLineEdit та знайдіть властивість objectName у панелі властивостей. Встановіть objectName на "lineEdit1".
6. Повторіть цей процес для двох інших елементів QLineEdit та трьох елементів QLabel, надаючи їм objectName на "lineEdit2", "lineEdit3", "label1", "label2" та "label3" відповідно.
7. Відкрийте головний файл проекту (mainwindow.cpp) та додайте наступний код у функцію конструктора:

```cpp
QLineEdit* lineEdits[] = {ui->lineEdit1, ui->lineEdit2, ui->lineEdit3};
QLabel* labels[] = {ui->label1, ui->label2, ui->label3};

for (int i = 0; i < 3; i++) {
    lineEdits[i]->setText("Поле " + QString::number(i+1));
    labels[i]->setText("Мітка " + QString::number(i+1));
}
```

Цей код створює масиви lineEdits та labels, що містять елементи QLineEdit та QLabel відповідно, які ми додали до форми. Він потім встановлює текст для кожного з цих елементів за допомогою циклу for.

1. Компілюйте та запускайте проект. Ви повинні бачити три елементи QLineEdit та три елементи QLabel, кожен з яких містить текст "Поле x" або "Мітка x", де x - номер елементу.

## 3. приклад більш складної програми на Qt C++, яка використовує форму та масиви для зберігання та обробки даних

В даному прикладі ми створимо форму для введення інформації про студентів та використаємо масив для зберігання цих даних. Надалі ми відобразимо ці дані у таблиці та візуалізуємо статистику успішності.

1. Створіть новий проект Qt C++ за допомогою конструктора форм.
2. Створіть на формі наступні елементи:
- QLabel з назвою "Ім'я:"
- QLineEdit для введення імені студента
- QLabel з назвою "Прізвище:"
- QLineEdit для введення прізвища студента
- QLabel з назвою "Група:"
- QLineEdit для введення номеру групи студента
- QLabel з назвою "Оцінка:"
- QSpinBox для вибору оцінки
- QPushButton для додавання даних про студента до масиву
1. Додайте на форму QTableView для відображення таблиці з даними студентів.
2. Створіть масив, який буде зберігати дані про студентів. Для цього створіть структуру, яка буде містити поля для імені, прізвища, номеру групи та оцінки.

```cpp

struct Student {
    QString firstName;
    QString lastName;
    QString groupNumber;
    int grade;
};

```

Далі створіть масив студентів за допомогою даної структури:

```cpp

const int MAX_STUDENTS = 100;
Student students[MAX_STUDENTS];
int numStudents = 0;

```

1. Додайте слот для кнопки QPushButton, який буде зберігати дані про студента в масив та оновлювати таблицю. Додайте також слот для відображення статистики успішності студентів.

```cpp

void MainWindow::on_addButton_clicked()
{
    if (numStudents >= MAX_STUDENTS) {
        return;
    }
    Student student;
    student.firstName = ui->firstNameEdit->text();
    student.lastName = ui->lastNameEdit->text();
    student.groupNumber = ui->groupNumberEdit->text();
    student.grade = ui->gradeSpinBox->value();
    students[numStudents] = student;
    numStudents++;

    // Оновлюємо таблицю
    model->insertRows(numStudents - 1, 1);
    QModelIndex index = model->index(numStudents - 1, 0)
		// першого стовпця
		model->setData(index, student.firstName);

		// Вставляємо дані про прізвище у другий стовпець
		index = model->index(numStudents - 1, 1);
		model->setData(index, student.lastName);
		
		// Вставляємо дані про групу у третій стовпець
		index = model->index(numStudents - 1, 2);
		model->setData(index, student.groupNumber);
		
		// Вставляємо дані про оцінку у четвертий стовпець
		index = model->index(numStudents - 1, 3);
		model->setData(index, student.grade);
}
	
void MainWindow::showStats()
{
	int numPass = 0;
	int numFail = 0;
	int sumGrades = 0;
	double avgGrade = 0.0;
	for (int i = 0; i < numStudents; i++) {
	    if (students[i].grade >= 60) {
	        numPass++;
	    } else {
	        numFail++;
	    }
	    sumGrades += students[i].grade;
	}
	if (numStudents > 0) {
	    avgGrade = (double)sumGrades / numStudents;
	}
	
	ui->passLabel->setText(QString::number(numPass));
	ui->failLabel->setText(QString::number(numFail));
	ui->avgGradeLabel->setText(QString::number(avgGrade));
}
```

6. Додайте модель QStandardItemModel, яка буде використовуватися для відображення таблиці з даними.

```cpp
model = new QStandardItemModel(this);
model->setHorizontalHeaderItem(0, new QStandardItem("Ім'я"));
model->setHorizontalHeaderItem(1, new QStandardItem("Прізвище"));
model->setHorizontalHeaderItem(2, new QStandardItem("Група"));
model->setHorizontalHeaderItem(3, new QStandardItem("Оцінка"));
ui->tableView->setModel(model);
```

7. Додайте таймер, який буде оновлювати статистику успішності студентів кожні 5 секунд.

```cpp

QTimer *timer = new QTimer(this);
connect(timer, &QTimer::timeout, this, &MainWindow::showStats);
timer->start(5000);

```

8. Запустіть програму та перевірте, чи коректно працює відображення даних у таблиці та статистики успішності студентів.

Зважаючи на те, що це тільки частковий код та для повного розуміння необхідно знати структуру класів та їхні методи, я наведу тільки основні частини коду для реалізації цих слотів:

```cpp
// додати слот для кнопки "Додати студента"
void MainWindow::on_addStudentButton_clicked()
{
    // створити новий об'єкт студента
    Student student(ui->nameLineEdit->text(),
                    ui->surnameLineEdit->text(),
                    ui->groupLineEdit->text().toInt(),
                    ui->markLineEdit->text().toDouble());

    // додати студента до масиву
    m_students.append(student);

    // оновити таблицю
    updateTable();
}

// додати слот для кнопки "Оновити статистику"
void MainWindow::on_updateStatisticsButton_clicked()
{
    // розрахувати статистику успішності
    double averageMark = calculateAverageMark();
    int numPassed = calculateNumPassed();

    // відобразити статистику успішності
    ui->averageMarkLabel->setText(QString::number(averageMark));
    ui->numPassedLabel->setText(QString::number(numPassed));
}

```

У першому слоті ми створюємо новий об'єкт студента за допомогою даних, введених користувачем в текстові поля, додаємо його до масиву студентів та оновлюємо таблицю, використовуючи метод **`updateTable()`**.

У другому слоті ми розраховуємо статистику успішності студентів, використовуючи методи **`calculateAverageMark()`** та **`calculateNumPassed()`**, та відображаємо її в відповідних елементах інтерфейсу.

```cpp
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    struct Student {
        QString firstName;
        QString lastName;
        QString groupNumber;
        int grade;
    };
    static const int MAX_STUDENTS = 100;
    Student students[MAX_STUDENTS];
    int numStudents = 0;
    QStandardItemModel *model;
    void showStats();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QStandardItemModel>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    model = new QStandardItemModel(this);
    model->setHorizontalHeaderItem(0, new QStandardItem("Ім'я"));
    model->setHorizontalHeaderItem(1, new QStandardItem("Прізвище"));
    model->setHorizontalHeaderItem(2, new QStandardItem("Група"));
    model->setHorizontalHeaderItem(3, new QStandardItem("Оцінка"));
    ui->tableView->setModel(model);

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::showStats);
    timer->start(5000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if (numStudents >= MAX_STUDENTS) {
            return;
        }
        Student student;
        student.firstName = ui->firstNameEdit->text();
        student.lastName = ui->lastNameEdit->text();
        student.groupNumber = ui->groupNumberEdit->text();
        student.grade = ui->gradeSpinBox->value();
        students[numStudents] = student;
        numStudents++;

        // Оновлюємо таблицю
        model->insertRows(numStudents - 1, 1);
        QModelIndex index = model->index(numStudents - 1, 0);
        // першого стовпця
        model->setData(index, student.firstName);

        // Вставляємо дані про прізвище у другий стовпець
        index = model->index(numStudents - 1, 1);
        model->setData(index, student.lastName);

        // Вставляємо дані про групу у третій стовпець
        index = model->index(numStudents - 1, 2);
        model->setData(index, student.groupNumber);

        // Вставляємо дані про оцінку у четвертий стовпець
        index = model->index(numStudents - 1, 3);
        model->setData(index, student.grade);
}я

void MainWindow::showStats()
{
    int numPass = 0;
    int numFail = 0;
    int sumGrades = 0;
    double avgGrade = 0.0;
    for (int i = 0; i < numStudents; i++) {
        if (students[i].grade >= 60) {
            numPass++;
        } else {
            numFail++;
        }
        sumGrades += students[i].grade;
    }
    if (numStudents > 0) {
        avgGrade = (double)sumGrades / numStudents;
    }

    ui->passLabel->setText(QString::number(numPass));
    ui->failLabel->setText(QString::number(numFail));
    ui->avgGradeLabel->setText(QString::number(avgGrade));
}

```

## прилад про книги

Програма буде містити наступні функції:

- Додавання нової книги до масиву.
- Відображення списку усіх книг у вікні програми.
- Пошук книги за назвою та відображення результатів у вікні програми.

Основний код програми може виглядати наступним чином:

```cpp

#include <QApplication>#include <QTableWidget>#include <QVBoxLayout>#include <QLineEdit>#include <QPushButton>#include <QLabel>class Book
{
public:
    QString title;
    QString author;
    QString publisher;
    int year;
    double price;

    Book(QString t, QString a, QString p, int y, double pr)
        : title(t), author(a), publisher(p), year(y), price(pr)
    {
    }
};

class Library : public QWidget
{
    Q_OBJECT

public:
    Library(QWidget *parent = 0);
    ~Library();

private slots:
    void addBook();
    void searchBooks();

private:
    void updateTable();
    int findBook(const QString &title) const;
    double calculateAveragePrice() const;

    QList<Book> m_books;
    QLineEdit *m_titleEdit;
    QLineEdit *m_authorEdit;
    QLineEdit *m_publisherEdit;
    QLineEdit *m_yearEdit;
    QLineEdit *m_priceEdit;
    QTableWidget *m_tableWidget;
    QLabel *m_averagePriceLabel;
};

Library::Library(QWidget *parent)
    : QWidget(parent)
{
    // create UI elements
    m_titleEdit = new QLineEdit;
    m_authorEdit = new QLineEdit;
    m_publisherEdit = new QLineEdit;
    m_yearEdit = new QLineEdit;
    m_priceEdit = new QLineEdit;
    QPushButton *addButton = new QPushButton(tr("Add Book"));
    connect(addButton, SIGNAL(clicked()), this, SLOT(addBook()));
    QPushButton *searchButton = new QPushButton(tr("Search Books"));
    connect(searchButton, SIGNAL(clicked()), this, SLOT(searchBooks()));
    m_tableWidget = new QTableWidget;
    m_tableWidget->setColumnCount(5);
    m_tableWidget->setHorizontalHeaderLabels(QStringList() << tr("Title") << tr("Author")
                                             << tr("Publisher") << tr("Year") << tr("Price"));
    m_averagePriceLabel = new QLabel;

    // create layout
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(new QLabel(tr("<b>Add Book</b>")));
    layout->addWidget(new QLabel(tr("Title:")));
    layout->addWidget(m_titleEdit);
    layout->addWidget(new QLabel(tr("Author:")));
    layout->addWidget(m_authorEdit);
    layout->addWidget(new QLabel(tr("Publisher:")));
    layout->addWidget(m_publisherEdit);
    layout->addWidget(new QLabel(tr("Year:")));
    layout->addWidget(m_yearEdit);
    layout->addWidget(new QLabel(tr("Price:")));
    layout->addWidget(m_priceEdit);
    layout->addWidget(addButton);
    layout->addWidget(new QLabel(tr("<b>Search Books</b>")));
    layout->addWidget(searchButton);
    layout->addWidget(m_tableWidget);
    layout->addWidget(new QLabel(tr("<b>Statistics</b>")));
		layout->addWidget(new QLabel(tr("Average Price:")));
		layout->addWidget(m_averagePriceLabel);
		setLayout(layout);
}

Library::~Library()
{
}

void Library::addBook()
{
		// get book details from the input fields
		QString title = m_titleEdit->text();
		QString author = m_authorEdit->text();
		QString publisher = m_publisherEdit->text();
		int year = m_yearEdit->text().toInt();
		double price = m_priceEdit->text().toDouble();
		// create new book object and add it to the list
		Book newBook(title, author, publisher, year, price);
		m_books.append(newBook);
		
		// update the table
		updateTable();
		
		// clear the input fields
		m_titleEdit->clear();
		m_authorEdit->clear();
		m_publisherEdit->clear();
		m_yearEdit->clear();
		m_priceEdit->clear();
}

void Library::searchBooks()
{
		// get search term from the input field
		QString searchTerm = m_titleEdit->text();
		// find all books with matching title
		QList<Book> matchingBooks;
		foreach (Book book, m_books) {
		    if (book.title.contains(searchTerm, Qt::CaseInsensitive)) {
		        matchingBooks.append(book);
		    }
		}
		
		// update the table with matching books
		m_tableWidget->clearContents();
		m_tableWidget->setRowCount(matchingBooks.size());
		int row = 0;
		foreach (Book book, matchingBooks) {
		    QTableWidgetItem *titleItem = new QTableWidgetItem(book.title);
		    QTableWidgetItem *authorItem = new QTableWidgetItem(book.author);
		    QTableWidgetItem *publisherItem = new QTableWidgetItem(book.publisher);
		    QTableWidgetItem *yearItem = new QTableWidgetItem(QString::number(book.year));
		    QTableWidgetItem *priceItem = new QTableWidgetItem(QString::number(book.price));
		    m_tableWidget->setItem(row, 0, titleItem);
		    m_tableWidget->setItem(row, 1, authorItem);
		    m_tableWidget->setItem(row, 2, publisherItem);
		    m_tableWidget->setItem(row, 3, yearItem);
		    m_tableWidget->setItem(row, 4, priceItem);
		    row++;
		}
		
		// update the average price label
		double averagePrice = calculateAveragePrice();
		m_averagePriceLabel->setText(QString("Average Price: $%1").arg(averagePrice, 0, 'f', 2));
}

void Library::updateTable()
{
		m_tableWidget->clearContents();
		m_tableWidget->setRowCount(m_books.size());
		int row = 0;
		foreach (Book book, m_books) {
				QTableWidgetItem *titleItem = new QTableWidgetItem(book.title);
				QTableWidgetItem *authorItem = new QTableWidgetItem(book.author);
				QTableWidgetItem *publisherItem = new QTableWidgetItem(book.publisher);
				QTableWidgetItem *yearItem = new QTableWidgetItem(QString::number(book.year));
				QTableWidgetItem *priceItem = new QTableWidgetItem(QString::number(book.price));
				m_tableWidget->setItem(row, 0, titleItem);
				m_tableWidget->setItem(row, 1, authorItem);
				m_tableWidget->setItem(row, 2, publisherItem);
				m_tableWidget->setItem(row, 3, yearItem);
				m_tableWidget->setItem(row, 4, priceItem);
				row++;
		}
		// update the average price label
		double averagePrice = calculateAveragePrice();
		m_averagePriceLabel->setText(QString("Average Price: $%1").arg(averagePrice, 0, 'f', 2));
}
```

```cpp
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QApplication>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class Book
{
public:
    QString title;
    QString author;
    QString publisher;
    int year;
    double price;

    Book(QString t, QString a, QString p, int y, double pr)
        : title(t), author(a), publisher(p), year(y), price(pr)
    {
    }
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void addBook();
    void searchBooks();

private:
    Ui::MainWindow *ui;
    void updateTable();
    int findBook(const QString &title) const;
    double calculateAveragePrice() const;

    QList<Book> m_books;
    QLineEdit *m_titleEdit;
    QLineEdit *m_authorEdit;
    QLineEdit *m_publisherEdit;
    QLineEdit *m_yearEdit;
    QLineEdit *m_priceEdit;
    QTableWidget *m_tableWidget;
    QLabel *m_averagePriceLabel;
};
#endif // MAINWINDOW_H

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

ui->setupUi(this);
   m_titleEdit = new QLineEdit(this);
//   m_titleEdit->setGeometry(100, 80, 113, 26);
   m_authorEdit = new QLineEdit(this);
//   m_authorEdit->setGeometry(100, 110, 113, 26);
   m_publisherEdit = new QLineEdit(this);
//   m_publisherEdit->setGeometry(100, 140, 113, 26);
   m_yearEdit = new QLineEdit(this);
//   m_yearEdit->setGeometry(100, 170, 113, 26);
   m_priceEdit = new QLineEdit(this);
//   m_priceEdit->setGeometry(100, 200, 113, 26);

   QPushButton *addButton = new QPushButton(tr("Add Book"), this);
//   addButton->setGeometry(30, 250, 95, 30);
   connect(addButton, SIGNAL(clicked()), this, SLOT(addBook()));
   QPushButton *searchButton = new QPushButton(tr("Search Books"), this);
//   searchButton->setGeometry(30, 290, 95, 30);
   connect(searchButton, SIGNAL(clicked()), this, SLOT(searchBooks()));
   m_tableWidget = new QTableWidget(this);
//   m_tableWidget->setGeometry(230, 20, 595, 530);
   m_tableWidget->setColumnCount(5);
   m_tableWidget->setHorizontalHeaderLabels(QStringList() << tr("Title") << tr("Author") << tr("Publisher") << tr("Year") << tr("Price"));
   m_averagePriceLabel = new QLabel(this);

   // create layout
   QVBoxLayout *layout = new QVBoxLayout(this);

   layout->addWidget(new QLabel(tr("<b>Add Book</b>"), this));
   layout->addWidget(new QLabel(tr("Title:")));
   layout->addWidget(m_titleEdit);
   layout->addWidget(new QLabel(tr("Author:"), this));
   layout->addWidget(m_authorEdit);
   layout->addWidget(new QLabel(tr("Publisher:"), this));
   layout->addWidget(m_publisherEdit);
   layout->addWidget(new QLabel(tr("Year:"), this));
   layout->addWidget(m_yearEdit);
   layout->addWidget(new QLabel(tr("Price:"), this));
   layout->addWidget(m_priceEdit);
   layout->addWidget(addButton);
   layout->addWidget(new QLabel(tr("<b>Search Books</b>"), this));
   layout->addWidget(searchButton);
   layout->addWidget(m_tableWidget);
   layout->addWidget(new QLabel(tr("<b>Statistics</b>"), this));
   layout->addWidget(new QLabel(tr("Average Price:"), this));
   layout->addWidget(m_averagePriceLabel);
   layout->setGeometry(*new QRect(20, 20, 500, 500));
   setLayout(layout);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addBook()
{
        // get book details from the input fields
        QString title = m_titleEdit->text();
        QString author = m_authorEdit->text();
        QString publisher = m_publisherEdit->text();
        int year = m_yearEdit->text().toInt();
        double price = m_priceEdit->text().toDouble();
        // create new book object and add it to the list
        Book newBook(title, author, publisher, year, price);
        m_books.append(newBook);

        // update the table
        updateTable();

        // clear the input fields
        m_titleEdit->clear();
        m_authorEdit->clear();
        m_publisherEdit->clear();
        m_yearEdit->clear();
        m_priceEdit->clear();
}
void MainWindow::searchBooks()
{
        // get search term from the input field
        QString searchTerm = m_titleEdit->text();
        // find all books with matching title
        QList<Book> matchingBooks;
        foreach (Book book, m_books) {
            if (book.title.contains(searchTerm, Qt::CaseInsensitive)) {
                matchingBooks.append(book);
            }
        }

        // update the table with matching books
        m_tableWidget->clearContents();
        m_tableWidget->setRowCount(matchingBooks.size());
        int row = 0;
        foreach (Book book, matchingBooks) {
            QTableWidgetItem *titleItem = new QTableWidgetItem(book.title);
            QTableWidgetItem *authorItem = new QTableWidgetItem(book.author);
            QTableWidgetItem *publisherItem = new QTableWidgetItem(book.publisher);
            QTableWidgetItem *yearItem = new QTableWidgetItem(QString::number(book.year));
            QTableWidgetItem *priceItem = new QTableWidgetItem(QString::number(book.price));
            m_tableWidget->setItem(row, 0, titleItem);
            m_tableWidget->setItem(row, 1, authorItem);
            m_tableWidget->setItem(row, 2, publisherItem);
            m_tableWidget->setItem(row, 3, yearItem);
            m_tableWidget->setItem(row, 4, priceItem);
            row++;
        }

        // update the average price label
        double averagePrice = calculateAveragePrice();
        m_averagePriceLabel->setText(QString("Average Price: $%1").arg(averagePrice, 0, 'f', 2));
}

void MainWindow::updateTable()
{
        m_tableWidget->clearContents();
        m_tableWidget->setRowCount(m_books.size());
        int row = 0;
        foreach (Book book, m_books) {
                QTableWidgetItem *titleItem = new QTableWidgetItem(book.title);
                QTableWidgetItem *authorItem = new QTableWidgetItem(book.author);
                QTableWidgetItem *publisherItem = new QTableWidgetItem(book.publisher);
                QTableWidgetItem *yearItem = new QTableWidgetItem(QString::number(book.year));
                QTableWidgetItem *priceItem = new QTableWidgetItem(QString::number(book.price));
                m_tableWidget->setItem(row, 0, titleItem);
                m_tableWidget->setItem(row, 1, authorItem);
                m_tableWidget->setItem(row, 2, publisherItem);
                m_tableWidget->setItem(row, 3, yearItem);
                m_tableWidget->setItem(row, 4, priceItem);
                row++;
        }
        // update the average price label
        double averagePrice = calculateAveragePrice();
        m_averagePriceLabel->setText(QString("Average Price: $%1").arg(averagePrice, 0, 'f', 2));
}
double MainWindow::calculateAveragePrice() const
{
    double totalPrice = 0.0;
        int count = m_books.size();

        for (int i = 0; i < count; i++) {
            totalPrice += m_books.at(i).price;
        }

        return (count == 0) ? 0 : (totalPrice / count);

}
int MainWindow::findBook(const QString &title) const
{
    for (int i = 0; i < m_books.size(); i++) {
        if (m_books[i].title == title) {
            return i;
        }
    }
    return -1;
}
```