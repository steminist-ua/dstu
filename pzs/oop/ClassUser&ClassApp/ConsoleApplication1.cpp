// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "user.h"
#include "app.h"
using namespace std;
int main()
{
    //std::cout << "Hello World!\n";
    //user id(10);
    //id.getId();
    //std::cout << id.getId();
    //============================

    app app1;
    cout << "id - " << app1.GetId() << "\n";
    cout << "name - " << app1.name << "\n";

    app app2(25, "michael");

        cout << "id - " << app2.GetId() << "\n";
    
        cout << "name - " << app2.name;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
