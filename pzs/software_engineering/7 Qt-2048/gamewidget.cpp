#include "gamewidget.h"
#include "ui_widget.h"
#include <QLabel>
#include <time.h>
#include <QKeyEvent>
#include <QMessageBox>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
#include <QCloseEvent>
#include <QPropertyAnimation>
#include <QFileDialog>

//нові лейбли на полі можуть з'являтися лише з цими значеннями в масиві (2 та/або 4)
int CREATE_NUMBER[2] = {
    2,
    4
};

const int colWidth = 75;      //ширина колонки
const int rowHeight = 75;     //висота строки
const int xOffset = 10;       //відстань зміщення (відступи між клітинками)
const int yOffset = 10;

GameWidget::GameWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->setWindowTitle("2048");

    //ініціалізуємо генератор випадкових чисел
    srand((size_t)time(NULL));

    //ініціалізуємо ігрове поле
    m_bgWidget = new BGWidget(this);
    m_bgWidget->setGeometry(19,200,310,310);

    this->m_labelCount = 0;     //кількість балів
    initGame();                 //ініціалізація гри

    setScore();

    //встановлюємо фокус на головне вікно (поле) гри
    this->m_bgWidget->setFocus();

    //динамічне оновлення форми гри при русі блоків (лейблів)
    connect(this,&GameWidget::GestureMove,this,&GameWidget::moveLabel);
    //динамічне оновлення форми гри при зміні кількості балів
    connect(this,&GameWidget::ScoreChange,this,&GameWidget::setScore);
}

GameWidget::~GameWidget()
{
    delete ui;
    releaseRes();
    delete m_bgWidget;
}

void GameWidget::createLabel()
{
    while(true){
        int row = rand() % 4;
        int col = rand() % 4;

        int index = rand() % 2;

        //видалити дублювання
        if(labels[row][col] != NULL){
            continue;
        }
        //фонове поле
        MyLabel *label=new MyLabel(CREATE_NUMBER[index]);
        int x = col * colWidth + xOffset;
        int y = row * rowHeight +yOffset;
        label->setGeometry(x,y,66,66);
        label->setParent(m_bgWidget);

        labels[row][col] = label;
        labels[row][col]->show();

        break;
    }

    ++m_labelCount;
}

void GameWidget::initGame()
{
    //ініціалізація рахунку (балів)
    m_score = 0;
    m_highScore = 0;

    //ініціалізація масиву блоків ігрового поля
    for(int row = 0;row < 4;++row)
    {
        for(int col = 0;col <4;++col)
        {
             labels[row][col] = NULL;
        }
    }
    
     // звернення до файлу у папці побудованого проєкту (build -> debug)
    QFile *file = new QFile("data.json");
    //перевірка чи файл існує, чи можливо його відкрити для читання (якщо ні, то гра продовжується)
    if(file->open(QIODevice::ReadOnly))
    {
        //зчитування даних з файлу
        QByteArray ba = file->readAll();

        //перетворення даних з файлу в об'єкт
        QJsonDocument d = QJsonDocument::fromJson(ba);
        QJsonObject json = d.object();
        //зчитування значень m_highScore та m_score з об'єкта у відповідні змінні 
        QJsonValue value = json.value(QString("m_highScore"));
        QJsonValue score = json.value(QString("m_score"));

        //відображення на формі значення m_highScore (найбільшого рахунку)
        m_highScore = value.toVariant().toInt();
        this->ui->best_2->setText(QString::number(m_highScore));

        //відображення на формі значення m_score (поточного рахунку)
        m_score = score.toVariant().toInt();
        this->ui->score_3->setText(QString::number(m_score));

        //збереження до файлу поточного прогресу гри (розміщення блоків/лейблів на полі з їх значеннями)
        QJsonValue labelsArr = json.value(QString("labels"));
        QJsonArray arr = labelsArr.toArray();
        for(int i = 0;i< arr.size(); i++)
        {
            QJsonValue labelValue = arr.at(i);
            QJsonArray arr1 = labelValue.toArray();
            for(int j = 0; j< arr1.size(); j++)
            {
                QJsonValue arrValue =  arr1.at(j);
                int oldValue = arrValue.toVariant().toInt();
                if(oldValue != 0)
                {
                    MyLabel *label=new MyLabel(oldValue);
                    int x = j * colWidth + xOffset;
                    int y = i * rowHeight +yOffset;
                    label->setGeometry(x,y,66,66);
                    label->setParent(m_bgWidget);

                    labels[i][j] = label;
                    labels[i][j]->show();

                    ++m_labelCount;
                }
            }
        }

        file->close();
    }
    else
    {
        //ініціалізація двох нових лейблів на полі (це якщо відкриття файлу не вдалося, його не існує та зчитати не можливо)
        for(int i=0;i<2;i++){
           createLabel();
        }
    }
}

