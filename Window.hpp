/**************************************************************************
 * Program Name:Window.hpp
 * Name:	Manda Jensen
 * Date:	08 JUN 2019
 * Description:	This file contains the definition of the class Window.
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
 *				all Space* variables to nullptr
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
 *				returns true if the objective has been 
 *				completed, false if not
 *		printType() - overriden function
 *			Parameters: none
 *			Return Type: string
 *			Prupose: returns a string that contains the type of
 *				the space centered within 18 characters with
 *				white space on either side
**************************************************************************/

#ifndef WINDOW_H
#define WINDOW_H

#include "Space.hpp"
#include "ingredients.hpp" 
#include <string>
#include <vector>

class Window: public Space
{	public:
		Window();
		~Window();
		int spaceMenu() override;
		bool play(std::vector<ingredients> &basket) override;
		std::string printType() override;
};
		
#endif //WINDOW_H
