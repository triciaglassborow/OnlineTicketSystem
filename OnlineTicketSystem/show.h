#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>

#include "FloorChart.h"

using namespace std;

class Show
{
public:
	Show(string Name, string Date, string Time);
	void DisplayShowName(int position);
	void DisplayFloorChart();
	void DisplayShowDetails();

protected:
	string showName,
		showDate,
		showTime;
	int showPosition;

	FloorChart FLOOR;
};

//Constructor 
Show::Show(string name, string date, string time)
{
	this->showName = name;
	this->showDate = date;
	this->showTime = time;

	
}

void Show::DisplayShowName(int position)
{
	this->showPosition = position;

	cout << showPosition << " " << showName << " | ";
}

void Show::DisplayShowDetails()
{
	cout << showName << endl;
	cout << showDate << endl;
	cout << showTime << endl;

	DisplayFloorChart();

}
void Show::DisplayFloorChart()
{
	FLOOR.CreateFloorChart();
}
