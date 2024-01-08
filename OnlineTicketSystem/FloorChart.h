#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>

using namespace std;

class FloorChart
{
public:
	FloorChart();
	void CreateFloorChart();

protected:
	int floor[3][5];
};

FloorChart::FloorChart()
{
	for (int r = 0; r < 3; ++r)
		for (int c = 0; c < 5; ++c)
			floor[r][c] = ' ';
}

void FloorChart::CreateFloorChart()
{
	
	for (int r = 0; r < 3; ++r)
	{
		if (r==0)
			cout << "  _____________________________" << "\n |     |     |     |     |     |\n"; // adding a top to first row
		cout << r+1 <<"|";
		for (int c = 0; c < 5; ++c)
		{
			cout << setw(3) << static_cast<char>(floor[r][c]); //Sets how big the boxes are?

			if (c != 2||3||4)
				cout << "  |";
		}
		if (r !=2) 
			cout << "\n |_____|_____|_____|_____|_____|" << "\n |     |     |     |     |     |\n"; // adding the row line to all of them then adding the beggining of the next box
		if (r == 2)
			cout << "\n |_____|_____|_____|_____|_____|"; // adding a bottom to the final row
	}
}
