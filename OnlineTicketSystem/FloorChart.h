/*
Features of FloorChart.h:
-storing seat pointers in a 2d array 
-initilises seat objects with their availablity and price
-their are 3 price tiers, the closer the row is to the stage the more expecsive the seat
-the size of the 2d array sets the size of the floor chart
-getting and setting seat availablity 
-User can select what seats they want
-Call DisplayTicket from ticket class
-Call Payment from ticket class
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>

#include "Seat.h"
#include "Ticket.h"


using namespace std;

class FloorChart
{

public:
	FloorChart();
	void InitialiseFloorChart();
	void DisplayFloorChart();
	void SelectSeat();
	void DisplayTicket();
	void MakePayment();
	void SetSeatsUnavailable();

protected:
	shared_ptr<Seat>floor[3][5];
	string available = "A",
		held = "H",
		unavaialble = "X";
	string seat;

	char pound = 156, // � in ASCII
		slash = 92 ; // \ in ASCII

	// setting price of each seat tier
	int tier1 = 10,
		tier2 = 15,
		tier3 = 20;

	int numOfSeats;

	Ticket TICK;
	
};

FloorChart::FloorChart()
{
	InitialiseFloorChart(); 
}

void FloorChart::InitialiseFloorChart()
{
	//2D arrary of pointers, 
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

		cout << "\n  |_____|_____|_____|_____|_____|"; // adding the bottom of the row
		if (r !=2) 
			cout << "\n  |     |     |     |     |     |\n";// the next row
		if (r == 2)
			cout <<
			"\n        __________________ " <<
			"\n       /       STAGE      " << slash << endl;; 
														//adding a bottom to the final row
	}
}



void FloorChart::SelectSeat()
{
	int count = 0;
	int row,
		seatPrice;
	char column;
	cout << "\nHow many seats would you like? (8 Max) ";
	cin >> numOfSeats;

	while (numOfSeats > 8)
	{
		cout << "\nMax seats allowed is 8 " << endl;
		cout << "\nHow many seats would you like? ";
		cin >> numOfSeats;
	}

	do
	{
		int c = 0;
		int r = 0;
		cout << "Enter a seat you would like, eg 2B: ";
		cin >> row >> column; // reading in the 2 characters inputed 
	
		r = row - 1; //Making the input line up with the array position. 
							//eg, first row = 0 but the input will be 1.

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
		
		//if CheckStatus returned held or unavailalbe 
		if (floor[r][c]->CheckStatus() != available)
		{
			cout << "Seat Not Available\n";
			count = count - 1; //taking the counter back one step so they can re-select a seat
		}
		else 
		{
			floor[r][c]->SetStatus(held); //making that seat status held
			seatPrice = floor[r][c]->GetPrice();  
			TICK.AddToTicket(numOfSeats, count, row, column, seatPrice);
		}
		count++;
	} while (count != numOfSeats);
	system("CLS");
	DisplayFloorChart();
}

void FloorChart::DisplayTicket()
{
	TICK.DisplayTicket();
	MakePayment();
}

void FloorChart::MakePayment()
{
	TICK.Payment();
	SetSeatsUnavailable();
}

void FloorChart::SetSeatsUnavailable()
{
	for (int r = 0; r < 3; ++r)
	{
		for (int c = 0; c < 5; ++c)
		{
			if (floor[r][c]->CheckStatus() == held)
				floor[r][c]->SetStatus(unavaialble);
		}
	}
	DisplayFloorChart();

	//Holds screen until the user presses a key
	cout << "Press any key to return to Main Menu";
	cin.get();
}
