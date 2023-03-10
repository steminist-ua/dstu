#include "lr2.h"
#include "newform.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    lr2 w;
//    w.show();


    // якщо необхідно зробити, щоб при запуску створенного застосунку відображалася інша форма (не та, яка була створена першою при створені проєкту)
    newForm nf;  //1. необхідно створити екземпляр класу відповідної форми
    nf.show(); //2. звернутися до цього екземпляру та викликати метод відкриття форми - show()


    return a.exec();
}
