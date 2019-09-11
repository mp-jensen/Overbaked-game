/**************************************************************************
 * Program Name:getLimitedInteger.cpp
 * Name:	Manda Jensen
 * Date:	27 MAY 2019
 * Description:	This file details the function getLimitedInteger. This function
 * 		has parameters for a pointer to an integer, an integer for
 * 		the lowest acceptable input integer and an integer for the highest
 * 		acceptable input integer. It returns nothing. It will loop until
 * 		the user inputs a valid input based on the input type being an
 * 		integer and the low and high limits supplied in the function call.
 * 		Each time an invalid input is submitted, an error message will
 * 		print and the function will wait for a new user input. The valid
 * 		input will be stored in the integer pointer passed as an argument.
 * References:  The use of the try/catch function was adapted from
 * 		tutorialspoint.com/cplusplus/cpp_exceptions_handling.htm
**************************************************************************/

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::stoi;

//arguments for this functin are a pointer to an integer, this is where the integer will
//be stored if it is an integer, a low limit for the integer and a high limit for the integer,
//these must be eitehr equal to each other or the low limit must be less than the high limit. 
//The limits are inclusive of the ends. The function will request input until a valid input
//is provided.
void getLimitedInteger(int* x, int lowLim, int highLim)
{
	bool status = true;
	string inputHold = "";

	//loop this until the input is valid
	do
	{	
		//temporarily hold user input
		getline(cin, inputHold);
	
		//check for length of input to know how long to loop the integer validation
		int length = inputHold.length();

		//set the status to true, it will be set to false if it is found invalid
		status = true;

		//validate each character in the user input ensuring it is a digit, if not
		//set the status to false
		for(int i=0; i<length; i++)
		{
			if(i>0)
			{	if(!isdigit(inputHold[i]))
				{	status = false;
				}
			}
			//the first character can have a + or - indicating the sign of the integer
			//check for that only on the first character of the input
			else
			{	if(!isdigit(inputHold[i]) && inputHold[i] != '-' && inputHold[i] != '+'
					&& length > 1)
				{	status = false;
				}
			}
		}
		//if the user input has been validated to be all integers or a signed integer
		//try converting it to an integer and placing it in the pointer that was passed
		//as an argument to the function
		if(status != false)
		{	try
			{	*x = std::stoi(inputHold,nullptr,10);
				if((*x < lowLim) || (*x > highLim))
				{	cout << "User input not within valid range! Try again." << endl;
					status = false;
				}
			}
		//if storing it in an integer fails (number is too large, number is too small . . .)
		//then send error message and set the status to false 
			catch(...)
			{	cout << "Invalid user input! Try again." << endl;
				status = false;
			}
		}
		else
		{	cout << "Invalid user input! Try again." << endl;
		}
	}while(!status);
}
