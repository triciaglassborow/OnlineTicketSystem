// OnlineTicketSystem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
using namespace std;


#include <iostream>
#include <string>

#include "customer.h"


int main()
{
    //Variables
    string a,
        b,
        c,
        //Customer
        username,
        fName,
        sName,
        address;

    int d;

    double e;

    char ch,
        terminator;

    //Objects
    customer CUST;

    //Getting customer details
    CUST.getLogin(username);
    CUST.getProfileInfo(fName,sName,address);
    //Displaying customer details
    CUST.displayProfileInfo(username, fName, sName, address);
}

