#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

//1. підключення бібліотек
#include <QPainter>
#include <QTime>
#include <QTimer>
//кінец підключення бібліотек

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

// перевизначення функції paintEvent - обрробки події "малювання"
// protected - захищене поле, але для наслідників доступне
protected:
    void paintEvent(QPaintEvent *) override;
// правою кнопкою миші - Рекфакторинг - Додати реалізацію у mainwindow.cpp
};
#endif // MAINWINDOW_H
