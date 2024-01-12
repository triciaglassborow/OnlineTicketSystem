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
	void AddToTicket(int NumOfSeats, int SeatNum, int R, char Column, int SeatPrice);
	void DisplayTicket(int NumOfSeats);
	//void GetSeatInfo(string SeatStatus, int SeatPrice);
	//void TicketInfo();

protected:
	string ticket[8];
};

Ticket::Ticket()
{

}

void Ticket::AddToTicket(int NumOfSeats, int SeatNum, int R, char Column, int SeatPrice)
{
	do
	{
		ticket[SeatNum] = ("Seat:", R, Column, "  Price: ", SeatPrice);
	} while (SeatNum != NumOfSeats);
}

void Ticket::DisplayTicket(int NumOfSeats)
{
	for (int i = 0; i < NumOfSeats; i++)
	{
		cout << ticket[i];
	}
}