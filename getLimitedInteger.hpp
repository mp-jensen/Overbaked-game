/**************************************************************************
 * Program Name:getLimitedInteger.hpp
 * Name:	Manda Jensen
 * Date:	27 MAY 2019
 * Description:	This file is the header file for the getLimitedInteger function
 * 		which has parameters for a pointer to an integer, an integer for
 * 		the lowest acceptable input integer and an integer for the highest
 * 		acceptable input integer. It returns nothing. It will loop until
 * 		the user inputs a valid input based on the input type being an
 * 		integer and the low and high limits supplied in the function call.
 * 		Each time an invalid input is submitted, an error message will
 * 		print and the function will wait for a new user input.
**************************************************************************/

#ifndef GETLIMITEDINTEGER_H
#define GETLIMITEDINTEGER_H

void getLimitedInteger(int *x, int lowLim, int highLim);

#endif //GETLIMITEDINTEGER_H
