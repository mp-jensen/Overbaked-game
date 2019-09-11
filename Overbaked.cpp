/**************************************************************************
 * Program Name:Overbaked.cpp
 * Name:	Manda Jensen
 * Date:	08 JUN 2019
 * Description:	This file contains the function definitions for the public
 * 		functions in the class Overbaked.
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
 *			kitchen, set currMove to 1, set the browniesComplete 
 *			flag to false
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
 *			true or the currMove is > 25
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
 *			direction (check using the isEmpty_ function of the space 
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

#include "Overbaked.hpp" 
#include "Space.hpp" 
#include "ingredients.hpp" 
#include "spaceType.hpp" 
#include "getLimitedInteger.hpp"
#include "Refrigerator.hpp"
#include "Pantry.hpp"
#include "Bowl.hpp"
#include "StandMixer.hpp"
#include "Oven.hpp"
#include "Dish.hpp"
#include "Window.hpp"
#include "Trash.hpp"

#include <iostream>
#include <iomanip>
#include <vector>

/*************************************************************************
 * Overbaked() - default constructor
 *	Parameters: none
 *	Return Type: n/a
 *	Purpose: initializes the kitchen space pointer to a pointer with the 
 *	below space arrangement, initializes the player pointer to point to 
 *	the same space as the kitchen, set currMove to 1, set the 
 *	browniesComplete flag to false
 *	kitchen arrangement:
 *	ref	pantry	bowl	mixer
 *	oven	dish	window	trash
*************************************************************************/
Overbaked::Overbaked()
{	//define new pointers for each space in the kitchen
	Space* initRef = new Refrigerator;
	Space* initPantry = new Pantry;
	Space* initBowl = new Bowl;
	Space* initStandMixer = new StandMixer;
	Space* initOven = new Oven;
	Space* initDish = new Dish;
	Space* initWindow = new Window;
	Space* initTrash = new Trash;
	//set the Neighbors for each of the spaces
	initRef->setNeighbors(nullptr, initPantry, initOven, nullptr);
	initPantry->setNeighbors(nullptr, initBowl, initDish, initRef);
	initBowl->setNeighbors(nullptr, initStandMixer, initWindow, initPantry);
	initStandMixer->setNeighbors(nullptr, nullptr, initTrash, initBowl);
	initOven->setNeighbors(initRef, initDish, nullptr, nullptr);
	initDish->setNeighbors(initPantry, initWindow, nullptr, initOven);
	initWindow->setNeighbors(initBowl, initTrash, nullptr, initDish);
	initTrash->setNeighbors(initStandMixer, nullptr, nullptr, initWindow);
	//set the kitchen pointer to the refrigerator space and the player pointer
	//to the refrigerator space
	kitchen = initRef;
	player = kitchen;
	//set each of the pointers used to initalize the kitchen to null
	initRef = nullptr;
	initPantry = nullptr;
	initBowl = nullptr;
	initStandMixer = nullptr;
	initOven = nullptr;
	initDish = nullptr;
	initWindow = nullptr;
	initTrash = nullptr;
	//set currMove and browniesComplete
	currMove = 1;
	browniesComplete = false;
}


/*************************************************************************
 *~Overbaked() - default destructor
 *	Parameters: n/a
 *	Return Type: n/a
 *	Purpose: safely frees the memory used for the dynamically allocated
 *	Space objects that are defined in the default constructor
*************************************************************************/
Overbaked::~Overbaked()
{	//define a temporary pointer holder, and set it equal to the 
	//next space in the row
	Space* temp = kitchen;
	temp = kitchen->getRight();
	//delete all spaces in the first row
	do
	{	delete kitchen;
		kitchen = temp;
		temp = kitchen->getRight();
	}while(temp != nullptr);
	//set the temp pointer to the last item in the second row
	//then delete all spaces in the second row
	temp = kitchen->getBottom();
	do
	{	delete kitchen;
		kitchen = temp;
		temp = kitchen->getLeft();
	}while(temp != nullptr);
	delete kitchen;
	kitchen = nullptr;
}

