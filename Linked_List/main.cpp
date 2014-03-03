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

int main(int argc, const char * argv[])
{
	
	// insert code here...
	
	Node<int> *head = new Node<int>(9);
	head->setNext( new Node<int>(4));
	head->getNext()->setItem(3);
	if (!prependList(head, 9999999)) {
		return -1;
	}
	
	traverseList(head, ^(Node<int> *node){
		cout << node->getItem() << "  " << node->getNext() << endl;
	});
	
	cout << find(head, 9) << endl;
	cout << find(head, 4) << endl;
	cout << find(head, 3) << endl;
	cout << find(head, 0) << endl;
	
	
	
	return 0;
}