bool GameWidget::merge(MyLabel *temp, int row, int col)
{
    if(temp != NULL)
    {
        //щоб визначити, чи рівні значення двох лейблів
        if(temp->text() == labels[row][col]->text())
        {
            int x = labels[row][col]->x();
            int y = row * rowHeight + yOffset;  //зміщення по вертикалі

            //ефект переміщення лейбла на полі (анімація)
            QPropertyAnimation *animation = new QPropertyAnimation(temp,"geometry");
            animation->setStartValue(temp->geometry());
            animation->setEndValue(QRect(x,y,temp->width(),temp->height()));
            animation->setDuration(100);
            animation->setEasingCurve(QEasingCurve::Linear);
            animation->start(QAbstractAnimation::DeleteWhenStopped);

            int score = 2*labels[row][col]->text().toInt();
            labels[row][col]->reSetText(score);

            m_score += score;
            emit ScoreChange();

            --m_labelCount;

            return true;
        }
    }
    return false;
}

bool GameWidget::isMerge()
{
    for(int row = 0;row < 4;++row)
    {
        for(int col = 0;col <4;++col)
        {
              if(isMergeDown(row,col) || isMergeRight(row,col))
              {
                return true;
              }
        }
    }

    return false;
}

bool GameWidget::gameOver()
{    
    bool flag = false;
    //якщо сітка заповнена(m_labelCount == 16). тобто все ігрове поле заповнене
    if(m_labelCount == 16)
    {
        bool isWin = isMerge();
        if(!isWin){
            //якщо немає лейблів, які можна об'єднати, то видаємо повідомлення про невдачу, програш
            QMessageBox::about(this, "Information", "fail!");
            flag = true;
        }
    }
    else
    {
        //якщо на полі є лейбл зі значенням 2048, то видаємо повідомлення про виграш
        for(int row = 0;row < 4;++row)
        {
            for(int col = 0;col <4;++col)
            {
                if(labels[row][col] != NULL && labels[row][col]->text() == "2048")
                {
                     QMessageBox::about(this, "Information", "Congrats, you won!");
                     flag = true;
                     break;
                }
            }
            if(flag)
            {
                break;
            }
        }
    }

    if(flag)
    {
        //очищуємо, починаємо з початку
        releaseRes();
        m_labelCount = 0;

        m_score = 0;
        emit ScoreChange();

        for(int i=0;i<2;i++){
           createLabel();
        }
    }

    return flag;
}

void GameWidget::saveGame()
{
    // відкриття того ж самого файлу, але тепер для запису (тих же даних - найбільший рахунок, з перевіркою, чи потрібно його переписати, поточний рахунок, та поточне положення лейблів на полі з їх значеннями)
    QFile *file = new QFile("data.json");
    if(file->open(QIODevice::WriteOnly))
    {
        QJsonDocument d;
        QJsonObject json = d.object();

        //рахунок
        QJsonArray arr;
        for(int i = 0;i< 4; i++)
        {
            QJsonArray arr1;
            for(int j = 0; j< 4; j++)
            {
                if(labels[i][j] != NULL)
                {
                    arr1.append(labels[i][j]->text());
                }
                else
                {
                    arr1.append(0);
                }
            }
            arr.append(arr1);
        }

        json.insert("labels",arr);

        json.insert("m_highScore",m_highScore);
        json.insert("m_score",m_score);
        d.setObject(json);
        QByteArray ba = d.toJson(QJsonDocument::Indented);

        //записати все до файлу та закрити потік запису
        file->write(ba);
        file->close();
    }
}

