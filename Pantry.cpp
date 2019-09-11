/**************************************************************************
 * Program Name:Pantry.cpp
 * Name:	Manda Jensen
 * Date:	08 JUN 2019
 * Description:	This file contains the definition of the functions included
 * 		in the class Pantry.
 * 		Pantry is a child class of and inherits from Space.
 * 	Variables:
 * 		no additional variables than the ones in Space.
 *
 *	Functions:
 *		Pantry() - default constructor
 *			Parameters: none
 *			Return Type: n/a
 *			Purpose: default constructor for Pantry, sets
 *				the type of the space appropriately and sets
 *				all Space* variables to nullptr, and fills
 *				the items of the pantry to start the
 *				game
 *		~Pantry() - default destructor
 *			Parameters: none
 *			Return Type: n/a
 *			Purpose: default destructor for Pantry, sets all
 *				Space* variables to nullptr
 *		spaceMenu() - overriden function
 *			Parameters: none
 *			Return Type: int
 *			Purpose: prints the space menu displaying the possible
 *				actions in that space and returns the integer
 *				for the user's choice
 *		play() - overriden function
 *			Parameters: Ingredient vector by reference
 *			Return Type: bool
 *			Purpose: goes through the actions to play out a turn
 *				when the player is on this space, will
 *				manipulate the ingredient vector provided
 *				as an argument as needed, calls spaceMenu()
 *				to determine the user's choice for action
 *				returns false
 *		printType() - overriden function
 *			Parameters: none
 *			Return Type: string
 *			Prupose: returns a string that contains the type of
 *				the space centered within 18 characters with
 *				white space on either side
**************************************************************************/

#include "Pantry.hpp"
#include "Space.hpp"
#include "spaceType.hpp"
#include "ingredients.hpp" 
#include "getLimitedInteger.hpp" 

#include <string>
#include <vector>
#include <iomanip>
#include <iostream>

/**************************************************************************
 *Pantry() - default constructor
 *	Parameters: none
 *	Return Type: n/a
 *	Purpose: default constructor for Pantry, sets the type of the 
 *		space appropriately and sets all Space* variables to nullptr
 *		and adds the appropriate ingredients to the items vector
 *		to start the game
**************************************************************************/
Pantry::Pantry()
{	top = nullptr;
	right = nullptr;
	bottom = nullptr;
	left = nullptr;
	type = pantry;
	items.push_back(sugar);
	items.push_back(flour);
	items.push_back(bakingSoda);
	items.push_back(cocoaPowder);
}

/**************************************************************************
 *~Pantry() - default destructor
 *	Parameters: none
 *	Return Type: n/a
 *	Purpose: default destructor for Pantry, sets all Space* variables 
 *		to nullptr
**************************************************************************/
Pantry::~Pantry()
{	top = nullptr;
	right = nullptr;
	bottom = nullptr;
	left = nullptr;
}

/**************************************************************************
 *spaceMenu() - overriden function
 *	Parameters: none
 *	Return Type: int
 *	Purpose: prints the space menu displaying the possible actions in 
 *		that space and returns the integer for the user's choice
 *		The possible options at the pantry are to pick up
 *		an item or to do nothing
**************************************************************************/
int Pantry::spaceMenu()
{
	int userChoice = 0;
	int lowLim = 1;
	int highLim = 2;
	int num = lowLim-1;

	//menu text that will be sent to the user
	for(int i=0; i<80; i++)
	{	std::cout <<"-";
	}
	std::cout << "\n";
	std::cout << "-" << std::setw(43) << std::right << "Pantry Menu" << std::setw(36) << "-" << "\n";
	for(int i=0; i<80; i++)
	{	std::cout <<"-";
	}
	std::cout << "\n";
	std::cout << "- " << std::setw(78) << std:: left << "Select an action to take from the list below"
		<< "-\n";
	std::cout << "- " << std::setw(2) << std::right << ++num << ". " << std::setw(73) << std::left 
		<< "Pick up an item from the pantry" << "-\n"; 
	std::cout << "- " << std::setw(2) << std::right << ++num << ". " << std::setw(73) << std::left 
		<< "Do nothing" << "-\n"; 
	for(int i=0; i<80; i++)
	{	std::cout <<"-";
	}
	std::cout << "\n";
	std::cout << "Please enter the integer of your choice:" << std::endl;
	//store and validate the user's choice
	getLimitedInteger(&userChoice, lowLim, highLim);

	return userChoice;
}

/**************************************************************************
 *play() - overriden function
 *	Parameters: Ingredient vector by reference
 *	Return Type: bool
 *	Purpose: goes through the actions to play out a turm when the player 
 *		is on this space, will manipulate the ingredient vector 
 *		provided as an argument as needed, calls spaceMenu() to 
 *		determine the user's choice for action, returns false
**************************************************************************/
bool Pantry::play(std::vector<ingredients> &basket)
{	printItems();
	int userChoice = spaceMenu();
	switch(userChoice)
	{	case 1:
			//if the user's basket has space, call the itemMenu
			//and add the item to the user's basket, else print
			//an error message
			if(basket.size()<3)
			{	userChoice = itemMenu();
				basket.push_back(items[userChoice-1]);
			}
			else
			{	std::cout << "You have reached the "
					<< "capacity of your basket.\n"
					<< "Remove an item at the trash "
					<< "to free up space.\n";
			}
			break;
		default:
			break;
	}
	return false;
}

/**************************************************************************
 *printType() - overriden function
 *	Parameters: none
 *	Return Type: string
 *	Prupose: returns a string that contains the type of the space centered 
 *		within 18 characters with white space on either side
**************************************************************************/
std::string Pantry::printType()
{	return "     Pantry     ";
}

