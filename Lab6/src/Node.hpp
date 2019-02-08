#ifndef NODE_HPP
#define NODE_HPP

/*************************************************************
*	Author: Martin Edmunds
*	Email: edmundsm@oregonstate.edu
*	Class: CS 162-400
*	Date: 02/08/19
*	Description: Node declaration file to implement a node to be used
*	in the linked-list class. 

Includes two pointers and an integer
Points to next node, previous node and contains an integer value
**************************************************************/

struct Node {

	Node* next;
	Node* prev;
	int val;

};


#endif