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
	void DisplayShow();

protected:
	string showName,
		showDate,
		showTime;
	
};

//Constructor 
show::show(string Name, string Date, string Time)
{
	this->showName = Name;
	this->showDate = Date;
	this->showTime = Time;
}

void show::DisplayShow()
{
	cout << showName;
}
