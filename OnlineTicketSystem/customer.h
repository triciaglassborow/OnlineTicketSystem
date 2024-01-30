//customer.h 
/*
-Sign Up
-Create Profile
-Display Profile Info
*/
#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>

using namespace std;

class Customer
{
public:
	Customer();
	~Customer();
	void SignUp();
	void CreateProfile();
	void DisplayProfileInfo();

protected:
	string username, 
		fName,
		sName,
		address;
};

//Constructor 
Customer::Customer()
{
	//Initialise Variables 
	fName = "";
	sName = "";
	address = "";
}

//Destructor
Customer::~Customer()
{}

//Login
void Customer::SignUp()
{
	/*The final system would use a database to store all the 
	usernames and passwords in a database */
	string password; /*For this first prototype, the system will accept any 
	username and password */

	//Output
	//Enter Username
	cout << "SIGN UP" << endl;
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
void Customer::CreateProfile()
{
	cout << "\nCREATE PROFILE" << endl;
	//First Name
	cout << "\nEnter First Name: ";
	getline(cin, fName);

	//Surname
	cout << "Enter Surname: ";
	getline(cin, sName);

	//Address -imporve this-
	cout << "Enter Address: ";
	getline(cin, address);
}

//Display Customer Profile
void Customer::DisplayProfileInfo()
{
	//cleaing input
	cin.clear();
	cin.ignore(100, '\n');

	system("CLS");
	cout << "PROFILE" << endl;
	cout << "Username: " << username << endl;
	cout << "First Name: " << fName << endl;
	cout << "Surname: " << sName << endl;
	cout << "Address: " << address << endl;

	// holds screen until a user input
	cout << "Press any key to return to Main Menu";
	cin.get();
}

