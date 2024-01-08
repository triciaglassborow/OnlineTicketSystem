#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>

using namespace std;

class FloorChart
{

public:
	FloorChart();
	void DisplayFloorChart();
	void SelectSeat();

protected:
	int floor[3][5];
	char available = 'A';
	char held =  'H';
	char unavailble = 'X';
	string seat;
	
};

FloorChart::FloorChart()
{
	for (int r = 0; r < 3; ++r)
		for (int c = 0; c < 5; ++c)
			floor[r][c] = available; //Displaying all seats as available when the floor chart is first created


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
			cout << setw(3) << static_cast<char>(floor[r][c]); // adding the seat availablity
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
	static_cast <char> (held);

	cout << "\nHow many seats would you like?";
	cin >> max; 

	do
	{
		cout << "\nEnter a seat you would like, eg 2,B: ";
		cin >> r >> comma >> column;

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
		// check seat status
		floor[r - 1][c] = held;
		DisplayFloorChart();

		count++;
	} while (count != max);
}
