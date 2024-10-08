/*
-Adding held seat info to the ticket
-Calculating total price
-Displaying the full ticket
-Payment
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>

using namespace std;


class Ticket
{
public:
	Ticket();
	void AddToTicket(int NumOfSeats, int SeatNum, int Row, char Column, int SeatPrice);
	void DisplayTicket();
	void Payment();

protected:
	string ticket[8];
	int numOfSeats = 0,
		totalPrice = 0;

	char pound = 156; // � in ASCII

	string credit, 
		cvc;
};

Ticket::Ticket()
{
	credit = "";
	cvc = "";
}


// Taking every seat info and adding it to the ticket
void Ticket::AddToTicket(int NumOfSeats, int SeatNum, int Row, char Column, int SeatPrice)
{
	this->numOfSeats = NumOfSeats;
	totalPrice = totalPrice + SeatPrice;

	string row = to_string(Row); // converting int R to string r
	string seatPrice = to_string(SeatPrice); //converting int SeatPrice to string seatPrice
	string ticketText = "Seat: " + row + Column + "   Price: " + pound + seatPrice; 
												// Makeing it one string to add to ticketList.
	ticket[SeatNum] = { ticketText };
}


// Display the full ticket with every seat and price on it
void Ticket::DisplayTicket()
{
	for (int i = 0; i < numOfSeats; i++)
	{
		cout << ticket[i] << "\n";
	}
	cout << "---------------------\n";
	cout << "    Total Price : " << pound << totalPrice << endl;
	
}


void Ticket::Payment()
{
	cin.clear();
	cin.ignore(100, '\n');
	cout << "\nPAYMENT" << endl;
	cout << "\nEnter Credit Card Number: ";
	getline(cin, credit);

	while (credit.length() != 16)
	{
		cout << "\nCredit Card Number must be 16 digits" << endl;
		cout << "\nRe-enter Credit Card Number: ";
		getline(cin, credit);
	}

	cout << "\nEnter CVC: ";
	getline(cin, cvc);

	while (cvc.length() != 3)
	{
		cout << "\nCVC must be 3 didgits " << endl;
		cout << "\nRe-enter CVC: ";
		getline(cin, cvc); 
	}

	cout << "\nPayment Accepeted"<< endl;
}

