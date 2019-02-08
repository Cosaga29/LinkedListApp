#ifndef MENU_HPP
#define MENU_HPP


/*************************************************************
*	Author: Martin Edmunds
*	Email: edmundsm@oregonstate.edu
*	Class: CS 162-400
*	Date: 01/09/19
*	Description: Simple menu class that handles the creation
*	and addition of menu prompts to be displayed by a program.
*
*	This function does not handle any logic for a main program
*	and must be implemented elseware.
*
*	The last menu function that should be given should be an exit option.
**************************************************************/


#include <vector>
#include <string>
#include <sstream>
#include "InputValidationFunctions.hpp"


class Menu {

private:

	std::ostream& outputStream;

	std::vector<std::string> prompts;

	int validateInputRangeMenu() const;

public:

	Menu();

	Menu(std::ostream& os);

	void addPrompt(const std::string& prompt);

	void clearMenu();

	void display() const;

	int getUserChoice() const;

	int getExitCode() const;

	void promptIndex(const int&);

	void displayMessage(const std::string&);

	std::string getPrompt(const int& index);

};




#endif