#include <iostream>
#include <string>

using namespace std;

// Базовий клас "Спортсмен"
class Sportsman {
protected:
    string name;
    int age;

public:
    Sportsman(const string& _name, int _age) : name(_name), age(_age) {}

    void displayInfo() {
        cout << "Ім'я: " << name << endl;
        cout << "Вік: " << age << " років" << endl;
    }
};

// Похідний клас "Футболіст"
class FootballPlayer : public Sportsman {
private:
    string position;
    string team;

public:
    FootballPlayer(const string& _name, int _age, const string& _position, const string& _team)
        : Sportsman(_name, _age), position(_position), team(_team) {}

    void displayInfo() {
        Sportsman::displayInfo();
        cout << "Позиція: " << position << endl;
        cout << "Команда: " << team << endl;
    }
};

// Похідний клас "Баскетболіст"
class BasketballPlayer : public Sportsman {
private:
    string position;
    string team;

public:
    BasketballPlayer(const string& _name, int _age, const string& _position, const string& _team)
        : Sportsman(_name, _age), position(_position), team(_team) {}

    void displayInfo() {
        Sportsman::displayInfo();
        cout << "Позиція: " << position << endl;
        cout << "Команда: " << team << endl;
    }
};

int main() {
    FootballPlayer footballPlayer("Джон Сміт", 28, "Нападник", "Манчестер Юнайтед");
    BasketballPlayer basketballPlayer("Майкл Джордан", 58, "Разігруючий", "Чикаго Буллз");

    cout << "Інформація про футболіста:" << endl;
    footballPlayer.displayInfo();

    cout << "\nІнформація про баскетболіста:" << endl;
    basketballPlayer.displayInfo();

    return 0;
}
