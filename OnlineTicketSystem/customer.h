//customer.h 

using namespace std;

#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>

class customer
{
public:
	customer();
	~customer();
	void getLogin();
	void getProfileInfo(string& fName, string& sName, string& address);
	void getPaymentInfo();

protected:
	string fName,
		sName,
		address;
};

//Constructor 
customer::customer()
{
	//Initialise Variables 
	fName = "";
	sName = "";
	address = "";
}

//Destructor
customer::~customer()
{}

//Login
void customer::getLogin()
{
	string username; /*The final system would use a database to store all the 
	usernames and passwords in a database */
	string password; /*For this first prototype, the system will accept any 
	username and password */

	//Output
	//Enter Username
	cout << "LOGIN" << endl;
	cout << "Enter Username: ";
	getline(cin, username);

	//Username is more then 10 characters
	while (username.length() > 10)
	{
		cout << "Username is more then 10 characters" << endl;
		cout << "Re-enter username: ";
		getline(cin, username);
	}

	//Username Accepted
	cout << "\nUsername Accepted" << endl;
	

	//Enter Password
	cout << "\nEnter Password: ";
	getline(cin, password);

	//Password is more then 10 characters
	while (password.length() > 10)
	{
		cout << "Password is more then 10 characters" << endl;
		cout << "Re-enter Password: ";
		getline(cin, password);
	}


	//Login Successfull
	system("CLS");
	cout << "Welcome " << username << endl;
}
