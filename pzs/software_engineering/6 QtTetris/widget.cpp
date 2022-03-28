#include <time.h>
#include <QMessageBox>
#include <QDebug>
#include <QPainter>
#include <QKeyEvent>
#include "widget.h"
#include "ui_widget.h"

// оскільки в тетрисі надовша та найвища фігура - це лінія з 4 блокі, то всі фігури будемо описувати через масиви 4х4
// опис фігури "квадрат"
int item1[4][4]=
{
    {0,0,0,0},
    {0,1,1,0},
    {0,1,1,0},
    {0,0,0,0}
};
// опис фігури "L"
int item2[4][4]=
{
    {0,1,0,0},
    {0,1,0,0},
    {0,1,1,0},
    {0,0,0,0}
};
// опис фігури "L-зеркальної"
int item3[4][4]=
{
    {0,0,1,0},
    {0,0,1,0},
    {0,1,1,0},
    {0,0,0,0}
};
// опис фігури "s"
int item4[4][4]=
{
    {0,1,0,0},
    {0,1,1,0},
    {0,0,1,0},
    {0,0,0,0}
};
// опис фігури "s-зеркальної"
int item5[4][4]=
{
    {0,0,1,0},
    {0,1,1,0},
    {0,1,0,0},
    {0,0,0,0}
};
// опис фігури "T"
int item6[4][4]=
{
    {0,0,0,0},
    {0,0,1,0},
    {0,1,1,1},
    {0,0,0,0}
};
// опис фігури "i"
int item7[4][4]=
{
    {0,0,1,0},
    {0,0,1,0},
    {0,0,1,0},
    {0,0,1,0}
};

// копіювання фігури (для подальних методів)
inline void block_cpy(int dblock[4][4],int sblock[4][4])
{
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            dblock[i][j]=sblock[i][j];
}

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // налаштування розміру вікна
    resize(AREA_COL*BLOCK_SIZE+MARGIN*4+4*BLOCK_SIZE,AREA_ROW*BLOCK_SIZE+MARGIN*2);

    // ініціалізація гри
    InitGame();
}

Widget::~Widget()
{
    delete ui;
}

// оновлення ігрового поля (сцени)
void Widget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    // межі ігрового поля (білий прямокутник)
    painter.setBrush(QBrush(Qt::white,Qt::SolidPattern));
    painter.drawRect(MARGIN,MARGIN,AREA_COL*BLOCK_SIZE,AREA_ROW*BLOCK_SIZE);

    // відображення наступної фігури (справа від ігрового поля, синя фігура)
    painter.setBrush(QBrush(Qt::blue,Qt::SolidPattern));
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            if(next_block[i][j]==1)
                painter.drawRect(MARGIN*3+AREA_COL*BLOCK_SIZE+j*BLOCK_SIZE,MARGIN+i*BLOCK_SIZE,BLOCK_SIZE,BLOCK_SIZE);

    // відображення тексту з набраними балами (score: 0) - чорний текст, шрифт - Arial, розмір - 14
    painter.setPen(Qt::black);
    painter.setFont(QFont("Arial",14));
    painter.drawText(QRect(MARGIN*3+AREA_COL*BLOCK_SIZE,MARGIN*2+4*BLOCK_SIZE,BLOCK_SIZE*4,BLOCK_SIZE*4),Qt::AlignCenter,"score: "+QString::number(score));

    // відображення на ігровому полі фігур. Нагадування: 1 - для активних фігур, які "летять", 2 - для стабільних "заземлених" фігур, 0 - для порожніх клітин ігрового поля
    for(int i=0;i<AREA_ROW;i++)
        for(int j=0;j<AREA_COL;j++)
        {
            // відображення фігури, що "летить" по ігровому полю (червона)
            if(game_area[i][j]==1)
            {
                painter.setBrush(QBrush(Qt::red,Qt::SolidPattern));
                painter.drawRect(j*BLOCK_SIZE+MARGIN,i*BLOCK_SIZE+MARGIN,BLOCK_SIZE,BLOCK_SIZE);
            }

            // відображення фігури, що "приземлилася" (зелена)
            else if(game_area[i][j]==2)
            {
                painter.setBrush(QBrush(Qt::green,Qt::SolidPattern));
                painter.drawRect(j*BLOCK_SIZE+MARGIN,i*BLOCK_SIZE+MARGIN,BLOCK_SIZE,BLOCK_SIZE);
            }
        }
}
void Widget::timerEvent(QTimerEvent *event)
{
    // таймер гри - коли йде цей таймер, то фігура рухається зверху до нижньої границі ігрового поля
    if(event->timerId()==game_timer)
        BlockMove(DOWN);

    // таймер оновлення вікна програми - цей таймер оновлює форму з грою, щоб відображати зміну положення фігур та динамічного реагування на дії гравця
    if(event->timerId()==paint_timer)
        update();
}

