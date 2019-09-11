/**************************************************************************
 * Program Name:mainMenu.cpp
 * Name:	Manda Jensen
 * Date:	2 MAY 2019
 * Description:	This file defines the functionality of the menu function which
 * 		has no arguments. It prompts the user with the menu,
 * 		validates the user's choice with the use of the
 * 		getLimitedInteger function. It returns the valid choice.
**************************************************************************/

#include <iostream>
#include <iomanip>
#include "getLimitedInteger.hpp"

using std::cin;
using std::cout;
using std::endl;

int mainMenu()
{
	//the user's choice is initalized here
	int userChoice = 0;
	//change the low and high limits for the user choice here, the low 
	//limit should correspond with the lowest valid integer choice and the 
	//high limit should correspond with the highest valid integer choice. 
	//All integers between the low limit and high limit must be valid or 
	//the function will not re-prompt for a user entry upon all invalid 
	//inputs
	int lowLim = 1;
	int highLim = 2;
	int num = lowLim-1;

	//menu text that will be sent to the user
	for(int i=0; i<80; i++)
	{	cout <<"-";
	}
	cout << "\n";
	cout << "-" << std::setw(43) << std::right << "MAIN MENU" << std::setw(36) << "-" << "\n";
	for(int i=0; i<80; i++)
	{	cout <<"-";
	}
	cout << "\n";
	cout << "- " << std::setw(2) << std::right << ++num << ". " << std::setw(73) << std::left 
		<< "Play Overbaked" << "-\n"; //change menu option here
	cout << "- " << std::setw(2) << std::right << ++num << ". " << std::setw(73) << std::left 
		<< "Exit" << "-\n"; //change menu option here
	for(int i=0; i<80; i++)
	{	cout <<"-";
	}
	cout << "\n";
	cout << "Please enter the integer of your choice:" << endl;
	getLimitedInteger(&userChoice, lowLim, highLim);

	return userChoice;
}
