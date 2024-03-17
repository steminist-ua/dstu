#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_plusBtn_clicked();

    void on_minusBtn_clicked();

    void on_multBtn_clicked();

    void on_divideBtn_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
