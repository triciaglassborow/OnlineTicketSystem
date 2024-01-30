/*
-each show is assigned its name, date and time in ShowList.h
-Seat Selection for the show, calling different functions from FloorChart.h to
make seat selection work
*/

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
	void SeatSelection();
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
	cout << position << " " << showName << " | ";
}

void Show::DisplayShowDetails()
{
	system("CLS");
	cout << showName << endl;
	cout << showDate << endl;
	cout << showTime << endl;

	SeatSelection();

}
void Show::SeatSelection()
{
	FLOOR.DisplayFloorChart();
	FLOOR.SelectSeat();
	FLOOR.DisplayTicketList();
}
