#include <iostream>
#include "linkedlistiterator.h"
using namespace std;

// demo of linked list iterator class

void Print(const LinkedList & theList) {
    LinkedListIterator iter (theList);  // binding the iterator object to list
	
	//theList.addToBeginning (200);     // does not compile with const parameter.
                                        // remove const and try. What do you expect to display?
                                        // Is first node 200 or not?
	
	//LinkedListIterator iter2(iter);   // this line shows the default copy constructor.
                                        // decomment this statement and change "iter"s with "iter2" in the rest of
                                        // this function. Default copy constructor makes shallow copy
                                        // but this is what we want here.

	// The following loop changes the int value of the current node.
	// This can be done only if Current() returns a reference.
	// Change the definition of Current() to make this work.
	/*for(iter.Init(); iter.HasMore(); iter.Next())
		iter.Current()++;	
    */
	
	for(iter.Init(); iter.HasMore(); iter.Next())
		cout << iter.Current() << endl;

    cout  << "size = " << theList.length() << endl << endl;
}


int main() {
	LinkedList list1, list3;

	for (int k=0; k < 4; k++)
		list1.addToBeginning(k+1);

	cout << "content of list1 (using free Print function):\n";
	Print(list1);

	cout << "content of list1 (using printList member function):\n";
	list1.printList();
	
	cout << "content of list3:\n";
	Print(list3);
	
	list3 = list1; 
	cout << "list1 is assigned to list3\n";
	cout << "content of list3:\n";
	Print(list3);

	list1.deleteList();
	cout << "list1 is deleted\n";
	cout << "content of list1:\n";
	Print(list1);

	list3.addToBeginning(10);
	cout << "10 added to the beginning of list3\n";
	cout << "content of list3:\n";
	Print(list3);

}  

