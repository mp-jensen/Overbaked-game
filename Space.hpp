/**************************************************************************
 * Program Name:Space.hpp
 * Name:	Manda Jensen
 * Date:	08 JUN 2019
 * Description:	This file contains the definition of the abstract class Space.
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

#ifndef SPACE_H
#define SPACE_H

#include "spaceType.hpp" 
#include "ingredients.hpp" 
#include <string>
#include <vector>

class Space
{	protected:
		Space* top;
		Space* right;
		Space* bottom;
		Space* left;
		spaceType type;
		std::vector<ingredients> items;

	public:
		virtual ~Space() {};
		virtual int spaceMenu() = 0;
		virtual bool play(std::vector<ingredients> &basket) = 0;
		virtual std::string printType() = 0;
		bool isEmptyTop();
		bool isEmptyRight();
		bool isEmptyBottom();
		bool isEmptyLeft();
		Space* getTop();
		Space* getRight();
		Space* getBottom();
		Space* getLeft();
		void printItems();
		int itemMenu();
		int basketMenu(std::vector<ingredients> basket);
		void setNeighbors(Space* top, Space* right, Space* bottom, 
					Space* left);
};
		
#endif //SPACE_H
