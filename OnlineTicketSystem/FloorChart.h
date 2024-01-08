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

protected:
	int floor[3][5];
	int available = 'A';
	int held =  'H';
	int unavailble = 'X';
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
			cout << "     A     B     C     D     E  \n" <<
					"   _____________________________" << 
			      "\n  |     |     |     |     |     |\n"; // adding a top to first row
		cout << r+1 <<" |";
		for (int c = 0; c < 5; ++c)
		{
			cout << setw(3) << static_cast<char>(floor[r][c]);

			if (c != 2||3||4)
				cout << "  |";
		}
		if (r !=2) 
			cout << "\n  |_____|_____|_____|_____|_____|" << "\n  |     |     |     |     |     |\n"; // adding the row line to all of them then adding the beggining of the next box
		if (r == 2)
			cout << "\n  |_____|_____|_____|_____|_____|"; // adding a bottom to the final row
	}
}