/*************************************************************************
 *playGame()
 *	Parameters: none
 *	Return Type: void
 *	Purpose: Loops playRound() until the complete flag is true or the 
 *	currMove is > 25
*************************************************************************/
void Overbaked::playGame()
{	//print the welcome instructions for the game
	std::cout << "\n" << std::setw(40) << std::right << "Welcome to "
	<< std::setw(40) << std::left << "Overbaked!!" << "\n";
	std::cout << "During this game you will move around the kitchen in order "
		<< "to prepare\na batch of brownies in time to deliver them to "
		<< "the party to celebrate.\nIf you do not deliver them in time "
		<< "partygoers will leave the party\nand the party will be "
		<< "ruined.\n";
	std::cout << "\nThe tasks you must complete in order to make brownies are:\n"
		<< "1. Collect ingredients\n"
		<< "2. Mix the wet ingredients (sugar, butter, eggs) in the stand mixer\n"
		<< "3. Mix the dry ingredients (four, baking soda, cocoa powder) in the "
			<< "mixing bowl\n"
		<< "4. Mix the wet and dry ingredients togeter in the stand mixer\n"
		<< "5. Bring the batter and pan to the oven\n"
		<< "6. Check on the brownies baking in the oven\n"
		<< "7. Deliver the brownies and pan from the oven to the window\n"
		<< "And this must all be completed within 35 steps, so be efficient!\n";
	
	//call playRound until browniesComplete is true or the current move is >=36
	while(!browniesComplete && currMove <36)
	{	playRound();
	}
	//if browniesComplete is true, print the success message
	if(browniesComplete)
	{	std::cout << "Congratulations!!! You delivered your delicious "
			<< "brownies to\nthe party and a fun time was had by "
			<< "all. It would not\nhave been possible without "
			<< "your expert baking skills!" << std::endl;
	}
	//if browniesComplete is false, print the failure message
	else
	{	std::cout << "You failed to finish the brownies in time. The "
			<< "party was\nruined and no one stayed to celebrate "
			<< "beacuse\nthe promised brownies were not delivered"
			<< ".\nBetter luck next time." << std::endl;
	}
}

/*************************************************************************
 *playRound()
 *	Parameters: none
 *	Return Type: void
 *	Purpose: goes through the motions of one round of the game, prints 
 *	the header for the round, calls printKitchen and printBasket, calls 
 *	the move function with the moveMenu as the argument, calls the play 
 *	function of the Square that the player is on and pass basket as the 
 *	argument
**************************************************************************/
void Overbaked::playRound()
{	//print round header
	std::cout << "\n\n";
	for(int i=0; i<30; i++)
	{	std::cout << "*";
	}
	std::cout << std::setw(10) << std::right << "ROUND";
	std::cout << std::setw(5) << currMove << "     ";
	for(int i=0; i<30; i++)
	{	std::cout << "*";
	}
	std::cout << "\n";
	std::cout << std::endl;
	//print the user's basket items and the current space items and
	//the kitchen and where the user is in the kitchen
	printBasket();
	player->printItems();
	printKitchen();
	//ask the player where they want to move and move accordingly
	move(moveMenu());
	//play the options on the current space of the player
	browniesComplete = player->play(basket);
	//increment the current step
	currMove++;
}
 
/*************************************************************************
 *move()
 *	Parameters: int
 *	Return Type: void
 *	Purpose: use the integer passed as an argument to move the player 
 *	Space pointer to the space in the direction as requested in the 
 *	argument, if the direction of the move is not possible as there is 
 *	no space in that direction (check using the isEmpty_ function of the 
 *	space for the direction), print a message to the user saying 
 *	they cannot move, after the move or non-move, call printKitchen
**************************************************************************/
void Overbaked::move(int direction)
{	//declare a bool to denote if the move is valid
	bool validMove = true;	
	switch(direction)
	{	case 1: //move up
			if(!(player->isEmptyTop()))
			{	player = player->getTop();
			}
			else
			{	validMove = false;
			}
			break;
		case 2: //move right
			if(!(player->isEmptyRight()))
			{	player = player->getRight();
			}
			else
			{	validMove = false;
			}
			break;
		case 3: //move down
			if(!(player->isEmptyBottom()))
			{	player = player->getBottom();
			}
			else
			{	validMove = false;
			}
			break;
		case 4: //move left
			if(!(player->isEmptyLeft()))
			{	player = player->getLeft();
			}
			else
			{	validMove = false;
			}
			break;
		case 5: //stay where you are
			break;
		default:
			break;
	}
	if(!validMove)
	{	std::cout << "That is not a valid direction to move, you will "
			<< "stay in your current location.\n";
	}
	std::cout << "Your location in the kitchen is now:\n";
	printKitchen();
}
			
