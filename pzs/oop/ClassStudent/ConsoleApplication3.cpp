#include <iostream>
#include "Student.h"
using namespace std;

int main()
{
	Student s1;
	s1.print();
	/*cout << "id: " << s1.getId() << endl;
	cout << "name: " << s1.getName() << endl;
	cout << "group: " << s1.getGroup() << endl;*/

	Student s2(1, "Name2", "Group2");
	s2.print();
	/*cout << endl;
	cout << "id: " << s2.getId() << endl;
	cout << "name: " << s2.getName() << endl;
	cout << "group: " << s2.getGroup() << endl;*/

	s1.setGroup("Group2");
	s1.print();

	if (s1.getGroup() == s2.getGroup()) {
		cout << "Yes!" << endl;
	}
	else {
		cout << "No!" << endl;
	}
}

