//customer.h 

#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>

using namespace std;

class customer
{
public:
	customer();
	~customer();
	void login();
	void createProfile();
	void displayProfileInfo();
	//void getPaymentInfo();

protected:
	string username, 
		fName,
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
void customer::login()
{
	/*The final system would use a database to store all the 
	usernames and passwords in a database */
	string password; /*For this first prototype, the system will accept any 
	username and password */

	//Output
	//Enter Username
	cout << "LOGIN" << endl;
	cout << "Enter Username: ";
	getline(cin, username);
	/*Create the profile then save */

	//Username is more then 10 characters
	while (username.length() > 10)
	{
		cout << "Username's must be 10 or less characters" << endl;
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
		cout << "Password's must be 10 or less characters" << endl;
		cout << "Re-enter Password: ";
		getline(cin, password);
	}


	//Login Successfull
	//Screen is cleared and then welcomes the user
	system("CLS");
	cout << "Welcome " << username << endl;
}

//Create Customer Profile
void customer::createProfile()
{
	cout << "CREATE PROFILE" << endl;
	//First Name
	cout << "\nEnter First Name: ";
	getline(cin, fName);

	//Surname
	cout << "Enter Surname Name: ";
	getline(cin, sName);

	//Address -imporve this-
	cout << "Enter Address: ";
	getline(cin, address);
}

//Display Customer Profile
void customer::displayProfileInfo()
{
	system("CLS");
	cout << "PROFILE" << endl;
	cout << "Username: " << username << endl;
	cout << "First Name: " << fName << endl;
	cout << "Surname: " << sName << endl;
	cout << "Address: " << address << endl;
}