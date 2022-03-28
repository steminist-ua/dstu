#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //12 задаємо таймер, щоб стрілки рухалися
    QTimer *timer = new QTimer;
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    //7 додаємо анімацію, щоб стрілка рухалася (8 нижще)
    QTime time = QTime::currentTime();



//1    QPainter painter;
//    painter.begin(this);
//    painter.end();

    QPainter painter;
    painter.begin(this);

    //2 сглажування намальованого зображення на формі
    painter.setRenderHint(QPainter::Antialiasing);

    //3 налаштування системи координат (ставимо центр системи у центрі форми)
    painter.translate(width()/2, height()/2);

    //4 розміщення годинника
    int R = 0.7 * qMin(width()/2, height()/2);

    //5 малюємо циферблат
    for(int i = 0; i < 60; i++)
    {
        //кожну 5-ту риску виділяємо (через умову)
        if(i % 5 == 0)
        {
            painter.drawLine(0, R, 0, R-10);
        }
        else
        {
            painter.drawLine(0, R, 0, R-4);
        }
        //поворот на 6 градусів
        painter.rotate(6.0);
    }

    //6 малюємо стрілку годинну
    painter.save();
    QPolygon pol;
    pol << QPoint(-0.05 * R, 0) << QPoint(0.05 * R, 0) << QPoint(0, -0.4 * R);

    //8 поворот для стрілки перед її відображенням. 1 година займаэ 30 градусів. Отже, 30 множимо на кількість годин та додамо кількість хвилин поділене на 60
    painter.rotate(30 * (time.hour() + time.minute()/60));

    //9 прибираємо контур стрілки та задаємо колір
    painter.setPen(Qt::NoPen);
    painter.setBrush(QColor(45, 128, 64));

    painter.drawPolygon(pol);
    painter.restore();


    //10 малюємо стрілку хвилинну (pol замінюємо на pol2)
    painter.save();
    QPolygon pol2;
    pol2 << QPoint(-0.05 * R, 0) << QPoint(0.05 * R, 0) << QPoint(0, -0.7 * R); //робимо стрілку довшою
    //Одна хвилина - 6 градусів. Отже 6 множимо на суму хвилин та секунд поділених на 60
    painter.rotate(6 * (time.minute() + time.second()/60));
    painter.setPen(Qt::NoPen);
    painter.setBrush(QColor(0, 127, 127, 191)); //змінюємо колір (додаємо прозорість)
    painter.drawPolygon(pol2);
    painter.restore();

    //11 малюємо стрілку секундну (pol2 замінюємо на pol3)
    painter.save();
    QPolygon pol3;
    //робимо стрілку тоншою та ще довшою
    pol3 << QPoint(-0.03 * R, 0) << QPoint(0.03 * R, 0) << QPoint(0, -0.9 * R); //робимо стрілку довшою
    //шість градусів на кількість секунд
    painter.rotate(6 * time.second());
    painter.setPen(Qt::NoPen);
    painter.setBrush(QColor(202, 0, 0, 191)); //змінюємо колір (додаємо прозорість)
    painter.drawPolygon(pol3);
    painter.restore();

    painter.end();

}

