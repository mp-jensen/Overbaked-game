/**************************************************************************
 * Program Name:Space.cpp
 * Name:	Manda Jensen
 * Date:	08 JUN 2019
 * Description:	This file contains the function definitions for the abstract
 * 		class Space. 
 * 		Classes Refrigerator, Pantry, Bowl, StandMixer, Oven, Dish,
 * 		Window and Trash are child classes of Space and inherit
 * 		from Space.
 * 	Variables:
 *		Space* top - pointer to the Space above this one
 *		Space* right - pointer to the Space to the right of this one
 * 		Space* bottom - pointer to the Space to the bottom of this one
 *		Space* left - pointer to the Space to the left of this one
 *		SpaceType type - enumerated variable that notes the spaceType
 *			of the Space
 *		vector<ingredients> items - vector that contains the ingredients
 *			that this space contains
 *
 *	Functions:
 *		~Space() - virtual destructor
 *			Parameters: none
 *			Return Type: n/a
 *			Purpose: default virtual destructor to be overridden in 
 *				child classes
 *		spaceMenu() - pure virtual function
 *			Parameters: none
 *			Return Type: int
 *			Purpose: prints the space menu displaying the possible
 *				actions in that space and returns the integer
 *				for the user's choice
 *		play() - pure virtual function
 *			Parameters: Ingredient vector by reference
 *			Return Type: bool
 *			Purpose: goes through the actions to play out a turn
 *				when the player is on this space, will
 *				manipulate the ingredient vector provided
 *				as an argument as needed, calls spaceMenu()
 *				to determine the user's choice for action
 *				returns true if the game objective has been
 *				completed, false if not
 *		printType() - pure virtual function
 *			Parameters: none
 *			Return Type: string
 *			Prupose: returns a string that contains the type of
 *				the space centered within 18 characters with
 *				white space on either side
 *		isEmptyTop()
 *			Parameters: none
 *			Return Type: bool
 *			Purpose: returns true if the top pointer is empty and 
 *				false if not
 *		isEmptyRight()
 *			Parameters: none
 *			Return Type: bool
 *			Purpose: returns true if the right pointer is empty and 
 *				false if not
 *		isEmptyBottom()
 *			Parameters: none
 *			Return Type: bool
 *			Purpose: returns true if the bottom pointer is empty 
 *				and false if not
 *		isEmptyLeft()
 *			Parameters: none
 *			Return Type: bool
 *			Purpose: returns true if the left pointer is empty and 
 *				false if not
 *		getTop()
 *			Parameters: none
 *			Return Type: Space*
 *			Purpose: getter for the top variable, returns the 
 *				Space pointer that the top variable contains
 *		getRight()
 *			Parameters: none
 *			Return Type: Space*
 *			Purpose: getter for the right variable, returns the 
 *				Space pointer that the right variable contains
 *		getBottom()
 *			Parameters: none
 *			Return Type: Space*
 *			Purpose: getter for the bottom variable, returns the 
 *				Space pointer that the bottom variable contains
 *		getLeft()
 *			Parameters: none
 *			Return Type: Space*
 *			Purpose: getter for the left variable, returns the 
 *				Space pointer that the left variable contains
 *		printItems()
 *			Parameters: none
 *			Return Type: none
 *			Purpose: prints the ingredients available at the space
 *		itemMenu()
 *			Parameters: none
 *			Return Type: int
 *			Purpose: prints the ingredients available at the space
 *				and asks the user to choose one to pick up
 *				returns the item number the user would like 
 *				to pick up, returns 0 if there are no items
 *				available
 *		basketMenu()
 *			Parameters: vector<ingredients>
 *			Return Type: int
 *			Purpose: prints the ingredients available in the basket 
 *				and asks the user to choose one to add 
 *				returns the item number the user would like 
 *				to add , returns 0 if there are no items
 *				available
 *		setNeighbors()
 *			Parameters: 4 Space pointers
 *			Return Type: void
 *			Purpose: set the top, right, bottom and left member
 *				variable Space pointers to the Space pointers
 *				provided as arguments
**************************************************************************/

