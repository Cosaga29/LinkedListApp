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
*	AN EXAMPLE FOR MENU LOGIC CAN BE FOUND AT THE BOTTOM
**************************************************************/



#include "Menu.hpp"



/*
Default constructor for menu class, the default stream for the class is standard output
Args:


Return:

*/
//Default constructor - set bound ostream to std::cout
Menu::Menu() :
	outputStream(std::cout){}



/*
One arg constructor for menu class

Args:
output: the stream to be bound to the menu

Return:

*/
//1-arg constructor to bind a specific output stream if necessary
Menu::Menu(std::ostream& output) :
	outputStream(output) {}




/*
Function that adds a prompt to the current menu container


Args:
prompt - prompt to add to collection


Return:

*/
//Add prompt to the containing vector
void Menu::addPrompt(const std::string& prompt)
{
	prompts.push_back(prompt);
	return;
}




/*
Function that clears the vector container that contains all the string prompts
Args:


Return:

*/
//clear the container
void Menu::clearMenu()
{
	prompts.clear();
	return;
}




/*
Function that loops through container to display all the current prompts held
in the container vector
Args:


Return:

*/
//for each element in container, display the elements to the proper bound output
void Menu::display() const
{
	for (unsigned i = 0; i < prompts.size(); i++) {
		outputStream << "[ " << i + 1 << " ] " << prompts[i] << std::endl;
	}

	return;
}





/*
Receive a choice from user, make sure that it falls within the correct range for the container.
Menu choices are: [1 - prompts.size()]
Container indicies are: [0 - (prompts.size() - 1)]


Args:


Return:

*/
int Menu::getUserChoice() const
{
	return validateInputRangeMenu();
}





/*
Funcion that returns the the last entry number the user would see in a menu

EXAMPLE:

1. first prompt
2. second prompt
3. exit

this function would return 3, which is the last prompt in the menu always.
Args:


Return:

*/
//Last menu entry should always be exit.
int Menu::getExitCode() const
{
	return prompts.size();
}




/*
Function that outputs the current prompt held in the container at the index specified
to the current bound output stream


Args:
index - index into the containing vector

Return:

*/
void Menu::promptIndex(const int& index)
{

	//check that index is valid:
	if (index >= 1 && index <= prompts.size()) {
		outputStream << "\t" << prompts[index - 1] << std::endl;	//return prompt string at the index
	}

}




/*
Output a message to the current bound out-stream.

Function that lets the menu display any message, is not part of the prompts contained in the vector
Args:
message to be printed

Return:

*/

void Menu::displayMessage(const std::string &message)
{
	outputStream << message << std::endl;
}





/*
Function that returns the current prompt held in the container at the index specified

Args:


Return:
string : string at the index specified

*/
//get a prompt message string from the menu if its within vector bounds
std::string Menu::getPrompt(const int & index)
{

	if (index-1 >= 0 && index <= prompts.size()) {
		return prompts[index-1];
	}
	else {
		return "";
	}
}






/*
The validation method that is always called when a choice is desired from a menu.

The function returns an int guarnteed to be in range of the menu. If bad input is given,
the menu is displayed again.

*/
int Menu::validateInputRangeMenu() const
{
	bool valid = false;
	int toReturn;
	while (!valid) {
		display();
		while (!(std::cin >> toReturn)) {
			display();
			std::cout << "Bad input. " << std::endl;
			clearInputStream();
		}

		if (toReturn >= 1 && toReturn <= prompts.size()) {
			valid = true;
		}
		else {
			std::cout << "Input out of range. " << std::endl;
			clearInputStream();
		}
	}

	return toReturn;
}









/*
EXAMPLE MENU LOGIC IMPLEMENTATION:

int userChoice;
	do {
		userChoice = playGameMenu.getUserChoice();

		switch (userChoice) {
		case 1:
			rounds = validateInputRange(MIN_ROUNDS, MAX_ROUNDS, playGameMenu.getPrompt(1));
			break;

		case 2:
			player1Die = (DIE_TYPE)validateInputRange(0, 1, playGameMenu.getPrompt(2));
			break;

		case 3:
			player2Die = (DIE_TYPE)validateInputRange(0, 1, playGameMenu.getPrompt(3));
			break;

		case 4:
			player1DieSides = validateInputRange(MIN_SIDES, MAX_SIDES, playGameMenu.getPrompt(4));
			break;

		case 5:
			player2DieSides = validateInputRange(MIN_SIDES, MAX_SIDES, playGameMenu.getPrompt(5));
			break;

		case 6:
			break;
		}



	} while (userChoice != playGameMenu.getExitCode());*/