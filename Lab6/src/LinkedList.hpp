#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include "Node.hpp"
#include <iostream>
#include <fstream>
#include <cctype>

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


class LinkedList {

private:

	Node* head;
	Node* tail;
	int size;



public:

	LinkedList();

	LinkedList(std::ifstream& inputFile);

	~LinkedList();

	void addNodeHead(int);
	
	void addNodeTail(int);

	void deleteHead();

	void deleteTail();

	void traverseList() const;

	void traverseListR() const;

	void printHeadValue() const;

	void printTailValue() const;

	
};





#endif
