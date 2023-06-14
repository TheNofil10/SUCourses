//Demonstrates templated linked list class

#include <iostream>
#include "linkedlisttemplate.h"
//#include "linkedlisttemplate.cpp"
using namespace std;

int main()
{
	string baskan[] = {"Muharrem", "Aziz", "Dursun", "Fikret"};
	LinkedList<string> strlist;	//Linked list object with string element type
	LinkedList<int> intlist;	//Linked list object with integer element type

	for (int k=0; k < 4; k++)  
	{
		strlist.addToBeginning(baskan[k]);
		intlist.addToBeginning(k+1);
	}

	cout << "string list contains:\n";
	strlist.printList();

	cout << "integer list contains:\n";
	intlist.printList();
	
}  

