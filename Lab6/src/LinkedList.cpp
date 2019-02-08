/*************************************************************
*	Author: Martin Edmunds
*	Email: edmundsm@oregonstate.edu
*	Class: CS 162-400
*	Date: 02/08/19
*	Description: Linked List declaration file

Manages a collection of nodes forming a linked-list.

Consists mainly of a head node, a tail node and a single integer
to keep track of the size of the list.
**************************************************************/

#include "LinkedList.hpp"

/*
No argument constructor, initializes private members to 0
*/
LinkedList::LinkedList()
{
	head = 0;
	tail = 0;
	size = 0;
}

/*
One argument constructor designed to create a linked list from an input file.

The input file should be formatted in the following way:

1 5 10 20 35 
(Space separated values)
*/
LinkedList::LinkedList(std::ifstream & inputFile)
{
	//read an integer from the input file
	head = 0;
	tail = 0;
	size = 0;

	int toAdd;	//store user input
	while (inputFile >> toAdd) {	//check if input is good
		addNodeTail(toAdd);			//add to linked list if input is good
	}

	inputFile.close();
}



/*
Linked list destructor

Starts at the head of the list, if it exists.

Steps through each node in the list and deletes the node
*/
LinkedList::~LinkedList()
{
	if (head != 0) {				//check if valid head
		Node* next = head->next;	//set next node to head's next node
		if (head != 0) {			
			delete head;			//delete the current head
			head = next;			//set new head to next head
			next = head->next;		//get new next head
		}
	}
}

/*
Adds a node to the head of the linked list

Param
	valueToAdd - value to be added tolist
*/
void LinkedList::addNodeHead(int valueToAdd)
{
	//create Node
	Node* toAdd = new Node();
	toAdd->val = valueToAdd;
	toAdd->prev = 0;
	toAdd->next = 0;

	if (size == 0) {	//no head exists
		head = toAdd;
		tail = toAdd;
	}
	else {				//a head already exists
		head->prev = toAdd;		//create a link from pervious head to new added node
		toAdd->next = head;		//create a link from added node to previous head
		head = toAdd;			//set added node as new head
	}
	size++;

	traverseList();
}

/*
Adds a node to the tail of the list

Param
	valueToAdd - value to be added to tail of the list
*/
void LinkedList::addNodeTail(int valueToAdd)
{
	Node* toAdd = new Node();
	toAdd->val = valueToAdd;
	toAdd->prev = 0;
	toAdd->next = 0;

	if (size == 0) {	//no head/tail exists, add it
		head = toAdd;
		tail = toAdd;
	}

	else {				//a tail already exists
		toAdd->prev = tail;		//connect new node to tail
		tail->next = toAdd;		//connect old tail to node
		tail = toAdd;			//set new tail
	}
	size++;

	traverseList();
}


/*
Function that delets the current head of the list, replacing it with a new head
*/
void LinkedList::deleteHead()
{
	if (head != 0) {	//check that there is a valid head to remove
		if (head->next == 0) {		//check if head is the only node, if it is, simply remove references (extra precaution) and delete
			head->prev = 0;
			head->next = 0;
			std::cout << size << std::endl;
			delete head;
			head = 0;
			tail = 0;
		}
		else {
			Node* temp = head;	//create temp pointer to store head reference
			head = head->next;	//move new head to next in list
			head->prev = 0;		//remove reference for old head

			temp->next = 0;		//make the old head safe to delete
			temp->prev = 0;
			delete temp;
		}

		size--;
		traverseList();
	}
	else {
		std::cout << "List is empty, cannot delete" << std::endl;
	}
}

/*
Function that deletes the tail of the list, replacing it if necessary
*/
void LinkedList::deleteTail()
{
	if (tail != 0) {	//check that there is a valid tail to remove
		if (tail->prev == 0) {		//check if tail is only node, if it is, remove reference and delete
			tail->next = 0;
			tail->prev = 0;
			delete tail;
			tail = 0;
			head = 0;
		}
		else {
			Node* temp = tail;	//create temp ptr to store tail reference
			tail = tail->prev;	//set new tail to the previous node in the sequence
			tail->next = 0;		//remove reference for old tail

			temp->next = 0;		//set temp to good state to delete, then delete
			temp->prev = 0;
			delete temp;

		}
		size--;
		traverseList();
	}
	else {
		std::cout << "List is empty, cannot delete" << std::endl;
	}


}


/*
Function that steps through the linked list, prints the values as it moves along

Starts at head, moves to tail
*/
void LinkedList::traverseList() const
{
	if (size == 0) {	//check if list is empty
		std::cout << "Linked List is empty" << std::endl;
	}
	else {
		//traverse list
		Node* currentNode;	//current node to read val
		Node* nextNode;		//next node in list

		currentNode = head;		
		nextNode = head->next;


		std::cout << head->val << " ";				//print head node
		while (nextNode != 0) {
			currentNode = nextNode;					//step currentNode and nextNode through the list
			nextNode = currentNode->next;
			std::cout << currentNode->val << " ";	//print current node
		}


		std::cout << std::endl;
	}
}


/*
Function that steps through the linked list, prints the values as it moves along

Starts at tail, moves to head
*/
void LinkedList::traverseListR() const
{
	if (size == 0) {
		std::cout << "Linked List is empty" << std::endl;
	}
	else {
		Node* currentNode;		//current node to read val
		Node* nextNode;			//next node in list


		currentNode = tail;
		nextNode = tail->prev;


		std::cout  << tail->val << " ";				//print tail node
		while (nextNode != 0) {
			currentNode = nextNode;					//step current node and next node through list
			nextNode = currentNode->prev;
			std::cout << currentNode->val << " ";	//print current node
		}


		std::cout << std::endl;
	}
}

/*
Function that prints the headof the node
*/
void LinkedList::printHeadValue() const
{
	if (head != 0) {
		std::cout << "Head Value: " << head->val << std::endl;
	}
}


/*
Function that prints the tail of the node
*/
void LinkedList::printTailValue() const
{
	if (tail != 0) {
		std::cout << "Tail Value: " << tail->val << std::endl;
	}
}

