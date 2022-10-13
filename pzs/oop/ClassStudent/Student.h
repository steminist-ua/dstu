#include <string>
using namespace std;

class Student
{
private:
	int id;
	string name;
	string group;

public:
	Student();
	Student(int id, string name, string group);

	void setId(int id);
	void setName(string name); 
	void setGroup(string group);

	int getId();
	string getName();
	string getGroup();

	void print();
};

