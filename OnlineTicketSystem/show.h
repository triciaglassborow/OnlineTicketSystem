#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>

using namespace std;

class show
{
public:
	show(string Name, string Date, string Time);
	~show();
	void DisplayShow(int position);

protected:
	string showName,
		showDate,
		showTime;

	int showPosition;
	
};

//Constructor 
show::show(string name, string date, string time)
{
	this->showName = name;
	this->showDate = date;
	this->showTime = time;
}

void show::DisplayShow(int position)
{
	this->showPosition = position;

	cout << showPosition << " " << showName << " | ";
}