void GameWidget::releaseRes()
{
    for(int col = 0;col <4;++col)
    {
        for(int row = 0;row < 4;++row)
        {
            if(labels[row][col] != NULL)
            {
                delete labels[row][col];
                labels[row][col] = NULL;
            }
        }
    }
}

void GameWidget::closeEvent(QCloseEvent *event)
{
    saveGame();
}

void GameWidget::setScore()
{
    this->ui->score_3->setText(QString::number(m_score));
    if(m_score > m_highScore)
    {
        m_highScore = m_score;
        this->ui->best_2->setText(QString::number(m_highScore));
    }
}

void GameWidget::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
        case Qt::Key_Left:
            emit GestureMove(GestureDirect::LEFT);
            break;
        case Qt::Key_Right:
            emit GestureMove(GestureDirect::RIGHT);
            break;
        case Qt::Key_Down:
            emit GestureMove(GestureDirect::DOWN);
            break;
        case Qt::Key_Up:
           emit GestureMove(GestureDirect::UP);
            break;
        default:
            break;
    }
    QWidget::keyPressEvent(event);
}

void GameWidget::moveLabel(GestureDirect direction)
{
    bool isMove = false;
    switch (direction) {
    case LEFT:
        isMove = moveLeft();
        break;
    case RIGHT:
        isMove = moveRight();
        break;
    case UP:
        isMove = moveUp();
        break;
    case DOWN:
        isMove = moveDown();
        break;
    default:
        break;
    }

    //перевірка, чи гра закінчена
    bool isOver = gameOver();

    //створюємо нові лейбли на полі, якщо у гравця є ще можливість рухати лейбли на полі (є вільне місце) та якщо ще не кінець гри 
    if(isMove && !isOver){
        createLabel();
    }

    //кінець гри
    if(!isOver)
    {
        gameOver();
    }
}

void GameWidget::on_bt_restart_clicked()
{
    //очищуємо та починаємо заново
    releaseRes();
    m_labelCount = 0;

    m_score = 0;
    emit ScoreChange();

    for(int i=0;i<2;i++){
       createLabel();
    }

    this->m_bgWidget->setFocus();
}


bool GameWidget::moveUp()
{
    bool isMove = false; //чи можна перемістити лейбл на полі
    int i , j ; //i:рядок запису
                //j:рядок, який записує, чи був поточний елемент об'єднаний
    for(int col = 0;col < 4;++col)
    {
        j = -1;
        for(int row = 0;row < 4;++row)
        {
            //перша знайдена ненульова мітка
            if(labels[row][col] == NULL)
            {
                i = row + 1;
                while(i < 4)
                {
                    MyLabel *temp = labels[i][col];
                    if(temp != NULL)
                    {
                        isMove = true;
                        bool flag = false;
                        if(j != (row-1))
                        {
                            flag= isMergeUp(i,col);
                        }
                        if(flag)
                        {
                            --row;
                            j = row;
                            --m_labelCount;
                        }else
                        {
                            //поміняти місцями лейбли
                            labels[row][col] = temp;
                            j = -1; //зменшити j на -1;
                        }

                        int x = temp->x();
                        int y = row * rowHeight + yOffset;  //зміщення по вертикалі

                        //анімація переміщення лейбла вгору
                        QPropertyAnimation *animation = new QPropertyAnimation(temp,"geometry");
                        animation->setStartValue(temp->geometry());
                        animation->setEndValue(QRect(x,y,temp->width(),temp->height()));
                        animation->setDuration(100);    //час анімації
                        animation->setEasingCurve(QEasingCurve::Linear); //тип анімації
                        animation->start(QAbstractAnimation::DeleteWhenStopped);

                        //зміна значення лейбла та змініть значення рахунку
                        if(flag){
                            int score = 2*labels[row][col]->text().toInt();
                            labels[row][col]->reSetText(score);

                            m_score += score;
                            emit ScoreChange();

                            delete temp;
                            temp = NULL;
                        }

                        labels[i][col] = NULL;
                        ++row;
                    }
                    ++i;
                }
            }
            else if(row + 1 < 4)
            {
                MyLabel *temp = labels[row + 1][col];
                bool flag = merge(temp,row,col);
                if(flag)
                {
                    isMove = true;
                    j = row;

                    delete labels[row + 1][col];
                    labels[row + 1][col] = NULL;
                }
            }
        }
    }

    return isMove;
}

