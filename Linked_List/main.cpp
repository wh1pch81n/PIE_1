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

int main(int argc, const char * argv[])
{
	
	// insert code here...
	
	Node<int> *head = new Node<int>(9);
	head->setNext( new Node<int>(4));
	head->getNext()->setItem(3);
	if (!prependList(head, 9999999)) {
		return -1;
	}
	
	for (Node<int> *cur = head; cur; cur = cur->getNext()) {
		cout << cur->getItem() << "  " << cur->getNext() << endl;
	}
	return 0;
}
