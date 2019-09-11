/**************************************************************************
 * Program Name:Dish.cpp
 * Name:	Manda Jensen
 * Date:	08 JUN 2019
 * Description:	This file contains the definition of the functions included
 * 		in the class Dish.
 * 		Dish is a child class of and inherits from Space.
 * 	Variables:
 * 		no additional variables than the ones in Space.
 *
 *	Functions:
 *		Dish() - default constructor
 *			Parameters: none
 *			Return Type: n/a
 *			Purpose: default constructor for Dish, sets
 *				the type of the space appropriately and sets
 *				all Space* variables to nullptr, and fills
 *				the items of the dish to start the
 *				game
 *		~Dish() - default destructor
 *			Parameters: none
 *			Return Type: n/a
 *			Purpose: default destructor for Dish, sets all
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

#include "Dish.hpp"
#include "Space.hpp"
#include "spaceType.hpp"
#include "ingredients.hpp" 
#include "getLimitedInteger.hpp"

#include <string>
#include <vector>
#include <iomanip>
#include <iostream>

/**************************************************************************
 *Dish() - default constructor
 *	Parameters: none
 *	Return Type: n/a
 *	Purpose: default constructor for Dish, sets the type of the 
 *		space appropriately and sets all Space* variables to nullptr
 *		and adds the appropriate ingredients to the items vector
 *		to start the game
**************************************************************************/
Dish::Dish()
{	top = nullptr;
	right = nullptr;
	bottom = nullptr;
	left = nullptr;
	type = dish;
	items.push_back(pan);
}

/**************************************************************************
 *~Dish() - default destructor
 *	Parameters: none
 *	Return Type: n/a
 *	Purpose: default destructor for Dish, sets all Space* variables 
 *		to nullptr
**************************************************************************/
Dish::~Dish()
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
 *		The possible options at the dish are to pick up
 *		an item or to do nothing
**************************************************************************/
int Dish::spaceMenu()
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
	std::cout << "-" << std::setw(43) << std::right << "Dish Menu" << std::setw(36) << "-" << "\n";
	for(int i=0; i<80; i++)
	{	std::cout <<"-";
	}
	std::cout << "\n";
	std::cout << "- " << std::setw(78) << std:: left << "Select an action to take from the list below"
		<< "-\n";
	std::cout << "- " << std::setw(2) << std::right << ++num << ". " << std::setw(73) << std::left 
		<< "Pick up a pan from the dish space" << "-\n"; 
	std::cout << "- " << std::setw(2) << std::right << ++num << ". " << std::setw(73) << std::left 
		<< "Do nothing" << "-\n"; 
	for(int i=0; i<80; i++)
	{	std::cout <<"-";
	}
	std::cout << "\n";
	std::cout << "Please enter the integer of your choice:" << std::endl;
	//validate and store the user's choice then return it
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
bool Dish::play(std::vector<ingredients> &basket)
{	printItems(); //print the items available at the space
	int userChoice = spaceMenu(); //call the spaceMenu to set the user's choice
	switch(userChoice)
	{	case 1:
			//if there is space in the user's basket, add the pan to 
			//the user's basket, else print an error message
			if(basket.size()<3)
			{	basket.push_back(pan);
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
std::string Dish::printType()
{	return "       Dish       ";
}