bool GameWidget::moveDown()
{
    bool isMove = false; 
    int i , j ; 
    for(int col = 0;col <4;++col)
    {
        j = -1;
        for(int row = 3;row > -1;--row)
         {
            if(labels[row][col] == NULL)
            {
                i =row-1;
                while(i > -1)
                {
                    MyLabel *temp = labels[i][col];
                    if(temp != NULL)
                    {
                        isMove = true;

                        bool flag = false;
                        if(j != (row + 1))
                        {
                            flag= isMergeDown(i,col);
                        }
                        if(flag)
                        {
                            ++row;
                            j = row;
                            --m_labelCount;
                        }else
                        {
                            labels[row][col] = temp;
                            j = -1;
                       }

                        int x= temp->x();
                        int y = row * rowHeight + yOffset;
                        QPropertyAnimation *animation = new QPropertyAnimation(temp,"geometry");
                        animation->setStartValue(temp->geometry());
                        animation->setEndValue(QRect(x,y,temp->width(),temp->height()));
                        animation->setDuration(100);
                        animation->setEasingCurve(QEasingCurve::Linear);
                        animation->start(QAbstractAnimation::DeleteWhenStopped);
                        if(flag){
                            int score = 2*labels[row][col]->text().toInt();
                            labels[row][col]->reSetText(score);

                            m_score += score;
                            emit ScoreChange();

                            delete temp;
                            temp = NULL;
                        }

                        labels[i][col] = NULL;
                        --row;
                    }
                    --i;
                }
            }
            else if(row-1>=0)
            {
                MyLabel *temp = labels[row-1][col];
                bool flag = merge(temp,row,col);
                if(flag)
                {
                    isMove = true;
                    j = row;

                    delete labels[row-1][col];
                    labels[row-1][col] = NULL;
                }
            }
        }
    }
    return isMove;
}

bool GameWidget::moveLeft()
{
    bool isMove = false;
    int i , j ;
    for(int row = 0;row < 4;++row)
    {
        j = -1;
        for(int col = 0;col < 4;++col)
        {
            if(labels[row][col] == NULL)
            {
                i = col + 1;
                while(i < 4)
                {
                    MyLabel *temp = labels[row][i];
                    if(temp != NULL)
                    {
                        isMove = true;
                        bool flag = false;
                        if(j != (col-1))
                        {
                            flag= isMergeLeft(row,i);
                        }
                        if(flag)
                        {
                            --col;
                            j = col;
                            --m_labelCount;
                        }else
                        {
                            labels[row][col] = temp;
                            j = -1;
                        }

                        int x = col * colWidth + xOffset;
                        int y = temp->y();

                        QPropertyAnimation *animation = new QPropertyAnimation(temp,"geometry");

                        animation->setStartValue(temp->geometry());
                        animation->setEndValue(QRect(x,y,temp->width(),temp->height()));
                        animation->setDuration(100);

                        animation->setEasingCurve(QEasingCurve::Linear);
                        animation->start(QAbstractAnimation::DeleteWhenStopped);

                        if(flag){
                            int score = 2*labels[row][col]->text().toInt();
                            labels[row][col]->reSetText(score);

                            m_score += score;
                            emit ScoreChange();

                            delete temp;
                            temp = NULL;

                        }

                        labels[row][i] = NULL;
                        ++col;
                    }
                    ++i;
                }
            }
            else if(col + 1 < 4)
            {
                MyLabel *temp = labels[row][col+1];
                bool flag = merge(temp,row,col);
                if(flag)
                {
                    isMove = true;
                    j = col;
                    delete labels[row][col+1];
                    labels[row][col+1] = NULL;
                }
            }
        }
    }

    return isMove;
}

