#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>

#include "mylabel.h"
#include "bgwidget.h"

namespace Ui {
class Widget;
}

class GameWidget : public QWidget
{
    Q_OBJECT

public:
    explicit GameWidget(QWidget *parent = 0);
    ~GameWidget();

    enum GestureDirect{
        LEFT,
        RIGHT,
        UP,
        DOWN
    };

    //Генерація лейблів (випадкова)
    void createLabel();
    //Ініціалізація гри
    void initGame();
    //Злиття лейблів та повернення результату успішного злиття.
    bool merge(MyLabel *temp,int row,int col);
    //Перевірка, чи можна зробити злиття
    bool isMerge();
    //кінець гри
    bool gameOver();
    //Збереження результатів гри та позицій лейблів
    void saveGame();
    //Позиції лейблів
    void releaseRes();
    //обробка події закриття вікна гри
    void closeEvent(QCloseEvent *event);
    //обробка події натиску на кнопки клавіатури
    void keyPressEvent(QKeyEvent *event);

private:
    bool moveUp();
    bool moveDown();
    bool moveLeft();
    bool moveRight();

    bool isMergeUp(int row,int col);
    bool isMergeDown(int row,int col);
    bool isMergeLeft(int row,int col);
    bool isMergeRight(int row,int col);

signals:
    //Запуску сигналу при переміщенні лейблу
    void GestureMove(GestureDirect direction);
    //зміна рахунку гри
    void ScoreChange();

private slots:
    //встановлення рахунку гри
    void setScore();
    //переміщення лейблів
    void moveLabel(GestureDirect direction);
    //почаги гру заново (обробка події натиску на відповідну кнопку на формі)
    void on_bt_restart_clicked();

private:
    Ui::Widget *ui;
    int m_score;                    //поточний рахунок
    int m_highScore;                //рекордний результат
    int m_labelCount;               //кількість лейблів на полі
    MyLabel *labels[4][4];          //лейбли
    BGWidget * m_bgWidget;          //ігрове поле
};

#endif // GAMEWIDGET_H
