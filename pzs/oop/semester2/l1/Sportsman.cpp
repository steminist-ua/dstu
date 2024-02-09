#include "sportsman.h"

Sportsman::Sportsman(string _name, int _age) : name(_name), age(_age) {}

// Sportsman::Sportsman(string _name, int _age){
//     name = _name;
//     age = _age;
// }


void  Sportsman::displayInfo() {
    cout << "Ім'я: " << this->name << endl;
    cout << "Вік: " << this->age << " років" << endl;
}