// обобка події натиску користувачем на кнопки клавіатури
void Widget::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
        case Qt::Key_Up: // якщо користувач натискає стрілку вверх на клавіатурі, то викликається метод BlockMove з параметром UP
            BlockMove(UP);
            break;
        case Qt::Key_Down: // якщо користувач натискає стрілку вниз на клавіатурі, то викликається метод BlockMove з параметром DOWN
            BlockMove(DOWN);
            break;
        case Qt::Key_Left: // якщо користувач натискає стрілку вліво на клавіатурі, то викликається метод BlockMove з параметром LEFT
            BlockMove(LEFT);
            break;
        case Qt::Key_Right: // якщо користувач натискає стрілку вправо на клавіатурі, то викликається метод BlockMove з параметром RIGHT
            BlockMove(RIGHT);
            break;
        case Qt::Key_Space: // якщо користувач натискає пробіл на клавіатурі, то викликається метод BlockMove з параметром SPACE
            BlockMove(SPACE);
            break;
        default: // якщо користувач натискає будь яку іншу кнопку, то ніяких дій не відбувається
            break;
    }
}

// створення фігури певного типу (за номером block_id) та копіювання її до змінної block, яка вказується першим параметром)
void Widget::CreateBlock(int block[4][4],int block_id)
{
    switch (block_id)
    {
        case 0:
            block_cpy(block,item1);
            break;
        case 1:
            block_cpy(block,item2);
            break;
        case 2:
            block_cpy(block,item3);
            break;
        case 3:
            block_cpy(block,item4);
            break;
        case 4:
            block_cpy(block,item5);
            break;
        case 5:
            block_cpy(block,item6);
            break;
        case 6:
            block_cpy(block,item7);
            break;
        default:
            break;
    }
}

// обчислення меж фігури
void Widget::GetBorder(int block[4][4],Border &border)
{
    //Вираховуємо нижню, верхню, праву та ліву границі
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            if(block[i][j]==1)
            {
                border.dbound=i;
                break; //до тих пір поки в останньому рядку не буде 1
            }
    for(int i=3;i>=0;i--)
        for(int j=0;j<4;j++)
            if(block[i][j]==1)
            {
                border.ubound=i;
                break;
            }
    for(int j=0;j<4;j++)
        for(int i=0;i<4;i++)
            if(block[i][j]==1)
            {
                border.rbound=j;
                break;
            }
    for(int j=3;j>=0;j--)
        for(int i=0;i<4;i++)
            if(block[i][j]==1)
            {
                border.lbound=j;
                break;
            }
}

// ініціалізація гри
void Widget::InitGame()
{
    //очищення ігрового поля (встановлюємо у всіх клітинках 0, тобто порожньо)
    for(int i=0;i<AREA_ROW;i++)
        for(int j=0;j<AREA_COL;j++)
            game_area[i][j]=0;

    speed_ms=800;       // встановлюємо швидкість гри, тобто швидкість падіння фігур
    refresh_ms=30;      // періодичність з якою оновлюється форма
    srand(time(0));     // ініціалізуємо генератор випадких чисел
    score=0;            // задаємо стартову кількість балів

    StartGame();        // виклик методу початку гри
}

