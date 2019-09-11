/**************************************************************************
 * Program Name:Overbaked.hpp
 * Name:	Manda Jensen
 * Date:	08 JUN 2019
 * Description:	This file contains the definition of the class Overbaked.
 *	Variables:
 *		Space* kitchen - pointer to the top left most corner of the 
 *			kitchen
 *		Space* player - points to the player's location in the kitchen,
 *			the location always starts in the same place within 
 *			the kitchen
 *		int currMove - current move the player is on
 *		vector<ingredients> basket - ingredients vector containing all
 *			of the ingredients the player currently has, limited
 *			to three ingredients at any given time in the Space 
 *			class
 *		bool browniesComplete - flag indicating if the baked brownies 
 *			have been delivered to the window yet, false if no, 
 *			true if yes
 *
 *	Functions:
 *		Overbaked() - default constructor
 *			Parameters: none
 *			Return Type: n/a
 *			Purpose: initializes the kitchen space pointer to a 
 *			pointer with the below space arrangement, initializes 
 *			the player pointer to point to the same space as the 
 *			kitchen, set currMove to 1, set the ingredient vector 
 *			list to an empty list, set the browniesComplete flags 
 *			to false
 *			kitchen arrangement:
 *			ref	pantry	bowl	mixer
 *			oven	dish	window	trash
 *		~Overbaked() - default destructor
 *			Parameters: n/a
 *			Return Type: n/a
 *			Purpose: safely frees the memory used for the 
 *			dynamically allocated Space objects that are defined 
 *			in the default constructor
 *		playGame()
 *			Parameters: none
 *			Return Type: void
 *			Purpose: Loops playRound() until the complete flag is 
 *			true or the currStep is > 25
 *		playRound()
 *			Parameters: none
 *			Return Type: void
 *			Purpose: goes through the motions of one round of the 
 *			game, prints the header for the round, calls printKitchen 
 *			and printBasket, calls the move function with the moveMenu 
 *			as the argument, calls the play function of the Square 
 *			that the player is on and pass basket as the argument
 *		move()
 *			Parameters: int
 *			Return Type: void
 *			Purpose: use the integer passed as an argument to move 
 *			the player Space pointer to the space in the direction 
 *			as requested in the argument, if the direction of the 
 *			move is not possible as there is no space in that 
 *			direction (check using the empty_ function of the space 
 *			for the direction), print a message to the user saying 
 *			they cannot move, after the move or non-move, call 
 *			printKitchen
 *		moveMenu()
 *			Parameters: none
 *			Return Type: int
 *			Purpose: print the menu to the user of which direction 
 *			to move in, there are five options - up, down, left, 
 *			right and no move, returns the integer corresponding 
 *			with the choice of the user
 *		printKitchen()
 *			Parameters: none
 *			Return Type: void
 *			Purpose: calls the printType() for each space in the 
 *			kitchen and prints the arrangement of the kitchen to the 
 *			screen
 *		printBasket()
 *			Parmaeters: none
 *			Return Type: void
 *			Purpose: prints all ingredients in the basket and how 
 *			much space is left in the basket
**************************************************************************/

#ifndef OVERBAKED_H
#define OVERBAKED_H

#include "Space.hpp" 
#include "ingredients.hpp" 
#include <vector>

class Overbaked
{	private:
		Space* kitchen;
		Space* player;
		int currMove;
		std::vector<ingredients> basket;
		bool browniesComplete;
	public:
		Overbaked();
		~Overbaked();
		void playGame();
		void playRound();
		void move(int direction);
		int moveMenu();
		void printKitchen();
		void printBasket();
};
		
#endif //OVERBAKED_H
