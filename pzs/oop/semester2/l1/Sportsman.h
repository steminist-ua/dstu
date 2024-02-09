#ifndef SPORTSMAN_H
#define SPORTSMAN_H

#include <iostream>
#include <string>
using namespace std;

class Sportsman
{
private:
    string name;
    int age;

public:
    Sportsman(string _name, int _age);
    void displayInfo();
};

#endif // SPORTSMAN_H
