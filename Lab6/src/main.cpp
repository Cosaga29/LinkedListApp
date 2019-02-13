#include <iostream>
#include "LinkedList.hpp"
#include "Menu.hpp"
#include "InputValidationFunctions.hpp"

/*************************************************************
*	Author: Martin Edmunds
*	Email: edmundsm@oregonstate.edu
*	Class: CS 162-400
*	Date: 02/08/19
*	Description: Main function for the linked-list project.
*	Controls the execution for a menu driven program that manages
*	a linked-list. 
*	
*	The user can choose to start with a blank list or create one from 
*	an imported file
**************************************************************/

int main() {

	std::cout << "Would you like to initialize list from file? (y/n)" << std::endl;	//prompt for extra credit file input
	char userFileChoice = validateInputYN();


	std::string fileName;
	std::ifstream inputFile;
	bool goodFile = false;


	LinkedList* list;


	if (userFileChoice == 'y') {		//create linked list from file
		while (!goodFile) {

			std::cout << "Please enter the name of a file to read from: " << std::endl;
			clearInputStream();			//clear away '\n' character
			std::getline(std::cin, fileName);
			inputFile.open(fileName.c_str());

			if (inputFile.good()) {
				goodFile = true;
			}
		}

		list = new LinkedList(inputFile);
	}

	else {			//create blank linked list

		list = new LinkedList();

	}


	
	int userAddedValue;	//variable to store user input 

	//Create and build user Menu function
	Menu userMenu;
	userMenu.addPrompt("Add a new node to head");
	userMenu.addPrompt("Add a new node to the tail");
	userMenu.addPrompt("Delete from head");
	userMenu.addPrompt("Delete from tail");
	userMenu.addPrompt("Traverse the list reversely");
	userMenu.addPrompt("Print the head of the list");
	userMenu.addPrompt("Print the tail of the list");
	userMenu.addPrompt("Exit");



	bool userExit = false;	//user exit flag
	while (!userExit) {
		switch (userMenu.getUserChoice()) {

		case 1:	//Add a number to head of list
			list->addNodeHead(validateInput("Enter a number to add to the head of the list: "));

			break;

		case 2:	//add a number to tail of list
			list->addNodeTail(validateInput("Enter a number to add to the tail of the list: "));

			break;

		case 3:	//delete head from list
			userMenu.displayMessage("Deleting head from list... ");
			list->deleteHead();

			break;

		case 4:	//delete tail from list
			userMenu.displayMessage("Deleting tail from list... ");
			list->deleteTail();

			break;

		case 5:	//print the list from tail to head (reverse)
			userMenu.displayMessage("Printing list in reverse: ");
			list->traverseListR();

			break;

		case 6:	//print the head of the list
			userMenu.displayMessage("Printing head of list...");
			list->printHeadValue();
			
			break;

		case 7: //print the tail of the list
			userMenu.displayMessage("Printing tail of list...");
			list->printTailValue();

			break;
		
		case 8:	//user has elected to exit
			userMenu.displayMessage("Exiting...");
			userExit = true;

			break;
		}
	}

	std::cin.get();		

	return 0;
}