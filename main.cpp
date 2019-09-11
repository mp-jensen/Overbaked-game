/**************************************************************************
 * Program Name:main.cpp
 * Name:	Manda Jensen
 * Date:	27 MAY 2019
 * Description:	This file contains the main function that drives the Overbaked
 * 		game. It first prints the menu to the user using 
 * 		mainMenu then based on the answer provided by the user
 * 		it calls the associated function and requests the
 * 		associated input needed to run that function.
 * 		It loops the menu until the user chooses to exit and upon
 * 		exiting it exits the main function.
**************************************************************************/
#include "mainMenu.hpp"
#include "getLimitedInteger.hpp"
#include "Overbaked.hpp"

int main()
{	//define variables to store the user's input during the progress of the 
	//program an integer for the user's menu choice 
	int menuChoice = 0;

	//print the menu and get the user's selection, loop this until the user 
	//chooses to exit
	do
	{	menuChoice = mainMenu();
		//define a game variable each time the menu is called
		Overbaked game;
		//use a switch statement to execute the proper code based on 
		//the user's choice
		switch(menuChoice)
		{
			case 1:
				game.playGame();
				break;

			default:
				break;
		}
	}while(menuChoice != 2);

	return 0;
}

