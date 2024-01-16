//showList.h 

using namespace std;

#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>

#include "show.h"

class ShowList
{
public:
	ShowList();
	~ShowList();
	void InitialiseShows();
	void DisplayShowList();
	void SelectShow();

protected:
	Show* showList[8];
};

//Constructor
ShowList :: ShowList()
{  
	InitialiseShows(); //Initilises Shows
}

//Destructor
ShowList::~ShowList()
{

}

void ShowList::InitialiseShows()
{
	showList[0] = new Show("show1", "Date1", "Time1");
	showList[1] = new Show("show2", "Date2", "Time2");
	showList[2] = new Show("show3", "Date3", "Time3");
	showList[3] = new Show("show4", "Date4", "Time4");

}

void ShowList::DisplayShowList()
{
	for (int counter = 0; counter <= 3; ++counter)
	{
		int position = counter + 1; //the position for the show starts from 1 insead of 0
		showList[counter]->DisplayShowName(position); //Prints the name of each Show for every show in the list
	}
	SelectShow();
}

void ShowList::SelectShow()
{
	char show = 0;
	cout << "\nEnter the number for the show you would like to select: ";
	cin >> show;

	switch (show)
	{
		case '1':  showList[0]->DisplayShowDetails();
			break;
	}
}
