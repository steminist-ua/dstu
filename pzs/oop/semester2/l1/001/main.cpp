#include <iostream>
#include "sportsman.h"
using namespace std;

int main()
{
    int a = 0;
    cin >> a; // получаем пользовательское число и сохраняем его в переменную a
    cout << "You entered " << a << std::endl;

    Sportsman footballPlayer("Джон Сміт", 28);
    Sportsman basketballPlayer("Майкл Джордан", 58);

    cout << "Інформація про футболіста:" << endl;
    footballPlayer.displayInfo();

    cout << "\nІнформація про баскетболіста:" << endl;
    basketballPlayer.displayInfo();
    return 0;
}