#include "Space.hpp"
#include "spaceType.hpp" 
#include "ingredients.hpp" 
#include "getLimitedInteger.hpp"
#include <string>
#include <vector>
#include <iomanip>
#include <iostream>

/**************************************************************************
 *isEmptyTop()
 *	Parameters: none
 *	Return Type: bool
 *	Purpose: returns true if the top pointer is empty and false if not
**************************************************************************/
bool Space::isEmptyTop()
{	if(top == nullptr)
	{	return true;
	}
	else
	{	return false;
	}
}

/**************************************************************************
 *isEmptyRight()
 *	Parameters: none
 *	Return Type: bool
 *	Purpose: returns true if the right pointer is empty and false if not
**************************************************************************/
bool Space::isEmptyRight()
{	if(right == nullptr)
	{	return true;
	}
	else
	{	return false;
	}
}

/**************************************************************************
 *isEmptyBottom()
 *	Parameters: none
 *	Return Type: bool
 *	Purpose: returns true if the bottom pointer is empty and false if not
**************************************************************************/
bool Space::isEmptyBottom()
{	if(bottom == nullptr)
	{	return true;
	}
	else
	{	return false;
	}
}

/**************************************************************************
 *isEmptyLeft()
 *	Parameters: none
 *	Return Type: bool
 *	Purpose: returns true if the left pointer is empty and false if not
**************************************************************************/
bool Space::isEmptyLeft()
{	if(left == nullptr)
	{	return true;
	}
	else
	{	return false;
	}
}

/**************************************************************************
 *getTop()
 *	Parameters: none
 *	Return Type: Space*
 *	Purpose: getter for the top variable, returns the Space pointer that 
 *		the top variable contains
**************************************************************************/
Space* Space::getTop()
{	return top;
}

/**************************************************************************
 *getRight()
 *	Parameters: none
 *	Return Type: Space*
 *	Purpose: getter for the right variable, returns the Space pointer 
 *	that the right variable contains
**************************************************************************/
Space* Space::getRight()
{	return right;
}

/**************************************************************************
 *getBottom()
 *	Parameters: none
 *	Return Type: Space*
 *	Purpose: getter for the bottom variable, returns the Space pointer 
 *		that the bottom variable contains
**************************************************************************/
Space* Space::getBottom()
{	return bottom;
}

/**************************************************************************
 *getLeft()
 *	Parameters: none
 *	Return Type: Space*
 *	Purpose: getter for the left variable, returns the Space pointer that 
 *		the left variable contains
**************************************************************************/
Space* Space::getLeft()
{	return left;
}

/**************************************************************************
 *printItems()
 *	Parameters: none
 *	Return Type: none
 *	Purpose: prints the ingredients available at the space
**************************************************************************/
void Space::printItems()
{	int size = items.size();
	//print the items in the items vector
	std::cout << "This space has " << size << " items\n";
	if(size > 0)
	{	std::cout << "SPACE ITEMS: ";
		for(int i=0; i<size; i++)
		{	if(i > 0)
			{	std::cout << ", ";
			}
			switch(items[i])
			{	case sugar:
					std::cout << "Sugar";
					break;
				case butter:
					std::cout << "Butter";
					break;
				case eggs:
					std::cout << "Eggs";
					break;
				case flour:
					std::cout << "Flour";
					break;
				case bakingSoda:
					std::cout << "Baking Soda";
					break;
				case cocoaPowder:
					std::cout << "Cocoa Powder";
					break;
				case wetMix:
					std::cout << "Wet Ingredients Mix";
					break;
				case dryMix:
					std::cout << "Dry Ingredients Mix";
					break;
				case mixingBowl:
					std::cout << "Mixing Bowl";
					break;
				case batter:
					std::cout << "Batter";
					break;
				case pan:
					std::cout << "Pan";
					break;
				case brownies:
					std::cout << "Brownies";
					break;
				default:
					break;
			}
		}
		std::cout << "\n";
	}
}

