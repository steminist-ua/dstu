#include <iostream>
#include "Student.h"
using namespace std;

Student::Student()
{
	this->id = 0;
	this->name = "Name";
	this->group = "Group";
}

Student::Student(int id, string name, string group)
{
	this->id = id;
	this->name = name;
	this->group = group;
}

void Student::setId(int id)
{
	this->id = id;
}

void Student::setName(string name)
{
	this->name = name;
}

void Student::setGroup(string group)
{
	this->group = group;
}

int Student::getId()
{
	return this->id;
}

string Student::getName()
{
	return this->name;
}

string Student::getGroup()
{
	return this->group;
}

void Student::print()
{
	cout << endl;
	cout << "id: " << this->getId() << endl;
	cout << "name: " << getName() << endl;
	cout << "group: " << getGroup() << endl;
}
