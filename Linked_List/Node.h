//
//  Node.h
//  LinkedList
//
//  Created by Derrick Ho on 3/2/14.
//  Copyright (c) 2014 Derrick Ho. All rights reserved.
//

#ifndef __LinkedList__Node__
#define __LinkedList__Node__

#include <iostream>

template <class T>
class Node {
  T item;
	Node *next;
	
public:
  Node (const T &item): item(item), next(NULL) {}
	~Node () {}
	
	Node *getNext() const { return this->next; }
	const T &getItem() const { return this->item; }
	void setNext(Node *next) { this->next = next; }
	void setItem(const T &item) { this->item = item; }
};

#endif /* defined(__LinkedList__Node__) */
