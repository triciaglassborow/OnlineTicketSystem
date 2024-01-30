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
void menu(Customer CUST, ShowList SHOWLIST, bool& exit)
{
    system("CLS");
    char menu_input = 0;
    cout << "MAIN MENU" << endl;

    cout << "1. Display Profile Info" << endl;
    cout << "2. Choose a Show" << endl;
    cout << "3. Exit Program" << endl; 

    cout << "Enter Choice: ";
    cin >> menu_input;

    switch (menu_input)
    {
    case '1': CUST.DisplayProfileInfo(); //Displaying customer details 
            break;
        case '2': SHOWLIST.DisplayShowList();
            break;
        case '3': exit = true;
    }
}

int main()
{
    bool exit = false;
    //Objects
    Customer CUST;
    ShowList SHOWLIST;


    //Getting customer details
    CUST.SignUp();
    CUST.CreateProfile();
    
    do
    {
        menu(CUST, SHOWLIST, exit); 

    } while (exit != true);
    //Main Menu, user can select what they want to do
      
}




