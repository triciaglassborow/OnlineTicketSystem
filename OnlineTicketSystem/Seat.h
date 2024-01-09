#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>

using namespace std;
//Seat staus and price

class Seat
{
public:
	Seat(string Status);
	void SetStatus(string Status);
	void DisplayStatus();
	void CheckStatus();

protected:
	string status;
	

	int price;
};

Seat::Seat(string Status)
{
	this->status = Status;
}

void Seat::SetStatus(string Status)
{
	this->status = Status;
}

void Seat::DisplayStatus()
{
	cout << "  " << status;
}

void Seat::CheckStatus()
{

}
