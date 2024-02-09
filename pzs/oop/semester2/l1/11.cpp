#include <iostream>
#include "Sportsman.h"
using namespace std;

int main()
{
    Sportsman footballPlayer("Джон Сміт", 28);
    Sportsman basketballPlayer("Майкл Джордан", 58);

    cout << "Інформація про футболіста:" << endl;
    footballPlayer.displayInfo();

    cout << "\nІнформація про баскетболіста:" << endl;
    basketballPlayer.displayInfo();
    return 0;
}
