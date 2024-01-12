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
	void InitiliseFloorChart();
	void DisplayFloorChart();
	void SelectSeat();
	void AddToTicketList(int SeatNum, int R, char Column, int SeatPrice);
	void DisplayTicketList();

protected:
	shared_ptr<Seat>floor[3][5];
	string available = "A",
		held = "H",
		unavailble = "X";
	string seat;

	char pound = 156, // £ in ASCII
		slash = 92 ; // \ in ASCII

	// setting price of each seat tier
	int tier1 = 1,
		tier2 = 2,
		tier3 = 3;

	int numOfSeats;

	string ticketList[8];
	
};

FloorChart::FloorChart()
{
	InitiliseFloorChart();
}

void FloorChart::InitiliseFloorChart()
{
	//Each row has a different price. 
	//For each row, set the same price for each column. All seats set to available
	for (int r = 0; r < 3; ++r)
	{
		if (r == 0)
		{
			for (int c = 0; c < 5; ++c)
				floor[r][c] = shared_ptr<Seat>(new Seat(available, tier1));
		}
		if (r == 1)
		{
			for (int c = 0; c < 5; ++c)
				floor[r][c] = shared_ptr<Seat>(new Seat(available, tier2));
		}

		if (r == 2)
		{
			for (int c = 0; c < 5; ++c)
				floor[r][c] = shared_ptr<Seat>(new Seat(available, tier3));
		}
	}

	/*for (int r = 0; r < 3; ++r)
		for (int c = 0; c < 5; ++c)
			floor[r][c] = shared_ptr<Seat>(new Seat(available)); //setting all seats as available when the floor chart is first created*/

}

void FloorChart::DisplayFloorChart()
{
	for (int r = 0; r < 3; ++r)
	{
		if (r==0)
			cout << "     A     B     C     D     E    Seat Price\n" << // coulmn lables
					"   _____________________________" << 
			      "\n  |     |     |     |     |     |\n"; // adding a top to first row
		cout << r+1 <<" |"; // row lables
		for (int c = 0; c < 5; ++c)
		{
			floor[r][c]->DisplayStatus(); // displaying each seats status 
			cout << "  |";
		}

		// Each rows differert price
		if (r == 0)
			cout << "     " << pound << tier1;
		if (r == 1)
			cout << "     " << pound << tier2;
		if (r == 2)
			cout << "     " << pound << tier3;

		if (r !=2) 
			cout << "\n  |_____|_____|_____|_____|_____|" << "\n  |     |     |     |     |     |\n";// adding the row line to all of them then adding the beggining of the next box
		if (r == 2)
			cout << "\n  |_____|_____|_____|_____|_____|" <<
			"\n        __________________ " <<
			"\n       /       STAGE      " << slash << endl;; // adding a bottom to the final row
	}
}



void FloorChart::SelectSeat()
{
	int count = 0;
	int row,
		seatPrice;
	char comma, column;
	cout << "\nHow many seats would you like? ";
	cin >> numOfSeats; //number of seats the user wants

	do
	{
		int c = 0,
			r = 0;
		cout << "\nEnter a seat you would like, eg 2,B: ";
		cin >> row >> comma >> column; // reading in the 3 characters inputed 

		r = row - 1; //Making the input line up with the array position. eg, first row = 0 but the input will be 1.

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

		floor[r][c]->CheckStatus();

		if (floor[r][c]->CheckStatus() != available) // if CheckStatus returned held or unavailalbe 
		{
			cout << "Seat Not Available";
			count = count - 1; // taking the counter back one step so they can re-select a seat
		}
		else 
		{
			floor[r][c]->SetStatus(held); //making that seat status held
			seatPrice = floor[r][c]->GetPrice();
			AddToTicketList(count, row, column, seatPrice);
		}
		count++;
	} while (count != numOfSeats);
	DisplayFloorChart();
}

void FloorChart::AddToTicketList(int SeatNum, int R, char Column, int SeatPrice)
{
	string r = to_string(R); // converting int R to string r
	string seatPrice = to_string(SeatPrice); //converting int SeatPrice to string seatPrice
	string ticketText ="Seat: " + r + Column+ "   Price: " + seatPrice; // Makeing it one string to add to ticketList
	ticketList[SeatNum] = { ticketText };
}

void FloorChart::DisplayTicketList()
{
	for (int i = 0; i < numOfSeats; i++)
	{
		cout << ticketList[i] << "\n";
	}
}
