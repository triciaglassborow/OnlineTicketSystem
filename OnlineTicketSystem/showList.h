//showList.h 
/*
-stores an array of Show pointer
-where shows are initilised
-where the user selects what show they want to see
*/

using namespace std;

#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>

#include "Show.h"

class ShowList
{
public:
	ShowList();
	~ShowList();
	void InitialiseShows();
	void DisplayShowList();
	void SelectShow();

protected:
	Show* showList[4]; //Array of show pointers
};

//Constructor
ShowList :: ShowList()
{  
	InitialiseShows();
}

//Destructor
ShowList::~ShowList()
{

}

void ShowList::InitialiseShows()
{
	showList[0] = new Show("SIX", "14th Feb 2024", "6:00pm");
	showList[1] = new Show("Mean Girls", "17th Feb 2024", "3:00pm");
	showList[2] = new Show("Beetlejuice", "20th Feb 2024", "5:00pm");
	showList[3] = new Show("Matilda", "22nd Feb 2024", "1:00pm");
}

void ShowList::DisplayShowList()
{
	for (int counter = 0; counter <= 3; ++counter)
	{
		int position = counter + 1; //the position for the show starts from 1 insead of 0
		showList[counter]->DisplayShowName(position); //Prints the name of each Show for 
																//every show in the list
	}
	SelectShow();
}

void ShowList::SelectShow()
{
	// clearing input 
	cin.clear();
	cin.ignore(100, '\n');

	char show;
	cout << "\nEnter the number for the show you would like to select: ";
	cin >> show;

	switch (show)
	{
	case '1':  showList[0]->DisplayShowDetails();
		break;
	case '2':  showList[1]->DisplayShowDetails();
		break;
	case '3':  showList[2]->DisplayShowDetails();
		break;
	case '4':  showList[3]->DisplayShowDetails();
		break;
	default: cout << "\nIncorrect Input";
		SelectShow();
	}

}
