// OnlineTicketSystem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
using namespace std;


#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>

#include "customer.h"
#include "ShowList.h"


//Main Menu Function
void menu(customer CUST, ShowList SHOWLIST)
{
    system("CLS");

    char menu_input;
    cout << "MAIN MENU" << endl;

    cout << "1. Display Profile Info" << endl;
    cout << "2. Choose a Show" << endl;

    cout << "Enter Choice: ";
    cin >> menu_input;

    switch (menu_input)
    {
        case '1' : CUST.displayProfileInfo(); //Displaying customer details
            break;
        case '2': SHOWLIST.DisplayShowList();
            break;
    }
}

int main()
{
    //Variables
    string a,
        b,
        c;

    int d;

    double e;

    char ch,
        terminator;

    //Objects
    customer CUST;
    ShowList SHOWLIST;


    //Getting customer details
    //CUST.login();
    //CUST.createProfile();
    
    //Main Menu, user can select what they want to do
    menu(CUST, SHOWLIST);
    cout << "END";
    
}




