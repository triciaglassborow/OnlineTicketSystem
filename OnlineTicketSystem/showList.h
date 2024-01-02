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

protected:
	show* showList[8];
};

//Constructor
ShowList :: ShowList()
{
	//Initialise Variables 

	
	
}

//Destructor
ShowList::~ShowList()
{

}

void ShowList::InitiliseShows()
{
	showList[0] = new show("show1", "Date1", "Time1");
}

