/**************************************************************************
 * Program Name:Oven.cpp
 * Name:	Manda Jensen
 * Date:	08 JUN 2019
 * Description:	This file contains the definition of the functions included
 * 		in the class Oven.
 * 		Oven is a child class of and inherits from Space.
 * 	Variables:
 * 		no additional variables than the ones in Space.
 *
 *	Functions:
 *		Oven() - default constructor
 *			Parameters: none
 *			Return Type: n/a
 *			Purpose: default constructor for Oven, sets
 *				the type of the space appropriately and sets
 *				all Space* variables to nullptr, and fills
 *				the items of the oven to start the
 *				game
 *		~Oven() - default destructor
 *			Parameters: none
 *			Return Type: n/a
 *			Purpose: default destructor for Oven, sets all
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

#include "Oven.hpp"
#include "Space.hpp"
#include "spaceType.hpp"
#include "ingredients.hpp" 
#include "getLimitedInteger.hpp"

#include <string>
#include <vector>
#include <iomanip>
#include <iostream>

/**************************************************************************
 *Oven() - default constructor
 *	Parameters: none
 *	Return Type: n/a
 *	Purpose: default constructor for Oven, sets the type of the 
 *		space appropriately and sets all Space* variables to nullptr
 *		and adds the appropriate ingredients to the items vector
 *		to start the game
**************************************************************************/
Oven::Oven()
{	top = nullptr;
	right = nullptr;
	bottom = nullptr;
	left = nullptr;
	type = oven;
}

/**************************************************************************
 *~Oven() - default destructor
 *	Parameters: none
 *	Return Type: n/a
 *	Purpose: default destructor for Oven, sets all Space* variables 
 *		to nullptr
**************************************************************************/
Oven::~Oven()
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
 *		The possible options at the oven are to add batter and the pan
 *		to the oven, check on brownie progress, take the pan and contents
 *		out of the oven, and do nothing. 
**************************************************************************/
int Oven::spaceMenu()
{
	int userChoice = 0;
	int lowLim = 1;
	int highLim = 4;
	int num = lowLim-1;

	//menu text that will be sent to the user
	for(int i=0; i<80; i++)
	{	std::cout <<"-";
	}
	std::cout << "\n";
	std::cout << "-" << std::setw(43) << std::right << "Oven Menu" << std::setw(36) << "-" << "\n";
	for(int i=0; i<80; i++)
	{	std::cout <<"-";
	}
	std::cout << "\n";
	std::cout << "- " << std::setw(78) << std:: left << "Select an action to take from the list below"
		<< "-\n";
	std::cout << "- " << std::setw(2) << std::right << ++num << ". " << std::setw(73) << std::left 
		<< "Add the batter and pan from my basket to the oven" << "-\n";
	std::cout << "- " << std::setw(2) << std::right << ++num << ". " << std::setw(73) << std::left 
		<< "Check on the brownie baking progress" << "-\n"; 
	std::cout << "- " << std::setw(2) << std::right << ++num << ". " << std::setw(73) << std::left 
		<< "Take the brownies and pan out of the oven" << "-\n"; 
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
 *		determine the user's choice for action
**************************************************************************/
bool Oven::play(std::vector<ingredients> &basket)
{	printItems(); //print the items available at the space
	int userChoice = spaceMenu(); //call the spaceMenu to set the user's choice
	//set the variables to be used in the switch statement to false
	bool hasBatter = false;
	bool hasPan = false;
	bool hasBrownies = false;
	switch(userChoice)
	{	case 1:
			//if the basket has batter and a pan, add it to the
			//space and remove them from the user's basket, else
			//print an error message
			for(unsigned int i=0; i<basket.size(); i++)
			{	if(basket[i] == batter)
				{	hasBatter = true;
				}
				if(basket[i] == pan)
				{	hasPan = true;
				}
			}	
			if(hasBatter && hasPan)
			{	items.push_back(batter);
				items.push_back(pan);
				for(int i=0; i<basket.size(); i++)
				{	if(basket[i] == batter || basket[i]
						== pan)
					{	basket.erase(basket.begin()+i);
						i--;
					}
				}
			}
			else
			{	std::cout << "You do not have batter and a "
					<< "pan in your basket.\n";
			}
			break;
		case 2:
			//check if the space has batter, pan or brownies
			for(unsigned int i=0; i<items.size(); i++)
			{	if(items[i] == batter)
				{	hasBatter = true;
				}
				if(items[i] == pan)
				{	hasPan = true;
				}
				if(items[i] == brownies)
				{	hasBrownies = true;
				}
			}
			//if brownies and a pan are present, tell the user to
			//take out the brownies
			if(hasBrownies && hasPan)
			{	std::cout << "Better take the brownies out "
					<< "soon or they may burn!\n";
			}
			//if batter and a pan are present, add brownies to
			//the space's items and remove batter, then tell the
			//user the brownies are ready, else print an error message
			else if(hasBatter && hasPan)
			{	items.push_back(brownies);
				for(unsigned int i=0; i<items.size(); i++)
				{	if(items[i] == batter)
					{	items.erase(items.begin()+i);
					}
				}
				std::cout << "Brownies are ready to take "
					<< "out of the oven!\n";
			}
			else
			{	std::cout << "You do not have brownies or "
					<< "batter and a pan in your oven.\n";
			}
			break;
		case 3:
			//check if the space has a pan and brownies
			for(unsigned int i=0; i<items.size(); i++)
			{	if(items[i] == pan)
				{	hasPan = true;
				}
				if(items[i] == brownies)
				{	hasBrownies = true;
				}
			}
			//if the basket does not have 2 spaces available, print
			//an error message to the user
			if(basket.size() > 1)
			{	std::cout << "You do not have enough space in "
					<< "your basket to pick up the items.\n";
			}
			//else if the space has a pan and brownies, remove the pan
			//and brownies from the space and add a pan and brownies
			//to the user's basket, else print an error message to the
			//user
			else if(hasPan && hasBrownies)
			{	for(int i=0; i<items.size(); i++)
				{	if(items[i] == brownies || items[i] == 
					   pan)
					{	items.erase(items.begin()+i);	
						i--;
					}
				}
				basket.push_back(brownies);
				basket.push_back(pan);
			}
			else
			{	std::cout << "Your oven does not have brownies "
					<< "and a pan to pick up.\n";
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
std::string Oven::printType()
{	return "       Oven       ";
}

