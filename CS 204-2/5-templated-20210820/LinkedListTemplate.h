#ifndef _LINKEDLISTTEMPLATE_H
#define _LINKEDLISTTEMPLATE_H

template <class itemType>
struct node {
	itemType info;
	node *next; 

	node ()
	{}

	node (const itemType & s, node * link)
		: info(s), next (link)
	{ }
	
};


template <class itemType>
class LinkedList 
{
	private:
		node<itemType> * head;
		int size;
	public:
		 LinkedList ();
		 LinkedList (const LinkedList &);  //copy constructor 
		 ~LinkedList ();   //destructor
		 void printList() const;
		 void addToBeginning(itemType n);
		 void deleteList ();
		 const LinkedList & LinkedList::operator = (const LinkedList & rhs);
		 node<itemType> * createClone () const; //generates the clone of the list and return the clone's head
};

#include "LinkedListTemplate.cpp"  
//Dont forget to include the impl. file either here or at the beginning of the main program, but not both
//Do not add this cpp to the project

#endif