// початок гри
void Widget::StartGame()
{
     // запуск таймерів гри та оновлення форми
     game_timer=startTimer(speed_ms);
     paint_timer=startTimer(refresh_ms);


     int block_id=rand()%7;             // збереження випадкового числа (0-6)
     CreateBlock(next_block,block_id);  // створення фігури відповідної випадковому числу
     ResetBlock();                      // "скидання" позицій
}

// "скидання" позицій (генерація поточної та нової фігури + встановлення координат, де буде зв'являтися блок на ігровом полі)
void Widget::ResetBlock()
{
    // генерація поточної фігури
    block_cpy(cur_block,next_block);
    GetBorder(cur_block,cur_border);

    // генерація наступної фігури
    int block_id=rand()%7;
    CreateBlock(next_block,block_id);

    // встановлення початкових координат фігури (лівий верхній кут - точка "прив'язки")
    block_point start_point;
    start_point.pos_x=AREA_COL/2-2; // центр поля горизонтально
    start_point.pos_y=0;            // верхня границя ігрового поля
    block_pos=start_point;
}

// кінець гри
void Widget::GameOver()
{
    // зупика таймерів
    killTimer(game_timer);
    killTimer(paint_timer);

    // вивід повідомлення про кінець гри
    QMessageBox::information(this,"failed","game over");
}

// поворот фігури (відповідно до точки "прив'язки"
void Widget::BlockRotate(int block[4][4])
{
    int temp_block[4][4];
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            temp_block[3-j][i]=block[i][j];
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            block[i][j]=temp_block[i][j];
}

// "заземлення" фігури на ігровому полі
void Widget::ConvertStable(int x,int y)
{
    for(int i=cur_border.ubound;i<=cur_border.dbound;i++)
        for(int j=cur_border.lbound;j<=cur_border.rbound;j++)
            if(cur_block[i][j]==1)
                game_area[y+i][x+j]=2;
}

// перевірка чи відбулося зіткнення
bool Widget::IsCollide(int x,int y,Direction dir)
{
    int temp_block[4][4]; // копія фігури
    block_cpy(temp_block,cur_block);
    Border temp_border;
    GetBorder(temp_block,temp_border);

    switch(dir)
    {
        case UP:
            BlockRotate(temp_block);
            GetBorder(temp_block,temp_border);
            break;
        case DOWN:
            y+=1;
            break;
        case LEFT:
            x-=1;
            break;
        case RIGHT:
            x+=1;
            break;
        default:
            break;
    }
    for(int i=temp_border.ubound;i<=temp_border.dbound;i++)
        for(int j=temp_border.lbound;j<=temp_border.rbound;j++)
            if(game_area[y+i][x+j]==2&&temp_block[i][j]==1||x+temp_border.lbound<0||x+temp_border.rbound>AREA_COL-1)
                return true;
    return false;
}