/**************************************************************************
 *itemMenu()
 *	Parameters: none
 *	Return Type: int
 *	Purpose: prints the ingredients available at the space and returns
 *		the user's choice for which one to pick up
**************************************************************************/
int Space::itemMenu()
{	int size = items.size();
	int userChoice = 0; //set userChoice to 0, will be retured if no 
			    //items available to pick up
	//print possible ingredients listed from 1 to x for indexes
	//0 to x-1 in the vector
	if(size > 0)
	{	std::cout << "The items available to add to your basket "
			<< "at this space are:\n";
		for(int i=0; i<size; i++)
		{	std::cout << i+1 << ". ";
			switch(items[i])
			{	case sugar:
					std::cout << "Sugar\n";
					break;
				case butter:
					std::cout << "Butter\n";
					break;
				case eggs:
					std::cout << "Eggs\n";
					break;
				case flour:
					std::cout << "Flour\n";
					break;
				case bakingSoda:
					std::cout << "Baking Soda\n";
					break;
				case cocoaPowder:
					std::cout << "Cocoa Powder\n";
					break;
				case wetMix:
					std::cout << "Wet Ingredients Mix\n";
					break;
				case dryMix:
					std::cout << "Dry Ingredients Mix\n";
					break;
				case mixingBowl:
					std::cout << "Mixing Bowl\n";
					break;
				case batter:
					std::cout << "Batter\n";
					break;
				case pan:
					std::cout << "Pan\n";
					break;
				case brownies:
					std::cout << "Brownies\n";
					break;
				default:
					break;
			}
		}
		std::cout << "Please enter the integer for the item you would like "
			<< "to add" << std::endl;
		//store the user's choice in the variable to be returned
		getLimitedInteger(&userChoice, 1, size);
	}
	//let the user know if there are no items available
	else
	{	std::cout << "There are no items available for you to pick up "
			<< "at this space.\n";
	}
	return userChoice;
}

/*************************************************************************
 *basketMenu()
 *	Parmaeters: vector<ingredients>
 *	Return Type: int
 *	Purpose: prints all ingredients in the vector of ingredeints passed
 *	as an argument and returns the user's choice of ingredient 
**************************************************************************/
int Space::basketMenu(std::vector<ingredients> basket)
{	int size = basket.size();
	int userChoice = 0; //set return value to 0, will remain unchanged if
			    //basket is empty
	//print the possible items in the basket, numbered 1 to x for index
	//0 to x-1 in the basket vector
	if(size > 0)
	{	std::cout << "The items available in your basket are:\n";
		for(int i=0; i<size; i++)
		{	std::cout << i+1 << ". ";
			switch(basket[i])
			{	case sugar:
					std::cout << "Sugar\n";
					break;
				case butter:
					std::cout << "Butter\n";
					break;
				case eggs:
					std::cout << "Eggs\n";
					break;
				case flour:
					std::cout << "Flour\n";
					break;
				case bakingSoda:
					std::cout << "Baking Soda\n";
					break;
				case cocoaPowder:
					std::cout << "Cocoa Powder\n";
					break;
				case wetMix:
					std::cout << "Wet Ingredients Mix\n";
					break;
				case dryMix:
					std::cout << "Dry Ingredients Mix\n";
					break;
				case mixingBowl:
					std::cout << "Mixing Bowl\n";
					break;
				case batter:
					std::cout << "Batter\n";
					break;
				case pan:
					std::cout << "Pan\n";
					break;
				case brownies:
					std::cout << "Brownies\n";
				default:
					break;
			}
		}
		std::cout << "Please enter the item you would like to add:" << std::endl;
		//store the user choice in the variable that is returned
		getLimitedInteger(&userChoice,1,size);
	}
	//if there are no items in the basket, let the user know
	else
	{	std::cout << "There are no items in your basket.\n";
	}
	return userChoice;
}
		

/**************************************************************************
 *setNeighbors()
 *	Parameters: 4 Space pointers
 *	Return Type: void
 *	Purpose: set the top, right, bottom and left member variable Space 
 *		pointers to the Space pointers provided as arguments
**************************************************************************/
void Space::setNeighbors(Space* top, Space* right, Space* bottom, Space* left)
{	//set the Space pointers provided in the arguments to the corresponding
	//variables of the Space object
	this->top = top;
	this->right = right;
	this->bottom = bottom;
	this->left = left;
}