bool GameWidget::moveRight()
{
    bool isMove = false;
    int i , j ;
    for(int row = 0;row < 4;++row)
     {
        j=-1;
        for(int col = 3; col > -1;--col)
        {
            if(labels[row][col] == NULL)
            {
                i = col - 1;
                while(i > -1)
                {
                    MyLabel *temp = labels[row][i];
                    if(temp != NULL)
                    {
                        isMove = true;
                        bool flag = false;
                        if(j != (col + 1)){
                            flag = isMergeRight(row,i);
                        }

                        if(flag)
                        {
                            ++col;
                            j = col;
                            --m_labelCount;
                        }
                        else
                        {
                            labels[row][col] = temp;
                            j = -1;
                        }

                        int x = col * colWidth + xOffset;
                        int y = temp->y();


                        QPropertyAnimation *animation = new QPropertyAnimation(temp,"geometry");

                        animation->setStartValue(temp->geometry());
                        animation->setEndValue(QRect(x,y,temp->width(),temp->height()));
                        animation->setDuration(100);

                        animation->setEasingCurve(QEasingCurve::Linear);
                        animation->start(QAbstractAnimation::DeleteWhenStopped);

                        if(flag){
                            int score = 2*labels[row][col]->text().toInt();
                            labels[row][col]->reSetText(score);

                            m_score += score;
                            emit ScoreChange();

                            delete temp;
                            temp = NULL;
                        }

                        labels[row][i] = NULL;
                        --col;
                    }
                    --i;
                }
            }
            else if(col-1>=0)
            {
                MyLabel *temp = labels[row][col-1];
                bool flag = merge(temp,row,col);
                if(flag)
                {
                    isMove = true;
                    j = col;

                    delete labels[row][col-1];
                    labels[row][col-1] = NULL;
                }
            }
        }
    }
    return isMove;
}
//проверка на слияние сверху
bool GameWidget::isMergeUp(int row, int col)
{
    if(row != 0)
    {
        int up = row - 1;
        while((up >= 0) && (labels[up][col]==NULL))
        {
            --up;
        }

        if(up >=0 && labels[up][col]->text() == labels[row][col]->text())
        {
            return true;
        }
    }

    return false;
}

bool GameWidget::isMergeDown(int row, int col)
{
    if(row != 3)
    {
        int down = row + 1;
        while((down < 4) && (labels[down][col] == NULL))
        {
            ++down;
        }
        if(down < 4 && labels[down][col]->text() == labels[row][col]->text())
        {
            return true;
        }
    }

    return false;
}

bool GameWidget::isMergeLeft(int row, int col)
{
    if(col != 0)
    {
        int left = col - 1;
        while((left >=0 ) && (labels[row][left] == NULL))
        {
            --left;
        }

        if(left >= 0 && labels[row][left]->text() == labels[row][col]->text())
        {
           return true;
        }
    }

    return false;
}

bool GameWidget::isMergeRight(int row, int col)
{
    if(col != 3)
    {
        int right = col + 1;
        while((right < 4) && (labels[row][right] == NULL))
        {
            ++right;
        }
        if(right < 4 && labels[row][right]->text() == labels[row][col]->text())
        {
            return true;
        }
    }

    return false;
}
