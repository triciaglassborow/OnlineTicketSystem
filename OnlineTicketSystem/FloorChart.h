#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>

#include "Seat.h"
using namespace std;

class FloorChart
{

public:
	FloorChart();
	void DisplayFloorChart();
	void SelectSeat();

protected:
	shared_ptr<Seat>floor[3][5];
	string available = "A",
		held = "H",
		unavailble = "X";
	string seat;
	
};

FloorChart::FloorChart()
{
	for (int r = 0; r < 3; ++r)
		for (int c = 0; c < 5; ++c)
			floor[r][c] = shared_ptr<Seat>(new Seat(available)); //setting all seats as available when the floor chart is first created


}

void FloorChart::DisplayFloorChart()
{
	for (int r = 0; r < 3; ++r)
	{
		if (r==0)
			cout << "     A     B     C     D     E  \n" << // coulmn lables
					"   _____________________________" << 
			      "\n  |     |     |     |     |     |\n"; // adding a top to first row
		cout << r+1 <<" |"; // row lables
		for (int c = 0; c < 5; ++c)
		{
			floor[r][c]->DisplayStatus(); // displaying each seats status 
			cout << "  |";
		}
		if (r !=2) 
			cout << "\n  |_____|_____|_____|_____|_____|" << "\n  |     |     |     |     |     |\n"; // adding the row line to all of them then adding the beggining of the next box
		if (r == 2)
			cout << "\n  |_____|_____|_____|_____|_____|"; // adding a bottom to the final row
	}
}



void FloorChart::SelectSeat()
{
	int count = 0;
	int r, c, max;
	char comma, column;
	cout << "\nHow many seats would you like?";
	cin >> max; 

	do
	{
		cout << "\nEnter a seat you would like, eg 2,B: ";
		cin >> r >> comma >> column; // reading in the 3 characters inputed 

		// Assigning the letter input to corresponding column postion 
		if (column == 'A' || column == 'a')  
			c = 0;
		if (column == 'B' || column == 'b')
			c = 1;
		if (column == 'C' || column == 'c')
			c = 2;
		if (column == 'D' || column == 'd')
			c = 3;
		if (column == 'E' || column == 'e')
			c = 4;

		floor[r - 1][c]->CheckStatus();

		if (floor[r - 1][c]->CheckStatus() != available) // if CheckStatus returned held or unavailalbe 
		{
			cout << "Seat Not Available";
			count = count - 1; // taking the counter back one step so they can re-select a seat
		}
		else 
		{
			floor[r - 1][c]->SetStatus(held); //making that seat status held
		}
		count++;
	} while (count != max);
	DisplayFloorChart();
}