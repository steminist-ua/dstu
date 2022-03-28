#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>


const int BLOCK_SIZE=25;    //розміри блоків з яких складаються фігури
const int MARGIN=5;         //відступи
const int AREA_ROW=20;      //кількість рядків ігрового поля
const int AREA_COL=12;      //кількість колонок ігрового поля

// перелік "направлень", що можна зробити з фігурою у тетрисі
enum Direction
{
    UP,
    DOWN,
    LEFT,
    RIGHT,
    SPACE
};

// структура для інформації про межі елементів (ubound - верхня межа, перша літера u - UP, dbound - нижня межа, d - DOWN і так далі)
struct Border
{
    int ubound;
    int dbound;
    int lbound;
    int rbound;
};

// структура координатів
struct block_point
{
    int pos_x;
    int pos_y;
};

namespace Ui { class Widget; }


class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void InitGame();    // ініціалізація гри (підготовка ігрового поля)
    void StartGame();   // початок гри, запуск таймерів
    void GameOver();    // кінец гри

    void ResetBlock();  // "скидання" позицій (генерація поточної та нової фігури + встановлення координат, де буде зв'являтися блок на ігровом полі
    void BlockMove(Direction dir);                      // переміщення фігури
    void BlockRotate(int block[4][4]);                  // перевернення фігури
    void CreateBlock(int block[4][4],int block_id);     // створення фігури
    void GetBorder(int block[4][4],Border &border);     // обчислення меж фігури
    void ConvertStable(int x,int y);                    // перетворення фігури на "заземлену"
    bool IsCollide(int x,int y,Direction dir);          // визначення чи є зіткнення

    virtual void paintEvent(QPaintEvent *event);        // оновлення ігрового поля (сцени)
    virtual void timerEvent(QTimerEvent *event);        // подія таймеру
    virtual void keyPressEvent(QKeyEvent *event);       // подія натиску кнопки на клаіатурі (управління через кнопки)

private:
    Ui::Widget *ui;

private:
    int game_area[AREA_ROW][AREA_COL];  //область сцени (ігрового поля), 1 - для активних фігур, які "летять", 2 - для стабільних "заземлених" фігур, 0 - для порожніх клітин ігрового поля
    block_point block_pos;              // поточні координати фігури (блоку)
    int cur_block[4][4];                // поточна форма фігури (блоку)
    Border cur_border;                  // поточні межі фігури (блоку)
    int next_block[4][4];               // форма "наступної" фігури
    bool isStable;                      // перевірка чи "заземлена" поточна фігура
    int score;                          // набрані бали під час гри
    int game_timer;                     // таймер гри
    int paint_timer;                    // таймер оновлення відображення форми (вікна гри)
    int speed_ms;                       // швидкість падання фігур (тобто, швидкість гри)
    int refresh_ms;                     // швидкість оновлення відображення форми (вікна гри)

};
#endif // WIDGET_H













