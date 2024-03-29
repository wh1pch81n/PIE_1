//
//  main.cpp
//  LinkedList
//
//  Created by Derrick Ho on 3/2/14.
//  Copyright (c) 2014 Derrick Ho. All rights reserved.
//

#include <iostream>
#include "Node.h"

using namespace std;

/**
 inserts a node to the beginging of the list
 @param head a reference to the pointer of the head of the list
 @param data the data value that you want to store
 @return if the insertion was a success then it will return true
 */
template <class T>
bool prependList (Node<T> *&head, T data) {
	Node<T> *newInstance = new Node<T>(data);
	if (!newInstance) {
		return false;
	}
	newInstance->setNext(head);
	head = newInstance;
	return true;
}

/**
 traverses the list
 @param node a node that will be the starting point of the traversal all the way to the end
 @param action a block pointer that will be called on the currect node.
 */
template <class z>
void traverseList(Node<z> *node, void(^action)(Node<z> *node)) {
  if (node) {
		action(node);
		traverseList(node->getNext(), action);
	}
}

/**
 finds the node that contains the given value
 @param
 */
template <class T>
Node<T> *find(Node<T> *node, T data) {
  __block Node<T> *cur = NULL;
	traverseList(node, ^(Node<T> *node){
		if (node->getItem() == data) {
			cur = node;
		}
	});

	return cur;
}


/*
 Deleting elements from the list
 @param head a reference to the first node of the list
 @param deleteMe reference to the node that will be deleted
 @return is true if it found the node and deleted it, false otherwise
 */
template <class T>
bool deleteElement(Node<T> *&head, Node<T> *deleteMe) {
  if (!head || !deleteMe) {
		return false;
	}
	
	if (head == deleteMe) {
		head = head->getNext();
		delete deleteMe;
		return true;
	}
	
	for (Node<T> *prev = head; prev->getNext(); prev = prev->getNext()) {
		if (prev->getNext() == deleteMe) {
			prev->setNext(prev->getNext()->getNext());
			delete deleteMe;
			return true;
		}
	}
	
	return false;
}

/**
 prints the list
 */
template <class T>
void printList(Node<T> *head) {
	traverseList(head, ^(Node<T> *node){
		cout << node << "  " << node->getItem() << "  " << node->getNext() << endl;
	});
}

/**
 recursive delete list
 then sets the head to NULL
*/
template <class T>
void deleteListRecursive(Node<T> *&head) {
	if (!head) {
		return;
	}
	Node<T> *deleteThis = head;
	head = head->getNext();
	deleteListRecursive<T>(head);
	delete deleteThis;
}


/**
 iterative delete list
 
 */
template <class T>
void deleteListIterative(Node<T> *&head) {
	Node<T> *deleteMe = head;
	for (; deleteMe;) {
		head = head->getNext();
		delete deleteMe;
		deleteMe = head;
	}
}

int main(int argc, const char * argv[])
{
	
	// insert code here...
	Node<int> *headNum;
	for (int i = 10; i >= 0; i--) {
		prependList(headNum, i);
	}
	Node<char> *headChar;
	for (char c = 'Z'; c >= 'A'; c--) {
		prependList(headChar, c);
	}
	
	printList(headNum);
	printList(headChar);
	
	deleteListRecursive(headNum);
	deleteListIterative(headChar);
	
	return 0;
}


