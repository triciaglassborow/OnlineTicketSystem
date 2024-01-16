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
	return status;
}

int Seat::GetPrice()
{
	return price;
}
