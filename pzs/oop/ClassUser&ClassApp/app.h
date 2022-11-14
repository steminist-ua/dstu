#pragma once
#include <string>
using namespace std;
class app
{
public:
	string name;
private:
	int id;

public: app();
	  app(int id,string name);

	  void SetId(int id);
	  int GetId();
};

