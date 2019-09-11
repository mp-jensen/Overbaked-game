/**************************************************************************
 * Program Name:Bowl.cpp
 * Name:	Manda Jensen
 * Date:	08 JUN 2019
 * Description:	This file contains the definition of the functions included
 * 		in the class Bowl.
 * 		Bowl is a child class of and inherits from Space.
 * 	Variables:
 * 		no additional variables than the ones in Space.
 *
 *	Functions:
 *		Bowl() - default constructor
 *			Parameters: none
 *			Return Type: n/a
 *			Purpose: default constructor for Bowl, sets
 *				the type of the space appropriately and sets
 *				all Space* variables to nullptr, and fills
 *				the items of the bowl to start the game
 *		~Bowl() - default destructor
 *			Parameters: none
 *			Return Type: n/a
 *			Purpose: default destructor for Bowl, sets all
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

#include "Bowl.hpp"
#include "Space.hpp"
#include "spaceType.hpp"
#include "ingredients.hpp" 
#include "getLimitedInteger.hpp"

#include <string>
#include <vector>
#include <iomanip>
#include <iostream>

/**************************************************************************
 *Bowl() - default constructor
 *	Parameters: none
 *	Return Type: n/a
 *	Purpose: default constructor for Bowl, sets the type of the 
 *		space appropriately and sets all Space* variables to nullptr
 *		and adds the appropriate ingredients to the items vector
 *		to start the game
**************************************************************************/
Bowl::Bowl()
{	top = nullptr;
	right = nullptr;
	bottom = nullptr;
	left = nullptr;
	type = bowl;
}

/**************************************************************************
 *~Bowl() - default destructor
 *	Parameters: none
 *	Return Type: n/a
 *	Purpose: default destructor for Bowl, sets all Space* variables 
 *		to nullptr
**************************************************************************/
Bowl::~Bowl()
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
 *		The possible options at the bowl are to add an item to the
 *		bowl, mix the items in the mixing bowl or pick up the dry
 *		mix from the mixing bowl or to do nothing.
**************************************************************************/
int Bowl::spaceMenu()
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
	std::cout << "-" << std::setw(43) << std::right << "Bowl Menu" << std::setw(36) << "-" << "\n";
	for(int i=0; i<80; i++)
	{	std::cout <<"-";
	}
	std::cout << "\n";
	std::cout << "- " << std::setw(78) << std:: left << "Select an action to take from the list below"
		<< "-\n";
	std::cout << "- " << std::setw(2) << std::right << ++num << ". " << std::setw(73) << std::left 
		<< "Add an item from your basket to the mixing bowl" << "-\n"; 
	std::cout << "- " << std::setw(2) << std::right << ++num << ". " << std::setw(73) << std::left 
		<< "Mix the items in the mixing bowl" << "-\n"; 
	std::cout << "- " << std::setw(2) << std::right << ++num << ". " << std::setw(73) << std::left 
		<< "Pick up the dry mix from the mixing bowl" << "-\n"; 
	std::cout << "- " << std::setw(2) << std::right << ++num << ". " << std::setw(73) << std::left 
		<< "Do nothing" << "-\n"; 
	for(int i=0; i<80; i++)
	{	std::cout <<"-";
	}
	std::cout << "\n";
	std::cout << "Please enter the integer of your choice:" << std::endl;
	//validate and store the user's choice
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
bool Bowl::play(std::vector<ingredients> &basket)
{	printItems();
	int userChoice = spaceMenu();
	//initalize variables to use in the switch statements
	bool hasFlour = false;
	bool hasBS = false;
	bool hasCP = false;
	int dryMixLoc = -1;
	switch(userChoice)
	{	case 1:
			//if the user has an item in their basket to 
			//add to the space, add it to the space's items
			//and delete it from the user's basket, if not
			//print an error message
			userChoice = basketMenu(basket);
			if(userChoice > 0)
			{	items.push_back(basket[userChoice-1]);
				basket.erase(basket.begin()+userChoice-1);
			}
			else
			{	std::cout << "You have nothing to add.\n";
			}
			break;
		case 2:
			//check if the user has flour, baking soda and 
			//cocoa powder, set the flags accordingly
			for(unsigned int i=0; i<items.size(); i++)
			{	if(items[i] == flour)
				{	hasFlour = true;
				}
				if(items[i] == bakingSoda)
				{	hasBS = true;
				}
				if(items[i] == cocoaPowder)
				{	hasCP = true;
				}
			}
			//if the proper ingredients are present, remove those
			//ingredients from the space and add the dryMix ingredient
			if(hasFlour && hasBS && hasCP)
			{	items.push_back(dryMix);
				for(int i=0; i<items.size(); i++)
				{	if(items[i] == flour || items[i] == 
					   bakingSoda || items[i] == cocoaPowder)
					{	items.erase(items.begin()+i);	
						i--;
					}
				}
			}
			//if not, print an error message to the user
			else
			{	std::cout << "Your mixing bowl must have "
					<< "four, baking soda and cocoa "
					<< "powder in order to mix.\n";
				std::cout << "No mixing was done.\n";
			}
			break;
		case 3:
			//if the space has the dryMix, and the basket has space
			//add it to the user's basket and delete it from the 
			//space, if either is false print the according error message
			for(unsigned int i=0; i<items.size(); i++)
			{	if(items[i] == dryMix)
				{	dryMixLoc = i;
					//dryMix was found, end for loop
					i = items.size(); 
				}
			}
			if(basket.size()<3 && dryMixLoc >= 0)
			{	
				basket.push_back(items[dryMixLoc]);
				items.erase(items.begin()+dryMixLoc);
			}
			else if(basket.size()>=3)
			{	std::cout << "You have reached the "
					<< "capacity of your basket.\n"
					<< "Remove an item at the trash "
					<< "to free up space.\n";
			}
			else
			{	std::cout << "Your mixing bowl does not "
					<< "contain any dry mix to add "
					<< "to your basket.\n";
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
std::string Bowl::printType()
{	return "      Bowl      ";
}

