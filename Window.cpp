/**************************************************************************
 * Program Name:Window.cpp
 * Name:	Manda Jensen
 * Date:	08 JUN 2019
 * Description:	This file contains the definition of the functions included
 * 		in the class Window.
 * 		Window is a child class of and inherits from Space.
 * 	Variables:
 * 		no additional variables than the ones in Space.
 *
 *	Functions:
 *		Window() - default constructor
 *			Parameters: none
 *			Return Type: n/a
 *			Purpose: default constructor for Window, sets
 *				the type of the space appropriately and sets
 *				all Space* variables to nullptr, and fills
 *				the items of the window to start the
 *				game
 *		~Window() - default destructor
 *			Parameters: none
 *			Return Type: n/a
 *			Purpose: default destructor for Window, sets all
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
 *				returns true if the player has achieved
 *				the objective and returns false if not
 *		printType() - overriden function
 *			Parameters: none
 *			Return Type: string
 *			Prupose: returns a string that contains the type of
 *				the space centered within 18 characters with
 *				white space on either side
**************************************************************************/

#include "Window.hpp"
#include "Space.hpp"
#include "spaceType.hpp"
#include "ingredients.hpp" 
#include "getLimitedInteger.hpp"

#include <string>
#include <vector>
#include <iomanip>
#include <iostream>

/**************************************************************************
 *Window() - default constructor
 *	Parameters: none
 *	Return Type: n/a
 *	Purpose: default constructor for Window, sets the type of the 
 *		space appropriately and sets all Space* variables to nullptr
 *		and adds the appropriate ingredients to the items vector
 *		to start the game
**************************************************************************/
Window::Window()
{	top = nullptr;
	right = nullptr;
	bottom = nullptr;
	left = nullptr;
	type = window;
}

/**************************************************************************
 *~Window() - default destructor
 *	Parameters: none
 *	Return Type: n/a
 *	Purpose: default destructor for Window, sets all Space* variables 
 *		to nullptr
**************************************************************************/
Window::~Window()
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
 *		The possible options at the window are to deliver completed
 *		brownies in the pan or do nothing
**************************************************************************/
int Window::spaceMenu()
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
	std::cout << "-" << std::setw(43) << std::right << "Window Menu" << std::setw(36) << "-" << "\n";
	for(int i=0; i<80; i++)
	{	std::cout <<"-";
	}
	std::cout << "\n";
	std::cout << "- " << std::setw(78) << std:: left << "Select an action to take from the list below"
		<< "-\n";
	std::cout << "- " << std::setw(2) << std::right << ++num << ". " << std::setw(73) << std::left 
		<< "Deliver completed brownies in the pan" << "-\n"; 
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
 *		determine the user's choice for action, returns true if
 *		the player has completed the objective, false if not
**************************************************************************/
bool Window::play(std::vector<ingredients> &basket)
{	bool objectiveCompleted = false; //set a variable to change if
					 //brownies are delivered
	int userChoice = spaceMenu(); //call spaceMenu to set the user's choice
	//create variables to ues in the switch statement
	bool hasBrownies = false;
	bool hasPan = false;	
	switch(userChoice)
	{	case 1:
			//check if the user has brownies and a pan in their basket
			for(unsigned int i=0; i<basket.size(); i++)
			{	if(basket[i] == brownies)
				{ 	hasBrownies = true;
				}
				if(basket[i] == pan)
				{ 	hasPan = true;
				}
			}
			//if they do, set the objectiveComplete to true
			if(hasBrownies && hasPan)
			{	objectiveCompleted = true;
			}
			//else print an error message to the user
			else
			{	std::cout << "You do not have brownies "
					<< "and a pan to deliver.\n";
			}
			break;
		default:
			break;
	}
	//return the objectiveCompleted - will only be true if the brownies and
	//pan are in the user's basket and they try to deliver them
	return objectiveCompleted;
}

/**************************************************************************
 *printType() - overriden function
 *	Parameters: none
 *	Return Type: string
 *	Prupose: returns a string that contains the type of the space centered 
 *		within 18 characters with white space on either side
**************************************************************************/
std::string Window::printType()
{	return "      Window      ";
}