/*************************************************************************
 *moveMenu()
 *	Parameters: none
 *	Return Type: int
 *	Purpose: print the menu to the user of which direction to move in, 
 *	there are five options - up, down, left, right and no move, returns 
 *	the integer corresponding with the choice of the user
**************************************************************************/
int Overbaked::moveMenu()
{
	int userChoice = 0;
	int lowLim = 1;
	int highLim = 5;
	int num = lowLim-1;

	//print the move menu
	std::cout << "- Select a direction to move during this turn" << std::setw(36) << std::right
		<< "-\n";
	std::cout << "- " << std::setw(2) << std::right << ++num << ". " << std::setw(73) << std::left 
		<< "Move Up" << "-\n"; 
	std::cout << "- " << std::setw(2) << std::right << ++num << ". " << std::setw(73) << std::left 
		<< "Move Right" << "-\n"; 
	std::cout << "- " << std::setw(2) << std::right << ++num << ". " << std::setw(73) << std::left 
		<< "Move Down" << "-\n"; 
	std::cout << "- " << std::setw(2) << std::right << ++num << ". " << std::setw(73) << std::left 
		<< "Move Left" << "-\n";
	std::cout << "- " << std::setw(2) << std::right << ++num << ". " << std::setw(73) << std::left 
		<< "Stay on current space" << "-\n";
	for(int i=0; i<80; i++)
	{	std::cout <<"-";
	}
	std::cout << "\n";
	std::cout << "Please enter the integer of your choice:" << std::endl;
	//store the user's choice and return it
	getLimitedInteger(&userChoice, lowLim, highLim);
	return userChoice;
}

/*************************************************************************
 *printKitchen()
 *	Parameters: none
 *	Return Type: void
 *	Purpose: calls the printType() for each space in the kitchen and 
 *	prints the arrangement of the kitchen to the screen
**************************************************************************/
void Overbaked::printKitchen()
{	for(int i=0; i<80; i++)
	{	std::cout <<"-";
	}
	std::cout << "\n";
	//set a reference printSpace to the start of the kitchen
	Space* printSpace = kitchen;
	for(int i=0; i<4; i++)
	{	std::cout << "| " << printSpace->printType() << " |";
		printSpace = printSpace->getRight();
	}
	std::cout << "\n";
	//set printSpace back to start of kitchen, check if the player is on
	//the printSpace and print where they are
	printSpace = kitchen;
	for(int i=0; i<4; i++)
	{	if(player == printSpace)
		{	std::cout << "|  (YOU ARE HERE)  |";
		}
		else
		{	std::cout << "|                  |";
		}
		printSpace = printSpace->getRight();
	}
	std::cout << "\n";
	for(int i=0; i<80; i++)
	{	std::cout <<"-";
	}
	std::cout << "\n";
	//set printSpace to the start of the second row of the kitchen
	printSpace = kitchen->getBottom();
	for(int i=0; i<4; i++)
	{	std::cout << "|" << printSpace->printType() << "|";
		printSpace = printSpace->getRight();
	}
	std::cout << "\n";
	//set printSpace to start of second row, check if teh player is on
	//the printSpace and print where they are
	printSpace = kitchen->getBottom();
	for(int i=0; i<4; i++)
	{	if(player == printSpace)
		{	std::cout << "|  (YOU ARE HERE)  |";
		}
		else
		{	std::cout << "|                  |";
		}
		printSpace = printSpace->getRight();
	}
	std::cout << "\n";
	for(int i=0; i<80; i++)
	{	std::cout <<"-";
	}
	std::cout << "\n";
}

/*************************************************************************
 *printBasket()
 *	Parmaeters: none
 *	Return Type: void
 *	Purpose: prints all ingredients in the basket and how much space is 
 *	left in the basket
**************************************************************************/
void Overbaked::printBasket()
{	int size = basket.size();
	//print the current capacity of the basket & how full it is
	std::cout << "Your basket contains " << size << " out of 3 possible "
		<< "items you can carry.\n";
	//print the basket items
	if(size > 0)
	{	std::cout << "BASKET ITEMS: "; 
		for(int i=0; i<size; i++)
		{	if(i >0)
			{	std::cout << ", ";
			}
			switch(basket[i])
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
		
