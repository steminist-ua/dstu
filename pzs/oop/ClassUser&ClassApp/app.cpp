#include "app.h"
using namespace std;

app::app()
{
	this->id = 22;
	this->name = "anton";
}

app::app(int id, string name)
{
	this->id = id;
	this->name = name;

}

void app::SetId(int id)
{
	this->id = id;
}

int app::GetId()
{
	return this->id;
}
