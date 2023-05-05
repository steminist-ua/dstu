#include <QFile>
#include <QTextStream>
#include <QDebug>

//Завдання: Напишіть програму, яка використовує <QTextStream> для зчитування даних з текстового файлу та виводу на екран лише тих рядків, які містять певне слово.

int main()
{
    QFile file("text.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return 1;

    QTextStream in(&file);
    QString searchWord = "hello";
    QString line;

    while (!in.atEnd()) {
        line = in.readLine();
        if (line.contains(searchWord))
            qDebug() << line;
    }

    return 0;
}