// переміщення фігури по ігровому полю (відповідно до кнопки яку натискає гравець)
void Widget::BlockMove(Direction dir)
{
    switch (dir)
    {
        case UP:
            if(IsCollide(block_pos.pos_x,block_pos.pos_y,UP))
                break;
            BlockRotate(cur_block);
            for(int i=0;i<4;i++)
                for(int j=0;j<4;j++)
                    game_area[block_pos.pos_y+i][block_pos.pos_x+j]=cur_block[i][j];
            GetBorder(cur_block,cur_border);
            break;
        case DOWN:
            if(block_pos.pos_y+cur_border.dbound==AREA_ROW-1)
            {
                ConvertStable(block_pos.pos_x,block_pos.pos_y);
                ResetBlock();
                break;
            }
            if(IsCollide(block_pos.pos_x,block_pos.pos_y,DOWN))
            {
                ConvertStable(block_pos.pos_x,block_pos.pos_y);
                ResetBlock();
                break;
            }
            for(int j=cur_border.lbound;j<=cur_border.rbound;j++)
                game_area[block_pos.pos_y][block_pos.pos_x+j]=0;

            block_pos.pos_y+=1;
            for(int i=0;i<4;i++)
                for(int j=cur_border.lbound;j<=cur_border.rbound;j++)
                    if(block_pos.pos_y+i<=AREA_ROW-1&&game_area[block_pos.pos_y+i][block_pos.pos_x+j]!=2)
                        game_area[block_pos.pos_y+i][block_pos.pos_x+j]=cur_block[i][j];
            break;

        case LEFT:
            if(block_pos.pos_x+cur_border.lbound==0||IsCollide(block_pos.pos_x,block_pos.pos_y,LEFT))
                break;
            for(int i=cur_border.ubound;i<=cur_border.dbound;i++)
                game_area[block_pos.pos_y+i][block_pos.pos_x+3]=0;
            block_pos.pos_x-=1;
            for(int i=cur_border.ubound;i<=cur_border.dbound;i++)
                for(int j=0;j<4;j++)
                    if(block_pos.pos_x+j>=0&&game_area[block_pos.pos_y+i][block_pos.pos_x+j]!=2)
                        game_area[block_pos.pos_y+i][block_pos.pos_x+j]=cur_block[i][j];
            break;

        case RIGHT:
            if(block_pos.pos_x+cur_border.rbound==AREA_COL-1||IsCollide(block_pos.pos_x,block_pos.pos_y,RIGHT))
                break;
            for(int i=cur_border.ubound;i<=cur_border.dbound;i++)
                game_area[block_pos.pos_y+i][block_pos.pos_x]=0;
            block_pos.pos_x+=1;
            for(int i=cur_border.ubound;i<=cur_border.dbound;i++)
                for(int j=0;j<4;j++)
                    if(block_pos.pos_x+j<=AREA_COL-1&&game_area[block_pos.pos_y+i][block_pos.pos_x+j]!=2)
                        game_area[block_pos.pos_y+i][block_pos.pos_x+j]=cur_block[i][j];
            break;

        case SPACE:
            while(block_pos.pos_y+cur_border.dbound<AREA_ROW-1&&!IsCollide(block_pos.pos_x,block_pos.pos_y,DOWN))
            {
                for(int j=cur_border.lbound;j<=cur_border.rbound;j++)
                    game_area[block_pos.pos_y][block_pos.pos_x+j]=0;
                block_pos.pos_y+=1;
                for(int i=0;i<4;i++)
                    for(int j=cur_border.lbound;j<=cur_border.rbound;j++)
                        if(block_pos.pos_y+i<=AREA_ROW-1&&game_area[block_pos.pos_y+i][block_pos.pos_x+j]!=2)
                            game_area[block_pos.pos_y+i][block_pos.pos_x+j]=cur_block[i][j];
            }
            ConvertStable(block_pos.pos_x,block_pos.pos_y);
            ResetBlock();
            break;

        default:
            break;
    }

    int i=AREA_ROW-1; //загальна кількість рядків ігрового поля
    int line_count=0; // змінна для збереження кількості рядків, які повністю заповнив гравець

    while(i>=1)
    {
        bool is_line_full=true;
        for(int j=0;j<AREA_COL;j++)
            if(game_area[i][j]==0)
            {
                // якщо поточний рядок порожній, то переходимо на новий рядок (індекс наступного рядка)
                is_line_full=false;
                i--;
                break;
            }
        if(is_line_full)
        {
            // якщо рядок повністю заповнений, то спускаємо всі заповнені клітинки нижче на одну та збільшуємо на +1 кількість заповнених рядків
            for(int k=i;k>=1;k--)
                for(int j=0;j<AREA_COL;j++)
                    game_area[k][j]=game_area[k-1][j];
            line_count++;
        }
    }
    score+=line_count*10; // начислення балів (за кожен зібраний рядок 10 балів)

    // перевірка, якщо останній рядок заповнений, то кінець гри
    for(int j=0;j<AREA_COL;j++)
        if(game_area[0][j]==2)
            GameOver();
}








