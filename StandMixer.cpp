/**************************************************************************
 * Program Name:StandMixer.cpp
 * Name:	Manda Jensen
 * Date:	08 JUN 2019
 * Description:	This file contains the definition of the functions included
 * 		in the class StandMixer.
 * 		StandMixer is a child class of and inherits from Space.
 * 	Variables:
 * 		no additional variables than the ones in Space.
 *
 *	Functions:
 *		StandMixer() - default constructor
 *			Parameters: none
 *			Return Type: n/a
 *			Purpose: default constructor for StandMixer, sets
 *				the type of the space appropriately and sets
 *				all Space* variables to nullptr, and fills
 *				the items of the stand mixer to start the
 *				game
 *		~StandMixer() - default destructor
 *			Parameters: none
 *			Return Type: n/a
 *			Purpose: default destructor for StandMixer, sets all
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

#include "StandMixer.hpp"
#include "Space.hpp"
#include "spaceType.hpp"
#include "ingredients.hpp" 
#include "getLimitedInteger.hpp"

#include <string>
#include <vector>
#include <iomanip>
#include <iostream>

/**************************************************************************
 *StandMixer() - default constructor
 *	Parameters: none
 *	Return Type: n/a
 *	Purpose: default constructor for StandMixer, sets the type of the 
 *		space appropriately and sets all Space* variables to nullptr
 *		and adds the appropriate ingredients to the items vector
 *		to start the game
**************************************************************************/
StandMixer::StandMixer()
{	top = nullptr;
	right = nullptr;
	bottom = nullptr;
	left = nullptr;
	type = standMixer;
}

/**************************************************************************
 *~StandMixer() - default destructor
 *	Parameters: none
 *	Return Type: n/a
 *	Purpose: default destructor for StandMixer, sets all Space* variables 
 *		to nullptr
**************************************************************************/
StandMixer::~StandMixer()
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
 *		The possible options at the stand mixer are to add an item
 *		to the stand mixer, mix the items in the stand mixer, pick up
 *		the batter from the stand mixer or do nothing 
**************************************************************************/
int StandMixer::spaceMenu()
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
	std::cout << "-" << std::setw(45) << std::right << "Stand Mixer Menu" << std::setw(33) << "-" << "\n";
	for(int i=0; i<80; i++)
	{	std::cout <<"-";
	}
	std::cout << "\n";
	std::cout << "- " << std::setw(78) << std:: left << "Select an action to take from the list below"
		<< "-\n";
	std::cout << "- " << std::setw(2) << std::right << ++num << ". " << std::setw(73) << std::left 
		<< "Add an item to the stand mixer" << "-\n"; 
	std::cout << "- " << std::setw(2) << std::right << ++num << ". " << std::setw(73) << std::left 
		<< "Mix the items in the stand mixer" << "-\n"; 
	std::cout << "- " << std::setw(2) << std::right << ++num << ". " << std::setw(73) << std::left 
		<< "Pick up the batter from the stand mixer" << "-\n"; 
	std::cout << "- " << std::setw(2) << std::right << ++num << ". " << std::setw(73) << std::left 
		<< "Do nothing" << "-\n"; 
	for(int i=0; i<80; i++)
	{	std::cout <<"-";
	}
	std::cout << "\n";
	std::cout << "Please enter the integer of your choice:" << std::endl;
	//validate and store user's choice then return it
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
bool StandMixer::play(std::vector<ingredients> &basket)
{	printItems(); //print space items
	int userChoice = spaceMenu(); //call spaceMenu to set userChoice
	//set variables to be used in switch statement based on user's choice
	bool hasButter = false;
	bool hasSugar = false;
	bool hasEggs = false;
	bool hasWetMix = false;
	bool hasDryMix = false;
	int batterLoc = -1;
	switch(userChoice)
	{	case 1:
			//call basketMenu, if there is a valid item to add,
			//add it to the space's items and remove it from the
			//user's basket, else print an error message
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
			//check if the space has the appropriate items to mix
			for(unsigned int i=0; i<items.size(); i++)
			{	if(items[i] == butter)
				{	hasButter = true;
				}
				if(items[i] == sugar)
				{	hasSugar = true;
				}
				if(items[i] == eggs)
				{	hasEggs = true;
				}
				if(items[i] == wetMix)
				{	hasWetMix = true;
				}
				if(items[i] == dryMix)
				{	hasDryMix = true;
				}
			}
			//if the proper ingredients are present, remove those
			//ingredients from the space and add the wetMix ingredient
			if(hasButter && hasSugar && hasEggs)
			{	items.push_back(wetMix);
				for(int i=0; i<items.size(); i++)
				{	if(items[i] == butter || items[i] == 
					   sugar || items[i] == eggs)
					{	items.erase(items.begin()+i);	
						i--;
					}
				}
			}
			//if the space has wetMix and dryMix, add batter to the space
			//and remove the wetMix and dryMix from the space
			else if(hasWetMix && hasDryMix )
			{	items.push_back(batter);
				for(int i=0; i<items.size(); i++)
				{	if(items[i] == wetMix || 
						items[i] == dryMix)
					{	items.erase(items.begin()+i);	
						i--;
					}
				}
			}
			//print an error message if none of the proper items are
			//present to mix
			else
			{	std::cout << "Your mixing bowl must have "
					<< "butter, eggs and sugar OR\n"
					<< "dry and wet ingredient mixes in "
					<< "order to mix.\n";
				std::cout << "No mixing was done.\n";
			}
			break;
		case 3:
			//check if the space has batter, and the basket has space
			//add the batter to the basket and remove it from the space
			for(unsigned int i=0; i<items.size(); i++)
			{	if(items[i] == batter)
				{	batterLoc = i;
					//batter has been found, end for loop
					i = items.size(); 
				}
			}
			if(basket.size()<3 && batterLoc >= 0)
			{	
				basket.push_back(items[batterLoc]);
				items.erase(items.begin()+batterLoc);
			}
			//else print the basket size error or no batter present
			//error accordingly
			else if(basket.size()>=3)
			{	std::cout << "You have reached the "
					<< "capacity of your basket.\n"
					<< "Remove an item at the trash "
					<< "to free up space.\n";
			}
			else
			{	std::cout << "Your stand mixer does not "
					<< "contain any finished batter to add "
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
std::string StandMixer::printType()
{	return "   Stand Mixer  ";
}

