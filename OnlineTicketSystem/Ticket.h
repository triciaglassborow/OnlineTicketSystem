#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>

using namespace std;

// have floorchart send each seat thats been held into a ticketlist
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

	char pound = 156; // £ in ASCII

	string credit, 
		cvc;
};

Ticket::Ticket()
{

}


// Taking every seat info and adding it to the ticket
void Ticket::AddToTicket(int NumOfSeats, int SeatNum, int Row, char Column, int SeatPrice)
{
	this->numOfSeats = NumOfSeats;
	totalPrice = totalPrice + SeatPrice;

	string row = to_string(Row); // converting int R to string r
	string seatPrice = to_string(SeatPrice); //converting int SeatPrice to string seatPrice
	string ticketText = "Seat: " + row + Column + "   Price: " + pound + seatPrice; // Makeing it one string to add to ticketList.
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
	cout << "    Total Price : " << pound << totalPrice;
}


void Ticket::Payment()
{
	cout << "Enter Credit Card Number";
	getline(cin, credit);
	while (credit.length() > 16)
	{
		cout << "Credit Card Number is more then 10 numbers" << endl;
		cout << "Re-enter Credit Card Number: ";
		getline(cin, credit);
	}

	cout << "Enter CVC";
	getline(cin, cvc);
	while (credit.length() > 3)
	{
		cout << "CVC is more then 3 numbers" << endl;
		cout << "Re-enter CVC: ";
		getline(cin, cvc); 
	}
}

