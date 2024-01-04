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
	void InitiliseShows();
	void DisplayShowList();

protected:
	show* showList[8];
};

//Constructor
ShowList :: ShowList()
{  
	InitiliseShows(); //Initilises Shows
}

//Destructor
ShowList::~ShowList()
{

}

void ShowList::InitiliseShows()
{
	showList[0] = new show("show1", "Date1", "Time1");
	showList[1] = new show("show2", "Date2", "Time2");
	showList[2] = new show("show3", "Date3", "Time3");
	showList[3] = new show("show4", "Date4", "Time4");

}

void ShowList::DisplayShowList()
{
	for (int counter = 0; counter <= 3; ++counter)
	{
		int position = counter + 1; //the position for the show starts from 1 insead of 0
		showList[counter]->DisplayShow(position); //Prints the name of each Show for every show in the list
	}
	
	
}
