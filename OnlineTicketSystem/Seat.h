#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>

using namespace std;
//Seat staus and price

class Seat
{
public:
	Seat(string Status, int Price);
	void SetStatus(string Status);
	void DisplayStatus();
	string CheckStatus();
	int GetPrice();

protected:
	string status;
	string available = "A",
		held = "H",
		unavailble = "X";

	int price;
};

Seat::Seat(string Status, int Price)
{
	this->status = Status;
	this->price = Price;
}

void Seat::SetStatus(string Status)
{
	this->status = Status;
}

void Seat::DisplayStatus()
{
	cout << "  " << status;
}

string Seat::CheckStatus()
{
	if (status == available)
		return available;
	if (status == held)
		return held;
	if (status == unavailble)
		return unavailble;
}

int Seat::GetPrice()
{
	cout << price;
}
