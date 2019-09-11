/**************************************************************************
 * Program Name:Oven.hpp
 * Name:	Manda Jensen
 * Date:	08 JUN 2019
 * Description:	This file contains the definition of the class Oven.
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
 *				all Space* variables to nullptr
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

#ifndef OVEN_H
#define OVEN_H

#include "Space.hpp"
#include "ingredients.hpp" 
#include <string>
#include <vector>

class Oven: public Space
{	public:
		Oven();
		~Oven();
		int spaceMenu() override;
		bool play(std::vector<ingredients> &basket) override;
		std::string printType() override;
};
		
#endif //OVEN_H
