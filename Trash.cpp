/**************************************************************************
 * Program Name:Trash.cpp
 * Name:	Manda Jensen
 * Date:	08 JUN 2019
 * Description:	This file contains the definition of the functions included
 * 		in the class Trash.
 * 		Trash is a child class of and inherits from Space.
 * 	Variables:
 * 		no additional variables than the ones in Space.
 *
 *	Functions:
 *		Trash() - default constructor
 *			Parameters: none
 *			Return Type: n/a
 *			Purpose: default constructor for Trash, sets
 *				the type of the space appropriately and sets
 *				all Space* variables to nullptr, and fills
 *				the items of the trash to start the
 *				game
 *		~Trash() - default destructor
 *			Parameters: none
 *			Return Type: n/a
 *			Purpose: default destructor for Trash, sets all
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

#include "Trash.hpp"
#include "Space.hpp"
#include "spaceType.hpp"
#include "ingredients.hpp" 
#include "getLimitedInteger.hpp"

#include <string>
#include <vector>
#include <iomanip>
#include <iostream>

/**************************************************************************
 *Trash() - default constructor
 *	Parameters: none
 *	Return Type: n/a
 *	Purpose: default constructor for Trash, sets the type of the 
 *		space appropriately and sets all Space* variables to nullptr
 *		and adds the appropriate ingredients to the items vector
 *		to start the game
**************************************************************************/
Trash::Trash()
{	top = nullptr;
	right = nullptr;
	bottom = nullptr;
	left = nullptr;
	type = trash;
}

/**************************************************************************
 *~Trash() - default destructor
 *	Parameters: none
 *	Return Type: n/a
 *	Purpose: default destructor for Trash, sets all Space* variables 
 *		to nullptr
**************************************************************************/
Trash::~Trash()
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
 *		The possible options at the trash are to pick up
 *		an item or to do nothing
**************************************************************************/
int Trash::spaceMenu()
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
	std::cout << "-" << std::setw(43) << std::right << "Trash Menu" << std::setw(36) << "-" << "\n";
	for(int i=0; i<80; i++)
	{	std::cout <<"-";
	}
	std::cout << "\n";
	std::cout << "- " << std::setw(78) << std:: left << "Select an action to take from the list below"
		<< "-\n";
	std::cout << "- " << std::setw(2) << std::right << ++num << ". " << std::setw(73) << std::left 
		<< "Throw out an item from your basket into the trash" << "-\n"; 
	std::cout << "- " << std::setw(2) << std::right << ++num << ". " << std::setw(73) << std::left 
		<< "Do nothing" << "-\n"; 
	for(int i=0; i<80; i++)
	{	std::cout <<"-";
	}
	std::cout << "\n";
	std::cout << "Please enter the integer of your choice:" << std::endl;
	//validate and store the user's input then return it
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
bool Trash::play(std::vector<ingredients> &basket)
{	
	int userChoice = spaceMenu(); //call spaceMenu to set the user's choice
	switch(userChoice)
	{	case 1:
			//call the basketMenu for the user to choose which item
			//to toss, delete that item from the user's basket
			userChoice = basketMenu(basket);
			if(userChoice > 0)
			{	basket.erase(basket.begin()+userChoice-1);
			}
			else
			{	std::cout << "There are no items in your "
					<< "basket to trash.\n";
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
std::string Trash::printType()
{	return "      Trash       ";
}

